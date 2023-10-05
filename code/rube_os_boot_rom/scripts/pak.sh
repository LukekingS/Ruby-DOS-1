#!/usr/bin/env bash
. ./scripts/impl_var.sh
arg=$1
argC=$2

PRINT=printf

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

EX='a'

function argc()
{
    if test -z ${arg}; then
        ${PRINT} "${RED}PAKER ERROR:\n\t${NO_COL}${YELLOW}NAME ARG IS NULL\n"
        exit 0
    fi
}

function main()
{
    argc
    if test -e ./${arg} ; then
        rm -r ./${arg}
        main
    else
        if test -e ./${BIN_DIR}/${arg}.a; then
#cp -ar ./fs ${arg}

#cp -ar ./x46FWlogo.png ${arg}
#cp -ar ./README.md ${arg}
#cp -ar ./LICENSE ${arg}
            cp ./include ./${arg}
            cp ./${BIN_DIR}/${arg} ./${arg}
            cp ./${arg} ./${arg}/fs
            if [ "${EX}" = "dll" ]; then
                cp ./bin/lib${arg}.${EX}.lib ./${arg}
            fi
        else
            ${PRINT} "${RED}PAKER ERROR:\n\t${NO_COL}${YELLOW}NO ELF\n"
            exit 0
        fi
    fi
}

main
