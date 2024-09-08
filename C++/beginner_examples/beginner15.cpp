#include <iostream>
using namespace std;

class A{
    public:     // her yerden erişilebilir.
    int a;
};
class B{
    protected:  //ya D classına kalıtım yapıldığı için D den erişilir ya da kendi içinden erişim yapılabilir.
    int b;

};
class C{
    private:    // Sadece kendi içinden erişim sağlanır.
    int c;
    public:
    void setc(int girilcekc){
        c = girilcekc;
    }
    void getc(){
        cout << c << endl;
    }

};
class D:public A , public B , public C{
    public:
    D(){
        b=20;
    }
    void getb(){
        cout<< b << endl;
    }

};


int main(){
    D example;
    example.a = 10;
    cout << example.a << endl;
    example.getb();
    example.setc(30);
    example.getc();

}