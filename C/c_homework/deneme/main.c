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

void verileri_al(const char *filename);
void yila_gore_siralama(struct Budget *budget, struct Name *name);
void oylara_gore_siralama(struct Budget *budget, struct Name *name);
void genres_yazdir(struct Name *name);
void budgetleri_goster(struct Budget *budget);
void isimleri_yazdir(struct Name *name);
void film_bilgileri_ile_genres(struct Name *name);
void film_bilgileri_detay(struct Budget *budget, struct Name *name, const char *title);
void filmleri_yila_gore_listele(struct Budget *budget, struct Name *name);
void skorlara_gore_filmler(struct Name *name);
void tur_frekansi(struct Name *name);

void verileri_al(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Dosya bulunamadi!\nCikiliyor..\n");
        exit(1);
    }

    int movieIndex = 0;
    char *ayirma_islemi = (char *)malloc(sizeof(char) * UZUNLUK);

    while (fgets(ayirma_islemi, UZUNLUK, file) != NULL) {
        if (movieIndex >= DOSYA_BOYUTU) {
            printf("Exceeded the maximum number of movies.\n");
            break;
        }

        char *token;

        token = strtok(ayirma_islemi, ";");
        if (token != NULL) {
            budgetArray[movieIndex].budget = atoi(token);
        }

        token = strtok(NULL, ";");
        if (token != NULL) {
            budgetArray[movieIndex].title = (char *)malloc(strlen(token) + 1);
            strcpy(budgetArray[movieIndex].title, token);
        }

        token = strtok(NULL, ";");
        if (token != NULL) {
            nameArray[movieIndex].title = (char *)malloc(strlen(token) + 1);
            strcpy(nameArray[movieIndex].title, budgetArray[movieIndex].title);
        }

        token = strtok(NULL, ";");
        if (token != NULL) {
            budgetArray[movieIndex].titletype = (char *)malloc(strlen(token) + 1);
            strcpy(budgetArray[movieIndex].titletype, token);
        }

        token = strtok(NULL, ";");
        if (token != NULL) {
            nameArray[movieIndex].rating = atof(token);
        }

        token = strtok(NULL, ";");
        if (token != NULL) {
            nameArray[movieIndex].runtime = atoi(token);
        }

        token = strtok(NULL, ";");
        if (token != NULL) {
            budgetArray[movieIndex].year = atoi(token);
        }

        token = strtok(NULL, ";");
        if (token != NULL) {
            nameArray[movieIndex].votes = atoi(token);
        }

        token = strtok(NULL, ";");
        if (token != NULL) {
            budgetArray[movieIndex].top250 = (char *)malloc(strlen(token) + 1);
            strcpy(budgetArray[movieIndex].top250, token);
        }

        token = strtok(NULL, ";");
        if (token != NULL) {
            nameArray[movieIndex].mustsee = (char *)malloc(strlen(token) + 1);
            strcpy(nameArray[movieIndex].mustsee, token);
        }

        token = strtok(NULL, ";");
        if (token != NULL) {
            nameArray[movieIndex].url = (char *)malloc(strlen(token) + 1);
            strcpy(nameArray[movieIndex].url, token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            nameArray[movieIndex].genre = (char *)malloc(strlen(token) + 1);
            strcpy(nameArray[movieIndex].genre, token);
        }

        token = strtok(NULL, ",");
        if (token != NULL) {
            nameArray[movieIndex].directors = (char *)malloc(strlen(token) + 1);
            strcpy(nameArray[movieIndex].directors, token);
        }

        movieIndex++;
    }

    fclose(file);
    free(ayirma_islemi);
}

