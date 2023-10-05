#!/usr/bin/env bash

function main()
{
    local dat="$(date +%m)$(date +%d)$(date +%Y)"
    printf "${dat}"
}


main

