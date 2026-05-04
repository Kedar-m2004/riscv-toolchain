// Implementation file of CLI features.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include"rvs_functions.h"

#ifdef _WIN32
#include<windows.h>
#endif

// We use _WIN32 to use safe dummy implementation of encapsulated parts, when run on non-Windows platform.
// This is called platform abstraction.
// #ifdef means "if defined"
// #ifndef means "if not defined"

/* This file includes thefollowing things:
    rvs_functions.h
        PUBLIC API

    rvs_functions.c
        PUBLIC functions
        PRIVATE helpers (static)
*/

static void print_check(const char* message, int passed);       // Helper function 01
static int command_exists(const char* command);                 // Helper function 02
static int path_exists(const char* path);                       // Helper function 03
static int file_exists(const char* path);                       // Helper function 04
static int path_contains_ctools();                              // Helper function 05



CommandMap command_table[] = {
    {"help", HELP},
    {"--help", HELP},
    {"-h", HELP},

    {"run", RUN},

    {"version", VERSION},
    {"--version", VERSION},
    {"-v", VERSION},

    {"doctor", DOCTOR},

    {"test", TEST}
};



Command parse_command(char* input){             // Returns the type of command entered by user
    
    int size = sizeof(command_table)/ sizeof(command_table[0]);

    for (int i = 0; i<size; i++){
        
        if(strcmp(input, command_table[i].entry) == 0){
            return command_table[i].command;
        }
    }
    return INVALID;
}



void print_help(){              // Helps the user to navigate through the CLI

    printf("RISC-V Studio CLI\n\n");
    printf("Usage: \n");
    printf("   rvs help\n");
    printf("   rvs version\n");
    printf("   rvs doctor\n");
    printf("   rvs run <test_name>\n");
    printf("   rvs run <assembly_file>\n");    
}



int run(int argc, char* argv[]){            // Features provided by "rvs run ..." command

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
        snprintf(cmd, sizeof(cmd), "\"C:\\tools\\Simulator.exe\" \"%s\"", target );
        return system(cmd);
    }
}



int version(){
    printf("RISC-V Studio CLI v0.1.1\n");
    printf("Build: May 2026\n");
    printf("Author: Kedar Modak\n");

    return 0;
}


int test(){
    return system("mingw32-make test");
}



/* below "rvs doctor" function will Ask 6 questions → print PASS/FAIL
    Is GCC installed?
    Is Make installed?
    ...

    The helper functions of docotr function are:
*/

static void print_check(const char* message, int passed){       // Helper func 01
    // static means only this file can use it.

    if(passed){
        printf("[PASS] %s\n", message);
    }
    else{
        printf("[FAIL] %s\n", message);
    }
}

static int command_exists(const char* command){
    char cmd[128];

    snprintf(cmd, sizeof(cmd), "where %s >nul 2>nul", command);

    return (system(cmd) == 0);

    /*  where gcc        → search for gcc
        >nul             → hide normal output
        2>nul            → hide error output
        system(cmd) == 0 → command succeeded
    */
}

#ifdef _WIN32

static int path_exists(const char* path){       // Check whether this path exists and is a folder.

    DWORD attributes = GetFileAttributesA(path);

    return (
        (attributes != INVALID_FILE_ATTRIBUTES) &&
        (attributes & FILE_ATTRIBUTE_DIRECTORY)
    );

    /*  Return true only if:
        1. Path exists
        2. Path is a folder
    */
}

static int file_exists(const char* path){       // Check whether this path exists and is a file.

    DWORD attributes = GetFileAttributesA(path);

    return (
        (attributes != INVALID_FILE_ATTRIBUTES) &&
        !(attributes & FILE_ATTRIBUTE_DIRECTORY)
    );

    /*  Return true only if:
        1. Path exists
        2. Path is NOT a folder
    */
}

#else

static int path_exists(const char* path){
    (void)path;         // Without this the compiler may warn: warning: unused parameter 'path'
    return 0;
}

static int file_exists(const char* path){
    (void)path;         // Without this the compiler may warn: warning: unused parameter 'path'
    return 0;
}

#endif



static int path_contains_ctools(){

    char* path = getenv("PATH");

    if(path == NULL){
        return 0;
    }

    return (
        (strstr(path, "C:\\tools") != NULL) ||
        (strstr(path, "C:/tools") != NULL)
    );
}

int doctor(){

    printf("RISC-V Studio Doctor\n");
    printf("--------------------\n");

    int gcc_ok = command_exists("gcc");
    int make_ok = command_exists("mingw32-make");
    int powershell_ok = command_exists("powershell");

    int ctools_ok = path_exists("C:\\tools");
    int rvs_ok = file_exists("C:\\tools\\rvs.exe");
    int simulator_ok = file_exists("C:\\tools\\Simulator.exe");
    int path_ok = path_contains_ctools();


    print_check("GCC is installed", gcc_ok);
    print_check("mingw32-make is installed", make_ok);
    print_check("PowerShell is available", powershell_ok);

    print_check("C:\\tools exists", ctools_ok);
    print_check("C:\\tools\\rvs.exe exists", rvs_ok);
    print_check("C:\\tools\\Simulator.exe exists", simulator_ok);
    print_check("C:\\tools is present in PATH", path_ok);

    if(
        gcc_ok 
        && make_ok 
        && powershell_ok
        && ctools_ok
        && rvs_ok
        && simulator_ok
        && path_ok
    ){
        printf("\nSystem is ready for RISC-V Studio.\n");
        return 0;
    }

    printf("\nSome checks failed. Fix the failed items above.\n");
    return 1;

}
