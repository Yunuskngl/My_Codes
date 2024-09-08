#include <iostream> 

using namespace std; 

// kullanıcı sistemi 

int main(){
    string email = "yunuskanngal@gmail.com";
    string şifre = "a";
    string kontrolemail ; 
    string kontrolşifre; 

    cout << "enter your email : " << endl;
    cin >> kontrolemail; 
    cout << "enter your password : " << endl;
    cin >> şifre; 

    if(kontrolemail == email && kontrolşifre == şifre ) cout << "Succesfull" << endl; 
    else if (kontrolemail == email || kontrolşifre == şifre ) {
        if(kontrolemail != email){
            cout <<  "wrong email" << endl;
        }
        else{
            cout  << "wrong password" << endl;
        }
    }
    else{
        cout << "check your email and password" << endl; 
    }
return 0 ;

}