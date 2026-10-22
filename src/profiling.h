#ifndef PROFILING_H
#define PROFILING_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "reading.h"

enum Profile{
    HUGE_CHEATER,
    CAUTIOUS,
    BALANCED,
    DYNAMIC,
    AGGRESSIVE,
};

// ===

int score_writing(int* tab_user_answer);
enum Profile gross_profile_profiling(int* tab_user_answer);
enum Profile prudence_rule(enum Profile gross_profile, int answer2, int answer3, int answer4);
int profile_writing(enum Language language_user, enum Profile user_profile);

#endif