//includes-----------------------
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//defines------------------------
#define SIZE 3450
#define LENGTH 1000


char *filename = "movie.txt";

//structs------------------------------------------
struct Budget{
      int budget;
      int year;
      char *title;
      char *titletype;
      char *top250;
};
struct Name{
    char **genre;
    char *title;
    char **directors;
    char *mustsee;
    double rating;
    int runtime;
    int score;
    char *url;
};
struct Name name[SIZE];
struct Budget budget[SIZE];

//functions defines------------------------------
void program_start();
void budget_list(struct Budget *budget);
void name_list(struct Name *name);
void movie_info(struct Budget *budget,struct Name *name);
void print_movie(struct Budget *budget,struct Name *name,int index);
void sort_movies_by_year(struct Budget *budget, struct Name *name);
void sort_movies_by_votes(struct Budget *budget, struct Name *name);
void print_unique_genres(struct Name *name);
void count_genres(struct Name *name);
void print_year(struct Budget *budget);

//main-------------------------------------
int main(int argc, char const *argv[]){
    program_start();
    return 0;
}

//functions----------------------------------
void program_start(){
    FILE *fp = fopen(filename,"r");
    if(fp == NULL){
        printf("File not Found!\nExit..\n");
        exit(1);
    }
    int secim,index = 0;
    const char *sep;
    char *stc = (char*)malloc(sizeof(char)*LENGTH);
    while(fgets(stc,LENGTH,fp) != NULL){
        budget[index].budget = atoi(strtok(stc,";"));
        budget[index].title = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(budget[index].title,strtok(NULL,";"));
        name[index].title = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(name[index].title,budget[index].title);
        budget[index].titletype = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(budget[index].titletype,strtok(NULL,";"));
        char *temp2 = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(temp2,strtok(NULL,";"));
        name[index].directors = (char**)malloc(sizeof(char*)*LENGTH);
        strcpy(name[index].directors,temp2);
        name[index].rating = atof(strtok(NULL,";"));
        name[index].runtime = atoi(strtok(NULL,";"));
        budget[index].year = atoi(strtok(NULL,";"));
        char *temp3 = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(temp3,strtok(NULL,";"));
        name[index].score = atoi(strtok(NULL,";"));
        budget[index].top250 = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(budget[index].top250,strtok(NULL,";"));
        name[index].mustsee = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(name[index].mustsee,strtok(NULL,";"));
        name[index].url = (char*)malloc(sizeof(char)*LENGTH);
        strcpy(name[index].url,strtok(NULL,";"));
        
        int i = 0;
        int j = 0;
        int k = 0;
        name[index].genre = (char**)malloc(sizeof(char*)*LENGTH);
        while(temp3[j] != '\0'){
            name[index].genre[i] = (char*)malloc(sizeof(char)*100);
            k=0;
            while(temp3[j] != ','){
                if(temp3[j] == '\0')
                    break;
                name[index].genre[i][k] = temp3[j];
                j++;
                k++;
            }
            name[index].genre[i][k] = '\0';
            
            if(temp3[j] == '\0'){
                name[index].genre[i+1] = (char*)malloc(sizeof(char)*100);
                name[index].genre[i+1][0] = '\0';
                break;
            }
            j++;
            i++;
        }
        index++;
    }
    sort_movies_by_year(budget,name);



    while(1){
        printf("\n1-List of budget array\n2-List of name array\n3-List of genres\n4-List of the Movie Through the Years\n5-List of the Movie Through the Scores\n6-All Information of a Single Movie\n7-Frequecy of the Genres\n8-Exit.\n");
        printf("Select your process : ");
        scanf("%d",&secim);
        switch (secim){
        case 1:
            budget_list(budget);
            break;
        case 2:
            name_list(name);
            break;
        case 3:
            print_unique_genres(name);
            break;
        case 4:
            print_year(budget);
            break;
        case 5:
            sort_movies_by_votes(budget,name);
            break;
        case 6:
            movie_info(budget,name);
            break;
        case 7:
            count_genres(name);
            break;
        case 8:
            printf("Exit\n");
            exit(1);
            break;
        default:
            printf("Error!\nExit");
            exit(1);
            break;
        }
    }
}
void budget_list(struct Budget *budget){
    int i;
    for(i = 0 ; i < SIZE ; i++){
        printf("%s : %d\n",budget[i].title,budget[i].budget);
    }
}
void name_list(struct Name *name){
    int i;
    for(i=0 ; i<SIZE ; i++){
        printf("%s \n",name[i].title);
    }
}
void movie_info(struct Budget *budget,struct Name *name){
    char moviename[100];
    printf("\nMovie name : ");scanf("%s",moviename);
    int i;
    for(i=0;i<SIZE;i++){
        if(strcmp(moviename,name[i].title)==0){
            print_movie(budget,name,i);
            break;
        }
    }if(i==SIZE)printf("Movie does not exist.");

}
void print_movie(struct Budget *budget,struct Name *name,int index){
    int i=0;
    printf("\nTitle : %s\n",name[index].title);
    printf("Type : %s\n",budget[index].titletype);
    printf("Genres : ");
    while(name[index].genre[i]!='\0'){
        printf("%s ",name[index].genre[i]);
        i++;}
    printf("\nDirector : %s\n",name[index].directors);
    printf("IMDB Rating : %.1lf (%d Votes) | IMDB Rank : %s\n",name[index].rating,name[index].score,budget[index].top250);
    printf("Year : %d\n",budget[index].year);
    printf("Budget : %d\n",budget[index].budget);
    printf("Runtime : %d\n",name[index].runtime);
    printf("1001 Must See : %s\n",name[index].mustsee);
    printf("URL : %s",name[index].url);
}

