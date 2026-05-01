CC = gcc

ASM_SRC = \
assembler/src/assembler.c \
assembler/src/encoder.c \
assembler/src/lexer.c \
assembler/src/parser.c \
assembler/src/symbol_table.c

SIM_SRC = \
simulator/src/main.c \
simulator/src/cpu.c \
simulator/src/decode.c \
simulator/src/execute.c

CFLAGS = -Iassembler/include -Isimulator/include -Wall -Wextra

all:
	$(CC) $(SIM_SRC) $(ASM_SRC) $(CFLAGS) -o Simulator


run: all
	./Simulator.exe

arithmetic: all
	./Simulator.exe assembler/test/test_arithmetic.txt
	@echo.

branch: all
	./Simulator.exe assembler/test/test_branch.txt
	@echo.

memory: all
	./Simulator.exe assembler/test/test_memory.txt
	@echo.

jump: all
	./Simulator.exe assembler/test/test_jump.txt
	@echo.

test: arithmetic branch memory jump

clean:
	-del Simulator.exe
