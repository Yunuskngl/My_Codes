//prime number kontrolü 1- n e kadar hangi sayılar prime number onu bulcaz
//n kullanıcdan alıncak. diyelim ki n =100 ise 1 den 100 e kadar asal sayıları bulcaz.
//kendisi veya 1 sayısı haricinde diğer hiç bi sayıya bölünmicek.


#include <iostream>
using namespace std;

int main(){
    int n ;
    cout<< "enter num" << endl;
    cin >> n;

    cout << "prime numbers : " << endl;
    

    for(int num = 2 ; num <= n ; num++){

        bool flag = true;  // flag = bayrak . 

        for(int i = 2; i <=num /2 ; i++){
            if (num %i == 0){                    
                flag = false;
                break;
            }
        }

        if (flag){
            cout << num << " " ;  
        }
    }
    return 0; 
}