void sort_movies_by_year(struct Budget *budget, struct Name *name) {
    int i, j, max_year, max_index;

    for (i = 0; i < SIZE - 1; i++) {
        max_year = budget[i].year;
        max_index = i;

        for (j = i + 1; j < SIZE; j++) {
            if (budget[j].year > max_year) {
                max_year = budget[j].year;
                max_index = j;
            }
        }

        if (max_index != i) {
            struct Budget tempBudget = budget[i];
            struct Name tempName = name[i];

            budget[i] = budget[max_index];
            name[i] = name[max_index];

            budget[max_index] = tempBudget;
            name[max_index] = tempName;
        }
    }
}
void print_year(struct Budget *budget){
    int i;
    for(i=0 ; i<SIZE ; i++){
        if(budget[i].year == 0)continue;
        printf("%s : %d\n",budget[i].title,budget[i].year);
    }
}

void sort_movies_by_votes(struct Budget *budget, struct Name *name) {
    int i, j, max_votes, max_index;

    struct Name tempName;
    struct Budget tempBudget;

    for (i = 0; i < SIZE - 1; i++) {
        max_votes = name[i].score;
        max_index = i;

        for (j = i + 1; j < SIZE; j++) {
            if (name[j].score > max_votes) {
                max_votes = name[j].score;
                max_index = j;
            }
        }

        if (max_index != i) {
            tempName = name[i];
            tempBudget = budget[i];

            name[i] = name[max_index];
            budget[i] = budget[max_index];

            name[max_index] = tempName;
            budget[max_index] = tempBudget;
        }
    }

    for (i = 0; i < SIZE; i++) {
        if (name[i].score == 0) continue;
        printf("%s : %d (score)\n", name[i].title, name[i].score);
    }
}


void print_unique_genres(struct Name *name) {
    int i, j;
    int genreCount = 0;
    char **uniqueGenres = NULL;

    for (i = 0; i < SIZE; i++) {
        char **genres = name[i].genre;

        while (*genres != NULL) {
            int isUnique = 1;

            for (j = 0; j < genreCount; j++) {
                if (uniqueGenres[j] != NULL && strcmp(uniqueGenres[j], *genres) == 0) {
                    isUnique = 0;
                    break;
                }
            }

            if (isUnique) {
                uniqueGenres = (char **)realloc(uniqueGenres, (genreCount + 1) * sizeof(char *));
                uniqueGenres[genreCount] = (char *)malloc((strlen(*genres) + 1) * sizeof(char));
                strcpy(uniqueGenres[genreCount], *genres);
                genreCount++;
            }

            genres++;
        }
    }

    printf("Unique Genres:\n");
    for (i = 0; i < genreCount; i++) {
        printf("%s\n", uniqueGenres[i]);
        free(uniqueGenres[i]);
    }
    free(uniqueGenres);
}

void count_genres(struct Name *name) {
    int i, j;
    int genreCount = 0;
    int *genreFrequency = NULL;
    char **uniqueGenres = NULL;

    for (i = 0; i < SIZE; i++) {
        char **genres = name[i].genre;

        while (*genres != NULL) {
            int isUnique = 1;

            for (j = 0; j < genreCount; j++) {
                if (uniqueGenres[j] != NULL && strcmp(uniqueGenres[j], *genres) == 0) {
                    isUnique = 0;
                    genreFrequency[j]++;
                    break;
                }
            }

            if (isUnique) {
                uniqueGenres = (char **)realloc(uniqueGenres, (genreCount + 1) * sizeof(char *));
                genreFrequency = (int *)realloc(genreFrequency, (genreCount + 1) * sizeof(int));

                uniqueGenres[genreCount] = (char *)malloc((strlen(*genres) + 1) * sizeof(char));
                strcpy(uniqueGenres[genreCount], *genres);

                genreFrequency[genreCount] = 1;
                genreCount++;
            }

            genres++;
        }
    }

    printf("Genre Frequency:\n");
    for (i = 0; i < genreCount; i++) {
        printf("%s: %d\n", uniqueGenres[i], genreFrequency[i]);
        free(uniqueGenres[i]);
    }

    free(uniqueGenres);
    free(genreFrequency);
}
