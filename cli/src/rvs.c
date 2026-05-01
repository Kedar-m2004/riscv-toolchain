// rvs :- CLI for RISCV Studio!

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

typedef enum{
    HELP,       // Compiler numbers this '0'
    RUN,       // Compiler numbers this '1'
    INVALID       // Compiler numbers this '2'
} Command;

Command parse_command(char* input){
    if(strcmp(input, "help")==0){
        return HELP;
    }
    else if(strcmp(input, "run")==0){
        return RUN;
    }
    else{
        return INVALID;
    }
}

void print_help(){
    printf("RISC-V Studio CLI\n\n");
    printf("Usage: \n");
    printf("   rvs help\n");
    printf("   rvs run <test_name>\n");
    printf("   rvs run <assembly_file>\n");    
}

int run(char* argv, int argc){

    if(argc < 3){
        printf("Error! Missing test name or assembly file!\n");
        print_help();
        return 1;
    }

    if(strcmp(argv, "arithmetic") == 0){
        system("mingw32-make arithmetic");
        return 0;
    }
    else if(strcmp(argv, "branch") == 0){
        system("mingw32-make branch");
        return 0;
    }
    else if(strcmp(argv, "memory") == 0){
        system("mingw32-make memory");
        return 0;
    }
    else if(strcmp(argv, "jump") == 0){
        system("mingw32-make jump");
        return 0;
    }
    else{
        char cmd[256];
        sprintf(cmd, "mingw32-make && .\\Simulator.exe %s", argv);
        return system(cmd);
    }
}


int main(int argc, char* argv[]){

    if(argc < 2){
        print_help();
        return 1;
    }

    Command cmd = parse_command(argv[1]);

    switch (cmd){
        case HELP:
            print_help();
            return 0;
        
        case RUN: 
            return run(argv[2], argc);

        default:
            printf("Invalid command!\n");
            return 1;
    }
}
