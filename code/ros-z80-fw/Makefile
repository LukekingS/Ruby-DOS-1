NAME = rz80
VID = 1.0
BIN = ${NAME}.ihx
ELF = ${NAME}.elf
LIBS = -L${II16_LIB} -lc -lm -lnosys
#${II16_DIR}/crtend.o ${II16_DIR}/crtbegin.o
LIB_INC = 
#BOND = 115200
#MCU = atmega168a


SCRTPTS = scripts

PROGER = arduino

DEBUG = 1

SEX = 0
SEX_LIST=test,sym1,sym2,sym3

ifeq ($(DEBUG),1)
OP_FLAG = -g -O0
VID = 1.0
DFLAG += -DDEBUG=1
else
DFLAG += -DDEBUG=0
OP_FLAG = -O2
endif

SRC_DIRS :=

# Whether to hide commands or not
VERBOSE = 0
ifeq ($(VERBOSE),0)
  V := @
endif

# Whether to colorize build messages
COLOR = 1

#==============================================================================#
# Target Executable and Sources                                                #
#==============================================================================#
# BUILD_DIR is the location where all build artifacts are placed
BUILD_DIR := bin
# Directories containing source files
SRC_DIR = src
SRC_DIRS += $(SRC_DIR) $(wildcard $(SRC_DIR)/**)
#src/Log4x \
#src/DSS \

C_FILES           := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
CXX_FILES         := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))
IXX_FILES         := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.ixx))
CC_FILES          := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cc))
#S_FILES           := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.s))
SS_FILES          := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.S))
ASM_FILES          := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.asm))
F90_FILES         := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.f90))
RS_FILES         := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.rs))
GO_FILES         := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.go))

# Object files
O_FILES := $(foreach file,$(F90_FILES),$(BUILD_DIR)/$(file:=.o)) \
		   $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:=.rel))   \
		   $(foreach file,$(CXX_FILES),$(BUILD_DIR)/$(file:=.o)) \
		   $(foreach file,$(IXX_FILES),$(BUILD_DIR)/$(file:=.o)) \
		   $(foreach file,$(CC_FILES),$(BUILD_DIR)/$(file:=.o))  \
		   $(foreach file,$(SS_FILES),$(BUILD_DIR)/$(file:=.o))  \
		   $(foreach file,$(ASM_FILES),$(BUILD_DIR)/$(file:=.rel))  \
		   $(foreach file,$(RS_FILES),$(BUILD_DIR)/$(file:=.o))  \
		   $(foreach file,$(GO_FILES),$(BUILD_DIR)/$(file:=.o)) 
		   

# tools
PRINT = printf

ifeq ($(COLOR),1)
NO_COL  := \033[0m
RED     := \033[0;31m
GREEN   := \033[0;32m
BLUE    := \033[0;34m
YELLOW  := \033[0;33m
BLINK   := \033[33;5m
MAGENTA := \033[0;35m
endif

# Common build print status function
define print
  @$(PRINT) "$(GREEN)$(1) $(YELLOW)$(2)$(GREEN) -> $(BLUE)$(3)$(NO_COL)\n"
endef

#==============================================================================#
# Main Targets                                                                 #
#==============================================================================#
# Default target
default: bin

info: boot

boot:
	$(V)$(BASH) $(SCRTPTS)/KROM.sh $(COLOR)

pak: boot
	@$(PRINT) "$(GREEN)paking :  $(BLUE)$(NAME) $(NO_COL)\n"
	$(V)$(BASH) $(SCRTPTS)/pak.sh $(NAME) $(COLOR)

flas: boot
	@$(PRINT) "$(GREEN)flasing$(NO_COL)\n"
	$(V)$(BASH) $(SCRTPTS)/avr_install.sh $(PROGER) $(BOND) $(MCU) $(NAME) $(COLOR)

zip: boot
	@$(PRINT) "$(GREEN)ziping :  $(BLUE)$(NAME) $(NO_COL)\n"
	$(V)$(BASH) $(SCRTPTS)/ziper.sh $(NAME) 0 $(COLOR) $(DEBUG)

zip-c: boot
	@$(PRINT) "$(GREEN)ziping : -c $(BLUE)$(NAME) $(NO_COL)\n"
	$(V)$(BASH) $(SCRTPTS)/ziper.sh $(NAME) 1 $(COLOR) $(DEBUG)

lib: boot $(LIB)

hex: boot $(HEX)

bin: boot $(BIN)

elf: boot $(ELF)

size:
	$(V)$(PY3) ./$(SCRTPTS)/get_file_size $1 $(COLOR)

dll: boot $(DLL)

so: boot $(SO)

disasm: boot
	@$(PRINT) "$(GREEN)disasming :  $(BLUE)$(NAME) $(NO_COL)\n"
	$(V)$(BASH) $(SCRTPTS)/disasm.sh $(TOOL_PREFIX) $(DLL)

sym: boot
	@$(PRINT) "$(GREEN)dumping sym :  $(BLUE)$(NAME) $(NO_COL)\n"
	$(V)$(BASH) $(SCRTPTS)/dumpsym.sh $(TOOL_PREFIX) $(DLL)

clean: boot
	@$(PRINT) "$(RED)cleaning lib :  $(YELLOW)$(NAME) $(NO_COL)\n"
	$(V)$(RM) -r $(BUILD_DIR) $(NAME) $(NAME)*.zip

ALL_DIRS := $(BUILD_DIR) $(addprefix $(BUILD_DIR)/,$(SRC_DIRS))

# Make sure build directory exists before compiling anything
DUMMY != mkdir -p $(ALL_DIRS)

#==============================================================================#
# Compilation Recipes                                                          #
#==============================================================================#

TOOL_PREFIX = ia16-elf-
CC = $(Z80_CC)
CXX = $(TOOL_PREFIX)g++
ASM = sdasz80
LD = $(Z80_LD)
AR = sdar
SIZE = $(TOOL_PREFIX)size
OBJCOPY = $(TOOL_PREFIX)objcopy
STRIP = $(TOOL_PREFIX)strip
ADDR2LINE = $(TOOL_PREFIX)addr2line
RANLIB = $(TOOL_PREFIX)ranlib
CPP_FILT = $(TOOL_PREFIX)c++filt
GF = $(TOOL_PREFIX)gfortran
BASH = /bin/bash
PY3 = /bin/python3
RUSTC = rustc
SIZEFLAGS=-d --common
Z80_ASM=sjasmplus
Z80_CC=sdcc
Z80_LD=sdld


ifneq (, $(shell command -v gnumfmt 2> /dev/null))
	SIZES_NUMFMT:=| gnumfmt --field=-4 --header $(NUMFMTFLAGS)
else
ifneq (, $(shell command -v numfmt 2> /dev/null))
	SIZES_NUMFMT:=| numfmt --field=-4 --header $(NUMFMTFLAGS)
else
	SIZES_NUMFMT:=
endif
endif

ifneq (, $(shell command -v sed 2> /dev/null))
SIZES_SED:=| sed -e 's/  dec/total/'
else
SIZES_SED:=
endif

NODEFAULTLIBS = 0

# Include directories
INCS := -I./include
PLAS := -J./include

# Optimization compiler flags
GCCFLAG =
DFLAG = -DL61="v1.0.0"
BFLAG = 

OPTFLAGS ?= $(OP_FLAG)

# Warning compiler flags
WARNFLAGS ?= #-Wall

# C compiler flags
CFLAGS := $(BFLAG) $(DFLAG) $(GCCFLAG) -mz80
#
# C++ compiler flags
CXXFLAGS := $(BFLAG) $(BFLAG) $(DFLAG) $(GCCFLAG) $(OPTFLAGS)  $(WARNFLAGS) -std=gnu++17

GFFLAG := $(OPTFLAGS) $(WARNFLAGS)


# Linker flags
LDFLAGS := 

# Assembler flags
ASFLAGS := $(GCCFLAG) $(WARNFLAGS) -l -o

# Default link file
#ifeq ($(LINKFILE),)
#EE_LINKFILE := $(PS2SDK)/ee/startup/linkfile
#endif

$(BUILD_DIR)/%.c.rel: %.c
	$(call print,Compiling:,$<,$@)
	$(V)$(CC) $(CFLAGS) $(INCS) $< -c -o $@
	$(V)if [ ${SEX} = 1 ]; then \
	$(BASH) ./$(SCRTPTS)/bstrip.sh $@ $(SEX_LIST); \
	fi 
	$(V)$(PY3) ./$(SCRTPTS)/get_file_size $@ $(COLOR)

$(BUILD_DIR)/%.go.o: %.go
	$(call print,Compiling:,$<,$@)
	$(V)$(CC) -c $(CFLAGS) $(INCS)  $< -o $@
	$(V)if [ ${SEX} = 1 ]; then \
	$(BASH) ./$(SCRTPTS)/bstrip.sh $@ $(SEX_LIST); \
	fi 
	$(V)$(PY3) ./$(SCRTPTS)/get_file_size $@ $(COLOR)

$(BUILD_DIR)/%.cc.o: %.cc
	$(call print,Compiling:,$<,$@)
	$(V)$(EE_CXX) -c $(CXXFLAGS) $(INCS)  $< -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	$(call print,Compiling:,$<,$@)
	$(V)$(CXX) -c $(CXXFLAGS) $(INCS)  $< -o $@
	$(V)if [ ${SEX} = 1 ]; then \
	$(BASH) ./$(SCRTPTS)/bstrip.sh $@ $(SEX_LIST); \
	fi 
	$(V)$(PY3) ./$(SCRTPTS)/get_file_size $@ $(COLOR)

$(BUILD_DIR)/%.rs.o: %.rs
	$(call print,Compiling:,$<,$@)
	$(V)$(RUSTC) --emit obj $< -o $@
	$(V)if [ ${SEX} = 1 ]; then \
	$(BASH) ./$(SCRTPTS)/bstrip.sh $@ $(SEX_LIST); \
	fi 


$(BUILD_DIR)/%.ixx.o: %.ixx
	$(call print,Compiling:,$<,$@)-T
	$(V)$(CXX) -c $(CXXFLAGS) $(INCS)  $< -o $@

$(BUILD_DIR)/%.f90.o: %.f90
	$(call print,Compiling:,$<,$@)
	$(V)$(GF) -c $(GFFLAG) $(PLAS) $(INCS)  $< -o $@
	$(V)if [ ${SEX} = 1 ]; then \
	$(BASH) ./$(SCRTPTS)/bstrip.sh $@ $(SEX_LIST); \
	fi 
	$(V)$(PY3) ./$(SCRTPTS)/get_file_size $@ $(COLOR)

COMMA:=,
$(BUILD_DIR)/%.S.o: %.S
	$(call print,Assembling:,$<,$@)
	$(V)$(CC) -c $(GFLAGS) $(ASFLAGS) $(patsubst %,-Wa$(COMMA)%,$(INCS))  $< -o $@
	$(V)if [ ${SEX} = 1 ]; then \
	$(BASH) ./$(SCRTPTS)/bstrip.sh $@ $(SEX_LIST); \
	fi 
	$(V)$(PY3) ./$(SCRTPTS)/get_file_size $@ $(COLOR)

$(BUILD_DIR)/%.asm.rel: %.asm
	$(call print,Assembling:,$<,$@)
	$(V)$(ASM) $(ASFLAGS) -o $@ $<
	$(V)if [ ${SEX} = 1 ]; then \
	$(BASH) ./$(SCRTPTS)/bstrip.sh $@ $(SEX_LIST); \
	fi 
	$(V)$(PY3) ./$(SCRTPTS)/get_file_size $@ $(COLOR)

#$(BUILD_DIR)/%.s.o: %.s
#	$(call print,Assembling:,$<,$@)
#	$(V)$(AS) $(ASFLAGS) $< -o $@
#EE_LINKFILE := $(PS2SDK)/ee/startup/linkfile
$(DLL): $(O_FILES)
	@$(PRINT) "$(GREEN)Linking DLL file:  $(BLUE)$@ $(NO_COL)\n"
	$(V)$(CXX) -shared $(OPTFLAGS) -o $(BUILD_DIR)/$(DLL) $(O_FILES) $(LDFLAGS) $(LDTIMEOBJ) $(LIBS) -Wl,--out-implib $(BUILD_DIR)/$(DLL).lib $(EXTRA_LDFLAGS)
#$(V)$(AR) cru $(BUILD_DIR)/$(DLL).lib  ./x46FWlogo.png
#line 191 is for x46FW
#ELF = ${NAME}.elf

$(SO): $(O_FILES)
	@$(PRINT) "$(GREEN)Linking SO file:  $(BLUE)$@ $(NO_COL)\n"
	$(V)$(CXX) -shared $(OPTFLAGS) -o $(BUILD_DIR)/$(SO) $(O_FILES) $(LDFLAGS) $(LDTIMEOBJ) $(LIBS) -Wl,--out-implib $(BUILD_DIR)/$(SO).a $(EXTRA_LDFLAGS)

$(ELF): $(O_FILES)
	@$(PRINT) "$(GREEN)Linking ELF file:  $(BLUE)$@ $(NO_COL)\n"
	$(V)$(LD)  $(OPTFLAGS)  -o $(BUILD_DIR)/$(ELF) $(O_FILES) $(GCCFLAG) $(LIBS) $(LDFLAGS) $(EXTRA_LDFLAGS)
	$(V)$(PY3) ./$(SCRTPTS)/get_file_size $(BUILD_DIR)/$@ $(COLOR)
#@$(PRINT) "$(GREEN)Section sizes:$(NO_COL)\n"
#$(V)$(SIZE) $(SIZEFLAGS) $(BUILD_DIR)/$@ $(SIZES_SED) $(SIZES_NUMFMT)
#-Wa,-T./bare8086.ld

#$(HEX): $(ELF)
#	@$(PRINT) "$(GREEN)Makeing HEX :  $(BLUE)$@ $(NO_COL)\n"
#	$(V)$(OBJCOPY) -O ihex -R .eeprom $(BUILD_DIR)/$(ELF) $(BUILD_DIR)/$(HEX)
#	$(V)./$(SCRTPTS)/get_file_size $(BUILD_DIR)/$@
	

#$(BIN): $(ASM_FILES) 
#	@$(PRINT) "$(GREEN)Makeing HEX :  $(BLUE)$@ $(NO_COL)\n"
#$(V)${Z80_LD} -o $(BUILD_DIR)/$(HEX) ${O_FILES}
#	$(V)${Z80_ASM} $(ASM_FILES) --raw=$(BUILD_DIR)/$(BIN)
#	$(V)./$(SCRTPTS)/get_file_size $(BUILD_DIR)/$@

$(BIN): $(O_FILES)
	@$(PRINT) "$(GREEN)Makeing HEX :  $(BLUE)$@ $(NO_COL)\n"
	$(V)${Z80_CC} -mz80 $(O_FILES) -o $(BUILD_DIR)/$(BIN)
	$(V)./$(SCRTPTS)/get_file_size $(BUILD_DIR)/$@
#$(V)${Z80_LD} -o $(BUILD_DIR)/$(HEX) ${O_FILES}


#$(BIN): $(O_FILES)
#	@$(PRINT) "$(GREEN)Linking ELF file:  $(BLUE)$@ $(NO_COL)\n"
#	$(V)$(LD)  $(OPTFLAGS)  -o $(BUILD_DIR)/$(BIN) $(O_FILES) $(GCCFLAG) $(LIBS) $(LDFLAGS) $(EXTRA_LDFLAGS)
#	$(V)$(PY3) ./$(SCRTPTS)/get_file_size $(BUILD_DIR)/$@ $(COLOR)
#$(BIN): $(ELF)
#	@$(PRINT) "$(GREEN)Makeing BIN :  $(BLUE)$@ $(NO_COL)\n"
#	$(V)$(OBJCOPY) -O binary $(BUILD_DIR)/$(ELF) $(BUILD_DIR)/$(BIN)
#	$(V)./$(SCRTPTS)/get_file_size $(BUILD_DIR)/$@


$(LIB): $(O_FILES)
	@$(PRINT) "$(GREEN)Makeing LIB :  $(BLUE)$@ $(NO_COL)\n"
	$(V)$(AR) crD $(BUILD_DIR)/$(LIB) $(O_FILES)
	$(V)$(PY3) ./$(SCRTPTS)/get_file_size $(BUILD_DIR)/$@ $(COLOR)
