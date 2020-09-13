#!/bin/sh

set -ex

VERSION=4.1.0.1829
SONAR_TOKEN=$SONAR_TOKEN
SCANNER_DIRECTORY=/tmp/cache/scanner
export SONAR_USER_HOME=$SCANNER_DIRECTORY/.sonar
OS="linux"
echo $SONAR_USER_HOME

if [[ ! -x "$SCANNER_DIRECTORY/sonar-scanner-$VERSION-$OS/bin/sonar-scanner" ]]; then
  curl -Ol https://binaries.sonarsource.com/Distribution/sonar-scanner-cli/sonar-scanner-cli-$VERSION-$OS.zip
  # skip */legal/* files. Causes "compressed symlink is not supported"
  unzip -qq -o sonar-scanner-cli-$VERSION-$OS.zip -d $SCANNER_DIRECTORY  -x */legal/*
fi

chmod +x $SCANNER_DIRECTORY/sonar-scanner-$VERSION-$OS/bin/sonar-scanner
chmod +x $SCANNER_DIRECTORY/sonar-scanner-$VERSION-$OS/jre/bin/java

$SCANNER_DIRECTORY/sonar-scanner-$VERSION-$OS/bin/sonar-scanner