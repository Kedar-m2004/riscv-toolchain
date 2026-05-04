# RISC-V Studio

A modular **RISC-V assembler, ISA simulator, and installable command-line development platform**, built completely in **C**.

This project is being developed from scratch as a systems programming and computer architecture initiative, with strong emphasis on:

* Correctness
* Modularity
* Portability
* Developer Experience
* Systems-Level Engineering

---

# Current Development Stage

Current release:

```text
v0.1.2-alpha
```

Current milestone:

> **Assembler + ISA Simulator + Portable CLI**

---

# Features

# Two-Pass Assembler

Features:

* Lexical Analysis
* Table-Driven Parsing
* Symbol Table Generation
* Label Resolution
* Intermediate Code Generation
* Machine Code Generation
* Binary Output (`program.bin`)
* Hex Output (`program.hex`)
* Token Overflow Protection
* Bounds-Checked Token Storage

---

# ISA Simulator

Features:

* Register File Simulation
* Instruction Memory Simulation
* Fetch → Decode → Execute cycle
* Arithmetic / Logical Instruction Execution
* Memory Instruction Execution
* Branch Instruction Execution
* Jump Instruction Execution
* Final Register-State Dump

---

# CLI (`rvs`)

Portable command-line interface for development and testing.

Features:

* Global Windows installation
* Automatic PATH integration
* Portable execution from any folder
* Runtime diagnostics
* Built-in regression testing
* Execute custom `.asm` programs

Supported commands:

```bash
rvs help
rvs version
rvs doctor
rvs test
rvs run <assembly_file>
```

Supported aliases:

```bash
rvs -h
rvs --help

rvs -v
rvs --version
```

---

# Supported RV32I Instructions

Current coverage:

## Register-Register Arithmetic / Logic

* ADD
* SUB
* AND
* OR
* XOR

## Immediate Arithmetic / Logic

* ADDI
* ANDI
* ORI
* XORI

## Memory

* LW
* SW

## Branch

* BEQ
* BNE

## Jump

* JAL
* JALR

## Custom

* HLT

> `HLT` is a custom halt instruction used by this simulator.

Current RV32I coverage:

```text
14 / 32 instructions
```

---

# Project Structure

```text
riscv-studio/

├── assembler/
│   ├── include/
│   ├── src/
│   └── test/
│
├── simulator/
│   ├── include/
│   └── src/
│
├── cli/
│   ├── include/
│   └── src/
│
├── docs/
│
├── scripts/
│   └── install_path.ps1
│
├── output/
│
├── Makefile
└── README.md
```

---

# Requirements (Windows)

Before building:

* GCC (MinGW)
* mingw32-make
* PowerShell

---

# Build

## Build Simulator

```bash
mingw32-make all
```

## Build CLI

```bash
mingw32-make rvs
```

---

# Installation

Install globally:

```bash
mingw32-make install
```

This installs:

```text
C:\tools\rvs.exe
C:\tools\Simulator.exe
```

and automatically adds:

```text
C:\tools
```

to User PATH.

After installation:

```bash
rvs
```

works from **any folder on Windows**.

---

# Runtime Diagnostics

Verify installation:

```bash
rvs doctor
```

Example:

```text
[PASS] GCC is installed
[PASS] mingw32-make is installed
[PASS] PowerShell is available
[PASS] C:\tools exists
[PASS] C:\tools\rvs.exe exists
[PASS] C:\tools\Simulator.exe exists
[PASS] C:\tools is present in PATH

System is ready for RISC-V Studio.
```

---

# Testing

## Run Full Regression Suite

```bash
rvs test
```

Current test suite:

* arithmetic
* branch
* memory
* jump
* logic
* immediate_logic

All tests currently passing.

## Run Individual Tests

```bash
mingw32-make arithmetic
mingw32-make branch
mingw32-make memory
mingw32-make jump
mingw32-make logic
mingw32-make immediate_logic
```

---

# Example

```asm
ADDI R1, R0, 10
ADDI R2, R0, 12

AND R3, R1, R2
OR R4, R1, R2
XOR R5, R1, R2

HLT
```

Expected:

```text
R3 = 8
R4 = 14
R5 = 6
```

---

# Documentation

ISA implementation progress:

```text
docs/rv32i_checklist.md
```

---

# Current Focus

Immediate engineering goals:

* Complete RV32I base ISA
* Improve regression coverage
* Add debugger support
* Build pipeline simulator

---

# Author

**Kedar Modak**
B.Tech Electrical Engineering
Systems Programming | Computer Architecture | RISC-V | Operating Systems

- GitHub: https://github.com/Kedar-m2004
- LinkedIn: https://linkedin.com/in/kedar-modak-56363b290/
- Email: kedar.modak30112004@gmail.com  
