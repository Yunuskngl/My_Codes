#include<stdio.h>
#include<stdlib.h>
#include<string.h>


#define DOSYA_BOYUTU 3451
#define UZUNLUK 1000


struct Budget{
      int budget;
      int year;
      char *title;
      char *titletype;
      char *top250;
};

struct Name{
    int runtime;
    int votes;
    double rating;
    char **genre;
    char *title;
    char **directors;
    char *mustsee;
    char *url;
    
};

struct Name nameArray[DOSYA_BOYUTU];
struct Budget budgetArray[DOSYA_BOYUTU];


void verileri_al();

void yila_gore_siralama(struct Budget *budget, struct Name *name);

void oylara_gore_siralama(struct Budget *budget, struct Name *name);

void genres_yazdir(struct Name *name);

void genres_sayilari(struct Name *name);

void budgetleri_goster(struct Budget *budget);

void name_dizileri_yazdir(struct Name *name);

void film_bilgileri(struct Budget *budget,struct Name *name);

void film_bilgileri_detay(struct Budget *budget,struct Name *name,int index);



void budgetleri_goster(struct Budget *budget){
    int index=0;
    for (int index = 0; index < DOSYA_BOYUTU; index++) {
        printf("%d : %s\n",budget[index].budget , budget[index].title);
    }
}

void name_dizileri_yazdir(struct Name *name)
{
    int index=0;
    for(index = 0; index < DOSYA_BOYUTU; index++) 
    {
        if(index % 10 == 0) {
        puts("");
        }
    printf("%s  \n", name[index].title);
    }
}

void film_bilgileri(struct Budget *budget,struct Name *name){

    char *film_adi = (char*)malloc(sizeof(char)*UZUNLUK);
    printf("\nFilm Ismi Giriniz : ");scanf(" %[^\n]",film_adi);
    
    int index;
    for(index=0;index<DOSYA_BOYUTU;index++){
        if(strcmp(film_adi,name[index].title)==0){
            film_bilgileri_detay(budget,name,index);
            break;
        }
    }if(index==3450)printf("Film bulunamadi.");

}

void film_bilgileri_detay(struct Budget *budget, struct Name *name, int index) {
    
    int i;

    printf("\nTitle : %s\n", name[index].title);
    printf("Type : %s\n", budget[index].titletype);
    printf("Genres : ");
    for (i = 0; name[index].genre[i] != NULL; i++) {
        printf("%s ", name[index].genre[i]);
    }
    printf("\nDirector : ");
    for (i = 0; name[index].directors[i] != NULL; i++) {
        printf("%s ", name[index].directors[i]);
    }
    puts("");
    printf("IMDB Rating : %.1lf\n", name[index].rating);
    printf("(%d Votes) \n", name[index].votes);
    printf("Top 250 : %s\n", budget[index].top250);
    printf("Year : %d\n", budget[index].year);
    printf("Budget : %d\n", budget[index].budget);
    printf("Runtime : %d\n", name[index].runtime);
    printf("1001 Must See : %s\n", name[index].mustsee);
    printf("URL : %s", name[index].url);
}

void yila_gore_siralama(struct Budget *budget, struct Name *name) {
    int i, j, max_year, max_index;

    for (i = 0; i < DOSYA_BOYUTU; i++) {
        max_year = budget[i].year;
        max_index = i;

        for (j = i + 1; j < DOSYA_BOYUTU; j++) {
            if (budget[j].year > max_year) {
                max_year = budget[j].year;
                max_index = j;
            }
        }

        struct Budget tokenBudget = budget[i];
        struct Name tokenName = name[i];

        budget[i] = budget[max_index];
        name[i] = name[max_index];

        budget[max_index] = tokenBudget;
        name[max_index] = tokenName;
    }
}
void oylara_gore_siralama(struct Budget *budget, struct Name *name) {
    int i, j, max_votes, max_index;

    struct Name siralamaName[DOSYA_BOYUTU];
    struct Budget siralamaBudget[DOSYA_BOYUTU];

    for (i = 0; i < DOSYA_BOYUTU; i++) {
        siralamaName[i] = name[i];
        siralamaBudget[i] = budget[i];
    }

    for (i = 0; i < DOSYA_BOYUTU; i++) {
        max_votes = siralamaName[i].votes;
        max_index = i;

        for (j = i + 1; j < DOSYA_BOYUTU; j++) {
            if (siralamaName[j].votes > max_votes) {
                max_votes = siralamaName[j].votes;
                max_index = j;
            }
        }


        struct Name tokenName = siralamaName[i];
        struct Budget tokenBudget = siralamaBudget[i];

        siralamaName[i] = siralamaName[max_index];
        siralamaBudget[i] = siralamaBudget[max_index];

        siralamaName[max_index] = tokenName;
        siralamaBudget[max_index] = tokenBudget;
    }
    for(i = 0; i<DOSYA_BOYUTU ; i++){
        if(siralamaName[i].votes == 0)continue;
        printf("%d (votes): %s \n",siralamaName[i].votes,siralamaName[i].title);
    }
}

