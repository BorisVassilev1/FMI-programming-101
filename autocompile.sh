#!/bin/bash

SHELL=/bin/bash

while sleep 1.0; do find . -name '*.cpp' | entr -cd ./try_compile.sh /_ ; done
