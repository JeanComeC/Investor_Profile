#include "reading.h"

struct TabQuestion init_tab(){
    struct Question* questions=malloc(NUMBER_QUESTIONS*sizeof(struct Question));
    if(!questions){
        perror("Error malloc().");
        exit(1);
    }
    struct TabQuestion tab;
    tab.size=0;
    tab.capacity=NUMBER_QUESTIONS;
    tab.questions=questions;
    return tab;
}

void add_tab(struct TabQuestion* tab, struct Question new_question){
    if(tab->size>=tab->capacity){
        fprintf(stderr,"Error: Overflow array.\n");
        return;
    }
    tab->questions[tab->size]=new_question;
    tab->size++;
}

void destroy_tab(struct TabQuestion* tab){
    free(tab->questions);
    tab->questions=NULL;
    tab->capacity=0;
    tab->size=0;
}
