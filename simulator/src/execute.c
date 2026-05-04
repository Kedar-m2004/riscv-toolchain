// execute.c file

#include<stdio.h>
#include<stdint.h>
#include"cpu.h"

// Refer EncodeInstr. Table in encode.c file of Assembler code.

void execute_r_type(DecodedInstr* di){      // R-Type Instruction Execution

    switch (di -> funct3){
        
        case 0x0:   // funct3 value for Arithmetic Operations

            if(di->funct7 == 0x00){         // ADD Instruction

                reg[di->rd] = reg[di->rs1] + reg[di->rs2];
            }
            else if(di->funct7 == 0x20){    // SUB Instruction

                reg[di->rd] = reg[di->rs1] - reg[di->rs2];
            }
            break;
        
        case 0x6:   // funct3 value for OR Operation
            reg[di->rd] = reg[di->rs1] | reg[di->rs2];
            break;
            
        case 0x7:   // funct3 value for AND Operation
            reg[di->rd] = reg[di->rs1] & reg[di->rs2];
            break;

        case 0x4:   // funct3 value for XOR Operation
            reg[di->rd] = reg[di->rs1] ^ reg[di->rs2];
            break;

        default:
            printf("\nUnknown R-Type funct3!");
    }
}

void execute_i_type(DecodedInstr* di){      // I-Type Instruction Execution 
    // This function includes instruction involvin only ALU Operations, 
    // not control flow immediate instructions, like, JALR, or memory imm. instr. like LW

    switch (di->funct3){
        case 0x0:   // ADDI
            reg[di->rd] = reg[di->rs1] + di->imm;
            break;
        
        case 0x6:   // ORI
            reg[di->rd] = reg[di->rs1] | di->imm;
            break;

        case 0x4:   // XORI
            reg[di->rd] = reg[di->rs1] ^ di->imm;
            break;

        case 0x7:   // ANDI
            reg[di->rd] = reg[di->rs1] & di->imm;
            break;

        default:
            printf("\nUnknown I-Type funct3!");
    }
}

void execute_load(DecodedInstr* di){        // Load Instruction Execution
    
    uint32_t addr = reg[di->rs1] + di->imm;
    
    if ((addr + 3) >= sizeof(memory)) {
        printf("Memory access violation!\n");
        return;
    }

    // Little endian load system: 
    uint32_t value = (
        memory[addr] |
        (memory[addr + 1] << 8) |
        (memory[addr + 2] << 16) |
        (memory[addr + 3] << 24)
    );

    reg[di->rd] = value;
}

void execute_store(DecodedInstr* di){       // Store Instruction Execution

    uint32_t addr = reg[di->rs1] + di->imm;
    uint32_t value = reg[di->rs2];

    if ((addr + 3) >= sizeof(memory)) {
        printf("Memory access violation!\n");
        return;
    }

    memory[addr] = value & 0xFF;
    memory[addr + 1] = (value >> 8) & 0xFF;
    memory[addr + 2] = (value >> 16) & 0xFF;
    memory[addr + 3] = (value >> 24) & 0xFF;    
}

void execute_branch(DecodedInstr* di, uint32_t* next_pc){      // B-Type Instruction Execution
    
    int taken = 0;      // refers to branch taken

    switch (di->funct3){
        case 0x0:       // BEQ
            taken = (reg[di->rs1] == reg[di->rs2]);     // taken if equal
            break;

        case 0x1:       // BNE
            taken = (reg[di->rs1] != reg[di->rs2]);     // taken if not equal
            break;  
    }
    
    if (taken) {
        *next_pc = pc + di->imm;
    }
}

void execute_j_type(DecodedInstr* di, uint32_t* next_pc){      // J-Type Instruction Execution
    
    // JAL 

    reg[di->rd] = pc + 4;       // return address.
    *next_pc = pc + di->imm;
}

void execute_jalr(DecodedInstr* di, uint32_t* next_pc){         // EXECUTE JALR INSTRUCTION (I_TYPE)
    // This is done separately remembering the principe: "GROUP BY BEHAVIOR, NOT BY ENCODING FORMAT"
    
    uint32_t target = (reg[di->rs1] + di->imm) & ~1;
    reg[di->rd] = pc + 4;

    *next_pc = target;
}

