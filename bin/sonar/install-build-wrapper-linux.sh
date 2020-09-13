#!/bin/sh

set -ex
curl -Ol https://sonarcloud.io/static/cpp/build-wrapper-linux-x86.zip
unzip -qq -o build-wrapper-linux-x86.zip
chmod +x build-wrapper-linux-x86/build-wrapper-linux-x86-64