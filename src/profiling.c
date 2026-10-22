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

enum Profile gross_profile_profiling(int* tab_user_answer){
    size_t score=0;
    for(size_t i=0;i<NUMBER_QUESTIONS;i++){
        score+=tab_user_answer[i];
    }
    enum Profile gross_profile=HUGE_CHEATER;
    if(score>10 && score<17)gross_profile=CAUTIOUS;
    if(score>18 && score<25)gross_profile=BALANCED;
    if(score>26 && score<33)gross_profile=DYNAMIC;
    if(score>34 && score<40)gross_profile=AGGRESSIVE;
    return gross_profile;
}

enum Profile prudence_rule(enum Profile gross_profile, int answer2, int answer3, int answer4){
    enum Profile profile_234=HUGE_CHEATER;
}

