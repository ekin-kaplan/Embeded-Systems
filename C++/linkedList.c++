#include <iostream>
using namespace std;

// Node sınıfını tanımla
class Node
{
public:
    int data;   // Veri kısmı
    Node *next; // Sonraki düğüme işaretçi

    // Node oluşturucu
    Node(int value) : data(value), next(nullptr) {}
};

// LinkedList sınıfını tanımla
class LinkedList
{
private:
    Node *head; // Başlangıç düğümüne işaretçi

public:
    // Yapıcı: Başlangıçta liste boş
    LinkedList() : head(nullptr) {}

    // Yeni bir düğümü listenin sonuna ekle
    void insertEnd(int value)
    {
        Node *newNode = new Node(value); // Yeni düğüm oluştur
        if (head == nullptr)
        {
            head = newNode; // Liste boşsa, yeni düğüm baş düğüm olur
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next; // Listenin sonuna kadar ilerle
        }
        temp->next = newNode; // Yeni düğümü sona ekle
    }

    // Listeyi yazdır
    void printList() const
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> "; // Mevcut düğümün verisini yazdır
            temp = temp->next;            // Sonraki düğüme geç
        }
        cout << "NULL" << endl; // Listenin sonunu belirt
    }

    // Yıkıcı: Tüm düğümleri serbest bırak
    ~LinkedList()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            Node *nextNode = temp->next;
            delete temp; // Düğümü serbest bırak
            temp = nextNode;
        }
    }
};

// Main fonksiyonu, bağlantılı listeyi test etmek için
int main()
{
    LinkedList list; // Yeni bir bağlantılı liste oluştur

    // Listeye düğümler ekle
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertEnd(30);
    list.insertEnd(40);

    // Listeyi yazdır
    list.printList();

    return 0;
}
