#!/usr/bin/env bash
arg=$1
PRINT=printf


if test -z ${arg} ; then
    arg=1
fi
if [ ${arg} == 1 ]; then
    NO_COL='\033[0m'
    MAGENTA='\033[0;35m'
    CYAN='\033[0;36m'
    RED='\033[0;31m'
    GREEN='\033[0;32m'
    BLUE='\033[0;34m'
    YELLOW='\033[0;33m'
    BLINK='\033[33;5m'
fi

function boot()
{
    local distroName=$(lsb_release -d | sed 's/\Description:\t//g')
   
    ${PRINT} "${GREEN}╔══════════════════╗${NO_COL}\n"
    ${PRINT} "${GREEN}║${NO_COL} ${YELLOW}Build System λ61${NO_COL} ${GREEN}║${NO_COL}\n"
    ${PRINT} "${GREEN}║${NO_COL} ${YELLOW}By ${RED}T${BLUE}R${CYAN}S${NO_COL}           ${GREEN}║${NO_COL}\n"
    ${PRINT} "${GREEN}╚══════════════════╝${NO_COL}\n"

    if [ 1 == 0 ]; then
    ${PRINT} "${GREEN}╔════════════════════════════════════════════════╗${NO_COL}\n"
    ${PRINT} "${GREEN}║${NO_COL} ${RED}!!Fortran Integration Is Highly Experimental!!${NO_COL} ${GREEN}║${NO_COL}\n"
    ${PRINT} "${GREEN}╚════════════════════════════════════════════════╝${NO_COL}\n"
    fi
    #PLATFORM
    if [ "${OS}" = "Windows_NT" ]; then
	    ${PRINT} "${GREEN}PLATFORM IS ${YELLOW}WIN NT${NO_COL}\n"
    else
	    ${PRINT} "${GREEN}PLATFORM IS ${YELLOW}UNIX${NO_COL}\n"
        ${PRINT} "${GREEN}DISTRO IS ${YELLOW}${distroName}${NO_COL}\n"
        #${PRINT} "${GREEN}VERSION IS ${YELLOW}${NO_COL}\n"
    fi
   
   
    exit 0
}


boot