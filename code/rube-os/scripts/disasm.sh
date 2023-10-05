#!/usr/bin/env bash
. ./scripts/impl_var.sh
arg1=$1
arg2=$2

PRINT=printf

NO_COL='\033[0m'
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[0;33m'
BLINK='\033[33;5m'

if test -z ${arg2} ; then
    arg2=${arg1}
    arg1=${ARC_GCC}
fi

function argc()
{
    if test -z ${arg1}; then
        ${PRINT} "${RED}DISASM ERROR:\n\t${NO_COL}${YELLOW}PREFIX ARG IS NULL\n"
        exit 0
    fi

    if test -z ${arg2}; then
        ${PRINT} "${RED}DISASM ERROR:\n\t${NO_COL}${YELLOW}BIN ARG IS NULL\n"
        exit 0
    fi
}

function main()
{
    argc
    if [ -f "${arg2}.disasm" ]; then
        rm -r ${arg2}.disasm
    fi
    if test -e ./${BIN_DIR}/${arg2} ; then
        local DASM="$(${arg1}objdump --disassemble-all ./bin/${arg2})"
        local DIR=$(basename ${arg2})
        printf "${DASM}" > "${DIR}.disasm"
    fi
}
main