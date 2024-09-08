#include <iostream>
#include "animal.h"
using namespace std;


int main(){
    animal one , two ;
    one.name = "Tata"; one.age = 5; one.colour = "Grey" ; one.genre = "dog";
    two.name = "aa"; one.age = 2 ; one.colour = "black"; one.genre = "cat";
    one.print_info();
    two.print_info();
}