// CPU Header File

#ifndef CPU_H
#define CPU_H

#include<stdint.h>

// 'extern' means 'reg exists somewhere (i.e. in cpu.c), I just want to use it'
extern uint32_t reg[32];

extern uint32_t pc;
extern uint8_t memory[16384];

typedef struct {
    uint32_t instruction;

    uint8_t opcode;
    uint8_t funct3;
    uint8_t rs1, rs2, rd;
    uint8_t funct7;

    int32_t imm;   // for I, S, B, U, J types
} DecodedInstr;


void cpu();

uint32_t fetch(uint32_t);

void decode(uint32_t, DecodedInstr*);

void execute(DecodedInstr*, uint32_t*);

void execute_r_type(DecodedInstr*);
void execute_i_type(DecodedInstr*);
void execute_load(DecodedInstr*);
void execute_store(DecodedInstr*);
void execute_branch(DecodedInstr*, uint32_t*);
void execute_j_type(DecodedInstr*, uint32_t*);
void execute_jalr(DecodedInstr*, uint32_t*);


#endif
