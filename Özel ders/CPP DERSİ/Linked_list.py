class Node:
    def __init__(self, data): 
        self.data = data # Veri
        self.next = None # İleriye işaretçi

class LinkedList:
    def __init__(self): # Bağlı liste oluşturucu
        self.head = None # Bağlı listenin başlangıç noktası

    def append(self, data): # Bağlı listeye eleman ekleme
        new_node = Node(data) # Yeni bir düğüm oluştur
        if self.head is None: # Bağlı liste boşsa
            self.head = new_node # Yeni düğümü başa ekle
            return 
        last = self.head # Bağlı listenin son elemanına git
        while last.next: # Son elemanın sonraki elemanı boş olana kadar
            last = last.next # Sonraki elemana git
        last.next = new_node  # Son elemanın sonraki elemanına yeni düğümü ekle

    def print_list(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

    def delete_node(self, key): # Bağlı listeden eleman silme
        temp = self.head # Geçici değişken
        if temp is not None: # Bağlı liste boş değilse
            if temp.data == key: # İlk elemanı silme
                self.head = temp.next # İlk elemanı bir sonraki eleman yap
                temp = None # İlk elemanı sil
                return 
        while temp is not None: # Bağlı liste boş değilse
            if temp.data == key: # Silinecek elemanı bul
                break 
            prev = temp # Önceki elemanı tut
            temp = temp.next # Sonraki elemana git
        if temp is None: # Silinecek eleman bulunamazsa
            return
        prev.next = temp.next # Önceki elemanın sonraki elemanını silinecek elemanın sonraki elemanı yap
        temp = None

# Linked List oluşturma ve işlemler
llist = LinkedList()
llist.append(1)
llist.append(2)
llist.append(3)
llist.append(4)

print("Linked List: ")
llist.print_list()

print("\n3'ü sil:")
llist.delete_node(3)
llist.print_list()



