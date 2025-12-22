#include "mll.h"

int main() {
    ListParent L;
    createListParent(L);

    insertFirstParent(L, alokasiParent("G004", "Romance"));
    insertFirstParent(L, alokasiParent("G003", "Horror"));
    insertFirstParent(L, alokasiParent("G002", "Comedy"));
    insertFirstParent(L, alokasiParent("G001", "Action"));

    adrParent P = L.first; 
    insertLastChild(P, alokasiChild("FA001", "The Raid", 101, 2011, 7.6));

    P = P->next; 
    insertLastChild(P, alokasiChild("FC001", "Agak Laen", 119, 2024, 8.0));
    insertLastChild(P, alokasiChild("FC002", "My Stupid Boss", 108, 2016, 6.8));

    P = P->next; 
    insertLastChild(P, alokasiChild("FH001", "Pengabdi Setan", 107, 2017, 8.4));

    P = P->next; 
    insertLastChild(P, alokasiChild("FR001", "Habibie & Ainun", 118, 2012, 7.6));
    insertLastChild(P, alokasiChild("FR002", "Dilan 1990", 110, 2018, 6.6));

    cout << "--- OUTPUT POIN 3 ---" << endl;
    printStrukturMLL(L);
    cout << endl;

    cout << "--- OUTPUT POIN 4 (Search Rating 8.0 - 8.5) ---" << endl;
    searchFilmByRatingRange(L, 8.0, 8.5);
    cout << endl;

    cout << "--- PROSES POIN 5 (Delete G002) ---" << endl;
    adrParent pDelete;
    deleteAfterParent(L, L.first, pDelete);
    cout << "Node G002 dan list child-nya berhasil dihapus." << endl << endl;

    cout << "--- OUTPUT POIN 6 (Setelah Delete) ---" << endl;
    printStrukturMLL(L);

    return 0;
}