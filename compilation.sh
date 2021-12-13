#!/bin/bash
cd rapport/
make
cd ../programme/
make
cd doc/latex/
make
cd ../../../
cp -f rapport/rapport.pdf ./resultat/rapport.pdf
cp -f programme/bin/asispell ./resultat/asispell
cp -f programme/doc/latex/refman.pdf ./resultat/documentation.pdf
