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
**Milestone 1 — Assembler + ISA Simulator + Installable CLI Integration**

---

# Features

## Assembler

* Two-pass assembly process
* Lexical analysis and parsing
* Label resolution
* Symbol table generation
* Intermediate code generation
* Machine code generation
* Binary and hexadecimal output generation

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
* Built-in test execution
* Custom assembly file execution
* Help command
* Version command
* Full regression test command
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
├── output/
│
├── Makefile
└── README.md
```

---

# Requirements (Windows)

Before building or installing, make sure the following are available:

* MinGW GCC
* mingw32-make
* PowerShell (Windows 10/11)

---

# Build

```bash
# Build Simulator
mingw32-make

# Build CLI
mingw32-make rvs
```

---

# Installation

```bash
mingw32-make install
```

After installation, `rvs` becomes globally accessible from any terminal.

---

# CLI Usage

```bash
rvs help
rvs -h
rvs --help

rvs version
rvs -v
rvs --version

rvs test

rvs run arithmetic
rvs run branch
rvs run memory
rvs run jump

rvs run assembler/test/test_arithmetic.txt
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

* Two-pass assembler implemented
* ISA simulator integrated
* Automated Makefile-based testing added
* Installable `rvs` CLI implemented
* Global command execution enabled
* Automatic PATH integration implemented
* Command registry architecture implemented
* Table-driven command parsing implemented
* Arithmetic test passing
* Branch test passing
* Memory test passing
* Jump test passing

---

# Next Milestones

* Improve debug output formatting
* Strengthen error handling
* Implement remaining RV32I instructions
* Add automated regression testing
* Develop 5-stage pipelined CPU simulator
* Develop cache simulator
* Begin GUI-based Studio environment
* Begin transition toward **RISC-V Studio Core Architecture**

---

This project is being developed incrementally with a strong focus on **correctness, modularity, developer experience, and systems-level engineering.**

# Author

**Kedar Modak**  
B.Tech Electrical Engineering  
Systems Programming | Computer Architecture | RISC-V | Operating Systems  

- Email: modak.kedar123@gmail.com  
- GitHub: https://github.com/Kedar-m2004  
- LinkedIn: https://linkedin.com/in/kedar-modak-56363b290/
