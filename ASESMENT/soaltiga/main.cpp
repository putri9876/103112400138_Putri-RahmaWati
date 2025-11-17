#include "StackMahasiswa.h"

int main() {
    StackMHS S;
    Mahasiswa data_pop;

    cout << "1) Membuat Stack Kosong" << endl;
    createStack(S);
    cout << endl;

    Mahasiswa Venti = {"Venti", "11111", 75.7, 82.1, 65.5};
    Mahasiswa Xiao = {"Xiao", "22222", 87.4, 88.9, 81.9};
    Mahasiswa Kazuha = {"Kazuha", "33333", 92.3, 88.8, 82.4};
    Mahasiswa Wanderer = {"Wanderer", "44444", 95.5, 85.5, 90.5};
    Mahasiswa Lynette = {"Lynette", "55555", 77.7, 65.4, 79.9};
    Mahasiswa Chasca = {"Chasca", "66666", 99.9, 93.6, 87.3};
    
    Mahasiswa Heizou = {"Heizou", "77777", 99.9, 88.8, 77.7};

    cout << "2) Input Data Mahasiswa" << endl;
    Push(S, Venti);
    Push(S, Xiao);
    Push(S, Kazuha);
    Push(S, Wanderer);
    Push(S, Lynette);
    Push(S, Chasca);
    cout << endl;

    cout << "3) Menampilkan Stack Setelah Input 6 Data" << endl;
    View(S);
    cout << endl;

    cout << "4) Melakukan Pop Sebanyak 1x" << endl;
    data_pop = Pop(S);
    if (data_pop.NIM != "") {
         cout << "Data yang di-pop adalah: " << data_pop.Nama << " (" << data_pop.NIM << ")" << endl;
    }
    cout << endl;
    
    cout << "5) Menampilkan Stack Setelah Pop 1x" << endl;
    View(S);
    cout << endl;
    
    cout << "6) Melakukan Update Data pada Posisi ke-3" << endl;
    Update(S, 3, Heizou);
    cout << endl;
    
    cout << "7) Menampilkan Stack Setelah Update" << endl;
    View(S);
    cout << endl;

    cout << "8) Mencari Data Mahasiswa dengan Nilai Akhir dalam Rentang 85.5 - 95.5" << endl;
    SearchNilaiAkhir(S, 85.5, 95.5);
    cout << endl;

    cout << "BAGIAN B: Menampilkan Data dengan Nilai Akhir Terbesar" << endl;
    MaxNilaiAkhir(S);

    return 0;
}

