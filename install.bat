@echo off

call npm install -g gitbook-cli svgexport ebook-convert
gitbook install .
