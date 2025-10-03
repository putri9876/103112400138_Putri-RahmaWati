#include <iostream>
using namespace std;

int cariMinimum(int arr[], int ukuran) {
    int min = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int cariMaksimum(int arr[], int ukuran) {
    int maks = arr[0];
    for (int i = 1; i < ukuran; i++) {
        if (arr[i] > maks) {
            maks = arr[i];
        }
    }
    return maks;
}

void hitungRataRata(int arr[], int ukuran) {
    int total = 0;
    for (int i = 0; i < ukuran; i++) {
        total += arr[i];
    }
    double rata = (double) total / ukuran;
    cout << "Nilai rata-rata array = " << rata << endl;
}

int main() {
    int arrA[] = {13, 8, 5, 7, 12, 26, 4, 55, 33, 50};
    int ukuran = sizeof(arrA) / sizeof(arrA[0]);

    cout << "Isi array: ";
    for (int i = 0; i < ukuran; i++) {
        cout << arrA[i] << " ";
    }
    cout << endl;

    cout << "Nilai maksimum = " << cariMaksimum(arrA, ukuran) << endl;
    cout << "Nilai minimum = " << cariMinimum(arrA, ukuran) << endl;
    hitungRataRata(arrA, ukuran);

    return 0;
}
