#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/..

DOCKER_IMAGE=${DOCKER_IMAGE:-minblock/ovod-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/ovod docker/bin/
cp $BUILD_DIR/src/ovo-cli docker/bin/
cp $BUILD_DIR/src/ovo-tx docker/bin/
strip docker/bin/ovod
strip docker/bin/ovo-cli
strip docker/bin/ovo-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
