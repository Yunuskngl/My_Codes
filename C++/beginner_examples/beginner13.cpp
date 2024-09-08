#include <iostream> 
using namespace std;

//ENCAPSULATİON YÖNTEMİ 


class student{
    private: // eğer private yaparsak içindeki bilgilere erişemeyiz.
    string name;
    int age; 
    int number;

    public: 
    /*eğer bu class içinde private kullansak bile içine değer atamak
    istiyorsak public açıp bu aşağıdaki fonksiyon bloklarında olduğu gibi 
    */
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
    student one;
    one.setname("Yunus");
    one.setage(20);
    one.setnumber(21052100);
    one.print_information();

}