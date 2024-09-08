#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

// Show_Menu function: Displays the menu and returns the user's choice
int Show_Menu() {
    int option;
    printf("-------- MENU ------------------\n");
    printf("1--> Insert a new ID\n");
    printf("2--> Find an ID\n");
    printf("3--> Show all IDs\n");
    printf("4--> Exit\n");
    printf("Select an option (1,2,3,4): ");
    scanf("%d", &option);
    return option;
}

// Insert function: Inserts a new ID into the array and returns the index
int Insert(int A[], int ID) {
    int index = ID % ARRAY_SIZE;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int try_index = (index + i) % ARRAY_SIZE;
        if (A[try_index] == -1) {
            A[try_index] = ID;
            return try_index;
        }
    }
    return -2; // Array is full
}

// Find function: Finds an ID in the array and returns the index
int Find(int A[], int ID) {
    int index = ID % ARRAY_SIZE;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        int try_index = (index + i) % ARRAY_SIZE;
        if (A[try_index] == ID) {
            return try_index;
        } else if (A[try_index] == -1) {
            return -2; // ID not found
        }
    }
    return -2; // ID not found
}

// Show_All_IDs function: Displays all IDs in the array with their indices
void Show_All_IDs(int A[]) {
    printf("The list of IDs:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (A[i] != -1) {
            printf("A[%d] = %d\n", i, A[i]);
        }
    }
}

// Numeric2Char function: Converts an integer to a char array
void Numeric2Char(char A[], int numeric) {
    sprintf(A, "%08d", numeric);
}

// Char2Numeric function: Converts a char array to an integer
int Char2Numeric(char A[]) {
    return atoi(A);
}

int main() {
    int A[ARRAY_SIZE];
    for (int i = 0; i < ARRAY_SIZE; i++) {
        A[i] = -1; // Initialize array
    }
    
    while (1) {
        int option = Show_Menu();
        if (option == 1) {
            int ID;
            printf("Enter the ID to be stored: ");
            scanf("%d", &ID);
            int result = Insert(A, ID);
            if (result == -2) {
                printf("The array is full.\n");
            } else {
                printf("The ID is inserted into index %d.\n", result);
            }
        } else if (option == 2) {
            int ID;
            printf("Enter the ID to be found: ");
            scanf("%d", &ID);
            int result = Find(A, ID);
            if (result == -2) {
                printf("ID %d has not been found.\n", ID);
            } else {
                printf("ID %d has been found into index %d.\n", ID, result);
            }
        } else if (option == 3) {
            Show_All_IDs(A);
        } else if (option == 4) {
            break;
        }
    }

    // Test the Numeric2Char and Char2Numeric functions
    char charArray[9];
    int numeric = 20814575;
    Numeric2Char(charArray, numeric);
    printf("Character representation: %s\n", charArray);
    
    char charArray2[9] = "33502543";
    int numeric2 = Char2Numeric(charArray2);
    printf("Integer representation: %d\n", numeric2);

    return 0;
}
