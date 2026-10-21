#include <stdio.h>
#include <stdlib.h>
//#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "reading.h"

int user_input(void *result, const char *format, size_t size_max);
enum Language choice_language();

// ===

int main(void){
    //printf("↩\n");
    enum Language language_user=choice_language();
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
    enum Language choice_user=UNKNOWN;
    printf("Choose your language :\n");
    printf("1- EN\n2- FR\n3- ES\n");
    //printf("4- DE\n5- IT\n6- RU\n");
    int cond;
    do{
        cond=user_input(&choice_user,"%d",1);
    }while(cond!=0);    
    return choice_user;
}
