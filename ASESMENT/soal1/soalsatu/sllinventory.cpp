#include <iostream>
#include "SLLInventory.h"
using namespace std;

void createList(List &L) {
    L.head = NULL;
}

bool isEmpty(List L) {
    return (L.head == NULL);
}

address allocate(Product P) {
    address N = new Node;
    N->info = P;
    N->next = NULL;
    return N;
}

void deallocate(address P) {
    delete P;
}

void insertFirst(List &L, Product P) {
    address N = allocate(P);
    N->next = L.head;
    L.head = N;
}

void insertLast(List &L, Product P) {
    address N = allocate(P);
    if (isEmpty(L)) {
        L.head = N;
    } else {
        address temp = L.head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = N;
    }
}

void insertAfter(List &L, address Q, Product P) {
    if (Q != NULL) {
        address N = allocate(P);
        N->next = Q->next;
        Q->next = N;
    }
}

void deleteFirst(List &L, Product &P) {
    if (!isEmpty(L)) {
        address temp = L.head;
        P = temp->info;
        L.head = temp->next;
        deallocate(temp);
    }
}

void deleteLast(List &L, Product &P) {
    if (!isEmpty(L)) {
        address temp = L.head;
        address prev = NULL;

        while (temp->next != NULL) {
            prev = temp;
            temp = temp->next;
        }

        P = temp->info;

        if (prev == NULL) {
            L.head = NULL;
        } else {
            prev->next = NULL;
        }

        deallocate(temp);
    }
}

void deleteAfter(List &L, address Q, Product &P) {
    if (Q != NULL && Q->next != NULL) {
        address temp = Q->next;
        P = temp->info;
        Q->next = temp->next;
        deallocate(temp);
    }
}

void updateAtPosition(List &L, int posisi, Product dataBaru) {
    address temp = L.head;
    int idx = 1;

    while (temp != NULL && idx < posisi) {
        temp = temp->next;
        idx++;
    }

    if (temp != NULL) {
        temp->info = dataBaru;
    }
}

float hargaAkhir(Product P) {
    return P.HargaSatuan * (1 - (P.DiskonPersen / 100));
}

void viewList(List L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    address temp = L.head;
    int idx = 1;

    while (temp != NULL) {
        cout << idx << ". " 
             << temp->info.Nama
             << " | SKU: " << temp->info.SKU
             << " | Jumlah: " << temp->info.Jumlah
             << " | Harga Satuan: " << temp->info.HargaSatuan
             << " | Diskon: " << temp->info.DiskonPersen
             << "% | Harga Akhir: " << hargaAkhir(temp->info)
             << endl;

        temp = temp->next;
        idx++;
    }
}

void searchByFinalPriceRange(List L, float minPrice, float maxPrice) {
    address temp = L.head;
    int idx = 1;
    bool found = false;

    while (temp != NULL) {
        float h = hargaAkhir(temp->info);
        if (h >= minPrice && h <= maxPrice) {
            cout << idx << ". " << temp->info.Nama
                 << " | Harga Akhir: " << h << endl;
            found = true;
        }
        temp = temp->next;
        idx++;
    }

    if (!found)
        cout << "Tidak ada produk dalam range.\n";
}

// ============== MAX HARGA AKHIR ==============
void MaxHargaAkhir(List L) {
    if (isEmpty(L)) {
        cout << "List kosong.\n";
        return;
    }

    float maxH = -1;
    address temp = L.head;

    while (temp != NULL) {
        float h = hargaAkhir(temp->info);
        if (h > maxH) maxH = h;
        temp = temp->next;
    }

    cout << "Produk dengan Harga Akhir terbesar (" << maxH << "):\n";

    temp = L.head;
    int idx = 1;

    while (temp != NULL) {
        if (hargaAkhir(temp->info) == maxH) {
            cout << idx << ". " << temp->info.Nama
                 << " | SKU: " << temp->info.SKU
                 << endl;
        }
        temp = temp->next;
        idx++;
    }
}
