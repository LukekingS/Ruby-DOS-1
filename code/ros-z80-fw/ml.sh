#!/usr/bin/env bash
ARG=$@

min=0
max=99999
function main()
{
    local ra=$((min + RANDOM % $((max-min))))
    local dat="$(date +%m)$(date +%d)$(date +%Y)"
    
    
    local AD=$(make ${ARG} COLOR=0)
    printf "${AD}" > "x46FW_makelog[${dat}-${ra}].log"
}

main
