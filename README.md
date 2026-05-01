# RISC-V Toolchain

A custom **RISC-V assembler, ISA simulator, and command-line development tool** built in **C**, developed as part of a long-term systems programming project.

This project aims to progressively build a complete **RISC-V Studio** ecosystem from scratch, including:

* Assembler
* Instruction Set Simulator
* Pipelined CPU Simulator
* Cache Simulator
* Instruction Trace Viewer
* Performance Profiler
* Custom Operating System
* High-Level Language Compiler

Current development stage:  
**Milestone 1 — Assembler + ISA Simulator + Initial CLI Integration**

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
* Built-in test execution
* Custom assembly file execution
* Help command
* Modular command dispatch using enums and switch-case

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
riscv-toolchain/

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
│   └── src/
│
├── output/
│
├── Makefile
└── README.md
```

---

# Build

```bash
# Build Simulator
mingw32-make

# Build RISC-V Studio CLI
mingw32-make rvs
```

---

# CLI Usage

```bash
.\rvs help

.\rvs run arithmetic
.\rvs run branch
.\rvs run memory
.\rvs run jump

.\rvs run assembler/test/test_arithmetic.txt
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

* Assembler successfully integrated with simulator
* Automated Makefile-based testing added
* Initial `rvs` CLI implemented
* Built-in test execution through CLI added
* Custom assembly file execution through CLI added
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
