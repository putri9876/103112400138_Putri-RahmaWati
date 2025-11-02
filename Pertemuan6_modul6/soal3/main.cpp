#include "list.h"

int main() {
    List daftarKendaraan;
    createList(daftarKendaraan);

    Infotype data;
    Address P;

    cout << "=== INPUT DATA KENDARAAN ===" << endl;

    data.nomorPolisi = "D001";
    data.warnaKendaraan = "hitam";
    data.tahunPembuatan = 90;
    insertLast(daftarKendaraan, alokasi(data));

    data.nomorPolisi = "D002";
    data.warnaKendaraan = "merah";
    data.tahunPembuatan = 90;
    insertLast(daftarKendaraan, alokasi(data));

    data.nomorPolisi = "D003";
    data.warnaKendaraan = "biru";
    data.tahunPembuatan = 90;
    insertLast(daftarKendaraan, alokasi(data));

    data.nomorPolisi = "D004";
    data.warnaKendaraan = "kuning";
    data.tahunPembuatan = 90;
    insertLast(daftarKendaraan, alokasi(data));

    string cari;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> cari;

    Address hapus = findElm(daftarKendaraan, cari);

    if (hapus != NULL) {
        if (hapus == daftarKendaraan.first) {
            deleteFirst(daftarKendaraan, P);
        } else if (hapus == daftarKendaraan.last) {
            deleteLast(daftarKendaraan, P);
        } else {
            deleteAfter(hapus->prev, P);
        }
        cout << "Data dengan nomor polisi " << cari << " berhasil dihapus.\n";
        dealokasi(P);
    } else {
        cout << "Data dengan nomor polisi " << cari << " tidak ditemukan.\n";
    }

    cout << "\nDATA LIST 1\n" << endl;
    printInfo(daftarKendaraan);

    return 0;
}
