#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 6;

struct Mahasiswa {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
};

typedef struct StackMahasiswa {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
} StackMHS;

void createStack(StackMHS &S);
bool isEmpty(StackMHS S);
bool isFull(StackMHS S);
void Push(StackMHS &S, Mahasiswa M);
Mahasiswa Pop(StackMHS &S);

void Update(StackMHS &S, int posisi, Mahasiswa M);
void View(StackMHS S);
void SearchNilaiAkhir(StackMHS S, float NilaiAkhirMin, float NilaiAkhirMax);

void MaxNilaiAkhir(StackMHS S);

float hitungNilaiAkhir(float tugas, float uts, float uas);