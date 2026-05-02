// Implementation file of CLI features.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"rvs_functions.h"

CommandMap command_table[] = {
    {"help", HELP},
    {"--help", HELP},
    {"-h", HELP},

    {"run", RUN},

    {"version", VERSION},
    {"--version", VERSION},
    {"-v", VERSION},

    {"test", TEST}
};

Command parse_command(char* input){
    
    int size = sizeof(command_table)/ sizeof(command_table[0]);

    for (int i = 0; i<size; i++){
        
        if(strcmp(input, command_table[i].entry) == 0){
            return command_table[i].command;
        }
    }
    return INVALID;
}

void print_help(){
    printf("RISC-V Studio CLI\n\n");
    printf("Usage: \n");
    printf("   rvs help\n");
    printf("   rvs run <test_name>\n");
    printf("   rvs run <assembly_file>\n");    
}

int run(int argc, char* argv[]){

    if(argc < 3){
        printf("Error! Missing test name or assembly file!\n");
        print_help();
        return 1;
    }

    // NOTE: Never index into argv until you’ve validated argc.

    char* target = argv[2];

    if(strcmp(target, "arithmetic") == 0){
        system("mingw32-make arithmetic");
        return 0;
    }
    else if(strcmp(target, "branch") == 0){
        system("mingw32-make branch");
        return 0;
    }
    else if(strcmp(target, "memory") == 0){
        system("mingw32-make memory");
        return 0;
    }
    else if(strcmp(target, "jump") == 0){
        system("mingw32-make jump");
        return 0;
    }
    else{
        char cmd[256];
        sprintf(cmd, "mingw32-make && .\\Simulator.exe %s", target);
        return system(cmd);
    }
}

int version(){
    printf("RISC-V Studio CLI v0.1\n");
    printf("Build: May 2026\n");
    printf("Author: Kedar Modak\n");

    return 0;
}

int test(){
    return system("mingw32-make test");
}
