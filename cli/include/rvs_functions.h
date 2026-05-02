// HEADER file for CLI feature declarations.

#ifndef RVS_FUNCTIONS_H
#define RVS_FUNCTIONS_H

typedef enum{
    HELP,       // Compiler numbers this '0'
    RUN,       // 1
    VERSION,    // 2
    TEST,       // 3
    DOCTOR,     // 4
    INVALID       // 5
} Command;

typedef struct {
    char entry[10];
    Command command;
} CommandMap;


Command parse_command(char*);
void print_help();
int run(int argc, char* argv[]);
int version();
int test();
int doctor();

#endif
