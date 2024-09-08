#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE_TABLE 8 
#define MINE_NUMBER 5

char tab[SIZE_TABLE+2][SIZE_TABLE+2];
int tabvalue[SIZE_TABLE+2][SIZE_TABLE+2];    // global variables
int row,column;
int nb_mine;
int win=0;
int howmany;

int control();
void create_mines();                      
void starting();
void after_starting();
void game_win();
void again_game();
void game_over();
void game_continue();

int main(){
    printf("WELCOME TO MY MINESWEEPER GAME: ");
	puts("");
    starting();
    after_starting();
return 0;}


void create_mines(){
    int i,j,a,b,k,p;
	for(i=1;i<=SIZE_TABLE+1;i++){
		for(j=1;j<=SIZE_TABLE+1;j++){
			tabvalue[i][j] = 0;
        }
    }
    srand(time(0));                
    for(int i = 0;i<MINE_NUMBER;i++){
        a = 1+rand()%SIZE_TABLE;
        b = 1+rand()%SIZE_TABLE;
        tabvalue[a][b] = -1;
    }
	for(int i = 1;i<=SIZE_TABLE;i++){
        for(j = 1;j<=SIZE_TABLE;j++){
            if(tabvalue[i][j]==-1){
				for(k = -1;k<2;k++){
					for(p = -1;p<2;p++){
						if(tabvalue[i+k][j+p]!=-1){
                            tabvalue[i+k][j+p]++;     
                        }
            		}
				}
			}
		}
    } 
}


void starting(){
    int i,j;
	puts("");
	for(i=1;i<=SIZE_TABLE;i++){
		printf("%d  ",i);
	}
	puts("");
    for(i=1;i<=SIZE_TABLE;i++){
		printf("---");
	}
	puts("");
    for(i=1;i<=SIZE_TABLE+1;i++){
		for(j=1;j<=SIZE_TABLE+1;j++){
			tab[i][j] = '#';
		}
    }
	for(i=1;i<=SIZE_TABLE;i++){
		for(j=1;j<=SIZE_TABLE;j++)
		{
			printf("%c  ",tab[i][j]);
		}
		printf(" |%d",i);	
		puts("");
	}
	for(i=1;i<=SIZE_TABLE;i++){
		printf("___");
	}
    create_mines();
}


void after_starting(){
    int flag = 0,i;
	win = control(); 
    do{
        printf("\nPLEASE ENTER VALUE LIKE THIS (column,row) (2,2 or 4 6):\n");
        scanf("%d,%d",&row,&column); fflush(stdin);
        if(tabvalue[column][row] == -1){
            game_over();
            flag = 1;        
            break;        
        }        
        else if(win == 5 ){
            game_win();
            break;
        }
        else{
            game_continue();
            continue;
        }
    }while(flag == 1);
}


int control(){
    int i,j ; 
	int flag1 = 64;
    for(i=1;i<=SIZE_TABLE+1;i++){
		for(j=1;j<=SIZE_TABLE+1;j++){
            if(tab[i][j] != '#'){
                flag1--;
            }
        }
    }
    return flag1;
}


void game_win(){
    int i,j;
    puts("");
	for(i=1;i<=SIZE_TABLE;i++){
		printf("%d  ",i);
	}
	puts("");
	for(i=1;i<=SIZE_TABLE;i++){
		printf("---");
	}
	puts("");
	for(i=1;i<=SIZE_TABLE;i++){
		for(j=1;j<=SIZE_TABLE;j++){
            if(tabvalue[i][j] == -1) printf("X  ");
            else printf("%d  ",tabvalue[i][j]);
		}
		printf(" |%d",i);	
		puts("");
	}
	for(i=1;i<=SIZE_TABLE;i++){
		printf("___");
	}
    puts("");
	printf("!!!!YOU WIN!!!!");
	puts("");
	puts("");
	again_game();
}


void again_game(){
	int again;
	int flag2 = 0;
    do{
		printf("DO YOU WANT TO PLAY AGAIN:\n(ENTER '1':YES , ENTER '0':NO)\n");
		scanf("%d",&again);
		if(again == 1){
			puts("");puts("");
			flag2 = 1;
			printf("WELCOME TO MY MINESWEEPER GAME: \n");
        	starting();
    		after_starting();

		}
		else if(again == 0){
			flag2 = 1;
			printf("THANK YOU FOR PLAY.");
			break;
		}
		else{
			printf("PLEASE ENTER 1 OR 0 FOR VALID VALUE.");
			continue;
		}
	}while (flag2 == 1);
}


void game_over(){
    int i,j;
    puts("");
	for(i=1;i<=SIZE_TABLE;i++){
		printf("%d  ",i);
	}
	puts("");
	for(i=1;i<=SIZE_TABLE;i++){
		printf("---");
	}
	puts("");
	for(i=1;i<=SIZE_TABLE;i++){
		for(j=1;j<=SIZE_TABLE;j++){
            if(tabvalue[i][j] == -1) printf("X  ");
            else printf("%d  ",tabvalue[i][j]);
		}
		printf(" |%d",i);	
		puts("");
	}
	for(i=1;i<=SIZE_TABLE;i++){
		printf("___");
	}
    puts("");
    printf("!!!GAME OVER!!!");
	puts("");
	puts("");
	again_game();
}


void game_continue(){
    int i,j,a,b;
    tab[row][column]=tabvalue[row][column] ;
    srand(time(0));
    howmany = 1 + rand()%10;
    for(int k = 0 ; k<howmany ; k++){
        a = 1+rand()%8;
        b = 1+rand()%8;
        if(tabvalue[a][b] != -1)  tab[a][b]=tabvalue[a][b] ;
    }
    puts("");
	for(i=1;i<=SIZE_TABLE;i++){
		printf("%d  ",i);
	}
	puts("");
	for(i=1;i<=SIZE_TABLE;i++){
		printf("---");
	}
	puts("");
	for(i=1;i<=SIZE_TABLE;i++){
		for(j=1;j<=SIZE_TABLE;j++){
            if(tab[i][j] == '#')       printf("%c  ",tab[i][j]);
            else if(tab[i][j] == -1)   printf("X  ");
            else                       printf("%d  ",tab[i][j]);
        }
		printf(" |%d",i);	
		puts("");
	}
	for(i=1;i<=SIZE_TABLE;i++){
		printf("___");
	}
    after_starting();
}