#include <iostream> 
using namespace std;

class student{
    private: 
    string name;
    int age; 
    int number;

    public: 
    
    void setname(string enteredname){   
        
        name = enteredname; 
    }
    void setage(int enteredage){
        age = enteredage;
    }
    void setnumber(int enterednumber){
        number = enterednumber;
    }
    void print_information(){
        cout<<name<<" "<< age << " " << number << endl; 
    }
};

int main(){
    student s1;
    s1.setname("Yunus");
    s1.setage(20);
    s1.setnumber(21052100);
    s1.print_information();

}