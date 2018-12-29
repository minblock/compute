FROM debian:stretch
LABEL maintainer="Ovo Developers <dev@ovocoin.ca>"
LABEL description="Dockerised OvoCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/
