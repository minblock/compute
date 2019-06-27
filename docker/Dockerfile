FROM debian:stretch
LABEL maintainer="Compute Developers <dev@putez.org>"
LABEL description="Dockerised ComputeCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/
