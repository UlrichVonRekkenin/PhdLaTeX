#!/bin/bash


for uml in Dissertation/listings/uml/*.puml
do
    plantuml -tlatex:nopreamble $uml
done