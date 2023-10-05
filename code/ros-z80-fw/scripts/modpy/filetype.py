from modpy.impl_vars import *
import os
import sys
import io

def file_type(name:str) -> str:
    ext = os.path.splitext(name)[1]
    if ext == ".elf":
        return "ELF"
    elif ext == ".o":
        return "CODE_OBJ"
    elif ext == ".py":
        return "PY_FILE"
    elif ext == ".bin":
        return "BIN"
    elif ext == ".hex":
        return "BIN/HEX"
    elif ext == ".zip":
        return "ZIP"
    elif ext == ".sh":
        return "SHALL SCRIPT"
    elif ext == ".jar":
        return "JAVA JAR"
    elif ext == ".class":
        return "JAVA CLASS"
    elif ext == ".a":
        return "GCC lib"
    elif ext == ".h":
        return "C HEADER"
    elif ext == ".hpp":
        return "C++ HEADER"
    elif ext == ".c":
        return "C FILE"
    elif ext == ".cpp":
        return "C++ FILE"
    else:
        return "nAFE"
    