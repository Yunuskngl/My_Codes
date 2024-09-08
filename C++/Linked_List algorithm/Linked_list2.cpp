#include <iostream>
using namespace std;

class Node{
    public:
    Node(const int& data = 0,Node* next = NULL) : data(data),next(next){ }
    int data;
    Node* next;
};
 
class list{
    Node* root;
    public : 
        list() : root(NULL){   }
        Node* begin()const{ return root;   }
        Node* end()const{ return NULL;     }
        //bool isEmpty()const{ return root==NULL; }
        bool isEmpty()const{return begin() == end(); }
        void push_back(const int& value){
            if(isEmpty()){
                root = new Node(value);
            }
            else{
                Node* temp = begin();
                while(temp->next != end()){
                    temp = temp ->next;
                }
                temp ->next = new Node(value);
            }
        }
        void push_front(const int &value){
            Node* temp = new Node(value);
            temp ->next = root;
            root = temp;

        }
        void print(){
            Node* temp = begin();
            while(temp !=  end()){
            cout << temp->data << " ";
            temp = temp->next;
            }
        }
        int front()const{
            if(isEmpty())
                throw "404";
            return begin()->data;
        }
        int back()const{
            if(isEmpty()) 
                throw "404";
            Node* temp = begin();
            while(temp->next != end()){
                temp = temp ->next;
            }
            return temp ->data;
        }
        void pop_back(){
        if(isEmpty()) throw "404";
        if(begin()->next == end()){
        delete root;
        root = NULL;
        }
        else{
        Node* temp = begin();
        while(temp->next->next != end()){
            temp = temp->next;
        }
        delete temp->next;
        temp->next = end();
            }
        }
        void pop_front(){
            if(isEmpty()) throw "404";
            Node* temp = root;
            root = temp->next;
            delete temp;

        }
};

int main(){
    list L;
    cout << L.isEmpty() << endl ; // boş ise 1 değerini döndürür.
    L.push_back(5);
    cout << L.isEmpty() << endl ;// dolu ise 0 değerini döndürür
    L.push_back(10);
    L.push_back(3);
    L.push_front(25); //en ön sıraya ekleme yapar.
    L.print();
    cout << endl;
    cout << L.front(); // baştaki elemanı verir.
    cout << endl;
    cout << L.back();//sondaki elemanı verir.
    cout << endl; 
    L.print();
    cout << endl;
    L.pop_back();//sondaki elemanı siler.
    L.print();
    L.pop_front();//baştaki elemanı siler.
    cout << endl;
    L.print();
    

    

return 0;} 