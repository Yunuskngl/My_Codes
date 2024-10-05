#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

#define SIZE_TABLE 8 
#define MINE_NUMBER 5

char tab[SIZE_TABLE+1][SIZE_TABLE+1];
int tabvalue[SIZE_TABLE+1][SIZE_TABLE+1];   
int row, column;
int win;

void create_mines();                   
void starting();
void after_starting();
void game_win();
void again_game();
void game_over();
int control(); 

int main() {
    starting();
    return 0;
}

void again_game() {
    int g = 0;
    printf("Would you like to play again? If so, enter 1 or enter anything else: ");
    scanf("%d", &g);
    if (g == 1) {
        starting();
    } else {
        printf("Game ended!\n");
        exit(0);
    }
}

void game_win() {
    printf("You won!\n");
    int z = 0;
    printf("1  2  3  4  5  6  7  8\n------------------------\n");
    for (int i = 1; i < SIZE_TABLE + 1; i++) {
        for (int j = 1; j < SIZE_TABLE + 1; j++) {
            if (tabvalue[i][j] == -1) {
                printf("X  ");
            } else {
                printf("%d  ", tabvalue[i][j]);
            }
        }
        z += 1;
        printf("| %d", z);
        printf("\n");
    }
    again_game();
}

void game_over() {
    printf("You lost!\n");
    int a = 0;
    printf("1  2  3  4  5  6  7  8\n------------------------\n");
    for (int i = 1; i < SIZE_TABLE + 1; i++) {
        for (int j = 1; j < SIZE_TABLE + 1; j++) {
            if (tabvalue[i][j] == -1) {
                printf("X  ");
            } else {
                printf("%d  ", tabvalue[i][j]);
            }
        }
        a += 1;
        printf("| %d", a);
        printf("\n");
    }
    again_game();
}

int control() {
    if (win == 0) { // Açılması gereken tüm hücreler açıldıysa oyun kazanılır
        game_win();
        return 1;
    }
    return 0;
}

void create_mines() {
    int v = 0;
    srand(time(0));

    while (v < MINE_NUMBER) {
        int random_row = (rand() % (SIZE_TABLE)) + 1;
        int random_column = (rand() % (SIZE_TABLE)) + 1;
        if (tabvalue[random_row][random_column] != -1) {
            tabvalue[random_row][random_column] = -1;
            v++;
        }
    }
    
    // Komşu hücrelerin değerlerini güncelle
    for (int i = 1; i < SIZE_TABLE + 1; i++) {
        for (int j = 1; j < SIZE_TABLE + 1; j++) {
            if (tabvalue[i][j] == -1) {
                for (int k = -1; k < 2; k++) {
                    for (int m = -1; m < 2; m++) {
                        if (i + k >= 1 && i + k <= SIZE_TABLE && j + m >= 1 && j + m <= SIZE_TABLE && tabvalue[i+k][j+m] != -1) {
                            tabvalue[i+k][j+m] += 1;
                        }
                    }
                }
            }
        }
    }
}

void after_starting() {
    printf("Please enter the row and the column numbers (ex: 1 1):\n");
    printf("Row: ");
    scanf("%d", &row);
    printf("Column: ");
    scanf("%d", &column);
    getchar();
    
    if ((row <= SIZE_TABLE && row >= 1) && (column <= SIZE_TABLE && column >= 1)) {
        if (tabvalue[row][column] == -1) {
            game_over();
        } else if (tab[row][column] != '#') {
            printf("Enter different dimensions!\n");
            after_starting();
        } else {
            tab[row][column] = tabvalue[row][column];
            win--; // Mayınsız hücreyi açınca win azaltılır

            // Ekrana tabloyu çizdir
            int a = 0;
            printf("1  2  3  4  5  6  7  8\n------------------------\n");
            for (int i = 1; i < SIZE_TABLE + 1; i++) {
                for (int j = 1; j < SIZE_TABLE + 1; j++) {
                    if (tab[i][j] == '#') {
                        printf("%c  ", tab[i][j]);
                    } else {
                        printf("%d  ", tab[i][j]);
                    }
                }
                a += 1;
                printf("| %d", a);
                printf("\n");
            }

            if (!control()) {
                after_starting(); // Eğer kazanç yoksa oyuna devam et
            }
        }
    }
}

void starting() {
    int a = 0;
    win = (SIZE_TABLE * SIZE_TABLE) - MINE_NUMBER; // Başlangıçta açılacak hücre sayısı
    
    printf("1  2  3  4  5  6  7  8\n------------------------\n");
    for (int i = 1; i < SIZE_TABLE + 1; i++) {
        for (int j = 1; j < SIZE_TABLE + 1; j++) {
            tab[i][j] = '#';
            printf("%c  ", tab[i][j]);
            tabvalue[i][j] = 0;
        }
        a += 1;
        printf("| %d", a);
        printf("\n");
    }
    create_mines();
    after_starting();
}
