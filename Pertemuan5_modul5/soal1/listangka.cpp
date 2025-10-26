#include "listangka.h"

void createList(linkedList &L) {
    L.first = NULL;
}

address alokasi(dataAngka x) {
    address p = new node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = NULL;
}

void printList(linkedList L) {
    address p = L.first;
    while (p != NULL) {
        cout << p->angka << " - ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(linkedList &L, address p) {
    p->next = L.first;
    L.first = p;
}

void insertLast(linkedList &L, address p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void insertAfter(linkedList &L, address p, address prec) {
    if (prec != NULL) {
        p->next = prec->next;
        prec->next = p;
    }
}

int nbList(linkedList L) {
    int count = 0;
    address p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void delAfter(linkedList &L, address &p, address prec) {
    if (prec != NULL && prec->next != NULL) {
        p = prec->next;
        prec->next = p->next;
        dealokasi(p);
    }
}

void updateFirst(linkedList &L) {
    if (L.first != NULL) {
        cout << "Masukkan update data node pertama :" << endl;
        cout << "masukkan angka : ";
        cin >> L.first->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.first != NULL) {
        address p = L.first;
        while (p->next != NULL) {
            p = p->next;
        }
        cout << "masukkan update data node terakhir :" << endl;
        cout << "Masukkan angka : ";
        cin >> p->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateAfter(linkedList &L, address prec) {
    if (prec != NULL && prec->next != NULL) {
        cout << "masukkan update data node setelah node " << prec->angka << " :" << endl;
        cout << "Masukkan angka : ";
        cin >> prec->next->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}