void genres_yazdir(struct Name *name) {
    int i, j;
    int genreCount = 0;
    char **essizGenres = (char **)malloc(DOSYA_BOYUTU * sizeof(char *));

    for (i = 0; i < DOSYA_BOYUTU; i++) {
        essizGenres[i] = NULL;
    }

    for (i = 0; i < DOSYA_BOYUTU; i++) {
        int genreIndex = 0;
        char **genres = name[i].genre;

        while (genres[genreIndex] != NULL) {
            int essiz_mi = 1;

            for (j = 0; j < genreCount; j++) {
                if (essizGenres[j] != NULL && strcmp(essizGenres[j], genres[genreIndex]) == 0) {
                    essiz_mi = 0;
                    break;
                }
            }

            if (essiz_mi) {
                essizGenres[genreCount] = (char *)malloc((strlen(genres[genreIndex]) + 1) * sizeof(char));
                strcpy(essizGenres[genreCount], genres[genreIndex]);
                genreCount++;
            }

            genreIndex++;
        }
    }

    printf("tek tur:\n");
    for (i = 0; i < genreCount; i++) {
        printf("%s\n", essizGenres[i]);
    }

    for (i = 0; i < genreCount; i++) {
        free(essizGenres[i]);
    }
    free(essizGenres);
}

void genres_sayilari(struct Name *name){
    int i, j;
    int genreCount = 0;
    int *turSikligi = (int *)malloc(DOSYA_BOYUTU * sizeof(int));
    char **essizGenres = (char **)malloc(DOSYA_BOYUTU * sizeof(char *));

    for (i = 0; i < DOSYA_BOYUTU; i++) {
        essizGenres[i] = NULL;
        turSikligi[i] = 0;
    }

    for (i = 0; i < DOSYA_BOYUTU; i++) {
        int genreIndex = 0;
        char **genres = name[i].genre;

        while (genres[genreIndex] != NULL) {
            int essiz_mi = 1;

            for (j = 0; j < genreCount; j++) {
                if (essizGenres[j] != NULL && strcmp(essizGenres[j], genres[genreIndex]) == 0) {
                    essiz_mi = 0;
                    break;
                }
            }

            if (essiz_mi) {
                essizGenres[genreCount] = (char *)malloc((strlen(genres[genreIndex]) + 1) * sizeof(char));
                strcpy(essizGenres[genreCount], genres[genreIndex]);
                genreCount++;
            }

            for (j = 0; j < genreCount; j++) {
                if (strcmp(essizGenres[j], genres[genreIndex]) == 0) {
                    turSikligi[j]++;
                    break;
                }
            }

            genreIndex++;
        }
    }

    // Büyükten küçüğe sıralama
    for (i = 0; i < genreCount - 1; i++) {
        for (j = i + 1; j < genreCount; j++) {
            if (turSikligi[i] < turSikligi[j]) {
                char *tempGenre = essizGenres[i];
                int tempFrequency = turSikligi[i];

                essizGenres[i] = essizGenres[j];
                turSikligi[i] = turSikligi[j];

                essizGenres[j] = tempGenre;
                turSikligi[j] = tempFrequency;
            }
        }
    }

    printf("Tur Sikligi (Buyukten Kucuge):\n");
    for (i = 0; i < genreCount; i++) {
        printf("%s: %d\n", essizGenres[i], turSikligi[i]);
    }

    // Belleği temizleme
    for (i = 0; i < genreCount; i++) {
        free(essizGenres[i]);
    }
    free(essizGenres);
    free(turSikligi);
}

