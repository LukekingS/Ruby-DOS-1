#!/usr/bin/env bash
. ./scripts/impl_var.sh
arg=$1
raw_argf=$2
argC=$3
argf=$(echo -e "${raw_argf}" | sed -e 's/,/ /g')

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
PRINT=printf

function main()
{
    for i in ${argf} 
    do
  
        df=$(${GCC_ARC}objdump --syms ${arg} | grep -o -m 1 ${i} | head -n1)
        
        #echo "${df}"
       
        if [ "${df}" == "${i}" ]; then
            ${GCC_ARC}strip --strip-debug -N ${i} ${arg} -o ${arg}
            ${PRINT} "${GREEN}striping ${YELLOW}\'${RED}${i}${YELLOW}\'${GREEN} from ${YELLOW}${arg}${NO_COL}\n"
        fi
        ${PRINT} "${GREEN}NO SYM ${YELLOW}${i}${NO_COL}\n"
    done
   
}
main

