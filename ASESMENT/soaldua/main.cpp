#include "dllplaylist.h"
#include <iostream>

int main() {
    List L = createList();
    std::cout << "Program Doubly Linked List Playlist Dimulai." << std::endl;

    Song senja = {"Senja di Kota", "Nona Band", 210, 150, 4.2};
    Song langkahku = {"Langkahku", "Delta", 185, 320, 4.8};
    Song hujan = {"Hujan Minggu", "Arka", 240, 90, 3.9};
    Song pelita = {"Pelita", "Luna", 200, 260, 4.5};
    Song fajar = {"Fajar", "Bintang", 170, 400, 5.0};
    Song newSenja = {"New Senja", "Nona Band", 215, 500, 4.9};

    insertLast(L, senja);
    insertLast(L, langkahku);
    insertLast(L, hujan);
    insertFirst(L, pelita); 

    viewListSimple(L, "Tampilan List Awal (4 Lagu)");

    Song deletedSong;
    deleteLast(L, deletedSong); 
    std::cout << "\n--- Operasi Penghapusan ---" << std::endl;
    std::cout << "deleteLast: Lagu '" << deletedSong.Title << "' dihapus." << std::endl;
    
    viewListSimple(L, "Tampilan List Setelah deleteLast");

    Node* Q_langkahku = searchNodeAtPosition(L, 3); 
    
    if (Q_langkahku != nullptr) {
        insertBefore(L, Q_langkahku, fajar); 
        std::cout << "\n--- Operasi Update dan Insert Spesifik ---" << std::endl;
        std::cout << "insertBefore: Lagu 'Fajar' dimasukkan sebelum '" << Q_langkahku->info.Title << "'." << std::endl;
        updateAtPosition(L, 1, newSenja); 
    }

    viewListSimple(L, "Tampilan List Setelah Update & Insert");
    searchByPopularityRangeSimple(L, 200.0, 500.0); 

    Song temp;
    while (!isEmpty(L)) {
        deleteFirst(L, temp);
    }
    return 0;
}