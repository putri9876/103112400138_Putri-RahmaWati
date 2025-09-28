# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Putri Rahma Wati - 103112400138</p>

## Dasar Teori
Awal tahun 1970-an Bjarne Stroustrup mengembangkan bahasa pemrograman C++ di laboratorium Bell, AT&T yang merupakan turunan dari bahasa C. Nama C++ sendiri diberikan oleh Rick Mascitti tahun 1983. Adapun tanda ++ berasal dari nama operator penaikan pada bahasa C. Bahasa C++ sudah mendukung paradig-ma pemrograman berorientasi objek. Greg Perry pada tahun 1993 menyatakan C++ dapat meningkatkan produktivitas pemrogram lebih dari dua kali dibanding-kan bahasa prosedural seperti C. PASCAL, dan BASIC karena kode dapat digunakan kembali. Kode program C++ dapat ditulis dengan sembarang teks editor. Format kode program C++ adalah .cpp. Supaya program dapat dijalankan pada komputer, le program harus dikompilasi dengan kompilator C++. [Hanief, S., Jepriana, I. W., & Kom, S. (2020). Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Penerbit Andi.] [1]
Kode bahasa C sifatnya adalah portabel dan fleksibel untuk semua jenis komputer. Aplikasi yang dibuat menggunakan sistem operasi windows dapat dipindah ke Linux dengan sedikit atau tidak sama sekali perubahan.[Aji, B. A. S., & Rahmanti, F. Z. (2021). Dasar Pemrograman Dalam Bahasa C. Deepublish.][2]
Bahasa pemrograman C++ merupakan bahasa pemrograman yang banyak digunakan dalam membangun aplikasi. Agar dapat mengeksekusi kode program C++ maka kita membutuhkan penerjemah. Penerjemah ini dikenal juga dengan istilah compiler. Ada banyak Integrated Development Environment (IDE) dengan compiler C++ yang dapat kita gunak... Salah satunya adalah NETBEANS.[Kaswar, A. B., & Zain, S. G. (2021). Mudah Belajar Pemrograman Dasar C++. Syiah Kuala University Press.][3]


### A. ...<br/>
...
#### 1. C++ mendukung konsep kelas, objek, pewarisan, dan polimorfisme, sehingga kode bisa digunakan kembali. [1]
#### 2. Program C++ dapat dijalankan di berbagai sistem operasi dengan sedikit atau tanpa perubahan. [2]
#### 3. Kode C++ harus dikompilasi menggunakan compiler, dan dapat menggunakan IDE seperti NetBeans. [3]

## Guided 

### 1.Perulangan for
 #include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukan angka: " <<endl;
    cin >> angka1;

    int i =0;
    int j =0;
    //perulangan while
    while (i < angka1) {
        cout << i << " - ";
        i++;
    }
    //perulangan do while
    do {
        cout << j << " - ";
        j++; // increment
    } while ( j < angka1);
    return 0;
}

penjelasan singkat guided 1
program ini mencetak deret angka dua kali, pertama dengan while dan kedua dengan do-while.

### 2.perulangan
#include <iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukan angka: ";
    cin >> angka1;
    cout << "angka yang di input " << angka1;
    return 0;
}

```C++
source code guided 2
```
penjelasan singkat guided 2
program ini membaca angka dan menampilkannya kembali.

### 3. struct
#include <iostream>
using namespace std;

int main() {
    const int jumlah = 5;

    struct rapot {
        string nama {5};
        int nilai;
    };
    rapot siswa[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukan nama siswa: " ;
        cin >> siswa[i].nama;
        cout << "Masukan nilai siswa: " ;
        cin >> siswa[i].nilai;
    }
    int i = 0;
    while (i < jumlah) {
        cout << "Nama : " << siswa[i].nama <<  " nilai: " << siswa[i].nilai << endl;
        i++;
    }
    return 0;
}

```C++
penjelasan guided 3
Program ini membuat daftar nilai siswa menggunakan struct rapot yang menyimpan nama dan nilai tiap siswa, kemudian menyimpan data 5 siswa dalam array siswa. Program meminta pengguna memasukkan nama dan nilai tiap siswa menggunakan for loop, lalu menampilkan semua data yang telah dimasukkan menggunakan while loop, sehingga hasilnya berupa daftar nama siswa beserta nilai mereka.

## Unguided 

### 1.Buatlah program yang menerima input-an dua buah bilangan betipe float, kemudian memberikan output-an hasil penjumlahan, pengurangan, perkalian, dan pembagian dari dua
bilangan tersebut.

```C++
source code unguided 1
#include <iostream>
using namespace std;

int main() {
    float a, b;

    cout << "Masukkan bilangan pertama: ";
    cin >> a;
    cout << "Masukkan bilangan kedua: ";
    cin >> b;

    cout << "\nHasil Penjumlahan: " << a + b << endl;
    cout << "Hasil Pengurangan: " << a - b << endl;
    cout << "Hasil Perkalian   : " << a * b << endl;
    cout << "hasil pembagian : " << a/b << endl;

    return 0;
}
### Output Unguided 1 :

##### Output 1

