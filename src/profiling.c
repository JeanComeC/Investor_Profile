#include "profiling.h"

int score_writing(int* tab_user_answer){
    size_t sum=0;
    for(size_t i=0;i<NUMBER_QUESTIONS;i++){
        sum+=tab_user_answer[i];
    }
    mkdir("output",0755);//if the file already exists, the error is not handled
    FILE *file_score = fopen("output/score.md","w");
    if(!file_score){
        perror("Error creating output/score.md");
        return -1;
    }
    fprintf(file_score,"%d",sum);
    fclose(file_score);
    return 0;
}

