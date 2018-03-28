FROM guiguem/root-docker:python3

MAINTAINER Mathieu Guigue "Mathieu.Guigue@pnnl.gov"

COPY . /cicada
COPY setup_cicada.sh /setup_cicada.sh

RUN chmod +x /cicada/install_docker.sh &&\
    /cicada/install_docker.sh

CMD ['source /setup.sh']
