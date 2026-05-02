# RISC-V Studio

A custom **RISC-V assembler, ISA simulator, and installable command-line development platform** built in **C**, developed as part of a long-term systems programming project.

This project aims to progressively build a complete **RISC-V Studio** ecosystem from scratch, including:

* Assembler
* Instruction Set Simulator
* Pipelined CPU Simulator
* Cache Simulator
* Instruction Trace Viewer
* Performance Profiler
* Custom Operating System
* High-Level Language Compiler
* AI Verification Framework
* Hardware Co-Design Platform

Current development stage:  
**Milestone 1 — Assembler + ISA Simulator + Portable Installable CLI**

---

# Features

## Assembler

* Two-pass assembly process
* Lexical analysis and parsing
* Label resolution
* Symbol table generation
* Intermediate code generation
* Machine code generation
* Binary output generation (`program.bin`)
* Hexadecimal output generation (`program.hex`)

## ISA Simulator

* Register file simulation
* Instruction memory simulation
* Fetch–Decode–Execute cycle
* Arithmetic instruction execution
* Memory instruction execution
* Branch and jump instruction execution
* Final register state dump after execution

## CLI (`rvs`)

* Native command-line interface
* Global executable installation
* Automatic PATH integration
* Portable execution from any folder
* Built-in regression tests
* Custom assembly file execution
* Runtime diagnostics using `doctor`
* Help command
* Version command
* Command aliases (`-h`, `--help`, `-v`, `--version`)
* Table-driven command parsing
* Modular command dispatch

---

# Supported Instructions

## Arithmetic

* ADD
* SUB
* ADDI

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

---

# Project Structure

```text
riscv-studio/

├── assembler/
│   ├── include/
│   ├── src/
│   ├── test/
│   └── build/
│
├── simulator/
│   ├── include/
│   └── src/
│
├── cli/
│   ├── include/
│   └── src/
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

Before building or installing:

* GCC (MinGW)
* mingw32-make
* PowerShell

---

# Build

```bash
# Build simulator
mingw32-make

# Build CLI
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

works from any folder.

---

# Runtime Diagnostics

Verify installation:

```bash
rvs doctor
```

Example output:

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

# CLI Usage

## Help

```bash
rvs help
rvs -h
rvs --help
```

## Version

```bash
rvs version
rvs -v
rvs --version
```

## Diagnostics

```bash
rvs doctor
```

## Regression Tests

```bash
rvs test
```

## Run Built-In Tests

```bash
rvs run arithmetic
rvs run branch
rvs run memory
rvs run jump
```

## Run Custom Assembly Program

Create:

```text
hello.asm
```

Example:

```asm
ADDI R1, R0, 10
ADDI R2, R0, 20
ADD R3, R1, R2
HLT
```

Run:

```bash
rvs run hello.asm
```

This works from any folder on Windows.

---

# Uninstall

Remove RISC-V Studio:

```bash
mingw32-make uninstall
```

---

# Run Individual Tests

```bash
mingw32-make arithmetic
mingw32-make branch
mingw32-make memory
mingw32-make jump
```

---

# Run Complete Test Suite

```bash
mingw32-make test
```

---

# Current Status

## Milestone 1 Complete

### Core Toolchain

* Two-pass assembler implemented
* ISA simulator implemented
* Binary + hex generation implemented

### CLI Platform

* Installable `rvs` CLI implemented
* Global command execution enabled
* Automatic PATH integration implemented
* Runtime diagnostics (`doctor`) implemented

### Portability

* Static executable builds
* Portable Windows installation
* Portable uninstall
* Run assembly programs from any folder

### Testing

* Arithmetic test passing
* Branch test passing
* Memory test passing
* Jump test passing

---

# Versioning

Current stable release:

```text
v0.1.0
```

---

# Next Milestones

* Remove all compiler warnings
* Improve error handling
* Add remaining RV32I instructions
* Add `rvs examples`
* Add `rvs new hello.asm`
* Develop 5-stage pipelined CPU simulator
* Develop cache simulator
* Develop instruction trace viewer

---

This project is being developed incrementally with a strong focus on:

* Correctness
* Modularity
* Developer Experience
* Systems-Level Engineering
* Computer Architecture Research

---

# Author

**Kedar Modak**  
B.Tech Electrical Engineering  
Systems Programming | Computer Architecture | RISC-V | Operating Systems  

- Email: modak.kedar123@gmail.com  
- GitHub: https://github.com/Kedar-m2004  
- LinkedIn: https://linkedin.com/in/kedar-modak-56363b290/