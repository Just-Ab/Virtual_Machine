#Directories---------------
MACH = Machine
ASM = Assembler
GLOBAL = Global
#--------------------------
MACH_SRC = $(MACH)/Source
ASM_SRC = $(ASM)/Source
#--------------------------
MACH_INC = $(MACH)/Include
ASM_INC = $(ASM)/Include


all : $(MACH_SRC)/*.c $(ASM_SRC)/*.c
	gcc -I $(MACH_INC) -I $(ASM_INC) $^ -o BIN/vm.exe
	BIN/vm.exe


machine : $(MACH_SRC)/*.c
	gcc -I $(MACH_INC) -I $(GLOBAL) $^ -o BIN/mach.exe
	BIN/vm.exe


assembler : $(ASM_SRC)/*.c
	gcc -I $(ASM_INC) -I $(GLOBAL) -I $^ -o BIN/asm.exe
	BIN/vm.exe