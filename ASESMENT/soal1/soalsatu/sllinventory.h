#ifndef SLLINVENTORY_H
#define SLLINVENTORY_H

#include <string>
using namespace std;

struct Product {
    string Nama;
    string SKU;
    int Jumlah;
    float HargaSatuan;
    float DiskonPersen;
};

struct Node;
typedef Node* address;

struct Node {
    Product info;
    address next;
};

struct List {
    address head;
};

void createList(List &L);
bool isEmpty(List L);
address allocate(Product P);
void deallocate(address P);

void insertFirst(List &L, Product P);
void insertLast(List &L, Product P);
void insertAfter(List &L, address Q, Product P);

void deleteFirst(List &L, Product &P);
void deleteLast(List &L, Product &P);
void deleteAfter(List &L, address Q, Product &P);

void updateAtPosition(List &L, int posisi, Product dataBaru);
void viewList(List L);
void searchByFinalPriceRange(List L, float minPrice, float maxPrice);

void MaxHargaAkhir(List L);

#endif
