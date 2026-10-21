#ifndef READING_H
#define READING_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE_MAX_TEXT 128

struct Question{
    char id;
    char question[SIZE_MAX_TEXT];
    char* answers[SIZE_MAX_TEXT];
};

struct TabQuestion{
    struct Question* tab;
    size_t size;
    size_t capacity;
};

#endif