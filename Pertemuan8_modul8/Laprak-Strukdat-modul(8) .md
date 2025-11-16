# <h1 align="center">Laporan Praktikum Modul 8 - queue (Bagian kedelapan)</h1>
<p align="center"> Putri Rahma Wati 103112400138 </p>

## Dasar Teori
Queue atau dalam bahasa Indonesia yang berarti antrean adalah struktur data yang menyusun elemen-elemen data dalam urutan linier. Prinsip dasar dari struktur data ini adalah “First In, First Out” (FIFO) yang berarti elemen data yang pertama dimasukkan ke dalam antrean akan menjadi yang pertama pula untuk dikeluarkan.[1]. Queue adalah struktur data yang menyimpan data secara berurutan dan mengikuti aturan First In First Out (FIFO), artinya elemen yang pertama masuk akan menjadi elemen pertama yang dikeluarkan. Konsep ini mirip antrean di dunia nyata: siapa yang datang duluan, dia yang dilayani dulu. Queue biasanya digunakan dalam berbagai proses seperti pengaturan tugas, sistem antrian printer, manajemen proses dalam sistem operasi, serta komunikasi data. Struktur ini dapat diimplementasikan menggunakan array maupun linked list, dan menyediakan operasi dasar seperti enqueue untuk menambahkan elemen ke bagian belakang antrian, serta dequeue untuk menghapus elemen dari bagian depan.[2]
### A. Konsep Dasar Struktur Queue
Queue merupakan struktur data berurutan yang mengikuti prinsip FIFO, sehingga elemen pertama yang masuk akan menjadi elemen pertama yang keluar. Struktur ini banyak digunakan dalam berbagai proses seperti penjadwalan tugas, antrian printer, hingga manajemen proses pada sistem operasi karena mampu mengatur data secara teratur dan berurutan.

...1. Operasi Dasar Queue
Operasi utama pada queue meliputi enqueue (menambahkan elemen ke bagian belakang antrean) dan dequeue (menghapus elemen dari bagian depan). Selain itu terdapat juga operasi pendukung seperti isEmpty untuk memeriksa apakah antrean kosong dan isFull untuk mengetahui apakah kapasitas antrean telah penuh.
...2. Implementasi Queue
Queue dapat diimplementasikan menggunakan array maupun linked list. Implementasi array biasanya lebih sederhana namun memiliki batasan kapasitas, sedangkan linked list bersifat dinamis dan dapat menyesuaikan jumlah data selama memori tersedia.

## Guided 

### 1. implementasi ADT Queue

```C++
source code guided 1
```main.cpp
#include "queue.h"
#include <iostream>
using namespace std;

int main() {
    queue Q;
    CreateQueue(Q);

    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Atha");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    clearQueue(Q);
    return 0;
}

queue.cpp

#include "queue.h"
using namespace std;

void CreateQueue(queue &Q) {
    Q.head = nullptr;
    Q.tail = nullptr;
}

bool isEmpty(queue Q) {
    return Q.head == nullptr;
}

bool isFull(queue) {
    return false;
}

void enQueue(queue &Q, const string &nama) {
    Node* baru = new Node{nama, nullptr};
    if (isEmpty(Q)) {
        Q.head = Q.tail = baru;
    } else {
        Q.tail->next = baru;
        Q.tail = baru;
    }
    cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    Node* hapus = Q.head;
    cout << "Menghapus data " << hapus->nama << "..." << endl;
    Q.head = Q.head->next;
    if (Q.head == nullptr) {
        Q.tail = nullptr;
    }
    delete hapus;
}

void viewQueue(queue Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!" << endl;
        return;
    }
    int i = 1;
    for (Node* p = Q.head; p != nullptr; p = p->next) {
        cout << i++ << ". " << p->nama << endl;
    }
}

void clearQueue(queue &Q) {
    while (!isEmpty(Q)) {
        deQueue(Q);
    }
}

queue.h
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
using namespace std;

struct Node{
    string nama;
    Node* next;; 
};

struct queue{
    Node* head;
    Node* tail;
};

void CreateQueue(queue &Q);
bool isEmpty(queue Q);
bool isFull(queue Q);
void enQueue(queue &Q, const string &nama);
void deQueue(queue &Q);
void viewQueue(queue Q);
void clearQueue(queue &Q);

#endif

