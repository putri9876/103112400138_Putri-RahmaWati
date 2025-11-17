#include <iostream>
#include "SLLInventory.h"
using namespace std;

int main() {
    List L;
    createList(L);

    Product P;

    P.Nama = "Pulpen";
    P.SKU = "A001";
    P.Jumlah = 20;
    P.HargaSatuan = 2500;
    P.DiskonPersen = 0;
    insertLast(L, P);

    P.Nama = "Buku Tulis";
    P.SKU = "A002";
    P.Jumlah = 10;
    P.HargaSatuan = 15000;
    P.DiskonPersen = 5;
    insertLast(L, P);

    P.Nama = "Penghapus";
    P.SKU = "A003";
    P.Jumlah = 30;
    P.HargaSatuan = 1500;
    P.DiskonPersen = 10;
    insertLast(L, P);

    cout << "\nList awal:\n";
    viewList(L);

    Product deleted;
    deleteFirst(L, deleted);

    cout << "\nSetelah deleteFirst:\n";
    viewList(L);

    Product baru;
    baru.Nama = "Stabilo";
    baru.SKU = "A010";
    baru.Jumlah = 40;
    baru.HargaSatuan = 9000;
    baru.DiskonPersen = 5;

    updateAtPosition(L, 2, baru);

    cout << "\nSetelah update posisi ke-2:\n";
    viewList(L);

    cout << "\nSearch harga akhir 2000 - 7000:\n";
    searchByFinalPriceRange(L, 2000, 7000);

    cout << "\n== Max Harga Akhir ==\n";
    MaxHargaAkhir(L);

    return 0;
}
