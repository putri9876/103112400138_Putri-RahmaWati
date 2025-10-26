# <h1 align="center">Laporan Praktikum Modul 5 -SINGLY LINKED LIST (BAGUAN KEDUA) </h1>
<p align="center">Putri Rahma Wati - 103112400138</p>

## Dasar Teori
[1]Linked list atau senarai berantai adalah salah satu bentuk struktur data yang berisi kumpulan data (node) yang tersusun secara sekuensial, saling terhubung melalui pointer, dan bersifat dinamis.[2] Salah satu bentuk struktur data yang berisi kumpulan data yang tersusun secara
sekuensial, saling bersambungan, dinamis dan terbatas adalah senarai berkait (linked list).
Suatu senarai berkait (linked list) adalah suatu simpul (node) yang dikaitkan dengan simpul yang
lain dalam suatu urutan tertentu. Suatu simpul dapat berbentuk suatu struktur atau class.
Simpul harus mempunyai satu atau lebih elemen struktur atau class yang berisi data. Secara
teori, linked list adalah sejumlah node yang dihubungkan secara linier dengan bantuan
pointer. Senarai berkait lebih efisien di dalam melaksanakan penyisipan-penyisipan dan
penghapusan-penghapusan. Senarai berkait juga menggunakan alokasi penyimpanan secara
dinamis, yang merupakan penyimpanan yang dialokasikan pada runtime. Karena di dalam
banyak aplikasi, ukuran dari data itu tidak diketahui pada saat kompile, hal ini bisa
merupakan suatu atribut yang baik juga. Setiap node akan berbentuk struct dan memiliki satu
buah field bertipe struct yang sama, yang berfungsi sebagai pointer

### A. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

### B. ...<br/>
...
#### 1. ...
#### 2. ...
#### 3. ...

## Guided 
### 1.List buah 
```C++
source code guided linked list
1. listBuah.cpp
```include "listBuah.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void referensielLast(linkedlist &List){
    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 1 (UPDATE) -----*/
//prosedur-prosedur untuk melakukan update data node
void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedlist List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

