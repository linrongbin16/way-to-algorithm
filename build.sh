#!/usr/bin/env bash

sudo npm install gitbook-cli -g
sudo npm install svgexport -g
mkdir -p ./bin
gitbook install .
gitbook build . --debug
gitbook pdf . ./bin/Way-to-Algorithm.pdf --debug
gitbook epub . ./bin/Way-to-Algorithm.epub --debug
gitbook mobi . ./bin/Way-to-Algorithm.mobi --debug
gitbook serve .
