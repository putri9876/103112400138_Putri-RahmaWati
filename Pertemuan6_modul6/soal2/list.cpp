#include "list.h"

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

Address alokasi(Infotype dataBaru) {
    Address P = new ElemenList;
    P->info = dataBaru;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(Address &P) {
    delete P;
    P = NULL;
}

bool isExist(List L, string nomorPolisi) {
    string nopolInput = nomorPolisi;
    transform(nopolInput.begin(), nopolInput.end(), nopolInput.begin(), ::toupper);

    Address P = L.first;
    while (P != NULL) {
        string nopolData = P->info.nomorPolisi;
        transform(nopolData.begin(), nopolData.end(), nopolData.begin(), ::toupper);
        if (nopolInput == nopolData) {
            return true;
        }
        P = P->next;
    }
    return false;
}

void insertLast(List &L, Address P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void printInfo(List L) {
    Address P = L.last;
    while (P != NULL) {
        cout << "Nomor Polisi   : " << P->info.nomorPolisi << endl;
        cout << "Warna Kendaraan: " << P->info.warnaKendaraan << endl;
        cout << "Tahun Pembuatan: " << P->info.tahunPembuatan << endl;
        cout << endl;
        P = P->prev;
    }
}

Address findElm(List L, string nomorPolisi) {
    string nopolInput = nomorPolisi;
    transform(nopolInput.begin(), nopolInput.end(), nopolInput.begin(), ::toupper);

    Address P = L.first;
    while (P != NULL) {
        string nopolData = P->info.nomorPolisi;
        transform(nopolData.begin(), nopolData.end(), nopolData.begin(), ::toupper);

        if (nopolInput == nopolData) {
            cout << "\nMasukkan Nomor Polisi yang dicari  : " << P->info.nomorPolisi << endl;
            cout << "\nNomor Polisi : " << P->info.nomorPolisi << endl;
            cout << "Warna        : " << P->info.warnaKendaraan << endl;
            cout << "Tahun        : " << P->info.tahunPembuatan << endl;
            return P;
        }
        P = P->next;
    }

    cout << "\nData dengan nomor polisi " << nomorPolisi << " tidak ditemukan.\n";
    return NULL;
}
