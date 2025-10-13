#include <iostream>
#include <iomanip>

using namespace std;
const int SIZE = 3;

void tampilkanArray(const int arr[SIZE][SIZE], const string& nama) {
    cout << " " << nama << " " << endl;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            cout << setw(4) << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
void tukarIsiArrayPosisi(int arrA[SIZE][SIZE], int arrB[SIZE][SIZE], 
                        int brs1, int kol1, int brs2, int kol2) {
    
    int temp = arrA[brs1][kol1];
    arrA[brs1][kol1] = arrB[brs2][kol2];
    arrB[brs2][kol2] = temp;
}

void tukarNilaiPointer(int *ptrA, int *ptrB) {
    int temp = *ptrA;
    *ptrA = *ptrB;
    *ptrB = temp;
}

int main() {
    int arrayA[SIZE][SIZE] = {{1, 2, 3},
                              {4, 5, 6},
                              {7, 8, 9}};
                                
    int arrayB[SIZE][SIZE] = {{10, 20, 30},
                              {40, 50, 60},
                              {70, 80, 90}};
    
    int nilaiP = 100;
    int nilaiQ = 200;
    
    int *ptrP = &nilaiP; 
    int *ptrQ = &nilaiQ;
    
    tampilkanArray(arrayA, "Array A (Awal)");
    tampilkanArray(arrayB, "Array B (Awal)");

    cout << "Menukar" << endl;
    tukarIsiArrayPosisi(arrayA, arrayB, 2, 0, 0, 1);

    tampilkanArray(arrayA, "Array A (Akhir)"); 
    tampilkanArray(arrayB, "Array B (Akhir)"); 

    cout << "POINTER" << endl;
    cout << "Awal: Nilai P = " << nilaiP << ", Nilai Q = " << nilaiQ << endl;
    
    tukarNilaiPointer(ptrP, ptrQ);

    cout << "Akhir: Nilai P = " << nilaiP << ", Nilai Q = " << nilaiQ << endl;
    
    return 0;
}