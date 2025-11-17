#include "StackMahasiswa.h"

float hitungNilaiAkhir(float tugas, float uts, float uas) {
    return (0.20 * tugas) + (0.40 * uts) + (0.40 * uas);
}

void createStack(StackMHS &S) {
    S.Top = -1;
    cout << "Stack berhasil dibuat dan diinisialisasi kosong." << endl;
}

bool isEmpty(StackMHS S) {
    return S.Top == -1;
}

bool isFull(StackMHS S) {
    return S.Top == MAX - 1;
}

void Push(StackMHS &S, Mahasiswa M) {
    if (isFull(S)) {
        cout << "Error: Stack penuh! Push gagal." << endl;
    } else {
        S.Top++;
        S.dataMahasiswa[S.Top] = M;
        cout << "Data mahasiswa " << M.Nama << " berhasil di-push (ditambahkan)." << endl;
    }
}

Mahasiswa Pop(StackMHS &S) {
    Mahasiswa M_kosong = {"", "", 0.0, 0.0, 0.0};
    if (isEmpty(S)) {
        cout << "Error: Stack kosong! Pop gagal." << endl;
        return M_kosong;
    } else {
        Mahasiswa M = S.dataMahasiswa[S.Top];
        S.Top--;
        cout << "Data mahasiswa " << M.Nama << " berhasil di-pop (dihapus)." << endl;
        return M;
    }
}

void Update(StackMHS &S, int posisi, Mahasiswa M) {
    int index = S.Top - (posisi - 1);
    if (posisi < 1 || posisi > (S.Top + 1)) {
        cout << "Error: Posisi " << posisi << " tidak valid untuk Update." << endl;
    } else {
        S.dataMahasiswa[index] = M;
        cout << "Data mahasiswa pada posisi ke-" << posisi << " (indeks " << index << ") berhasil diupdate menjadi " << M.Nama << "." << endl;
    }
}

void View(StackMHS S) {
    if (isEmpty(S)) {
        cout << "\nStack Kosong, tidak ada data untuk ditampilkan." << endl;
        return;
    }

    cout << "\nDATA MAHASISWA DALAM STACK" << endl;
    cout << "Posisi Index Nama           NIM      Tugas UTS   UAS   Akhir" << endl;
    
    for (int i = S.Top; i >= 0; i--) {
        float nilaiAkhir = hitungNilaiAkhir(S.dataMahasiswa[i].NilaiTugas, S.dataMahasiswa[i].NilaiUTS, S.dataMahasiswa[i].NilaiUAS);
        int posisi = S.Top - i + 1;
        
        cout << setw(6) << posisi
             << setw(6) << i
             << setw(16) << S.dataMahasiswa[i].Nama
             << setw(9) << S.dataMahasiswa[i].NIM
             << setw(7) << fixed << setprecision(1) << S.dataMahasiswa[i].NilaiTugas
             << setw(5) << fixed << setprecision(1) << S.dataMahasiswa[i].NilaiUTS
             << setw(6) << fixed << setprecision(1) << S.dataMahasiswa[i].NilaiUAS
             << setw(6) << fixed << setprecision(1) << nilaiAkhir
             << endl;
    }
    cout << "Jumlah data saat ini: " << S.Top + 1 << endl;
}

void SearchNilaiAkhir(StackMHS S, float NilaiAkhirMin, float NilaiAkhirMax) {
    if (isEmpty(S)) {
        cout << "\nStack Kosong, tidak ada data untuk pencarian." << endl;
        return;
    }

    cout << "\nHasil Pencarian Mahasiswa dengan Nilai Akhir antara " << fixed << setprecision(1) << NilaiAkhirMin << " dan " << NilaiAkhirMax << endl;
    bool found = false;

    for (int i = S.Top; i >= 0; i--) {
        float nilaiAkhir = hitungNilaiAkhir(S.dataMahasiswa[i].NilaiTugas, S.dataMahasiswa[i].NilaiUTS, S.dataMahasiswa[i].NilaiUAS);
        int posisi = S.Top - i + 1;

        if (nilaiAkhir >= NilaiAkhirMin && nilaiAkhir <= NilaiAkhirMax) {
            cout << "Ditemukan: Nama=" << S.dataMahasiswa[i].Nama 
                 << ", NIM=" << S.dataMahasiswa[i].NIM 
                 << ", Nilai Akhir=" << fixed << setprecision(2) << nilaiAkhir
                 << ", Posisi (dari Top)=" << posisi 
                 << " (Indeks=" << i << ")" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Tidak ada mahasiswa yang ditemukan dalam rentang nilai akhir tersebut." << endl;
    }
}

void MaxNilaiAkhir(StackMHS S) {
    if (isEmpty(S)) {
        cout << "\nStack Kosong, tidak dapat mencari nilai maksimum." << endl;
        return;
    }

    float maxNilai = -1.0;
    int maxIndex = -1;

    for (int i = S.Top; i >= 0; i--) {
        float nilaiAkhir = hitungNilaiAkhir(S.dataMahasiswa[i].NilaiTugas, S.dataMahasiswa[i].NilaiUTS, S.dataMahasiswa[i].NilaiUAS);
        
        if (nilaiAkhir > maxNilai) {
            maxNilai = nilaiAkhir;
            maxIndex = i;
        }
    }

    if (maxIndex != -1) {
        int posisi = S.Top - maxIndex + 1;
        cout << "\nMahasiswa dengan Nilai Akhir Terbesar" << endl;
        cout << "Nama           : " << S.dataMahasiswa[maxIndex].Nama << endl;
        cout << "NIM            : " << S.dataMahasiswa[maxIndex].NIM << endl;
        cout << "Nilai Akhir    : " << fixed << setprecision(2) << maxNilai << endl;
        cout << "Posisi (dari Top): " << posisi << " (Indeks Array: " << maxIndex << ")" << endl;
    }
}