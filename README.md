# RISC-V Toolchain

A custom RISC-V assembler and ISA simulator built in C.

## Features

### Assembler

* Two-pass assembler
* Label resolution
* Symbol table generation
* Machine code generation

### ISA Simulator

* Register file simulation
* Memory simulation
* Fetch–Decode–Execute cycle
* Command-line test execution

## Supported Instructions

### Arithmetic

* ADD
* SUB
* ADDI

### Memory

* LW
* SW

### Branch

* BEQ
* BNE

### Jump

* JAL
* JALR

### Custom

* HLT

## Project Structure

```text
assembler/
simulator/
output/
Makefile
```

## Build

```bash
mingw32-make
```

## Run Tests

```bash
mingw32-make arithmetic
mingw32-make branch
mingw32-make memory
mingw32-make jump
mingw32-make test
```

## Current Status

Milestone 1 complete:

* Assembler integrated with simulator
* 4 test programs passing
* GitHub repository initialized
