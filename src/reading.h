#ifndef READING_H
#define READING_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_MAX_TEXT 128
#define NUMBER_QUESTIONS 10

enum Language{
    LANG_UNKNOWN,
    LANG_EN,
    LANG_FR,
    LANG_ES,
    LANG_DE,
    LANG_IT,
    LANG_RU,
};

// ===

struct Question{
    char id;
    char question[SIZE_MAX_TEXT];
    char answers[4][SIZE_MAX_TEXT];
};

struct TabQuestion{
    struct Question* questions;
    size_t size;
    size_t capacity;
};

// ===

struct TabQuestion init_tab();
void add_tab(struct TabQuestion* tab, struct Question new_question);
void destroy_tab(struct TabQuestion* tab);

void reading_filling(enum Language language_user, struct TabQuestion* tab);

#endif