#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "reading.h"
#include "profiling.h"

int user_input(void *result, const char *format, size_t size_max);
enum Language choice_language();

// ===

int main(void){
    enum Language language_user=choice_language();
    struct TabQuestion tab_question=init_tab();
    reading_filling(language_user,&tab_question);
    //
    int* tab_user_answer=malloc(NUMBER_QUESTIONS*sizeof(int));
    if(!tab_user_answer){perror("Error malloc().");exit(1);}

    for(int i=0;i<NUMBER_QUESTIONS;i++){
        printf("%s\n",tab_question.questions[i].question);
        for(int j=0;j<4;j++){
            printf("%s\n",tab_question.questions[i].answers[j]);
        }
        printf("0- back ↩\n");
        int shutdown_condition;
        do{
            shutdown_condition=user_input(&tab_user_answer[i],"%d",1);
        }while(shutdown_condition!=0);
        //For a look back :
        if(tab_user_answer[i]==0){
            if(i<1){
                i--;
            }else{
                i-=2;
            }
        }
    }
    //
    score_writing(tab_user_answer);
    enum Profile user_profile=prudence_rule(gross_profile_profiling(tab_user_answer),tab_user_answer[2-1],tab_user_answer[3-1],tab_user_answer[4-1]);
    profile_writing(language_user,user_profile);
    //
    
    //
    free(tab_user_answer);
    destroy_tab(&tab_question);
    return 0;
}

// ===

int user_input(void *result, const char *format, size_t size_max){//size_max is the number of characters allowed
    char buffer[size_max + 3];// +1 for \n possible +1 for \0 + safety margin
    if(fgets(buffer, sizeof(buffer), stdin)==NULL){
        fprintf(stderr, "Error reading.\n");
        return 1;
    }
    //
    size_t len = strlen(buffer);
    bool troncq = false;
    if(len>0 && buffer[len-1]=='\n'){
        buffer[len-1]='\0';
        len--;
    }else{
        // No \n -> The input is too long for the buffer, so the rest is discarded
        troncq = true;
        int c;
        while ((c=getchar())!='\n' && c!=EOF){}
    }
    //
    if(len==0){
        fprintf(stderr, "Error : empty entry.\n");
        return 1;
    }

    if(size_max>0 && (len>size_max || troncq)){
        fprintf(stderr, "Error : data entry takes too long (max %zu characters%s).\n", size_max, size_max > 1 ? "s" : "");
        return 1;
    }
    //
    if(sscanf(buffer, format, result)!=1){
        fprintf(stderr, "Error : invalid format (expected : %s).\n", format);
        return 1;
    }

    return 0;
}

enum Language choice_language(){
    enum Language choice_user=LANG_UNKNOWN;
    printf("Choose your language :\n");
    printf("1- EN\n2- FR\n3- ES\n");
    //printf("4- DE\n5- IT\n6- RU\n");
    int cond;
    do{
        cond=user_input(&choice_user,"%d",1);
    }while(cond!=0);    
    return choice_user;
}