penjelasan singkat guided 1
Program ini membahas implementasi ADT Queue menggunakan linked list yang bekerja dengan prinsip (First In First Out), di mana elemen yang pertama masuk adalah elemen pertama yang keluar. Queue direpresentasikan dengan dua pointer, yaitu head sebagai elemen depan dan tail sebagai elemen belakang, sehingga penambahan dan penghapusan elemen dapat dilakukan secara efisien. Fungsi CreateQueue digunakan untuk inisialisasi awal, isEmpty memeriksa kondisi kosong, enQueue menambahkan data baru di bagian belakang queue, dan deQueue menghapus elemen paling depan. Fungsi viewQueue digunakan untuk menampilkan seluruh isi queue dari depan ke belakang, sedangkan clearQueue menghapus semua elemen hingga queue kembali kosong. Implementasi menggunakan linked list membuat queue bersifat dinamis sehingga ukurannya dapat bertambah selama memori masih tersedia.

### 2. ...implementasi ADT Queue menggunakan array

```C++
source code guided 2
```main.cpp
#include "queue.h"
#include <iostream>

using namespace std;

int main(){
    queue Q;

    CreateQueue(Q);
    enQueue(Q, "dhimas");
    enQueue(Q, "Arvin");
    enQueue(Q, "Rizal");
    enQueue(Q, "Hafizh");
    enQueue(Q, "Fathur");
    enQueue(Q, "Daffa");
    cout << endl;

    cout << "--- Isi Queue Setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    deQueue(Q);
    // deQueue(Q);
    // deQueue(Q);
    cout << endl;

    cout << "--- Isi Queue Setelah deQueue ---" << endl;
    viewQueue(Q);

    return 0;
}

queue.cpp
#include "queue.h"
#include <iostream>

using namespace std;

// NOTE : 
// Implementasi 1 = head diam, tail bergerak (Queue Linear Statis, kerana head nya tetap diam)
// Implementasi 2 = head bergerak, tail bergerak (Queue Linear Dinamis, karena head & tail nya sama-sama bergerak)
// Implementasi 3 = head dan tail berputar (Queue Circular, karena jika udh mentok tapi masih ada space, diputar sehingga tail bisa ada didepan head)

bool isEmpty(queue Q){
    if(Q.head == -1 && Q.tail == -1){
        return true;
    } else {
        return false;
    }
}

//isFull implmenetasi 1 & 2
bool isFull(queue Q){
    if(Q.tail == MAKSIMAL - 1){
        return true;
    } else {
        return false;
    }
}

// //isFull implementasi 3
// bool isFull(queue Q){
//     if((Q.tail + 1) % MAKSIMAL == Q.head){
//         return true;
//     } else {
//         return false;
//     }
// }

void CreateQueue(queue &Q){ //terbentuk queue dengan head = -1 dan tail = -1 
    Q.head = -1;
    Q.tail = -1;
}

//enqueue implementasi 1 & 2
void enQueue(queue &Q, string nama){
    if(isFull(Q) == true){
        cout << "Queue sudah penuh!" << endl;
    } else {
        if(isEmpty(Q) == true){
            Q.head = Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.nama[Q.tail] = nama;
        cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
    }
}

// //enQueue implementasi 3
// void enQueue(queue &Q, string nama){
//     if(isFull(Q) == true){
//         cout << "Queue sudah penuh!" << endl;
//     } else {
//         if(isEmpty(Q) == true){
//             Q.head = Q.tail = 0;
//         } else {
//             Q.tail = (Q.tail + 1) % MAKSIMAL; // bergerak melingkar
//         }
//         Q.nama[Q.tail] = nama;
//         cout << "nama " << nama << " berhasil ditambahkan kedalam queue!" << endl;
//     }
// }

//dequeue implementasi 1
void deQueue(queue &Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
        for(int i = 0; i < Q.tail; i++){
            Q.nama[i] =  Q.nama[i+1];
        }
        Q.tail--;
        if(Q.tail < 0){ //kalo semua isi queue nya udh dikelaurin, set head & tail ke -1
            Q.head = -1;
            Q.tail = -1;
        }
    }
}

// //dequeue implementasi 2
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         Q.head++;
//         if(Q.head > Q.tail){ //kalo elemennya udh abis (head akan lebih 1 dari tail), maka reset ulang head & tail ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         }
//     }
// }

// //deQueue implementasi 3
// void deQueue(queue &Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         cout << "Mengahapus data " << Q.nama[Q.head] << "..." << endl;
//         if(Q.head == Q.tail){ //kalo elemennya tinggal 1, langsungkan saja head & tail nya reset ke -1
//             Q.head = -1;
//             Q.tail = -1;
//         } else {
//             Q.head = (Q.head + 1) % MAKSIMAL; // bergerak melingkar
//         }
//     }
// }

//viewQueue implementasi 1 & 2
void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        for(int i = Q.head; i <= Q.tail; i++){
            cout << i -  Q.head + 1 << ". " << Q.nama[i] << endl;
        }
    }
    cout << endl;
}

