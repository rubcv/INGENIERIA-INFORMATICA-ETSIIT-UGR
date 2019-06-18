##########################################################################
SKP = (hola64-c.s printf32.s printf32e.s printf64.s)

A32 = $(filter-out $(SKP), $(wildcard *32*.s))
S32 = $(filter-out $(SKP), $(wildcard *32*.c *32*.cc))
O32 = $(A32:.s=.o)
E32 = $(basename $(A32) $(S32))

A64 = $(filter-out $(SKP), $(wildcard *64*.s))
S64 = $(filter-out $(SKP), $(wildcard *64*.c *64*.cc))
O64 = $(A64:.s=.o)
E64 = $(basename $(A64) $(S64))

ASM = $(filter-out $(A32) $(A64), $(wildcard *.s))
SRC = $(wildcard *.c *.cc)
OBJ = $(O32) $(O64)
EXE = $(E32) $(E64) $(basename $(ASM)) $(basename $(SRC))
ATT = $(EXE:=.att)
##########################################################################
CFLAGS = -g -std=c11 -Wall
CXXFLAGS = $(CFLAGS:c11=c++11)
##########################################################################
default: $(OBJ) $(EXE)

all: default $(ATT)

clean:
	$(RM) $(ATT) $(EXE) $(OBJ) perf.data core.* *~

.PHONY: all clean default
##########################################################################
$(O32): ASFLAGS=--32 -g -nostartfiles
$(E32): LDFLAGS=-dynamic-linker -lc -melf_i386

printf32: printf32.s
	$(CC) $(CFLAGS) -m32 -nostartfiles $< -o $@

printf32e: printf32e.s
	$(CC) $(CFLAGS) -m32 -nostartfiles $< -o $@

$(O64): ASFLAGS=--64 -g -nostartfiles
$(E64): LDFLAGS=-dynamic-linker -lc -melf_x86_64

hola64-c: hola64-c.s
	$(CC) $(CFLAGS) -m64 -nostartfiles $< -o $@

printf64: printf64.s
	$(CC) $(CFLAGS) -m64 -nostartfiles $< -o $@

sum0: CXXFLAGS+=-O0
sum1: CXXFLAGS+=-O1
sum2: CXXFLAGS+=-O2
sum3: CXXFLAGS+=-O3
sums: CXXFLAGS+=-Os
##########################################################################
%: %.o
	$(LD) $(LDFLAGS) $< -o $@

%: %.s
	$(CC) $(CFLAGS) -nostartfiles $< -o $@

%: %.c
	$(CC) $(CFLAGS) $< -o $@

%: %.cc
	$(CXX) $(CXXFLAGS) $< -o $@

%.att: %
	objdump -C -d $< > $@
##########################################################################
