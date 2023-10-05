#!/usr/bin/env bash
#BUG it will fucking crash bash, if runs without arguments
#TODO FIX BUG
. ./scripts/impl_var.sh
arg=${1}-os
CR=${2}
argC=${3}
DB=${4}

PRINT=printf

DAT=$(. ./scripts/xdate.sh)

if test -z ${argC} ; then
    argC=1
fi

min=0
max=99999
ra=$((min + RANDOM % $((max-min))))

if [ "${DB}" == "1" ]; then
    PAK="${arg}-[${DAT}-${ra}-DEBUG]"
else
    PAK="${arg}-[${DAT}-${ra}]"
fi



if test -z ${argC} ; then
    argC=1
fi
if [ ${argC} == 1 ]; then
    NO_COL='\033[0m'
    MAGENTA='\033[0;35m'
    CYAN='\033[0;36m'
    RED='\033[0;31m'
    GREEN='\033[0;32m'
    BLUE='\033[0;34m'
    YELLOW='\033[0;33m'
    BLINK='\033[33;5m'
fi

. ./scripts/pak.sh ${arg}

function zipc()
{
    if ! command -v zip &> /dev/null ; then
        ${PRINT} "${RED}PAKER ZIPER ERROR:\n\t${NO_COL}${YELLOW}NO ZIP\n"
        exit 0
    fi
}

function argc()
{
    zipc
    if test -z ${arg} ; then
        ${PRINT} "${RED}PAKER ERROR:\n\t${NO_COL}${YELLOW}NAME ARG IS NULL\n"
    exit 0
    fi
}

function ZIPER()
{
    local GT=${PWD}
    cd ./${arg}
    zip ../${PAK}.zip -rq . 
    cd ${GT}
}

function main()
{
    argc
    if test -e ./${arg} ; then
        if test -e ./${arg}*.zip ; then
            rm ./${arg}*.zip
            main
        else
            ZIPER
            if [ "${CR}" = "1" ]; then
                rm -r ./${arg}
            fi
        fi
    else
        exit 0
    fi
    
}

main