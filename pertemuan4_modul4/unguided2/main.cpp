#include "list.h"

int main() {
    List L;
    address P1, P2, P3, P4, P5, Pdel;
    CreateList(L);

    P1 = alokasi(9); insertFirst(L, P1);
    P2 = alokasi(12); insertLast(L, P2);
    P3 = alokasi(8); insertLast(L, P3);
    P4 = alokasi(0); insertLast(L, P4);
    P5 = alokasi(2); insertLast(L, P5);

    cout << "List awal: ";
    printInfo(L);

    deleteFirst(L, Pdel);
    dealokasi(Pdel);

    deleteLast(L, Pdel);
    dealokasi(Pdel);

    deleteAfter(L, L.First, Pdel);
    dealokasi(Pdel);

    cout << "Setelah penghapusan: ";
    printInfo(L);

    cout << "Jumlah node: " << nbList(L) << endl;

    deleteList(L);
    cout << "- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node: " << nbList(L) << endl;

    return 0;
}
