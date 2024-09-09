#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DOSYA_BOYUTU 3451
#define UZUNLUK 1000

struct Budget {
    int budget; 
    int year;
    char *title;
    char *titletype;
    char *top250;
};

struct Name {
    int runtime;
    int votes; 
    double rating;
    char *genre; 
    char *title;
    char *directors;
    char *mustsee;
    char *url;
};

struct Budget budgetArray[DOSYA_BOYUTU];
struct Name nameArray[DOSYA_BOYUTU];
int movieCount = 0;

void verileri_al(const char *filename);
void yila_gore_siralama(struct Budget *budget, struct Name *name);
void oylara_gore_siralama(struct Budget *budget, struct Name *name);
void genres_yazdir(struct Name *name);
void budgetleri_goster(struct Budget *budget);
void film_bilgileri_detay(struct Budget *budget, struct Name *name, int index);

void verileri_al(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Dosya bulunamadi!\nCikiliyor..\n");
        exit(1);
    }

    char *ayirma_islemi = (char *)malloc(sizeof(char) * UZUNLUK);
    if (ayirma_islemi == NULL) {
        printf("Bellek ayrilamadi!\n");
        fclose(file);
        exit(1);
    }

    while (fgets(ayirma_islemi, UZUNLUK, file) != NULL && movieCount < DOSYA_BOYUTU) {
        budgetArray[movieCount].budget = atoi(strtok(ayirma_islemi, ";"));

        budgetArray[movieCount].title = strdup(strtok(NULL, ";"));
        nameArray[movieCount].title = strdup(budgetArray[movieCount].title);

        budgetArray[movieCount].titletype = strdup(strtok(NULL, ";"));
        nameArray[movieCount].rating = atof(strtok(NULL, ";"));
        nameArray[movieCount].runtime = atoi(strtok(NULL, ";"));
        budgetArray[movieCount].year = atoi(strtok(NULL, ";"));
        nameArray[movieCount].votes = atoi(strtok(NULL, ";"));

        budgetArray[movieCount].top250 = strdup(strtok(NULL, ";"));
        nameArray[movieCount].mustsee = strdup(strtok(NULL, ";"));
        nameArray[movieCount].url = strdup(strtok(NULL, ";"));

        nameArray[movieCount].genre = strdup(strtok(NULL, ","));
        nameArray[movieCount].directors = strdup(strtok(NULL, ","));

        movieCount++;
    }

    fclose(file);
    free(ayirma_islemi);
    yila_gore_siralama(budgetArray, nameArray);
}

void yila_gore_siralama(struct Budget *budget, struct Name *name) {
    for (int i = 0; i < movieCount; i++) {
        int max_year = budget[i].year;
        int max_index = i;

        for (int j = i + 1; j < movieCount; j++) {
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

void genres_yazdir(struct Name *name) {
    for (int i = 0; i < movieCount; i++) {
        printf("Genre: %s\n", name[i].genre);
    }
}

void budgetleri_goster(struct Budget *budget) {
    for (int i = 0; i < movieCount; i++) {
        printf("%d: %s\n", budget[i].budget, budget[i].title);
    }
}

void film_bilgileri_detay(struct Budget *budget, struct Name *name, int index) {
    if (index >= movieCount || index < 0) {
        printf("Hatali film indeksi!\n");
        return;
    }
    printf("\nTitle: %s\n", name[index].title);
    printf("Type: %s\n", budget[index].titletype);
    printf("Genres: %s\n", name[index].genre);
    printf("Directors: %s\n", name[index].directors);
    printf("IMDB Rating: %.1lf\n", name[index].rating);
    printf("(%d Votes)\n", name[index].votes);
    printf("Top 250: %s\n", budget[index].top250);
    printf("Year: %d\n", budget[index].year);
    printf("Budget: %d\n", budget[index].budget);
    printf("Runtime: %d\n", name[index].runtime);
    printf("1001 Must See: %s\n", name[index].mustsee);
    printf("URL: %s\n", name[index].url);
}

int main() {
    verileri_al("movie.txt");
    int islem;

    while (1) {
        printf("\n1-Budget dizisinin listesi\n2-Name dizisinin listesi\n3-Genre (turlerin) listesi\n4-Yillara gore Movie (Filmlerin) Listesi\n5-Skorlara (score) gore Filmlerin Listesi\n6-Tek Bir Filmin Tum Bilgileri\n7-Cikis.\n");
        printf("Isleminizi seciniz: ");
        scanf("%d", &islem);

        switch (islem) {
            case 1:
                budgetleri_goster(budgetArray);
                break;
            case 2:
                genres_yazdir(nameArray);
                break;
            case 6:
                film_bilgileri_detay(budgetArray, nameArray, 0);
                break;
            case 7:
                printf("Cikiliyor...\n");
                return 0;
            default:
                printf("Hatali Islem!\n");
                break;
        }
    }

    return 0;
}