/*----- MATERI PERTEMUAN 5 - SINGLY LINKED LIST (BAGIAN KEDUA) - PART 2 (SEARCHING) -----*/
//prosedur-prosedur untuk searching data
//prosedur untuk mencari node berdasarkan data
void FindNodeByData(linkedlist list, string data){
    if(isEmpty(list) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while(nodeBantu != Nil){
            posisi++;
            if(nodeBantu->isidata.nama == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false){
            cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan alamat node
void FindNodeByAddress(linkedlist list, address node) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        while (nodeBantu != Nil) {
            posisi++;
            if(nodeBantu == node) {
                cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
                cout << "Alamat node : " << nodeBantu << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                found = true;
                break;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Node dengan alamat " << node << " tidak ditemukan dalam list!" << endl;
        }
    }
    cout << endl;
}

//prosedur untuk mencari node berdasarkan range data (range harga)
void FindNodeByRange(linkedlist list, float hargaAwal, float hargaAkhir) {
    if(isEmpty(list) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = list.first;
        int posisi = 0;
        bool found = false;
        cout << "--- Buah dalam range harga " << hargaAwal << " - " << hargaAkhir << " ---" << endl;
        cout << "-------------------------------------------" << endl;
        while (nodeBantu != Nil) {
            posisi++;
            float harga = nodeBantu->isidata.harga;
            if(harga >= hargaAwal && harga <= hargaAkhir) {
                cout << "Data ditemukan pada posisi ke-" << posisi << " :" << endl;
                cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
                cout << "-------------------------------------------" << endl;
                found = true;
            }
            nodeBantu = nodeBantu->next;
        }
        if(found == false) {
            cout << "Tidak ada data buah dalam range harga tersebut!" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    cout << endl;
}

2. listBuah.h
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL

#include<iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah; 
    float harga;
};

typedef buah dataBuah; //Memberikan nama alias databuah untuk struct buah.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataBuah isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
//Materi modul 4
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);
void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);

//materi modul 5 (part 2 - searching)
void FindNodeByData(linkedlist list, string data);
void FindNodeByAddress(linkedlist list, address node);
void FindNodeByRange(linkedlist list, float hargaAwal, float HargaAkhir);

#endif

3. main.cpp
#include "listBuah.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtBuah;

    nodeA = alokasi("Jeruk", 100, 3000);
    nodeB = alokasi("Apel", 75, 4000);
    nodeC = alokasi("Pir", 87, 5000);
    nodeD = alokasi("Semangka", 43, 11500);
    nodeE = alokasi("Durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List, nodeD);

    cout << "--- ISI LIST SETELAH DILAKUKAN UPDATE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    FindNodeByData(List, "kelapa");
    FindNodeByAddress(List, nodeC);
    FindNodeByRange(List, 5000, 10000);

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}

penjelasan singkat guided list linked
 
### Tugas Modul 5
### Buatlah ADT Singly Linked list sebagai berikut di dalam file “ListAngka.h” :
```C++
source code unguided 1
```
1. listangka.cpp
#include "listangka.h"

void createList(linkedList &L) {
    L.first = NULL;
}

address alokasi(dataAngka x) {
    address p = new node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = NULL;
}

void printList(linkedList L) {
    address p = L.first;
    while (p != NULL) {
        cout << p->angka << " - ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(linkedList &L, address p) {
    p->next = L.first;
    L.first = p;
}

void insertLast(linkedList &L, address p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void insertAfter(linkedList &L, address p, address prec) {
    if (prec != NULL) {
        p->next = prec->next;
        prec->next = p;
    }
}

int nbList(linkedList L) {
    int count = 0;
    address p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void delAfter(linkedList &L, address &p, address prec) {
    if (prec != NULL && prec->next != NULL) {
        p = prec->next;
        prec->next = p->next;
        dealokasi(p);
    }
}

2. listangka.h
#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &p);
void printList(linkedList L);
void insertFirst(linkedList &L, address p);
void insertLast(linkedList &L, address p);
void insertAfter(linkedList &L, address p, address prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &p, address prec);

#endif
3. main.cpp
#include "listangka.h"

int main() {
    linkedList L;
    createList(L);

    address nodeA = alokasi(8);
    address nodeB = alokasi(13);
    address nodeC = alokasi(18);
    address nodeD = alokasi(25);
    address nodeE = alokasi(33);
    address nodeF = alokasi(40);

    insertFirst(L, nodeB);        
    insertLast(L, nodeA);         
    insertAfter(L, nodeD, nodeB); 
    insertFirst(L, nodeC);        
    insertLast(L, nodeE);         
    insertFirst(L, nodeF);       
    address temp;
    delAfter(L, temp, nodeC);     

    printList(L);
    return 0;
}
##### Output 
![Screenshot Outputtugas](https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/outputtugas-unguidedtugas.png)
Penjelasan singkat:


### 1.  Buatlah procedure updateFirst, updateLast, dan updateAfter dengan rincian 
sebagai berikut : 
Procedure updateFirst ( input / output L : List ) 
Procedure updateLast ( input / output L : List ) 
Procedure updateAfter ( input / output L : List, input nodePrev : address ) 
Kemudian pada “main.cpp” lakukanlah : 
➢ Update data 40 menjadi 50 
➢ Update data 8 menjadi 29 
➢ Update data 33 menjadi 45 
➢ Update data 18 menjadi 20 
➢ Tampilkan seluruh list setelah diupdate 

```C++
source code unguided 1
```
1. listangka.cpp
#include "listangka.h"

void createList(linkedList &L) {
    L.first = NULL;
}

address alokasi(dataAngka x) {
    address p = new node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = NULL;
}

void printList(linkedList L) {
    address p = L.first;
    while (p != NULL) {
        cout << p->angka << " - ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(linkedList &L, address p) {
    p->next = L.first;
    L.first = p;
}

void insertLast(linkedList &L, address p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void insertAfter(linkedList &L, address p, address prec) {
    if (prec != NULL) {
        p->next = prec->next;
        prec->next = p;
    }
}

int nbList(linkedList L) {
    int count = 0;
    address p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void delAfter(linkedList &L, address &p, address prec) {
    if (prec != NULL && prec->next != NULL) {
        p = prec->next;
        prec->next = p->next;
        dealokasi(p);
    }
}

void updateFirst(linkedList &L) {
    if (L.first != NULL) {
        cout << "Masukkan update data node pertama :" << endl;
        cout << "masukkan angka : ";
        cin >> L.first->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.first != NULL) {
        address p = L.first;
        while (p->next != NULL) {
            p = p->next;
        }
        cout << "masukkan update data node terakhir :" << endl;
        cout << "Masukkan angka : ";
        cin >> p->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateAfter(linkedList &L, address prec) {
    if (prec != NULL && prec->next != NULL) {
        cout << "masukkan update data node setelah node " << prec->angka << " :" << endl;
        cout << "Masukkan angka : ";
        cin >> prec->next->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

2. listangka.h
#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &p);
void printList(linkedList L);
void insertFirst(linkedList &L, address p);
void insertLast(linkedList &L, address p);
void insertAfter(linkedList &L, address p, address prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &p, address prec);

#endif

3. main..cpp
#include "listangka.h"

int main() {
    linkedList L;
    createList(L);

    address nodeA = alokasi(8);
    address nodeB = alokasi(13);
    address nodeC = alokasi(18);
    address nodeD = alokasi(25);
    address nodeE = alokasi(33);
    address nodeF = alokasi(40);

    insertFirst(L, nodeB);
    insertLast(L, nodeA);
    insertAfter(L, nodeD, nodeB);
    insertFirst(L, nodeC);
    insertLast(L, nodeE);
    insertFirst(L, nodeF);
    address temp;
    delAfter(L, temp, nodeC);

    printList(L);
    cout << endl;

    updateFirst(L);         
    updateAfter(L, nodeD);   
    updateLast(L);           
    updateAfter(L, nodeF);   

    printList(L);

    return 0;
}

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/output1-unguided1-1.png)

penjelasan unguided 1 
Program menunjukkan kemampuan modifikasi data node tanpa mengubah struktur list. Operasi update ini penting untuk menjaga efisiensi penyimpanan dan fleksibilitas pengelolaan data dalam list.

### 2. Buatlah procedure SearchByData, SearchByAddress, dan SearchByRange dengan 
rincian sebagai berikut : 
Procedure SearchByData( input L : List, input data : integer ) 
Procedure SearchByAddress( input L : List, input node : address ) 
Procedure SearchByRange( input L : List, input nilaiMin : integer ) 
Kemudian pada “main.cpp” lakukanlah : 
➢ Mencari data nilai 20 
➢ Mencari data nilai 55 
➢ Mencari data alamat nodeB 
➢ Mencari data alamat nodeA 
➢ Mencari data dengan nilai minimal 40  

```C++
source code unguided 2
```
1. listangka.cpp
#include "listangka.h"

void createList(linkedList &L) {
    L.first = NULL;
}

address alokasi(dataAngka x) {
    address p = new node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = NULL;
}

void printList(linkedList L) {
    address p = L.first;
    while (p != NULL) {
        cout << p->angka << " - ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(linkedList &L, address p) {
    p->next = L.first;
    L.first = p;
}

void insertLast(linkedList &L, address p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void insertAfter(linkedList &L, address p, address prec) {
    if (prec != NULL) {
        p->next = prec->next;
        prec->next = p;
    }
}

int nbList(linkedList L) {
    int count = 0;
    address p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void delAfter(linkedList &L, address &p, address prec) {
    if (prec != NULL && prec->next != NULL) {
        p = prec->next;
        prec->next = p->next;
        dealokasi(p);
    }
}

void updateFirst(linkedList &L) {
    if (L.first != NULL) {
        cout << "Masukkan update data node pertama :" << endl;
        cout << "masukkan angka : ";
        cin >> L.first->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.first != NULL) {
        address p = L.first;
        while (p->next != NULL) {
            p = p->next;
        }
        cout << "masukkan update data node terakhir :" << endl;
        cout << "Masukkan angka : ";
        cin >> p->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateAfter(linkedList &L, address prec) {
    if (prec != NULL && prec->next != NULL) {
        cout << "masukkan update data node setelah node " << prec->angka << " :" << endl;
        cout << "Masukkan angka : ";
        cin >> prec->next->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

2. listangka.h
#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &p);
void printList(linkedList L);
void insertFirst(linkedList &L, address p);
void insertLast(linkedList &L, address p);
void insertAfter(linkedList &L, address p, address prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &p, address prec);

#endif
3. main.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* address;
struct List {
    address first;
};

void createList(List &L) {
    L.first = NULL;
}

address allocate(int dataBaru) {
    address P = new Node;
    P->data = dataBaru;
    P->next = NULL;
    return P;
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void showAll(List L) {
    address P = L.first;
    while (P != NULL) {
        cout << P->data << " - ";
        P = P->next;
    }
    cout << endl;
}

void updateFirst(List &L, int newData) {
    if (L.first != NULL) {
        L.first->data = newData;
        cout << "Data Berhasil Diupdate!" << endl;
    }
}

void updateLast(List &L, int newData) {
    address P = L.first;
    if (P == NULL) return;
    while (P->next != NULL) {
        P = P->next;
    }
    P->data = newData;
    cout << "Data Berhasil Diupdate!" << endl;
}

void updateAfter(List &L, int prevData, int newData) {
    address P = L.first;
    while (P != NULL && P->data != prevData) {
        P = P->next;
    }
    if (P != NULL && P->next != NULL) {
        P->next->data = newData;
        cout << "Data Berhasil Diupdate!" << endl;
    }
}

void SearchByData(List L, int dataCari) {
    address P = L.first;
    int posisi = 1;
    bool found = false;
    while (P != NULL) {
        if (P->data == dataCari) {
            cout << "Data " << dataCari << " ditemukan pada posisi ke-" << posisi << "!" << endl;
            found = true;
            break;
        }
        P = P->next;
        posisi++;
    }
    if (!found) {
        cout << "Node dengan data " << dataCari << " tidak ditemukan!" << endl;
    }
}

void SearchByAddress(List L, address nodeCari) {
    address P = L.first;
    int posisi = 1;
    bool found = false;
    while (P != NULL) {
        if (P == nodeCari) {
            cout << "Node ditemukan pada posisi ke-" << posisi << "!" << endl;
            cout << "Alamat node : " << P << endl;
            found = true;
            break;
        }
        P = P->next;
        posisi++;
    }
    if (!found) {
        cout << "Node dengan alamat " << nodeCari << " tidak ditemukan dalam list!" << endl;
    }
}

void SearchByRange(List L, int nilaiMin) {
    address P = L.first;
    int posisi = 1;
    cout << "--- Data diatas nilai " << nilaiMin << " ---" << endl;
    while (P != NULL) {
        if (P->data > nilaiMin) {
            cout << "-----------------------------------------------" << endl;
            cout << "Data ditemukan pada posisi ke-" << posisi << ", nilai : " << P->data << endl;
        }
        P = P->next;
        posisi++;
    }
    cout << "-----------------------------------------------" << endl;
}

int main() {
    List L;
    createList(L);

    insertLast(L, allocate(50));
    insertLast(L, allocate(20));
    insertLast(L, allocate(25));
    insertLast(L, allocate(29));
    insertLast(L, allocate(45));

    showAll(L);
    cout << endl;

    SearchByData(L, 20);
    cout << endl;

    SearchByData(L, 55);
    cout << endl;

    address nodeA = L.first;       
    address nodeB = L.first->next; 
    SearchByAddress(L, (address)0x2748f6f3630); 
    cout << endl;

    SearchByAddress(L, nodeA->next->next->next); 
    cout << endl;

    SearchByRange(L, 40);

    return 0;
}

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/output2-unguided2-1.png)

penjelasan unguided 2
Program mendemonstrasikan cara traversal list untuk menemukan data tertentu. Pencarian dilakukan dengan perulangan hingga data atau alamat yang dicari ditemukan. Fitur ini berguna untuk analisis atau validasi data dalam struktur list.

### 3.  Lakukanlah operasi aritmetika penjumlahan, pengurangan, dan perkalian terhadap 
semua data yang ada didalam list tersebut! Untuk penjumlahan nilai awal adalah 0, 
untuk pengurangan nilai awal adalah nilai node pertama (first), untuk perkalian nilai 
awal adalah 1. 
Output yang diharapkan :

```C++
source code unguided 3
```
1. listangka.cpp
#include "listangka.h"

void createList(linkedList &L) {
    L.first = NULL;
}

address alokasi(dataAngka x) {
    address p = new node;
    p->angka = x;
    p->next = NULL;
    return p;
}

void dealokasi(address &p) {
    delete p;
    p = NULL;
}

void printList(linkedList L) {
    address p = L.first;
    while (p != NULL) {
        cout << p->angka << " - ";
        p = p->next;
    }
    cout << endl;
}

void insertFirst(linkedList &L, address p) {
    p->next = L.first;
    L.first = p;
}

void insertLast(linkedList &L, address p) {
    if (L.first == NULL) {
        L.first = p;
    } else {
        address q = L.first;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = p;
    }
}

void insertAfter(linkedList &L, address p, address prec) {
    if (prec != NULL) {
        p->next = prec->next;
        prec->next = p;
    }
}

int nbList(linkedList L) {
    int count = 0;
    address p = L.first;
    while (p != NULL) {
        count++;
        p = p->next;
    }
    return count;
}

void delAfter(linkedList &L, address &p, address prec) {
    if (prec != NULL && prec->next != NULL) {
        p = prec->next;
        prec->next = p->next;
        dealokasi(p);
    }
}

void updateFirst(linkedList &L) {
    if (L.first != NULL) {
        cout << "Masukkan update data node pertama :" << endl;
        cout << "masukkan angka : ";
        cin >> L.first->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateLast(linkedList &L) {
    if (L.first != NULL) {
        address p = L.first;
        while (p->next != NULL) {
            p = p->next;
        }
        cout << "masukkan update data node terakhir :" << endl;
        cout << "Masukkan angka : ";
        cin >> p->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

void updateAfter(linkedList &L, address prec) {
    if (prec != NULL && prec->next != NULL) {
        cout << "masukkan update data node setelah node " << prec->angka << " :" << endl;
        cout << "Masukkan angka : ";
        cin >> prec->next->angka;
        cout << "Data Berhasil Diupdate!" << endl << endl;
    }
}

2. listangka.h
#ifndef LISTANGKA_H
#define LISTANGKA_H

#include <iostream>
using namespace std;

typedef int dataAngka;
typedef struct node *address;

struct node {
    dataAngka angka;
    address next;
};

struct linkedList {
    address first;
};

void createList(linkedList &L);
address alokasi(dataAngka x);
void dealokasi(address &p);
void printList(linkedList L);
void insertFirst(linkedList &L, address p);
void insertLast(linkedList &L, address p);
void insertAfter(linkedList &L, address p, address prec);
int nbList(linkedList L);
void delAfter(linkedList &L, address &p, address prec);

#endif

3. main.cpp
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

typedef Node* address;
struct List {
    address first;
};

void createList(List &L) {
    L.first = NULL;
}

address allocate(int dataBaru) {
    address P = new Node;
    P->data = dataBaru;
    P->next = NULL;
    return P;
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}


void totalPenjumlahan(List L) {
    int total = 0;
    address P = L.first;
    while (P != NULL) {
        total += P->data;
        P = P->next;
    }
    cout << "Total penjumlahan : " << total << endl;
}

void totalPengurangan(List L) {
    if (L.first == NULL) return;
    int total = L.first->data;
    address P = L.first->next;
    while (P != NULL) {
        total -= P->data;
        P = P->next;
    }
    cout << "\nTotal pengurangan : " << total << endl;
}

void totalPerkalian(List L) {
    int total = 1;
    address P = L.first;
    while (P != NULL) {
        total *= P->data;
        P = P->next;
    }
    cout << "\nTotal perkalian : " << total << endl;
}

int main() {
    List L;
    createList(L);

    insertLast(L, allocate(50));
    insertLast(L, allocate(20));
    insertLast(L, allocate(25));
    insertLast(L, allocate(29));
    insertLast(L, allocate(45));
 
    totalPenjumlahan(L);
    totalPengurangan(L);
    totalPerkalian(L);

    return 0;
}

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/output3-unguided3-1.png)

penjelasan unguided 3
Hasil operasi menunjukkan bagaimana traversal pointer dapat digunakan untuk menghitung nilai-nilai agregat tanpa perlu memindahkan data di memori. Struktur linked list yang fleksibel tetap efisien untuk operasi matematis, asalkan traversal dilakukan dengan benar dari node pertama hingga terakhir.
## Kesimpulan
Singly Linked List merupakan struktur data dinamis yang efisien untuk operasi insert, delete, update, dan search. Melalui praktikum ini, dapat dipahami bahwa setiap operasi bekerja dengan memanipulasi pointer antar-node tanpa perlu menggeser seluruh elemen seperti pada array. Fitur update dan searching memperluas kemampuan pengelolaan data secara langsung di dalam list.

## Referensi
[1]. (https://daismabali.com/artikel_detail/54/1/Mengenal-Single-Linked-List-dalam-Struktur-Data.html)
<br>[2] https://elektro.um.ac.id/wp-content/uploads/2016/04/ASD-Modul-6-Linked-List.pdf
<br>...
