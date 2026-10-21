#ifndef READING_H
#define READING_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define SIZE_MAX_TEXT 128
#define NUMBER_QUESTIONS 10

struct Question{
    char id;
    char question[SIZE_MAX_TEXT];
    char answers[SIZE_MAX_TEXT][4];
};

struct TabQuestion{
    struct Question* questions;
    size_t size;
    size_t capacity;
};

struct TabQuestion init_tab();
void add_tab(struct TabQuestion* tab, struct Question new_question);
void destroy_tab(struct TabQuestion* tab);

#endif