![Screenshot Output Unguided 1_1](https://github.com/putri9876/103112400138_Putri-Rahma-Wati/blob/main/Pertemuan1_Modul1/Output-Unguided1-1.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/putri9876/103112400138_Putri-Rahma-Wati/blob/main/Pertemuan1_Modul1/Output-Unguided1-2.png)

penjelasan unguided 1 
Program ini meminta memasukan bilangan pecahan lalu program akan menghitung dan menampilkan penjumlahan,pengurangan,perkalian, dan pembagian.

### 2. Buatlah sebuah program yang menerima masukan angka dan mengeluarkan output nilai angka tersebut dalam bentuk tulisan. Angka yang akan di- input-kan user adalah bilangan bulat positif mulai dari 0 s.d 100

contoh: 79: tujuh puluh Sembilan

```C++
source code unguided 2
#include <iostream>
#include <string>
using namespace std;

string angkaKeTulisan(int n) {
    string satuan[] = {"nol", "satu", "dua", "tiga", "empat", "lima", "enam", "tujuh", "delapan", "sembilan", "sepuluh", "sebelas", "dua belas", "tiga belas", "empat belas", "lima belas", "enam belas", "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", "lima puluh", "enam puluh", "tujuh puluh", "delapan puluh", "sembilan puluh"};

    if (n < 20) {
        return satuan[n];
    } else if (n < 100) {
        int p = n / 10;
        int s = n % 10;
        if (s == 0)
            return puluhan[p];
        else
            return puluhan[p] + " " + satuan[s];
    } else if (n == 100) {
        return "seratus";
    } else {
        return "di luar jangkauan";
    }
}

int main() {
    int angka;
    cout << "Masukkan angka (0-100): ";
    cin >> angka;

    if (angka >= 0 && angka <= 100) {
        cout << angka << ": " << angkaKeTulisan(angka) << endl;
    } else {
        cout << "Input harus antara 0 sampai 100!" << endl;
    }

return 0;
}
### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/putri9876/103112400138_Putri-Rahma-Wati/blob/main/Pertemuan1_Modul1/Output-Unguided2-1.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/putri9876/103112400138_Putri-Rahma-Wati/blob/main/Pertemuan1_Modul1/Output-Unguided2-2.png)
penjelasan unguided 2
Program ini mengubah angka 0–100 menjadi sebuah teks dan diminta memasukkan angka, dan program akan mengubah sebuah angka menjadi kata-kata seperti 17 akan menjadi "tujuh belas"

### 3. Buatlah program yang dapat memberikan input dan output sbb.

input: 3
output:
321 * 123
 21 * 12
  1 * 1
    *

```C++
source code unguided 3
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Input: ";
    cin >> n;
    cout << "Output:\n";
    for (int i = n; i >= 1; i--) {
        for (int s = 0; s < n - i; s++) {
            cout << "  "; 
        }

        for (int j = i; j >= 1; j--) {
            cout << j << " ";
        }

        cout << "* ";

        for (int j = 1; j <= i; j++) {
            cout << j << " ";
        }

        cout << endl;
    }

    for (int s = 0; s < n; s++) {
        cout << "  ";
    }
    cout << "*" << endl;

    return 0;
}
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/putri9876/103112400138_Putri-Rahma-Wati/blob/main/Pertemuan1_Modul1/Output-Unguided3-1.png)

##### Output 2
![Screenshot Output Unguided 1_1](https://github.com/putri9876/103112400138_Putri-Rahma-Wati/blob/main/Pertemuan1_Modul1/Output-Unguided3-2.png)

penjelasan unguided 3
Program ini mencetak pola angka berbentuk segitiga terbalik dengan simbol * di tengah. Pengguna memasukkan tinggi piramida n, lalu program menggunakan loop untuk setiap baris, mencetak spasi di kiri agar pola rapi, angka menurun dari i ke 1 di kiri simbol *, simbol * di tengah, dan angka meningkat dari 1 ke i di kanan simbol *. Setelah semua baris selesai, program menampilkan satu * di tengah bawah sebagai puncak terakhir pola.
## Kesimpulan
Ketiga program memperkenalkan konsep dasar pemrograman C++ seperti input/output, perhitungan, pengolahan data, dan pola perulangan.
Program pertama menghitung operasi dasar (penjumlahan, pengurangan, perkalian, pembagian) dari dua bilangan pecahan.
Program kedua mengubah angka 0–100 menjadi teks dalam bahasa Indonesia menggunakan logika kondisional. 
Program ketiga mencetak pola piramida angka terbalik dengan simbol * menggunakan loop bersarang. Secara keseluruhan, ketiga program ini membantu memahami cara membaca input, melakukan perhitungan, mengolah data, dan menggunakan perulangan untuk mencetak pola dalam C++.

## Referensi
[1] Hanief, S., Jepriana, I. W., & Kom, S. (2020). Konsep Algoritme dan Aplikasinya dalam Bahasa Pemrograman C++. Penerbit Andi. 
[2] Aji, B. A. S., & Rahmanti, F. Z. (2021). Dasar Pemrograman Dalam Bahasa C. Deepublish.". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
[3]Kaswar, A. B., & Zain, S. G. (2021). Mudah Belajar Pemrograman Dasar C++. Syiah Kuala University Press.

