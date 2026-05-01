CC = gcc

.PHONY: all run rvs clean test arithmetic branch memory jump

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

CLI_SRC = cli/src/rvs.c

CFLAGS = -Iassembler/include -Isimulator/include -Wall -Wextra

all:
	$(CC) $(SIM_SRC) $(ASM_SRC) $(CFLAGS) -o Simulator


run: all
	./Simulator.exe

arithmetic: all
	./Simulator.exe assembler/test/test_arithmetic.txt
	@cmd /c echo.

branch: all
	./Simulator.exe assembler/test/test_branch.txt
	@cmd /c echo.

memory: all
	./Simulator.exe assembler/test/test_memory.txt
	@cmd /c echo.

jump: all
	./Simulator.exe assembler/test/test_jump.txt
	@cmd /c echo.

test: arithmetic branch memory jump

rvs:
	$(CC) $(CLI_SRC) -Wall -Wextra -o rvs


clean:
	-del Simulator.exe
	-del rvs.exe
