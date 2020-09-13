#!/bin/sh

set -e
SONAR_BUILD_WRAPPER=/tmp/cache/build-wrapper
SONAR_BUILD_WRAPPER_BIN=$SONAR_BUILD_WRAPPER/build-wrapper-$OS-x86/bin
mkdir -p $SONAR_BUILD_WRAPPER
curl -Ol https://sonarcloud.io/static/cpp/build-wrapper-linux-x86.zip
unzip -qq -o build-wrapper-linux-x86.zip -d $SONAR_BUILD_WRAPPER
chmod +x $SONAR_BUILD_WRAPPER_BIN/build-wrapper-linux-x86-64
export PATH=$PATH:$SONAR_BUILD_WRAPPER_BIN