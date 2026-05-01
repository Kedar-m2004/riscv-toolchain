// cpu.c file

#include<stdio.h>
#include<stdint.h>      // Header file declared in C99 (used for uint32_t)
#include<stdlib.h>
#include"cpu.h"

uint8_t memory[16384];      // byte addressable memory
uint32_t pc = 0;             // pc is a byte address

uint32_t reg[32] = {0};


uint32_t fetch(uint32_t pc){
    // fetch function will input pc, and output instruction.

    uint32_t temp = 0, instruction = 0;

    if( (pc+3) >= sizeof(memory) ){
        printf("PC out of bounds! \n");
        exit(1);
    }
    
    temp = memory[pc];
    instruction |= temp;        // Since, RISCV is little endian (Lowest Address = LSB)

    temp = memory[pc+1];
    instruction |= (temp << 8);
    
    temp = memory[pc+2];
    instruction |= (temp << 16);
    
    temp = memory[pc+3];
    instruction |= (temp << 24);        // Highest Address = MSB
    
    return instruction;
}

void execute(DecodedInstr* di, uint32_t* next_pc){     // Dispatcher
    
    switch (di -> opcode){

        case 0x33: execute_r_type(di); break;       // R-Type
        case 0x13: execute_i_type(di); break;       // I-Type
        case 0x03: execute_load(di); break;         // Load
        case 0x23: execute_store(di); break;        // Store
        case 0x63: execute_branch(di, next_pc); break;       // Branch
        case 0x6F: execute_j_type(di, next_pc); break;       // J_Type
        case 0x67: execute_jalr(di, next_pc); break;        // JALR Instruction (I-Type)
        
        default:
            printf("\nUnknown opcode: %x \n", di->opcode);
            break;
    }
}

void cpu(){

    // Using uint32_t gurrantees exact 32 bit unsigned integer declaration
    uint32_t instruction = 0;
    uint32_t next_pc = 0;
        
    while(1){
        
        // Instruction Fetch: 
        instruction = fetch(pc);

        // break; condition: 
        if(instruction == 0xFFFFFFFF){
            printf("\n\nProgram Halted!\n");
            break;
        }

        // Instruction decode: 
        DecodedInstr di;       // di refers to "decoded instruction"
        decode(instruction, &di);

        // Printing for debugging: 
        printf("\nPC=%u | opcode=%x | rd=%d | rs1=%d | rs2=%d | imm=%d",
        pc, di.opcode, di.rd, di.rs1, di.rs2, di.imm);

        next_pc = pc + 4;       // default

        // Instruction execution: 
        execute(&di, &next_pc);

        pc = next_pc;
        reg[0] = 0;       // R0 always 0.
    }

    // Checking status of the register bank: 
    printf("\nRegister bank status, after execution of program: ");
    for(int i = 0; i<32; i++){
        printf("\nR[%d] = %u", i, reg[i]);
    }
    printf("\n");
}
