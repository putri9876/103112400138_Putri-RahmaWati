#include <iostream>
using namespace std;

void tampilkanHasil(int arr[3][3]){
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int arrA[3][3], arrB[3][3];
    int arrC[3][3] = {0}; 
    int arrD[3][3] = {0}; 
    int arrE[3][3] = {0}; 

    cout << "Masukkan matriks A 3x3:" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> arrA[i][j];
        }
    }

    cout << "Masukkan matriks B 3x3:" << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> arrB[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            arrD[i][j] = arrA[i][j] - arrB[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                arrE[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "\nHasil Penjumlahan:" << endl;
    tampilkanHasil(arrC);

    cout << "\nHasil Pengurangan:" << endl;
    tampilkanHasil(arrD);

    cout << "\nHasil Perkalian:" << endl;
    tampilkanHasil(arrE);

    return 0;
}