// //viewQueue implementasi 3
// void viewQueue(queue Q){
//     if(isEmpty(Q) == true){
//         cout << "Queue kosong!" << endl;
//     } else {
//         int i = Q.head;
//         int count = 1;
//         while(true){
//             cout << count << ". " << Q.nama[i] << endl;
//             if(i == Q.tail){
//                 break;
//             }
//             i = (i + 1) % MAKSIMAL;
//             count++;
//         }   
//     }
// }
 
 queue.h
 #ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
using namespace,std;
const int MAKSIMAL = 5;

struct queue{
    string nama[MAKSIMAL];
    int head;
    int tail;

};

bool isFull(queue Q);
bool isEmpty(queue Q);
void CreateQueue(queue &Q);
void enQueue(queue &Q, string nama);
void deQueue(queue &Q);
void viewQueue(queue Q);

endif 

penjelasan singkat guided 2
Guided 2 membahas implementasi ADT Queue menggunakan array dengan tiga pendekatan berbeda: Implementasi 1 (head diam, tail bergerak), Implementasi 2 (head bergerak, tail bergerak), dan Implementasi 3 (head dan tail berputar/circular queue). Pada semua implementasi, queue direpresentasikan oleh array nama[] dengan dua indeks head dan tail. Fungsi CreateQueue menginisialisasi queue dengan head = tail = -1, isEmpty memeriksa apakah queue kosong, dan isFull memeriksa apakah array sudah penuh. Fungsi enQueue menambahkan elemen ke posisi tail, sedangkan deQueue menghapus elemen pada indeks head. Perbedaan utama terletak pada cara elemen digeser atau bagaimana indeks bergerak: implementasi 1 menggeser seluruh isi array saat dequeue, implementasi 2 cukup menggeser indeks head, dan implementasi 3 menggunakan operasi modulo agar indeks head–tail bisa berputar memanfaatkan ruang kosong di depan array. Fungsi viewQueue menampilkan seluruh isi queue sesuai mekanisme masing-masing. Fokus dari guided ini adalah memahami perilaku head–tail pada tiap jenis queue dan bagaimana perubahan indeks mempengaruhi efisiensi operasi.

## Unguided 

### 1. Buatlah ADT Queue menggunakan ARRAY sebagai berikut di dalam file “queue.h”

```C++
source code unguided 1
```main.cpp
#include <iostream>
using namespace std;     

#include "queue.h"       

int main() {
    cout << "Hello World!" << endl;
    Queue Q;
    createQueue(Q);

    cout<<"--------------------------"<<endl;
    cout<<"H - T \t| Queue info"<<endl;
    cout<<"--------------------------"<<endl;

    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

queue.cpp
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1 && Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh\n";
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
            Q.tail = 0;
        } else {
            Q.tail++;
        }
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    infotype x;
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong\n";
        return -1;
    } else {
        x = Q.info[Q.head];
        if (Q.head == Q.tail) {
            Q.head = Q.tail = -1;
        } else {
            Q.head++;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << " \t| Queue info ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

...queue.h
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];   
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan8_modul8/latihan1_1.png)


penjelasan unguided 1 
unguided 1, Queue diimplementasikan menggunakan array linear statis dengan kapasitas tetap (5 elemen). Struktur queue direpresentasikan oleh indeks head dan tail yang menunjukkan posisi awal dan akhir data. Operasi enqueue menambah elemen pada posisi tail, sementara dequeue menghapus elemen pada posisi head dengan cara menggeser seluruh elemen ke kiri satu posisi. Fungsi isEmptyQueue mengecek apakah queue masih kosong, dan isFullQueue mengecek apakah posisi tail sudah mencapai kapasitas maksimum. Implementasi ini bekerja secara sederhana, namun kurang efisien saat dequeue karena membutuhkan pergeseran elemen setiap kali operasi dilakukan.


### 2.  Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
 queue Alternatif 2 (head bergerak, tail bergerak).
```C++
source code unguided 2
```main.cpp
#include <iostream>
using namespace std;     

#include "queue.h"       

int main() {
    cout << "Hello World!" << endl;
    Queue Q;
    createQueue(Q);

    cout<<"--------------------------"<<endl;
    cout<<"H - T \t| Queue info"<<endl;
    cout<<"--------------------------"<<endl;

    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

...queue.cpp
#include <iostream>
#include "queue.h"
using namespace std;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return (Q.tail == 4);  
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    for (int i = 0; i < Q.tail; i++) {
        Q.info[i] = Q.info[i + 1];
    }

    Q.tail--;

    if (Q.tail < 0) {
        Q.head = Q.tail = -1;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| Queue info ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    for (int i = Q.head; i <= Q.tail; i++) {
        cout << Q.info[i] << " ";
    }
    cout << endl;
}

...queue.h
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];   
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif



### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1] https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan8_modul8/latihan2_1.png)

