#include "mll.h"

void createListParent(ListParent &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrParent alokasiParent(string id, string nama) {
    adrParent P = new ElmParent;
    P->info.idGenre = id;
    P->info.namaGenre = nama;
    P->next = nullptr;
    P->prev = nullptr;
    P->firstChild = nullptr;
    return P;
}

adrChild alokasiChild(string id, string judul, int durasi, int tahun, float rating) {
    adrChild C = new ElmChild;
    C->info.idFilm = id;
    C->info.judulFilm = judul;
    C->info.durasiFilm = durasi;
    C->info.tahunTayang = tahun;
    C->info.ratingFilm = rating;
    C->next = nullptr;
    return C;
}

void dealokasiNodeChild(adrChild &C) {
    delete C;
    C = nullptr;
}

void hapusListChild(adrParent &P) {
    adrChild C = P->firstChild;
    while (C != nullptr) {
        adrChild temp = C;
        C = C->next;
        dealokasiNodeChild(temp);
    }
    P->firstChild = nullptr;
}

void dealokasiNodeParent(adrParent &P) {
    if (P != nullptr) {
        hapusListChild(P); 
        delete P;
        P = nullptr;
    }
}

void insertFirstParent(ListParent &L, adrParent P) {
    if (L.first == nullptr) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(adrParent &P, adrChild C) {
    if (P != nullptr) {
        if (P->firstChild == nullptr) {
            P->firstChild = C;
        } else {
            adrChild lastC = P->firstChild;
            while (lastC->next != nullptr) {
                lastC = lastC->next;
            }
            lastC->next = C;
        }
    }
}

void deleteAfterParent(ListParent &L, adrParent prec, adrParent &P) {
    if (prec != nullptr && prec->next != nullptr) {
        P = prec->next;
        if (P == L.last) {
            L.last = prec;
            prec->next = nullptr;
            P->prev = nullptr;
        } else {
            prec->next = P->next;
            P->next->prev = prec;
            P->next = nullptr;
            P->prev = nullptr;
        }
        dealokasiNodeParent(P);
    }
}

void searchFilmByRatingRange(ListParent L, float minR, float maxR) {
    adrParent P = L.first;
    int posP = 1;
    while (P != nullptr) {
        adrChild C = P->firstChild;
        int posC = 1;
        while (C != nullptr) {
            if (C->info.ratingFilm >= minR && C->info.ratingFilm <= maxR) {
                cout << "Data Film ditemukan pada list child dari node parent " << P->info.namaGenre << " pada posisi ke-" << posC << "!" << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "Judul Film : " << C->info.judulFilm << endl;
                cout << "Posisi dalam list child : posisi ke-" << posC << endl;
                cout << "ID Film : " << C->info.idFilm << endl;
                cout << "Durasi Film : " << C->info.durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->info.tahunTayang << endl;
                cout << "Rating Film : " << C->info.ratingFilm << endl;
                cout << "--------------------------" << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                cout << "ID Genre : " << P->info.idGenre << endl;
                cout << "Posisi dalam list parent : posisi ke-" << posP << endl;
                cout << "Nama Genre : " << P->info.namaGenre << endl;
                cout << "==========================" << endl;
            }
            C = C->next;
            posC++;
        }
        P = P->next;
        posP++;
    }
}

void printStrukturMLL(ListParent L) {
    adrParent P = L.first;
    int i = 1;
    while (P != nullptr) {
        cout << "=== Parent " << i << " ===" << endl;
        cout << "ID Genre : " << P->info.idGenre << endl;
        cout << "Nama Genre : " << P->info.namaGenre << endl;
        
        adrChild C = P->firstChild;
        int j = 1;
        while (C != nullptr) {
            cout << "  - Child " << j << " :" << endl;
            cout << "    ID Film : " << C->info.idFilm << endl;
            cout << "    Judul Film : " << C->info.judulFilm << endl;
            cout << "    Durasi Film : " << C->info.durasiFilm << " menit" << endl;
            cout << "    Tahun Tayang : " << C->info.tahunTayang << endl;
            cout << "    Rating Film : " << C->info.ratingFilm << endl;
            C = C->next;
            j++;
        }
        cout << "--------------------------" << endl;
        P = P->next;
        i++;
    }
}