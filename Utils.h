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

/**
 *@brief Send an int in between min and max included. Return -1 if min > max.
 *
 * @param min min value
 * @param max max value
 * @return int
 */
int randInterval(const int min, const int max);

// quick seed rand 
void qsrand();

// clear the stdin buffer from anything
void empty_stdin();

/**
 *@brief show a formated error in the console
 *
 * @param code error code
 * @param fatal should the program exit
 * @param message to explain what is going on, facultativ
 */
void showError(Error_Code code, Bool fatal, char* message);

#ifndef scanf_s
// define a secure scanf (if you ask for an int, do not flood the console as en exemple)
/**
 *@brief define a more secure scanf
 *
 * @param value the value you want to scan into
 * @param format the format for the scan (%d, %s ...)
 * @param message a message to print for the user before the input
 * @param conditions function that return true if value match the requirement
 * @return int
 */
int scanf_s(const void* value, char* format, char* message, Bool(*conditions(const void* value)));
#endif

#endif