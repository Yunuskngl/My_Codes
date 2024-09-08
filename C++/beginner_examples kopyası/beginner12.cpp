#include <iostream>

using namespace std;

class human{
    public:
    string name;
    int age;

    void print_information(){
        cout << name << " / " << age;
    }
};

int main(){
    human h1,h2;
    h1.name = "Yunus";h2.name = "Zeynep";
    h1.age = 20; h2.age = 20;
    h1.print_information();
    cout << endl;
    h2.print_information();
}