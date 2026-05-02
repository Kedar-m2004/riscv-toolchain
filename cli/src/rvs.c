// rvs :- CLI for RISCV Studio!

#include<stdio.h>
#include"rvs_functions.h"


int main(int argc, char* argv[]){

    if(argc < 2){
        printf("No command provided.\n");
        print_help();
        return 1;
    }

    Command cmd = parse_command(argv[1]);

    switch (cmd){
        case HELP:
            print_help();
            return 0;
        
        case RUN: 
            return run(argc, argv);

        case VERSION:
            return version();

        case TEST:
            return test();

        case DOCTOR:
            return doctor();

        default:
            printf("Unknown command: %s.\n", argv[1]);
            printf("Type 'rvs help' for available commands\n");
            return 1;
    }
}