int main(int argc, char const *argv[]){
    verileri_al();
    return 0;
}
char *filename = "movie.txt";
void verileri_al(){
    FILE *file = fopen(filename,"r");
    if(file == NULL){
        printf("Dosya bulunamadi!\nCikiliyor..\n");
        exit(1);
    }
    int islem,movieIndex = 0;
    const char *token;
    char *ayirma_islemi = (char*)malloc(sizeof(char)*UZUNLUK);
    while(fgets(ayirma_islemi,UZUNLUK,file) != NULL){

        budgetArray[movieIndex].budget = atoi(strtok(ayirma_islemi,";"));
        
        budgetArray[movieIndex].title = (char*)malloc(sizeof(char)*UZUNLUK);
        strcpy(budgetArray[movieIndex].title,strtok(NULL,";"));

        nameArray[movieIndex].title = (char*)malloc(sizeof(char)*UZUNLUK);
        strcpy(nameArray[movieIndex].title,budgetArray[movieIndex].title);

        budgetArray[movieIndex].titletype = (char*)malloc(sizeof(char)*UZUNLUK);
        strcpy(budgetArray[movieIndex].titletype,strtok(NULL,";"));

        char *gecici_2 = (char*)malloc(sizeof(char)*UZUNLUK);
        strcpy(gecici_2,strtok(NULL,";"));

        nameArray[movieIndex].rating = atof(strtok(NULL,";"));

        nameArray[movieIndex].runtime = atoi(strtok(NULL,";"));

        budgetArray[movieIndex].year = atoi(strtok(NULL,";"));

        char *gecici = (char*)malloc(sizeof(char)*UZUNLUK);
        strcpy(gecici,strtok(NULL,";"));

        nameArray[movieIndex].votes = atoi(strtok(NULL,";"));

        budgetArray[movieIndex].top250 = (char*)malloc(sizeof(char)*UZUNLUK);
        strcpy(budgetArray[movieIndex].top250,strtok(NULL,";"));

        nameArray[movieIndex].mustsee = (char*)malloc(sizeof(char)*UZUNLUK);
        strcpy(nameArray[movieIndex].mustsee,strtok(NULL,";"));

        nameArray[movieIndex].url = (char*)malloc(sizeof(char)*UZUNLUK);
        strcpy(nameArray[movieIndex].url,strtok(NULL,";"));
        
        
        
        int i=0;
        const char *token=strtok(gecici,",");
        nameArray[movieIndex].genre = (char**)malloc(sizeof(char*)*UZUNLUK);
        while(token != NULL){
            nameArray[movieIndex].genre[i] = (char*)malloc(sizeof(char)*UZUNLUK);
            strcpy(nameArray[movieIndex].genre[i],token);
            token=strtok(NULL,",");
            i++;
        }

        i=0;
        const char *token2=strtok(gecici_2,",");
        nameArray[movieIndex].directors = (char**)malloc(sizeof(char*)*UZUNLUK);
        while(token2 != NULL){
            nameArray[movieIndex].directors[i] = (char*)malloc(sizeof(char)*UZUNLUK);
            strcpy(nameArray[movieIndex].directors[i],token2);
            token2=strtok(NULL,",");
            i++;
        }

        movieIndex++;
    }
    
    yila_gore_siralama(budgetArray,nameArray);


    while(1){
        printf("\n1-Budget dizisinin listesi\n2-Name dizisinin listesi\n3-Genre (turlerin) listesi\n4-Yillara gore Movie (Filmlerin) Listesi\n5-Skorlara (score) gore Filmlerin Listesi\n6-Tek Bir Filmin Tum Bilgileri\n7-Turlerin Sikligi (frekansi)\n8-Cikis.\n");
        printf("Isleminizi seciniz : ");scanf("%d",&islem);
        switch (islem){
        case 1:
            budgetleri_goster(budgetArray);
            break;
        case 2:
            name_dizileri_yazdir(nameArray);
            break;
        case 3:
            genres_yazdir(nameArray);
            break;
        case 4:
            for(int i=0; i<DOSYA_BOYUTU ; i++){
                if(budgetArray[i].year == 0)continue;
                printf("%d : %s\n",budgetArray[i].year,budgetArray[i].title);
            }
            break;
        case 5:
            oylara_gore_siralama(budgetArray,nameArray);
            break;
        case 6:
            film_bilgileri(budgetArray,nameArray);
            break;
        case 7:
            genres_sayilari(nameArray);
            break;
        case 8:
            printf("Cikiliyor...\n");
            exit(1);
            break;
        default:
            printf("Hatali Islem!\nCikiliyor...");
            exit(1);
            break;
        }
    }
}