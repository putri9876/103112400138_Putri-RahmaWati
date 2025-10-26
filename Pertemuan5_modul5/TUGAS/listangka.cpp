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
