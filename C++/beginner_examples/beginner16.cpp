// INHERITANCE 
#include <iostream>
using namespace std;

class Team{
    public:
    string team_name;
    int team_year;

};

class FPlayer:public Team{
    private: 
    string Name;
    public : 
    int salary;
    int age;

    void setName(string Name){
        this -> Name = Name;
    }
    string getName(){
        return Name;
    }
};

int main(){
    FPlayer one; 
    one.team_name = "REAL MADRID";
    one.setName("ARDA GULER");
    one.age = 18;
    one.salary = 1000000;
    cout << one.getName() << " " << one.team_name << " " << one.age << " " <<  one.salary << endl;

}