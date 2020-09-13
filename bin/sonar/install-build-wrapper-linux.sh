#!/bin/sh

set -ex

# build-wrapper requires glibc to run on alpine
apk --no-cache add ca-certificates wget
wget -q -O /etc/apk/keys/sgerrand.rsa.pub https://alpine-pkgs.sgerrand.com/sgerrand.rsa.pub
wget https://github.com/sgerrand/alpine-pkg-glibc/releases/download/2.28-r0/glibc-2.28-r0.apk
apk add glibc-2.28-r0.apk


curl -Ol https://sonarcloud.io/static/cpp/build-wrapper-linux-x86.zip
unzip -qq -o build-wrapper-linux-x86.zip
chmod +x build-wrapper-linux-x86/build-wrapper-linux-x86-64