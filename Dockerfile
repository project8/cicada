FROM guiguem/root-docker:python3

MAINTAINER Mathieu Guigue "Mathieu.Guigue@pnnl.gov"

COPY . /cicada

RUN chmod +x /cicada/install_docker.sh &&\
    /cicada/install_docker.sh

CMD ['source /setup.sh']
