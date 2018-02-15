FROM guiguem/root-docker:python3

MAINTAINER Mathieu Guigue "Mathieu.Guigue@pnnl.gov"

COPY . /cicada
COPY setup_cicada.sh /setup_cicada.sh

WORKDIR /cicada/build

RUN /bin/bash -c "source /setup.sh &&\
    cmake -D CMAKE_INSTALL_PREFIX=/build .. &&\
    make -j install &&\
    make install &&\
    pip3 install colorlog==2.10.0 &&\
    cat /setup_cicada.sh"   

CMD ['source /setup_cicada.sh']
