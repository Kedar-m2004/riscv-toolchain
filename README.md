# RISC-V Studio

A custom **RISC-V assembler, ISA simulator, and installable command-line development platform** built completely in **C**, developed as part of a long-term systems programming and computer architecture initiative.

**RISC-V Studio** aims to evolve into a complete **AI-assisted computer architecture and hardware co-design platform**, built entirely from scratch.

---

# Vision

## Phase 1 — RISC-V Studio Core (2026–2027)

A **MATLAB-like learning and experimentation platform for computer architecture**, including:

- Two-Pass Assembler
- Instruction Set Simulator
- 5-Stage Pipeline Simulator
- Cache Simulator
- Instruction Trace Viewer
- Performance Profiler

## Phase 2 — AI Verification

- Automatic assembly test generation
- Corner-case discovery
- Regression testing
- Assertion generation
- Bug localization

## Phase 3 — Hardware Co-Design

- Workload analysis
- Custom instruction recommendations
- Accelerator suggestions
- Verilog generation
- Testbench generation
- FPGA deployment

## Phase 4 — Collaboration Ecosystem

- Benchmark sharing
- RTL versioning
- Waveform diffing
- Collaborative architecture experimentation

---

# Current Development Stage

## Milestone 1 Complete

### Assembler + ISA Simulator + Portable CLI

Current stable release:

```text
v0.1.1
```

---

# Features

# Assembler

- Two-pass assembly process
- Lexical analysis
- Table-driven parsing
- Symbol table generation
- Label resolution
- Intermediate code generation
- Machine code generation
- Binary output generation (`program.bin`)
- Hexadecimal output generation (`program.hex`)
- Token overflow protection
- Safer token storage with bounds checking

---

# ISA Simulator

- Register file simulation
- Instruction memory simulation
- Fetch–Decode–Execute cycle
- Arithmetic instruction execution
- Memory instruction execution
- Branch instruction execution
- Jump instruction execution
- Final register-state dump

---

# CLI (`rvs`)

- Native command-line interface
- Install globally on Windows
- Automatic PATH integration
- Portable execution from any folder
- Built-in regression tests
- Execute custom `.asm` programs
- Runtime diagnostics (`doctor`)
- Version command
- Help command
- Command aliases

Supported aliases:

```bash
-h
--help

-v
--version
```

---

# Supported Instructions

## Arithmetic

- ADD
- SUB
- ADDI

## Memory

- LW
- SW

## Branch

- BEQ
- BNE

## Jump

- JAL
- JALR

## Custom

- HLT

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

Before building:

- GCC (MinGW)
- mingw32-make
- PowerShell

---

# Build

## Build Simulator

```bash
mingw32-make
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

## Built-In Regression Tests

```bash
rvs test
```

## Individual Tests

```bash
rvs run arithmetic
rvs run branch
rvs run memory
rvs run jump
```

## Run Custom Assembly Program

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

This works from **any folder on Windows**.

---

# Uninstall

```bash
mingw32-make uninstall
```

---

# Testing

## Run Individual Tests

```bash
mingw32-make arithmetic
mingw32-make branch
mingw32-make memory
mingw32-make jump
```

## Run Complete Test Suite

```bash
mingw32-make test
```

---

# Engineering Improvements in v0.1.1

- Zero compiler warnings
- Strict C11 builds
- `-Wall -Wextra -Wpedantic`
- Encoder API cleanup
- Safer lexer token storage
- Token overflow detection
- Negative testing added
- Windows install/uninstall workflow validated

---

# Next Milestones

## v0.1.2

- Improve CLI path handling
- Better file diagnostics
- Consistent stderr-based error reporting
- Exit-code cleanup
- Negative test expansion

## Milestone 2

- Remaining RV32I instructions
- Pipeline hazard detection
- Forwarding
- Stall logic
- Branch prediction experiments

## Milestone 3

- Cache simulator
- Instruction trace viewer
- Performance profiler

---

This project is being developed incrementally with strong focus on:

- Correctness
- Modularity
- Portability
- Developer Experience
- Systems-Level Engineering
- Computer Architecture Research

---

# Author

**Kedar Modak**  
B.Tech Electrical Engineering  
Systems Programming | Computer Architecture | RISC-V | Operating Systems

- GitHub: https://github.com/Kedar-m2004
- LinkedIn: https://linkedin.com/in/kedar-modak-56363b290/
- Email: modak.kedar123@gmail.com
