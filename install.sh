#!/usr/bin/env bash

sudo apt install bzip2
sudo npm install -g gitbook-cli svgexport ebook-convert
gitbook install .