penjelasan unguided 2
queue masih menggunakan array linear, tetapi mekanismenya sudah lebih efisien dibandingkan unguided 1. Di sini, proses dequeue tidak lagi menggeser semua elemen, melainkan cukup menaikkan nilai head satu langkah. tail tetap bergerak maju sesuai jumlah elemen masuk. Hal ini membuat operasi dequeue lebih cepat karena tidak ada pergeseran data. Namun, implementasi ini tetap memiliki kelemahan: ketika tail sudah mencapai batas array, queue dianggap penuh meskipun ada ruang kosong di depan akibat pergerakan head. Dengan kata lain, kapasitas array tidak dimanfaatkan secara optimal.

### 3. Buatlah implementasi ADT Queue pada file “queue.cpp” dengan menerapkan mekanisme
 queue Alternatif 3 (head dan tail berputar).

```C++
source code unguided 3
```main.cpp
#include <iostream>
using namespace std;     

#include "queue.h"       

int main() {
    cout << "Hello World!" << endl;
    Queue Q;
    createQueue(Q);

    cout<<"--------------------------"<<endl;
    cout<<"H - T \t| Queue info"<<endl;
    cout<<"--------------------------"<<endl;

    printInfo(Q);
    enqueue(Q,5); printInfo(Q);
    enqueue(Q,2); printInfo(Q);
    enqueue(Q,7); printInfo(Q);
    dequeue(Q); printInfo(Q);
    enqueue(Q,4); printInfo(Q);
    dequeue(Q); printInfo(Q);
    dequeue(Q); printInfo(Q);

    return 0;
}

...queue.cpp
#include <iostream>
#include "queue.h"
using namespace std;

const int MAX = 5;

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.head == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Queue penuh" << endl;
        return;
    }

    if (isEmptyQueue(Q)) {
        Q.head = 0;
        Q.tail = 0;
    } else {
        Q.tail = (Q.tail + 1) % MAX;
    }

    Q.info[Q.tail] = x;
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        cout << "Queue kosong" << endl;
        return -1;
    }

    infotype x = Q.info[Q.head];

    if (Q.head == Q.tail) {
        Q.head = Q.tail = -1;
    } else {
        Q.head = (Q.head + 1) % MAX;
    }

    return x;
}

void printInfo(Queue Q) {
    cout << Q.head << " - " << Q.tail << "\t| Queue info ";

    if (isEmptyQueue(Q)) {
        cout << "empty queue" << endl;
        return;
    }

    int i = Q.head;
    while (true) {
        cout << Q.info[i] << " ";
        if (i == Q.tail) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

...queue.h
#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue {
    infotype info[5];   
    int head, tail;
};

void createQueue(Queue &Q);
bool isEmptyQueue(Queue Q);
bool isFullQueue(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif


### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1] (https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan8_modul8/latihan3_1.png)

penjelasan unguided 3
Unguided 3 merupakan implementasi queue yang paling efisien dengan menggunakan array melingkar (circular). Pada mekanisme ini, baik head maupun tail akan bergerak menggunakan operasi modulo sehingga dapat kembali ke indeks awal ketika mencapai batas array. Metode ini memungkinkan pemanfaatan penuh kapasitas array tanpa harus melakukan pergeseran elemen. Operasi enqueue dan dequeue bekerja sangat efisien karena hanya melibatkan pergerakan indeks, bukan pemindahan data. Queue dianggap penuh jika (tail + 1) % MAX == head, bentuk pengecekan yang khas pada circular queue.
## Kesimpulan
...ADT Queue dapat diimplementasikan menggunakan linked list maupun array, masing-masing dengan kelebihan dan kekurangan. Implementasi dengan linked list bersifat dinamis sehingga tidak memiliki batas kapasitas, sedangkan implementasi dengan array memiliki kapasitas tetap namun dapat dibuat lebih efisien dengan teknik circular queue. Tiga alternatif queue pada array—head diam, head dan tail bergerak, serta head dan tail berputar—menunjukkan perbedaan efisiensi terutama pada operasi dequeue. Circular queue menjadi pilihan terbaik untuk memaksimalkan ruang dan menghindari pergeseran elemen yang mahal secara waktu. Secara keseluruhan, pemahaman berbagai mekanisme ini penting agar dapat memilih struktur data queue sesuai kebutuhan program.

## Referensi
[1] https://www.dicoding.com/blog/struktur-data-queue-pengertian-fungsi-dan-jenisnya/
<br>
[2] Aliyanto, A. (2011, June). Sistem Pembelajaran Algoritma Stack dan Queue dengan Pendekatan Problem Based Learning untuk Mendukung Pembelajaran Struktur Data. In Seminar Nasional Aplikasi Teknologi Informasi (SNATI).
<br>...
