#include "list.h"

int main() {
    List L;
    createList(L);

    infotype x;
    address P;

    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.tahunBuat;  

        if (isExist(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar\n" << endl;
        } else {
            P = alokasi(x);
            insertLast(L, P);
        }
    }

    cout << "\nDATA LIST 1\n";
    printInfo(L);

    return 0;
}
