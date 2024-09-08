#include <iostream>
#include <fstream>
//DOSYA OKUMA 

using namespace std;
int main(){
    ifstream dosya("C:\\Users\\YNS\\Desktop\\example.txt");
    string name[4];
    int numbers[4];
    int ages[4];
    int i=0;
    while(dosya){
        dosya >> name[i] >> numbers[i] >> ages[i];
        i++;
    }

    for(int j=0 ; j<4 ; j++){
    cout<<  name[j] << " " << numbers[j] << " " << ages[j] << endl;
    }

return 0;}