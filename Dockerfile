FROM guiguem/root-docker:python3

MAINTAINER Mathieu Guigue "Mathieu.Guigue@pnnl.gov"

ADD . /cicada

RUN /bin/bash -c "source /setup.sh &&\
    mkdir /cicada/build &&\
    cd /cicada/build &&\
    which cmake &&\
    cmake -DCMAKE_INSTALL_PREFIX:PATH=/build .. &&\
    make -j4 &&\
    make install"

CMD ['source /setup.sh']
