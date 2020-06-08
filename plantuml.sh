#!/bin/bash

type=$1

for uml in Dissertation/listings/uml/*.puml
do
    name="$(basename -- $uml .puml)"
    plantuml -t$type $uml
    mv -v Dissertation/listings/uml/$name.$type Dissertation/images
done