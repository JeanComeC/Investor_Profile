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
    if(score>=10 && score<=17)gross_profile=CAUTIOUS;
    if(score>=18 && score<=25)gross_profile=BALANCED;
    if(score>=26 && score<=33)gross_profile=DYNAMIC;
    if(score>=34 && score<=40)gross_profile=AGGRESSIVE;
    return gross_profile;
}

enum Profile prudence_rule(enum Profile gross_profile, int answer2, int answer3, int answer4){
    enum Profile profile_234=HUGE_CHEATER;
    size_t score_234=answer2+answer3+answer4;
    if(score_234>=3 && score_234<=5)profile_234=CAUTIOUS;
    if(score_234>=6 && score_234<=7)profile_234=BALANCED;
    if(score_234>=8 && score_234<=10)profile_234=DYNAMIC;
    if(score_234>=11 && score_234<=12)profile_234=AGGRESSIVE;

    if(profile_234<=gross_profile){
        return profile_234;
    }else{
        return gross_profile;
    }
}

int profile_writing(enum Language language_user, enum Profile user_profile){
    mkdir("output",0755);//if the file already exists, the error is not handled
    FILE *file_profile = fopen("output/profile.md","w");
    if(!file_profile){
        perror("Error creating output/profile.md");
        return -1;
    }
    switch(language_user){
    case LANG_EN:
        switch(user_profile){
        case CAUTIOUS:
            fprintf(file_profile,"Your investor profile is : CAUTIOUS .");
            break;
        case BALANCED:
            fprintf(file_profile,"Your investor profile is : BALANCED .");
            break;
        case DYNAMIC:
            fprintf(file_profile,"Your investor profile is : DYNAMIC .");
            break;
        case AGGRESSIVE:
            fprintf(file_profile,"Your investor profile is : AGGRESSIVE .");
            break;
        default:
            fprintf(file_profile,"Your investor profile is : HUGE_CHEATER .\n\nYou thought you were clever for trying to cheat on my questionnaire, but as a developer from a bygone era would say: \"The hunter becomes the hunted!\"");
            break;
        }
        break;
    
    case LANG_FR:
        switch(user_profile){
        case CAUTIOUS:
            fprintf(file_profile,"Votre profil d'investisseur est : PRUDENT .");
            break;
        case BALANCED:
            fprintf(file_profile,"Votre profil d'investisseur est : ÉQUILIBRÉ .");
            break;
        case DYNAMIC:
            fprintf(file_profile,"Votre profil d'investisseur est : DYNAMIQUE .");
            break;
        case AGGRESSIVE:
            fprintf(file_profile,"Votre profil d'investisseur est : OFFENSIF .");
            break;
        default:
            fprintf(file_profile,"Votre profil d'investisseur est : ÉNORME_TRICHEUR .\n\nVous vous êtes cru plus malin à vouloir tricher à mon questionnaire, et bien de la part d'un développeur d'un autre siècle : \"Tel est pris qui croyait prendre !\".");
            break;
        }
        break;
    
    case LANG_ES:
        switch(user_profile){
        case CAUTIOUS:
            fprintf(file_profile,"Tu perfil de inversor es : PRUDENTE .");
            break;
        case BALANCED:
            fprintf(file_profile,"Tu perfil de inversor es : EQUILIBRADO .");
            break;
        case DYNAMIC:
            fprintf(file_profile,"Tu perfil de inversor es : DINÁMICO .");
            break;
        case AGGRESSIVE:
            fprintf(file_profile,"Tu perfil de inversor es : OFENSIVO .");
            break;
        default:
            fprintf(file_profile,"Tu perfil de inversor es : GRAN_TRAMPOSO .\n\nTe creíste más listo por intentar hacer trampa en mi cuestionario, pues bien, en palabras de un desarrollador de otro siglo: «¡Al que quería atrapar, lo atraparon!».");
            break;
        }
        break;
    
    default:
        //until the other languages have been coded
        switch(user_profile){
        case CAUTIOUS:
            fprintf(file_profile,"Your investor profile is : CAUTIOUS .");
            break;
        case BALANCED:
            fprintf(file_profile,"Your investor profile is : BALANCED .");
            break;
        case DYNAMIC:
            fprintf(file_profile,"Your investor profile is : DYNAMIC .");
            break;
        case AGGRESSIVE:
            fprintf(file_profile,"Your investor profile is : AGGRESSIVE .");
            break;
        default:
            fprintf(file_profile,"Your investor profile is : HUGE_CHEATER .\n\nYou thought you were clever for trying to cheat on my questionnaire, but as a developer from a bygone era would say: \"The hunter becomes the hunted!\"");
            break;
        }
        break;
    }

    fclose(file_profile);
    return 0;
}
