// RISCV ISA Simulator

#include<stdio.h>
#include"cpu.h"
#include"assembler.h"

void load_program(const char* filename){
    FILE* fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Error in reading the .bin file\n");
        return;
    }

    fread(memory, sizeof(uint8_t), sizeof(memory), fp);
    fclose(fp);
}

int main(int argc, char* argv[]){   // argc = argument count, argv = argument value

    {// Checking Input Argument and initializing Assembler:

        if(argc != 2){
            printf("Usage: ./Simulator.exe <assembly_file> \n");
            return 1;
        }

        if(assemble(argv[1]) != 0){
            printf("Assembly failed. Simulation Stopped! \n");
            return 1;
        }
    }

    printf("\n\n\n\n------------ WELCOME TO SIMULATOR ------------\n");
    
    // Loading file in main memory (RAM)
    load_program("program.bin");
    
    // executing the code: 
    cpu();

    return 0;
}
