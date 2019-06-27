#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/..

DOCKER_IMAGE=${DOCKER_IMAGE:-computepay/computed-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/computed docker/bin/
cp $BUILD_DIR/src/compute-cli docker/bin/
cp $BUILD_DIR/src/compute-tx docker/bin/
strip docker/bin/computed
strip docker/bin/compute-cli
strip docker/bin/compute-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
