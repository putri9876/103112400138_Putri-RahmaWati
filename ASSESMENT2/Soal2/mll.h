#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct Film {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
};

typedef struct ElmChild *adrChild;
struct ElmChild {
    Film info;
    adrChild next;
};

struct Genre {
    string idGenre;
    string namaGenre;
};

typedef struct ElmParent *adrParent;
struct ElmParent {
    Genre info;
    adrParent next;
    adrParent prev;
    adrChild firstChild;
};

struct ListParent {
    adrParent first;
    adrParent last;
};

void createListParent(ListParent &L);
adrParent alokasiParent(string id, string nama);
adrChild alokasiChild(string id, string judul, int durasi, int tahun, float rating);
void dealokasiNodeChild(adrChild &C);
void dealokasiNodeParent(adrParent &P);
void hapusListChild(adrParent &P);
void insertFirstParent(ListParent &L, adrParent P);
void insertLastChild(adrParent &P, adrChild C);
void deleteAfterParent(ListParent &L, adrParent prec, adrParent &P);
void searchFilmByRatingRange(ListParent L, float minR, float maxR);
void printStrukturMLL(ListParent L);

#endif