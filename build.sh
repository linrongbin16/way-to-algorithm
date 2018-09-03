#!/usr/bin/env bash

sudo npm install gitbook-cli -g
sudo npm install svgexport -g
mkdir -p ./bin
gitbook install .
gitbook build .
gitbook pdf . ./bin/Way-to-Algorithm.pdf &
gitbook epub . ./bin/Way-to-Algorithm.epub &
gitbook mobi . ./bin/Way-to-Algorithm.mobi &
gitbook serve .
