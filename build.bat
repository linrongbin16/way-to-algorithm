@ECHO OFF

npm install gitbook-cli -g
npm install svgexport -g
gitbook install .
gitbook build .
gitbook pdf . ./bin/Way-to-Algorithm.pdf &
gitbook epub . ./bin/Way-to-Algorithm.epub &
gitbook mobi . ./bin/Way-to-Algorithm.mobi &
gitbook serve .
