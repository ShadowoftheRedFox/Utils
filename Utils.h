#ifndef HEADER_UTILS_HANDOUT
#define HEADER_UTILS_HANDOUT
#include <stdio.h>

typedef enum Bool {
    false, true
} Bool;

typedef enum Error_Code {
    CODE_OK,
    CODE_MALLOC_FAILED,
    CODE_ARG_NULL,
    CODE_ARG_INVALID,
    CODE_THRESHOLD_SURPASSED,
    // can not be fatal
    CODE_WARNING,
    // always fatal
    CODE_ERROR
} Error_Code;

// renvoie des entiers inclus dans [min, max]
// renvoie -1 si min > max
int randInterval(const int min, const int max);

// seed rand 
void qsrand();

// clear the stdin buffer from anything
void empty_stdin();

// show an error in the console
void showError(Error_Code code, Bool fatal, char* message);

#ifndef scanf_s
// define a secure scanf (if you ask for an int, do not flood the console as en exemple)
int scanf_s(const void* value, char* format, char* message, Bool(*conditions(const void* value))); //TODO finish
#endif

//TODO give description for everything

#endif