#include "list.h"

int main() {
    List daftarKendaraan;
    createList(daftarKendaraan);

    Infotype dataKendaraan;
    Address P;

    cout << "=== INPUT DATA KENDARAAN ===" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "\nMasukkan Nomor Polisi   : ";
        cin >> dataKendaraan.nomorPolisi;
        cout << "Masukkan Warna Kendaraan: ";
        cin >> dataKendaraan.warnaKendaraan;
        cout << "Masukkan Tahun Pembuatan: ";
        cin >> dataKendaraan.tahunPembuatan;

        if (isExist(daftarKendaraan, dataKendaraan.nomorPolisi)) {
            cout << "\nNomor polisi sudah terdaftar.\n";
        } else {
            P = alokasi(dataKendaraan);
            insertLast(daftarKendaraan, P);
        }
    }

    cout << "\n=== DATA LIST ===" << endl;
    printInfo(daftarKendaraan);

    string cari;
    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> cari;
    findElm(daftarKendaraan, cari);

    return 0;
}
