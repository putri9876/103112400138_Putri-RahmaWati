#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <algorithm>
using namespace std;

struct Kendaraan {
    string nomorPolisi;
    string warnaKendaraan;
    int tahunPembuatan;
};

typedef Kendaraan Infotype;
typedef struct ElemenList *Address;

struct ElemenList {
    Infotype info;
    Address next;
    Address prev;
};

struct List {
    Address first;
    Address last;
};

void createList(List &L);
Address alokasi(Infotype dataBaru);
void dealokasi(Address &P);
bool isExist(List L, string nomorPolisi);
void insertLast(List &L, Address P);
void printInfo(List L);
Address findElm(List L, string nomorPolisi);

void deleteFirst(List &L, Address &P);
void deleteLast(List &L, Address &P);
void deleteAfter(Address Prec, Address &P);

#endif
