#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts;
    float uas;
    float tugas;
    float nilai_akhir; 
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

void inputDataMahasiswa(Mahasiswa &mhs) {
    cout << "Nama: ";
    cin.ignore();
    getline(cin, mhs.nama);
    cout << "NIM: ";
    cin >> mhs.nim;
    cout << "Nilai UTS: ";
    cin >> mhs.uts;
    cout << "Nilai UAS: ";
    cin >> mhs.uas;
    cout << "Nilai Tugas: ";
    cin >> mhs.tugas;

    mhs.nilai_akhir = hitungNilaiAkhir(mhs.uts, mhs.uas, mhs.tugas);
}

void tampilkanData(const Mahasiswa &mhs) {
    cout << "Nama: " << mhs.nama << endl;
    cout << "NIM: " << mhs.nim << endl;
    cout << "UTS: " << mhs.uts << endl;
    cout << "UAS: " << mhs.uas << endl;
    cout << "Tugas: " << mhs.tugas << endl;
    cout << "Nilai Akhir: " << mhs.nilai_akhir << endl;
}

int main() {
    Mahasiswa mhs_tunggal; 
    inputDataMahasiswa(mhs_tunggal);
    tampilkanData(mhs_tunggal);

    return 0; 
}