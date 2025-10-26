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

void showAll(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->data << " - ";
        P = P->next;
    }
    cout << endl;
}

void updateFirst(List &L, int newData) {
    if (L.first != NULL) {
        L.first->data = newData;
        cout << "Data Berhasil Diupdate!" << endl;
    }
}

void updateLast(List &L, int newData) {
    address P = L.first;
    if (P == NULL) return;
    while (P->next != NULL) {
        P = P->next;
    }
    P->data = newData;
    cout << "Data Berhasil Diupdate!" << endl;
}

void updateAfter(List &L, int prevData, int newData) {
    address P = L.first;
    while (P != NULL && P->data != prevData) {
        P = P->next;
    }
    if (P != NULL && P->next != NULL) {
        P->next->data = newData;
        cout << "Data Berhasil Diupdate!" << endl;
    }
}

void SearchByData(List L, int dataCari) {
    address P = L.first;
    int posisi = 1;
    bool found = false;
    while (P != NULL) {
        if (P->data == dataCari) {
            cout << "Data " << dataCari << " ditemukan pada posisi ke-" << posisi << "!" << endl;
            found = true;
            break;
        }
        P = P->next;
        posisi++;
    }
    if (!found) {
        cout << "Node dengan data " << dataCari << " tidak ditemukan!" << endl;
    }
}

void SearchByAddress(List L, address nodeCari) {
    address P = L.first;
    int posisi = 1;
    bool found = false;
    while (P != NULL) {
        if (P == nodeCari) {
            cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
            cout << "Alamat node : " << P << endl;
            found = true;
            break;
        }
        P = P->next;
        posisi++;
    }
    if (!found) {
        cout << "Node dengan alamat " << nodeCari << " tidak ditemukan dalam list!" << endl;
    }
}

void SearchByRange(List L, int nilaiMin) {
    address P = L.first;
    int posisi = 1;
    cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
    while (P != NULL) {
        if (P->data > nilaiMin) {
            cout << "-----------------------------------------------" << endl;
            cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << P->data << endl;
        }
        P = P->next;
        posisi++;
    }
    cout << "-----------------------------------------------" << endl;
}

int main() {
    List L;
    createList(L);

    insertLast(L, allocate(50));
    insertLast(L, allocate(20));
    insertLast(L, allocate(25));
    insertLast(L, allocate(29));
    insertLast(L, allocate(45));

    showAll(L);
    cout << endl;

    SearchByData(L, 20);
    cout << endl;

    SearchByData(L, 55);
    cout << endl;

    address nodeA = L.first;       
    address nodeB = L.first->next; 
    SearchByAddress(L, (address)0x2748f6f3630); 
    cout << endl;

    SearchByAddress(L, nodeA->next->next->next); 
    cout << endl;

    SearchByRange(L, 40);

    return 0;
}
