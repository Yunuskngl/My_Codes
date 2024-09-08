#include <bits/stdc++.h>
using namespace std;
char front[3][3] = {{'1', '2', '3'},
                  {'4', '5', '6'},
                  {'7', '8', '9'}};
void printFront();
void start();
int checkwin();
void whilegame();
void control();
bool isFull();

int main() {
    start();
return 0;}
void printFront() {
    for (int i = 0; i < 3; i++) {
        cout << front[i][0] << " | " << front[i][1] << " | " << front[i][2] << endl;
        cout << "----------" << endl;
    }
}
void start(){
    cout << "WELCOME TO TIC TAC TOE" << endl;
    
    printFront();
    
    cout << "Good luck!" << endl;
    whilegame();
}
int checkwin(){
    if(front[0][0] == 'X' && front[0][1] == 'X' && front[0][2] == 'X'){
        return 1;
    }
    else if(front[1][0] == 'X' && front[1][1] == 'X' && front[1][2] == 'X'){
        return 1;
    }
    else if(front[2][0] == 'X' && front[2][1] == 'X' && front[2][2] == 'X'){
        return 1;
    }
    else if(front[0][0] == 'X' && front[1][0] == 'X' && front[2][0] == 'X'){
        return 1;
    }
    else if(front[0][1] == 'X' && front[1][1] == 'X' && front[1][2] == 'X'){
        return 1;
    }
    else if(front[0][2] == 'X' && front[1][2] == 'X' && front[2][2] == 'X'){
        return 1;
    }
    else if(front[0][0] == 'X' && front[1][1] == 'X' && front[2][2] == 'X'){
        return 1;
    }
    else if(front[0][2] == 'X' && front[1][1] == 'X' && front[2][0] == 'X'){
        return 1;
    }
    else if(front[0][0] == 'O' && front[0][1] == 'O' && front[0][2] == 'O'){
        return 2;
    }
    else if(front[1][0] == 'O' && front[1][1] == 'O' && front[1][2] == 'O'){
        return 2;
    }
    else if(front[2][0] == 'O' && front[2][1] == 'O' && front[2][2] == 'O'){
        return 2;
    }
    else if(front[0][0] == 'O' && front[1][0] == 'O' && front[2][0] == 'O'){
        return 2;
    }
    else if(front[0][1] == 'O' && front[1][1] == 'O' && front[1][2] == 'O'){
        return 2;
    }
    else if(front[0][2] == 'O' && front[1][2] == 'O' && front[2][2] == 'O'){
        return 2;
    }
    else if(front[0][0] == 'O' && front[1][1] == 'O' && front[2][2] == 'O'){
        return 2;
    }
    else if(front[0][2] == 'O' && front[1][1] == 'O' && front[2][0] == 'O'){
        return 2;
    }
    return 0;
}
bool isFull() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(isdigit(front[i][j])) {
                return false;
            }
        }
    }
    return true;
}
void whilegame() {
    int player1, player2;
    while(1) {
        control();
        if (checkwin() || isFull()) break;

        cin >> player1;
        while (front[(player1-1)/3][(player1-1)%3] == 'X' || front[(player1-1)/3][(player1-1)%3] == 'O') {
            cout << "Box already taken. Choose again: ";
            cin >> player1;
        }
        front[(player1-1)/3][(player1-1)%3] = 'X';
        printFront();

        control();
        if (checkwin() || isFull()) break;

        cin >> player2;
        while (front[(player2-1)/3][(player2-1)%3] == 'X' || front[(player2-1)/3][(player2-1)%3] == 'O') {
            cout << "Box already taken. Choose again: ";
            cin >> player2;
        }
        front[(player2-1)/3][(player2-1)%3] = 'O';
        printFront();
    }
}
void control() {
    int win = checkwin();
    if(win == 1) {
        cout << "Player 1 wins!" << endl;
        exit(0);
    } else if(win == 2) {
        cout << "Player 2 wins!" << endl;
        exit(0);
    } else if(isFull()) {
        cout << "It's a tie!" << endl;
        exit(0);
    }
}