void yila_gore_siralama(struct Budget *budget, struct Name *name) {
    for (int i = 0; i < DOSYA_BOYUTU; i++) {
        int max_year = budget[i].year;
        int max_index = i;

        for (int j = i + 1; j < DOSYA_BOYUTU; j++) {
            if (budget[j].year < max_year) {
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
    for (int i = 0; i < DOSYA_BOYUTU; i++) {
        int max_votes = name[i].votes;
        int max_index = i;

        for (int j = i + 1; j < DOSYA_BOYUTU; j++) {
            if (name[j].votes > max_votes) {
                max_votes = name[j].votes;
                max_index = j;
            }
        }

        struct Budget tempBudget = budget[i];
        struct Name tempName = name[i];

        budget[i] = budget[max_index];
        name[i] = name[max_index];

        budget[max_index] = tempBudget;
        name[max_index] = tempName;
    }

    for (int i = 0; i < DOSYA_BOYUTU; i++) {
        if (name[i].votes == 0) continue;
        printf("%d (votes): %s\n", name[i].votes, name[i].title);
    }
}

void genres_yazdir(struct Name *name) {
    for (int i = 0; i < DOSYA_BOYUTU; i++) {
        if (name[i].genre != NULL && strlen(name[i].genre) > 0) {
            printf("%s: %s\n", name[i].title, name[i].genre);
        }
    }
}

void budgetleri_goster(struct Budget *budget) {
    for (int i = 0; i < DOSYA_BOYUTU; i++) {
        printf("%d: %s\n", budget[i].budget, budget[i].title);
    }
}

void isimleri_yazdir(struct Name *name) {
    for (int i = 0; i < DOSYA_BOYUTU; i++) {
        printf("%s\n", name[i].title);
    }
}

void filmleri_yila_gore_listele(struct Budget *budget, struct Name *name) {
    yila_gore_siralama(budget, name);
    for (int i = 0; i < DOSYA_BOYUTU; i++) {
        printf("%d: %s\n", budget[i].year, name[i].title);
    }
}

void skorlara_gore_filmler(struct Name *name) {
    for (int i = 0; i < DOSYA_BOYUTU; i++) {
        printf("%.1lf: %s (%d)\n", name[i].rating, name[i].title, budgetArray[i].year);
    }
}

void film_bilgileri_detay(struct Budget *budget, struct Name *name, const char *title) {
    for (int i = 0; i < DOSYA_BOYUTU; i++) {
        if (strcmp(name[i].title, title) == 0) {
            printf("\nTitle: %s\n", name[i].title);
            printf("Type: %s\n", budget[i].titletype);
            printf("Genres: %s\n", name[i].genre);
            printf("Directors: %s\n", name[i].directors);
            printf("IMDB Rating: %.1lf\n", name[i].rating);
            printf("(%d Votes)\n", name[i].votes);
            printf("Top 250: %s\n", budget[i].top250);
            printf("Year: %d\n", budget[i].year);
            printf("Budget: %d\n", budget[i].budget);
            printf("Runtime: %d\n", name[i].runtime);
            printf("1001 Must See: %s\n", name[i].mustsee);
            printf("URL: %s\n", name[i].url);
            return;
        }
    }
    printf("Film bulunamadi.\n");
}

void tur_frekansi(struct Name *name) {
    int genreCount[DOSYA_BOYUTU] = {0}; 
    char *genres[DOSYA_BOYUTU]; 
    int genreIndex = 0;

    for (int i = 0; i < DOSYA_BOYUTU; i++) {
        char *token = strtok(name[i].genre, ","); // Türleri virgüle göre ayır
        while (token != NULL) {
            int exists = 0;
            for (int j = 0; j < genreIndex; j++) {
                if (strcmp(token, genres[j]) == 0) {
                    genreCount[j]++;
                    exists = 1;
                    break;
                }
            }
            if (!exists) {
                genres[genreIndex] = token; // Yeni bir tür ekleniyor
                genreCount[genreIndex]++;
                genreIndex++;
            }
            token = strtok(NULL, ","); // Bir sonraki türü kontrol et
        }
    }

    // Türleri ve frekanslarını yazdır
    for (int i = 0; i < genreIndex; i++) {
        printf("Genre: %s, Count: %d\n", genres[i], genreCount[i]);
    }
}


int main() {
    verileri_al("movie.txt"); 
    int islem;

    while (1) {
        printf("\n1-Budget dizisinin listesi\n2-Name dizisinin listesi\n3-Genre (turlerin) listesi\n4-Yillara gore Movie (Filmlerin) Listesi\n5-Skorlara (score) gore Filmlerin Listesi\n6-Tek Bir Filmin Tum Bilgileri\n7-Turlerin Frekansi (sikligi)\n8-Cikis.\n");
        printf("Isleminizi seciniz (1-8): ");

        if (scanf("%d", &islem) != 1) {
            printf("Gecersiz secim!\n");
            while (getchar() != '\n');
            continue;
        }

        switch (islem) {
            case 1:
                budgetleri_goster(budgetArray);
                break;
            case 2:
                isimleri_yazdir(nameArray);
                break;
            case 3:
                genres_yazdir(nameArray);
                break;
            case 4:
                filmleri_yila_gore_listele(budgetArray, nameArray);
                break;
            case 5:
                skorlara_gore_filmler(nameArray);
                break;
            case 6: {
                char filmTitle[UZUNLUK];
                printf("Detaylarini gormek istediginiz filmin ismini giriniz: ");
                getchar(); // Boşluk karakterini temizlemek için
                fgets(filmTitle, UZUNLUK, stdin);
                filmTitle[strcspn(filmTitle, "\n")] = '\0'; // newline karakterini sil
                film_bilgileri_detay(budgetArray, nameArray, filmTitle);
                break;
            }
            case 7:
                tur_frekansi(nameArray);
                break;
            case 8:
                printf("Cikiliyor...\n");
                return 0;
            default:
                printf("Hatali Islem!\n");
                break;
        }
    }

    return 0;
}
