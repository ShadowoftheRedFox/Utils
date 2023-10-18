#include "Utils.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int randInterval(const int min, const int max) {
    // seed if random is not seeded
#ifndef RANDOM_IS_SEEDED
    qsrand();
#endif
    // check for errors
    if (min > max) {
        return -1;
    } else if (min == max) {
        return min;
    }
    // return a value between MIN and MAX in it
    return rand() % (max - min + 1) + min;
}

void qsrand() {
#ifndef RANDOM_IS_SEEDED
#define RANDOM_IS_SEEDED
#endif
    srand(time(NULL));
}

void empty_stdin() {
    while (getchar() != '\n') { ; };
}

void showError(Error_Code code, Bool fatal, char* message) {
    switch (code) {
    case CODE_OK:
        if (message != NULL) {
            printf("OK | %s\n", message);
        } else {
            printf("OK\n");
        }
    case CODE_MALLOC_FAILED:
        if (message != NULL) {
            printf("Malloc failed | %s\n", message);
        } else {
            printf("Malloc failed\n");
        }
    case CODE_ARG_NULL:
        if (message != NULL) {
            printf("Argument null | %s\n", message);
        } else {
            printf("Argument null\n");
        }
    case CODE_ARG_INVALID:
        if (message != NULL) {
            printf("Argument invalid | %s\n", message);
        } else {
            printf("Argument invalid\n");
        }
    case CODE_THRESHOLD_SURPASSED:
        if (message != NULL) {
            printf("Threshold surpassed | %s\n", message);
        } else {
            printf("Threshold surpassed\n");
        }
    default:
        if (message != NULL) {
            printf("Unknown code | %s\n", message);
        } else {
            printf("Unknown code\n");
        }
        break;
    }

    if (fatal) {
        exit(1);
    }
}