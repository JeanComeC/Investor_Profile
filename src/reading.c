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


void reading_filling(enum Language language_user, struct TabQuestion* tab){
    const char* path_questionnaire;
    switch(language_user){
    case LANG_EN:
        path_questionnaire="questionnaires/EN-questionnaire.txt";
        break;
    case LANG_FR:
        path_questionnaire="questionnaires/FR-questionnaire.txt";
        break;
    case LANG_ES:
        path_questionnaire="questionnaires/ES-questionnaire.txt";
        break;
    default:
        //until the other languages have been coded
        path_questionnaire="questionnaires/EN-questionnaire.txt";
        break;
    }
    // ===
    FILE *file753 = fopen(path_questionnaire,"r");
    if(!file753){
        fprintf(stderr,"Error reading %s .\n",path_questionnaire);
        exit(1);
    }
    char buffer[SIZE_MAX_TEXT];
    struct Question current_q;
    int line_counter = 0;

    while(fgets(buffer, sizeof(buffer), file753)){
        buffer[strcspn(buffer, "\n")] = '\0';
        if(strlen(buffer) == 0) continue;

        if(line_counter==0){//This is a new question...
            current_q.id=buffer[0];
            strcpy(current_q.question, buffer);
            line_counter++;
        } 
        else{//This is an answer...
            int ans_index=line_counter-1;
            strcpy(current_q.answers[ans_index],buffer);
            line_counter++;
            
            if(line_counter==5){
                add_tab(tab,current_q);
                line_counter=0;//Let’s start afresh for the next question
            }
        }
    }
    fclose(file753);
}

