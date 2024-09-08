#include <iostream>
#include <string>
using namespace std;

//string ve char tipinde dizilerin farkı
int main(){
    char isimler[3][20] = {{"ali"} , {"veli"} , {"mehmet"}};
    string isimler2[3] = {"ali", "veli","mehmet"};

    cout << isimler[0] << endl;
    cout << isimler2[1] << endl;
    return 0;
}