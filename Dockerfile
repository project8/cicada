FROM project8/p8compute_dependencies:v0.2.0 as cicada_common

ENV CICADA_TAG=v1.2.1
ENV CICADA_BUILD_PREFIX=/usr/local/p8/cicada/$CICADA_TAG

RUN mkdir -p $CICADA_BUILD_PREFIX &&\
    cd $CICADA_BUILD_PREFIX &&\
    echo "source ${COMMON_BUILD_PREFIX}/setup.sh" > setup.sh &&\
    echo "export CICADA_TAG=${CICADA_TAG}" >> setup.sh &&\
    echo "export CICADA_BUILD_PREFIX=${CICADA_BUILD_PREFIX}" >> setup.sh &&\
    echo 'ln -sf $CICADA_BUILD_PREFIX $CICADA_BUILD_PREFIX/../current || /bin/true' >> setup.sh &&\
    echo 'export PATH=$CICADA_BUILD_PREFIX/bin:$PATH' >> setup.sh &&\
    echo 'export LD_LIBRARY_PATH=$CICADA_BUILD_PREFIX/lib:$LD_LIBRARY_PATH' >> setup.sh &&\
    /bin/true

########################
FROM cicada_common as cicada_done

# repeat the cmake command to get the change of install prefix to set correctly (a package_builder known issue)
RUN source $CICADA_BUILD_PREFIX/setup.sh &&\
    mkdir /tmp_install &&\
    cd /tmp_install &&\
    git clone https://github.com/project8/cicada &&\
    cd cicada &&\
    git fetch && git fetch --tags &&\
    git checkout $CICADA_TAG &&\
    git submodule update --init --recursive &&\
    mkdir build &&\
    cd build &&\
    cmake -DCMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX:PATH=$CICADA_BUILD_PREFIX -DCMAKE_SKIP_INSTALL_RPATH:BOOL=True .. &&\
    cmake -DCMAKE_BUILD_TYPE=Release -D CMAKE_INSTALL_PREFIX:PATH=$CICADA_BUILD_PREFIX -DCMAKE_SKIP_INSTALL_RPATH:BOOL=True .. &&\
    make -j3 &&\
    make -j3 install &&\
    /bin/true

########################
FROM cicada_common

COPY --from=cicada_done $CICADA_BUILD_PREFIX $CICADA_BUILD_PREFIX

RUN mkdir -p /tmp_install/cicada/Library &&\ 
    ls  $CICADA_BUILD_PREFIX/include &&\ 
    cp -r $CICADA_BUILD_PREFIX/include/Cicada/*.hh /tmp_install/cicada/Library &&\ 
    cp -r $CICADA_BUILD_PREFIX/include/Cicada/Scarab/* /tmp_install/cicada/Library &&\ 
    cp -r $CICADA_BUILD_PREFIX/include/Cicada/rapidjson/*  /tmp_install/cicada/Library
