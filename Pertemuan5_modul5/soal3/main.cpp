#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* address;
struct List {
    address first;
};

void createList(List &L) {
    L.first = NULL;
}

address allocate(int dataBaru) {
    address P = new Node;
    P->data = dataBaru;
    P->next = NULL;
    return P;
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}


void totalPenjumlahan(List L) {
    int total = 0;
    address P = L.first;
    while (P != NULL) {
        total += P->data;
        P = P->next;
    }
    cout << "Total penjumlahan : " << total << endl;
}

void totalPengurangan(List L) {
    if (L.first == NULL) return;
    int total = L.first->data;
    address P = L.first->next;
    while (P != NULL) {
        total -= P->data;
        P = P->next;
    }
    cout << "\nTotal pengurangan : " << total << endl;
}

void totalPerkalian(List L) {
    int total = 1;
    address P = L.first;
    while (P != NULL) {
        total *= P->data;
        P = P->next;
    }
    cout << "\nTotal perkalian : " << total << endl;
}

int main() {
    List L;
    createList(L);

    insertLast(L, allocate(50));
    insertLast(L, allocate(20));
    insertLast(L, allocate(25));
    insertLast(L, allocate(29));
    insertLast(L, allocate(45));
 
    totalPenjumlahan(L);
    totalPengurangan(L);
    totalPerkalian(L);

    return 0;
}
