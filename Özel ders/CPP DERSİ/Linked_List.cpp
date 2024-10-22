#include <iostream>
using namespace std;

class Node {
public:
    int data; // Veri 
    Node* next; // İleriye doğru işaretçi

    Node(int data) {  // Yapıcı fonksiyon
        this->data = data; // Veriyi ata
        this->next = nullptr; // İleriye doğru işaretçiyi nullptr yap
    }
};

class LinkedList { // Bağlı liste sınıfı
public:
    Node* head; // Başlangıç düğümü

    LinkedList() { // Yapıcı fonksiyon
        head = nullptr; // Başlangıç düğümünü nullptr yap
    }

    // Listeye eleman ekleme
    void append(int data) { // Veri al 
        Node* new_node = new Node(data); // Yeni düğüm oluştur
        if (head == nullptr) { // Eğer başlangıç düğümü yoksa
            head = new_node; // Yeni düğümü başlangıç düğümü yap
            return;
        }
        Node* last = head; // Son düğümü bul
        while (last->next != nullptr) { // Son düğümün sonraki düğümü nullptr olana kadar
            last = last->next; // Sonraki düğüme git
        }
        last->next = new_node; // Son düğümün sonraki düğümüne yeni düğümü ekle
    }

    // Listeyi yazdırma
    void printList() {
        Node* current = head; // Başlangıç düğümünden başla
        while (current != nullptr) { // Düğüm nullptr olana kadar
            cout << current->data << " -> "; // Düğümün verisini yazdır
            current = current->next; // Sonraki düğüme git
        }
        cout << "nullptr" << endl; // nullptr yazdır
    }

    // Belirtilen düğümü silme
    void deleteNode(int key) { // Silinecek düğümün verisini al
        Node* temp = head; // Başlangıç düğümünden başla
        Node* prev = nullptr; // Önceki düğümü tutan işaretçi

        if (temp != nullptr && temp->data == key) { // Eğer başlangıç düğümü silinecek düğümse
            head = temp->next; // Başlangıç düğümünü sonraki düğüm yap
            delete temp; // Sil
            return; 
        }

        while (temp != nullptr && temp->data != key) {  // Silinecek düğümü bul
            prev = temp; // Önceki düğümü güncelle
            temp = temp->next;  // Sonraki düğüme git
        }

        if (temp == nullptr) return;    // Eğer düğüm bulunamadıysa

        prev->next = temp->next;    // Önceki düğümün sonraki düğümünü silinecek düğümün sonraki düğümü yap
        delete temp;    // Sil
    }
};

int main() {
    LinkedList list;

    // Linked List'e eleman ekleme
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);

    cout << "Linked List: " << endl;
    list.printList();

    cout << "\n3'ü sil: " << endl;
    list.deleteNode(3);
    list.printList();

    return 0;
}
