/*
Listing of all Records:
The function that lists all records in the array must be given in the form below. This function prints all employee numbers (IDs) with the index numbers in the array.
void Show_All_IDs(int A[]);

sample output
-------- MENU ------------------
1--> Insert a new ID
2--> Find an ID
3--> Show all IDs
4--> Exit
Select an option (1,2,3,4) 
1
Enter the ID to be stored: 9855
The ID is inserted into the array.

-------- MENU ------------------
1--> Insert a new ID
2--> Find an ID
3--> Show all IDs
4--> Exit
Select an option (1,2,3,4) 
1
Enter the ID to be stored: 555
The ID is inserted into the array.

-------- MENU ------------------
1--> Insert a new ID
2--> Find an ID
3--> Show all IDs
4--> Exit
Select an option (1,2,3,4) 
2
Enter the ID to be found: 555
ID 555 has been found into index 56.

-------- MENU ------------------
1--> Insert a new ID
2--> Find an ID
3--> Show all IDs
4--> Exit
Select an option (1,2,3,4) 
3
The list of IDs:
A[55] = 9855
A[56] = 555

-------- MENU ------------------
1--> Insert a new ID
2--> Find an ID
3--> Show all IDs
4--> Exit
Select an option (1,2,3,4)

Note: Please compress the codes (only c/c++ code, makefile and readme.txt) before uploading and upload it to online.yildiz.edu.tr. The submission via e-mail will not be accepted.
ASSIGNMENT 2: (35 Points)

Assume that the maximum number of employees working in a company is 100 and all employees have personnel numbers (ID) between [1-9999999]. Employees' numbers (IDs) will be stored in an array of size 100. In order to accelerate the process of searching and registering employee numbers in the array, the technique described below will be applied. Complete the attached source code to develop a C program that performs this process according to the following description:

The C program must consist of functions that display menu, add record, find a specific record and list all records in the array. The elements which have not yet been assigned must be -1.

Display Menu:
The menu should be a function that produces the output given below and return a menu number
int Show_Menu();
-------- MENU ------------------
1--> Insert a new ID
2--> Find an ID
3--> Show all IDs
4--> Exit
Select an option (1,2,3,4): 
The Technique for Inserting an ID (Record):

Assume that the ID of a personnel is 15426, then

15426 % 100 = 26 will be calculated and this ID will be assigned to the 26th index of the array. If an ID has already been assigned here, 15426 will be assigned to the 27th index of the array. If 27th index is also full, then an empty space must be searched by increasing the index number and the ID must be assigned when an empty space is found. (If the 99th index is reached when searching empty space, return to the index 0 and continue to search an empty space.) If all elements of the array are full, then the program must print an output indicating that “the array is full”.

The function that adds records should be given in the form below. This function returns the index number to which the ID is assigned. It must return -2 if the array is full.
int Insert(int A[], int ID);
The Technique for Searching an ID (Record):
The function that search an ID should be given in the form below. This function returns the index number of the searched ID. If the searched ID cannot be found, it returns -2. Instead of searching all elements of the array, the function should make a search using the method described in the above insertion technique. This will make searching much faster.
int Insert(int A[], int ID);
Programming Language I – Homework
Due To: 05.08.2024 23.59

21.07.2024

If you are not a Linux user, please install Ubuntu 24.04 LTS from https://ubuntu.com/download/desktop

You can install ubuntu as a virtual machine on oracle VM VirtualBox. First install oracle virtual machine on windows or mac computer and then you can install ubuntu. Once you install ubuntu, make sure that gcc and g++ compilers are installed, if not search through internet how to install on ubuntu and install it. Please learn how to create makefile and prepare a make file for compiling c/c++ programs. Please prepare a readme.txt file that guides how to run your program. (30 Points)

ASSIGNMENT 1: (35 Points)

a) Write a C function that assigns an integer with 8 digits whose name is “numeric” to a char array A of size 9. The last element of the array consists of the null character ('\0'). The format of the function is given as:
void Numeric2Char(char A[], int numeric);
b) Write a function that takes an input as a char array A of size 9 whose first 8 elements are numbers between [0-9] and the last element is null characters ('\0'), and converts it to an integer with 8 digits. The format of the function is given as:

int Char2Numeric(char A[]);
The output of the C program using these functions is given below. Do not use any header file except stdio.h in assignment 1.
Choose an option:
To convert integer to char, press 1.
To convert char to integer, press 2.
1
Enter the numerical value with 8 digits: 20814575
The character representation: 20814575
------------------------------
Process exited after 12.66 seconds with return value 0
Press any key to continue . . .

Choose an option:
To convert integer to char, press 1.
To convert char to integer, press 2.
2
Enter the string representation with 8 characters: 33502543
The integer representation: 33502543
------------------------------
Process exited after 9.022 seconds with return value 0
Press any key to continue . . .


*/


#include <stdio.h>
#include <stdlib.h>

int Insert(int A[], int ID);
int Find(int A[], int ID);
void Show_All_IDs(int A[]);
int Show_Menu();

int main()
{
    int A[100];
    for (int i = 0; i < 100; i++)
    {
        A[i] = -1;
    }

    int choice;
    int ID;
    int index;

    while (1)
    {
        choice = Show_Menu();
        switch (choice)
        {
        case 1:
            printf("Enter the ID to be stored: ");
            scanf("%d", &ID);
            index = Insert(A, ID);
            if (index == -2)
            {
                printf("The array is full.\n");
            }
            else
            {
                printf("The ID is inserted into the array.\n");
            }
            break;
        case 2:
            printf("Enter the ID to be found: ");
            scanf("%d", &ID);
            index = Find(A, ID);
            if (index == -2)
            {
                printf("ID %d has not been found.\n", ID);
            }
            else
            {
                printf("ID %d has been found into index %d.\n", ID, index);
            }
            break;
        case 3:
            Show_All_IDs(A);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
            break;
        }
    }

    return 0;
}

int Show_Menu()
{
    int choice;
    printf("-------- MENU ------------------\n");
    printf("1--> Insert a new ID\n");
    printf("2--> Find an ID\n");
    printf("3--> Show all IDs\n");
    printf("4--> Exit\n");
    printf("Select an option (1,2,3,4): ");
    scanf("%d", &choice);
    return choice;
}

int Insert(int A[], int ID)
{
    int index = ID % 100;
    int i = 0;
    while (A[index] != -1)
    {
        index = (index + 1) % 100;
        i++;
        if (i == 100)
        {
            return -2;
        }
    }
    A[index] = ID;
    return index;
}

int Find(int A[], int ID)
{
    int index = ID % 100;
    int i = 0;
    while (A[index] != ID)
    {
        index = (index + 1) % 100;
        i++;
        if (i == 100)
        {
            return -2;
        }
    }
    return index;
}

void Show_All_IDs(int A[])
{
    printf("The list of IDs:\n");
    for (int i = 0; i < 100; i++)
    {
        if (A[i] != -1)
        {
            printf("A[%d] = %d\n", i, A[i]);
        }
    }
}

