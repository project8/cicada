FROM guiguem/root-docker:python3

MAINTAINER Mathieu Guigue "Mathieu.Guigue@pnnl.gov"

COPY . /cicada
COPY setup_cicada.sh /setup_cicada.sh

RUN /bin/bash -c "source /setup.sh &&\
    mkdir /cicada/build &&\
    cd /cicada/build &&\
    cmake -D CMAKE_INSTALL_PREFIX=/build .. &&\
    make -j install &&\
    make install &&\
    pip3 install colorlog==2.10.0 &&\
    cat /setup_cicada.sh"   

CMD ['source /setup_cicada.sh']
