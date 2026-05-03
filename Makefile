CC = gcc

.PHONY: all run rvs clean test arithmetic branch memory jump install uninstall

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

CLI_SRC = \
cli/src/rvs.c\
cli/src/rvs_functions.c

CFLAGS = -Iassembler/include -Isimulator/include -Wall -Wextra -Wpedantic -std=c11 -static
CLI_CFLAGS = -Icli/include -Wall -Wextra -Wpedantic -std=c11 -static

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
	$(CC) $(CLI_SRC) $(CLI_CFLAGS) -o rvs


install: all rvs
	powershell -NoProfile -Command "New-Item -ItemType Directory -Force -Path 'C:\tools' | Out-Null"
	cmd /c copy /Y rvs.exe C:\tools\rvs.exe
	cmd /c copy /Y Simulator.exe C:\tools\Simulator.exe
	powershell -NoProfile -ExecutionPolicy Bypass -File scripts/install_path.ps1
	

uninstall:
	-powershell -NoProfile -Command "Remove-Item -Force 'C:\tools\rvs.exe' -ErrorAction SilentlyContinue"
	-powershell -NoProfile -Command "Remove-Item -Force 'C:\tools\Simulator.exe' -ErrorAction SilentlyContinue"
	
clean:
	-del Simulator.exe
	-del rvs.exe
