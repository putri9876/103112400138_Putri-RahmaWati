# <h1 align="center">Laporan Praktikum Modu6 Pertemuan ke 6 </h1>
<p align="center">Putri Rahma Wati - 103112400138</p>

## Dasar Teori
Linked list atau yang disebut juga senarai berantai merupakan salah satu bentuk struktur data dinamis yang digunakan untuk menyimpan sekumpulan elemen data secara berurutan, di mana setiap elemen (node) saling terhubung melalui pointer[1]. Struktur ini terdiri atas dua komponen utama yaitu data yang berisi nilai atau informasi yang disimpan, dan pointer yang menunjuk ke node berikutnya (atau sebelumnya pada jenis tertentu). Karena sifatnya yang dinamis, linked list memungkinkan penambahan dan penghapusan elemen tanpa perlu menggeser elemen lain seperti pada array[2].

### A. ...<br/>
...
#### 1. Linked list atau yang disebut juga senarai berantai merupakan salah satu bentuk struktur data dinamis yang digunakan untuk menyimpan sekumpulan elemen data secara berurutan, di mana setiap elemen (node) saling terhubung melalui pointer
#### 2. Struktur ini terdiri atas dua komponen utama yaitu data yang berisi nilai atau informasi yang disimpan, dan pointer yang menunjuk ke node berikutnya (atau sebelumnya pada jenis tertentu). Karena sifatnya yang dinamis, linked list memungkinkan penambahan dan penghapusan elemen tanpa perlu menggeser elemen lain seperti pada array



## Guided 

### 1. ...

```C++
source code guided 1
```listmakanan.cpp
#include "listMakanan.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){ 
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node selanjutnya (nodenext)tidak valid" << endl;
        }
    }
}
2. listmakanan.h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

#endif

3. main.cpp
#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeC);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    return 0;
}

penjelasan singkat guided 1
membahas tentang cara membuat dan mengelola Doubly Linked List, yaitu struktur data yang setiap elemennya saling terhubung dua arah (maju dan mundur). Dalam program ini, data yang disimpan berupa informasi makanan seperti nama, jenis, harga, dan rating. Fungsi-fungsi yang digunakan meliputi membuat list baru, menambahkan data di awal atau akhir list, menyisipkan data sebelum atau sesudah data tertentu, serta menampilkan seluruh isi list. Selain itu, terdapat juga fitur untuk memperbarui isi data yang sudah ada. Melalui Guided 1, kita belajar dasar-dasar pengelolaan data dengan operasi insert dan update pada list yang dapat diakses dari dua arah.

### 2. ...
1. listmkan.cpp
#include "listMakanan.h"
#include <iostream>
#include <string>
using namespace std;

bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedlist &List) {
    List.first = Nil;
    List.last = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string jenis, float harga, float rating) { 
    address nodeBaru = new node;
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jenis = jenis; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->isidata.rating =  rating;
    nodeBaru->next = Nil;
    nodeBaru->prev = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    node->prev = Nil;
    delete node;
}

void insertFirst(linkedlist &List, address nodeBaru){
    if (isEmpty(List)) {
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->next = List.first;
        List.first->prev = nodeBaru;
        List.first = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node pertama list" << endl;
}

void insertLast(linkedlist &List, address nodeBaru){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        nodeBaru->prev = List.last;
        List.last->next = nodeBaru;
        List.last = nodeBaru;
    }
    cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebagai node terakhir list" << endl;
}

void insertAfter(linkedlist &List, address nodeBaru, address nodePrev){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodePrev != Nil){
            if(nodePrev == List.last){
                insertLast(List, nodeBaru);
            } else {
                nodeBaru->next = nodePrev->next;
                nodeBaru->prev = nodePrev;
                (nodePrev->next)->prev = nodeBaru;
                nodePrev->next = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan setelah node " << nodePrev->isidata.nama << endl;
            }
        } else {
            cout << "node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void insertBefore(linkedlist &List, address nodeBaru, address nodeNext){
    if(isEmpty(List) == true){
        List.first = List.last = nodeBaru;
    } else {
        if (nodeNext != Nil){
            if(nodeNext == List.first){
                insertFirst(List, nodeBaru);
            } else {
                nodeBaru->next = nodeNext;
                nodeBaru->prev = nodeNext->prev;
                (nodeNext->prev)->next = nodeBaru;
                nodeNext->prev = nodeBaru;
                cout << "Node " << nodeBaru->isidata.nama << " berhasil ditambahkan sebelum node " << nodeNext->isidata.nama << endl;
            }
        } else {
            cout << "node setelahnya (nodeNext) tidak valid!" << endl;
        }
    }
}

void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama makanan : " << nodeBantu->isidata.nama << endl;
            cout << "Jenis        : " << nodeBantu->isidata.jenis << endl;
            cout << "Harga        : " << nodeBantu->isidata.harga << endl; 
            cout << "Rating       : " << nodeBantu->isidata.rating << endl;
            cout << "-------------------------------" << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

void updateFirst(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.first->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.first->isidata.jenis);
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Rating : ";
        cin >> List.first->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateLast(linkedlist List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node terakhir : " << endl;
        cout << "Nama makanan : ";
        getline(cin, List.last->isidata.nama);
        cout << "Jenis makanan : ";
        getline(cin, List.last->isidata.jenis);
        cout << "Harga : ";
        cin >> List.last->isidata.harga;
        cout << "Rating : ";
        cin >> List.last->isidata.rating;
        cin.ignore(); //menghapus karakter newline (/n) dari input buffer
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl; 
    }
}

void updateAfter(linkedlist List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if(nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (nodePrev) tidak valid!" << endl;
        }
    }
}

void updateBefore(linkedlist List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodeNext != Nil && nodeNext->prev != Nil){
            address nodeBantu = nodeNext->prev;
            cout << "masukkan update data node sebelum node " << nodeNext->isidata.nama << " : " << endl;
            cout << "Nama makanan : ";
            getline(cin, nodeBantu->isidata.nama);
            cout << "Jenis makanan : ";
            getline(cin, nodeBantu->isidata.jenis);
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Rating : ";
            cin >> nodeBantu->isidata.rating;
            cin.ignore(); //menghapus karakter newline (/n) dari input buffer
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

// SEARCHING
void findByName(linkedlist List, string nama){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.nama == nama){
            cout << "Ditemukan (berdasarkan nama):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan nama \"" << nama << "\" tidak ditemukan." << endl;
}

void findByJenis(linkedlist List, string jenis){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.jenis == jenis){
            cout << "Ditemukan (berdasarkan jenis):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Data dengan jenis \"" << jenis << "\" tidak ditemukan." << endl;
}

void findByMinRating(linkedlist List, float minRating){
    if(isEmpty(List)){
        cout << "List kosong!" << endl;
        return;
    }
    address p = List.first;
    while(p != Nil){
        if(p->isidata.rating >= minRating){
            cout << "Ditemukan (rating >= " << minRating << "):" << endl;
            cout << "Nama makanan : " << p->isidata.nama << endl;
            cout << "Jenis        : " << p->isidata.jenis << endl;
            cout << "Harga        : " << p->isidata.harga << endl;
            cout << "Rating       : " << p->isidata.rating << endl;
            return;
        }
        p = p->next;
    }
    cout << "Tidak ada data dengan rating >= " << minRating << "." << endl;
}

// DELETE
void deleteFirst(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.first;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.first = pDel->next;
        List.first->prev = Nil;
        pDel->next = Nil;
    }
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi pertama." << endl;
    dealokasi(pDel);
}

void deleteLast(linkedlist &List){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    address pDel = List.last;
    if(List.first == List.last){
        List.first = List.last = Nil;
    } else {
        List.last = pDel->prev;
        List.last->next = Nil;
        pDel->prev = Nil;
    }
    pDel->next = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus dari posisi terakhir." << endl;
    dealokasi(pDel);
}

void deleteAfter(linkedlist &List, address Prev){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(Prev == Nil || Prev->next == Nil){
        cout << "Node sebelumnya (Prev) tidak valid atau tidak ada node setelahnya!" << endl;
        return;
    }
    if(Prev->next == List.last){
        deleteLast(List);
        return;
    }
    address pDel = Prev->next;
    Prev->next = pDel->next;
    pDel->next->prev = Prev;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus setelah node " << Prev->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteBefore(linkedlist &List, address nodeNext){
    if(isEmpty(List) == true){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }
    if(nodeNext == Nil || nodeNext->prev == Nil){
        cout << "Node setelahnya (nodeNext) tidak valid atau tidak ada node sebelumnya!" << endl;
        return;
    }
    if(nodeNext->prev == List.first){
        deleteFirst(List);
        return;
    }
    address pDel = nodeNext->prev;
    nodeNext->prev = pDel->prev;
    pDel->prev->next = nodeNext;
    pDel->next = Nil;
    pDel->prev = Nil;
    cout << "Node " << pDel->isidata.nama << " berhasil dihapus sebelum node " << nodeNext->isidata.nama << "." << endl;
    dealokasi(pDel);
}

void deleteNode(linkedlist &List, address target){
    if(isEmpty(List) == true || target == Nil){
        cout << "Target tidak valid atau list kosong!" << endl;
        return;
    }
    if(target == List.first){
        deleteFirst(List);
    } else if(target == List.last){
        deleteLast(List);
    } else {
        address L = target->prev;
        address R = target->next;
        L->next = R;
        R->prev = L;
        target->next = Nil;
        target->prev = Nil;
        cout << "Node " << target->isidata.nama << " berhasil dihapus dari tengah list." << endl;
        dealokasi(target);
    }
}

void deleteByName(linkedlist &List, string nama){
    if(isEmpty(List)){
        cout << "List kosong! Tidak ada node yang dihapus." << endl;
        return;
    }

    address target = List.first;
    while(target != Nil && target->isidata.nama != nama){
        target = target->next;
    }
    if(target == Nil){
        cout << "Node dengan nama \"" << nama << "\" tidak ditemukan." << endl;
        return;
    }

    deleteNode(List, target);
    cout << "Node dengan nama \"" << nama << "\" telah dihapus dan didealokasi." << endl;
}

2. listmakanan.h
#ifndef LISTMAKANAN_H
#define LISTMAKANAN_H
#define Nil NULL

#include<iostream>
using namespace std;

struct makanan{
    string nama;
    string jenis; 
    float harga;
    float rating; 
};

typedef makanan dataMakanan;

typedef struct node *address;

struct node{
    dataMakanan isidata;
    address next;
    address prev;
};

struct linkedlist{
    address first;
    address last;
};

bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string jenis, float harga, float rating);
void dealokasi(address &node);

void insertFirst(linkedlist &List, address nodeBaru);
void insertLast(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertBefore(linkedlist &List, address nodeBaru, address nodeNext);

void printList(linkedlist List);

void updateFirst(linkedlist List);
void updateLast(linkedlist List);
void updateAfter(linkedlist List, address prev);
void updateBefore(linkedlist List, address nodeNext);

// Searching
void findByName(linkedlist List, string nama);
void findByJenis(linkedlist List, string jenis);
void findByMinRating(linkedlist List, float minRating);

// Delete
void deleteFirst(linkedlist &List);
void deleteLast(linkedlist &List);
void deleteAfter(linkedlist &List, address Prev);
void deleteBefore(linkedlist &List, address nodeNext);

void deleteNode(linkedlist &List, address target);
void deleteByName(linkedlist &List, string nama);

#endif

3. main.cpp
	#include "listMakanan.h"
#include <iostream>

using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMakanan dtMakanan;

    nodeA = alokasi("Nasi Rames", "Makanan Berat", 10000, 8.5);
    nodeB = alokasi("Ayam Geprek", "Makanan Berat", 13000, 9.0);
    nodeC = alokasi("Risol Mayo", "Makanan Ringan", 3500, 8.8);
    nodeD = alokasi("Mie Ayam", "Makanan Berat", 15000, 9.9);
    nodeE = alokasi("Donat", "Makanan Ringan", 2000, 7.7);

    insertFirst(List, nodeD);
    insertLast(List, nodeE);
    insertAfter(List, nodeA, nodeD);
    insertBefore(List, nodeC, nodeE);
    insertLast(List, nodeB);
    cout << endl;

    //D - A - C - E - B
    cout << "--- Isi List Setelah Insert ---" << endl;
    printList(List);
    cout << endl;

    updateFirst(List);
    updateLast(List);
    updateBefore(List, nodeC);
    updateAfter(List, nodeA);

    cout << "--- Isi List Setelah Update ---" << endl;
    printList(List);

    cout << endl;

    findByName(List, "Nasgor");

    deleteByName(List, "Nasgor");
    deleteFirst(List);
    deleteBefore(List, nodeE);

    cout << endl << "--- Isi List Setelah Delete ---" << endl;
    printList(List);

    return 0;
}

penjelasan singkat guided 2
membahas tentang cara membuat dan mengelola Doubly Linked List, yaitu struktur data yang setiap elemennya saling terhubung dua arah (maju dan mundur) Dalam program ini, data yang disimpan berupa informasi makanan seperti nama, jenis, harga, dan rating Fungsi-fungsi yang digunakan meliputi membuat list baru, menambahkan data di awal atau akhir list, menyisipkan data sebelum atau sesudah data tertentu, serta menampilkan seluruh isi list Selain itu, terdapat juga fitur untuk memperbarui isi data yang sudah ada melalui Guided 1, kita belajar dasar-dasar pengelolaan data dengan operasi insert dan update pada list yang dapat diakses dari dua arah.

### 1. (isi dengan soal unguided 1)

```C++
source code unguided 1
```#include "Doublylist.h"

void createList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

bool isExist(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) return true;
        P = P->next;
    }
    return false;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last; 
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna : " << P->info.warna << endl;
        cout << "tahun : " << P->info.thnBuat << endl;
        cout << endl;
        P = P->prev;
    }
}

list.h
#ifndef LIST_H
#define LIST_H
#include <iostream>
using namespace std;

struct kendaraan {
    string nopol;
    string warna;
    int tahunBuat;   
};

typedef kendaraan infotype;
typedef struct ElmList *address;

struct ElmList {
    infotype info;
    address next;
    address prev;
};

struct List {
    address First;
    address Last;
};

void createList(List &L) {
    L.First = NULL;
    L.Last = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = NULL;
}

bool isExist(List L, string nopol) {
    address P = L.First;
    while (P != NULL) {
        if (P->info.nopol == nopol) {
            return true;
        }
        P = P->next;
    }
    return false;
}

void insertLast(List &L, address P) {
    if (L.First == NULL) {
        L.First = P;
        L.Last = P;
    } else {
        L.Last->next = P;
        P->prev = L.Last;
        L.Last = P;
    }
}

void printInfo(List L) {
    address P = L.Last; 
    while (P != NULL) {
        cout << "no polisi : " << P->info.nopol << endl;
        cout << "warna     : " << P->info.warna << endl;
        cout << "tahun     : " << P->info.tahunBuat << endl;
        cout << endl;
        P = P->prev;
    }
}

#endif

main.cpp
#include "list.h"

int main() {
    List L;
    createList(L);

    infotype x;
    address P;

    for (int i = 0; i < 4; i++) {
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;
        cout << "masukkan warna kendaraan: ";
        cin >> x.warna;
        cout << "masukkan tahun kendaraan: ";
        cin >> x.tahunBuat;  

        if (isExist(L, x.nopol)) {
            cout << "nomor polisi sudah terdaftar\n" << endl;
        } else {
            P = alokasi(x);
            insertLast(L, P);
        }
    }

    cout << "\nDATA LIST 1\n";
    printInfo(L);

    return 0;
}

### Output Unguided 1 :
##### Output 1
![Screenshot Output Unguided 1_1] (https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan6_Modul6/soal1-1.png)

penjelasan unguided 1 

menerapkan konsep Doubly Linked List untuk mengelola data kendaraan di area parkir, di mana setiap elemen menyimpan informasi berupa nomor polisi, jenis kendaraan, durasi parkir, dan biaya parkir yang dihitung otomatis sesuai jenis kendaraan. Melalui struktur ini, data dapat ditambahkan di akhir list menggunakan prosedur insertLast, ditampilkan menggunakan printList, dicari dengan cariKendaraan, dan dihapus berdasarkan nomor polisi melalui deleteByNopol. Dengan adanya pointer ganda next dan prev, program ini memungkinkan akses data dua arah, sehingga proses penelusuran dan penghapusan data menjadi lebih efisien tanpa perlu memindahkan seluruh elemen di dalam list.


### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
```
list.cpp
#include "list.h"

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

Address alokasi(Infotype dataBaru) {
    Address P = new ElemenList;
    P->info = dataBaru;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(Address &P) {
    delete P;
    P = NULL;
}

bool isExist(List L, string nomorPolisi) {
    string nopolInput = nomorPolisi;
    transform(nopolInput.begin(), nopolInput.end(), nopolInput.begin(), ::toupper);

    Address P = L.first;
    while (P != NULL) {
        string nopolData = P->info.nomorPolisi;
        transform(nopolData.begin(), nopolData.end(), nopolData.begin(), ::toupper);
        if (nopolInput == nopolData) {
            return true;
        }
        P = P->next;
    }
    return false;
}

void insertLast(List &L, Address P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void printInfo(List L) {
    Address P = L.last;
    while (P != NULL) {
        cout << "Nomor Polisi   : " << P->info.nomorPolisi << endl;
        cout << "Warna Kendaraan: " << P->info.warnaKendaraan << endl;
        cout << "Tahun Pembuatan: " << P->info.tahunPembuatan << endl;
        cout << endl;
        P = P->prev;
    }
}

Address findElm(List L, string nomorPolisi) {
    string nopolInput = nomorPolisi;
    transform(nopolInput.begin(), nopolInput.end(), nopolInput.begin(), ::toupper);

    Address P = L.first;
    while (P != NULL) {
        string nopolData = P->info.nomorPolisi;
        transform(nopolData.begin(), nopolData.end(), nopolData.begin(), ::toupper);

        if (nopolInput == nopolData) {
            cout << "\nMasukkan Nomor Polisi yang dicari  : " << P->info.nomorPolisi << endl;
            cout << "\nNomor Polisi : " << P->info.nomorPolisi << endl;
            cout << "Warna        : " << P->info.warnaKendaraan << endl;
            cout << "Tahun        : " << P->info.tahunPembuatan << endl;
            return P;
        }
        P = P->next;
    }

    cout << "\nData dengan nomor polisi " << nomorPolisi << " tidak ditemukan.\n";
    return NULL;
}

list.h
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <algorithm>
using namespace std;

struct Kendaraan {
    string nomorPolisi;
    string warnaKendaraan;
    int tahunPembuatan;
};

typedef Kendaraan Infotype;
typedef struct ElemenList *Address;

struct ElemenList {
    Infotype info;
    Address next;
    Address prev;
};

struct List {
    Address first;
    Address last;
};

void createList(List &L);
Address alokasi(Infotype dataBaru);
void dealokasi(Address &P);
bool isExist(List L, string nomorPolisi);
void insertLast(List &L, Address P);
void printInfo(List L);
Address findElm(List L, string nomorPolisi);

#endif

main.cpp
#include "list.h"

int main() {
    List daftarKendaraan;
    createList(daftarKendaraan);

    Infotype dataKendaraan;
    Address P;

    cout << "=== INPUT DATA KENDARAAN ===" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "\nMasukkan Nomor Polisi   : ";
        cin >> dataKendaraan.nomorPolisi;
        cout << "Masukkan Warna Kendaraan: ";
        cin >> dataKendaraan.warnaKendaraan;
        cout << "Masukkan Tahun Pembuatan: ";
        cin >> dataKendaraan.tahunPembuatan;

        if (isExist(daftarKendaraan, dataKendaraan.nomorPolisi)) {
            cout << "\nNomor polisi sudah terdaftar.\n";
        } else {
            P = alokasi(dataKendaraan);
            insertLast(daftarKendaraan, P);
        }
    }

    cout << "\n=== DATA LIST ===" << endl;
    printInfo(daftarKendaraan);

    string cari;
    cout << "Masukkan Nomor Polisi yang dicari  : ";
    cin >> cari;
    findElm(daftarKendaraan, cari);

    return 0;
}

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan6_Modul6/soal2-1.png)

penjelasan unguided 2
Program ini menggunakan Single Linked List untuk menyimpan data kendaraan berdasarkan nomor polisi, warna, dan tahun pembuatan. Program mampu mencegah duplikasi data dengan memeriksa nomor polisi yang sudah terdaftar sebelum menambah elemen baru. Selain itu, tersedia fitur untuk menampilkan seluruh data kendaraan serta menghapus data berdasarkan nomor polisi melalui prosedur deleteFirst(), deleteLast(), dan deleteAfter(). Implementasi ini menunjukkan bagaimana operasi dasar pada linked list diterapkan untuk mengelola data secara dinamis tanpa menggunakan array statis.

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```
list.cpp
#include "list.h"

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

Address alokasi(Infotype dataBaru) {
    Address P = new ElemenList;
    P->info = dataBaru;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(Address &P) {
    delete P;
    P = NULL;
}

bool isExist(List L, string nomorPolisi) {
    string nopolInput = nomorPolisi;
    transform(nopolInput.begin(), nopolInput.end(), nopolInput.begin(), ::toupper);

    Address P = L.first;
    while (P != NULL) {
        string nopolData = P->info.nomorPolisi;
        transform(nopolData.begin(), nopolData.end(), nopolData.begin(), ::toupper);
        if (nopolInput == nopolData) {
            return true;
        }
        P = P->next;
    }
    return false;
}

void insertLast(List &L, Address P) {
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}
void printInfo(List L) {
    Address P = L.last;
    while (P != NULL) {
        cout << "Nomor Polisi : " << P->info.nomorPolisi << endl;
        cout << "Warna        : " << P->info.warnaKendaraan << endl;
        cout << "Tahun        : " << P->info.tahunPembuatan << endl;
        cout << endl;
        P = P->prev;
    }
}

Address findElm(List L, string nomorPolisi) {
    string nopolInput = nomorPolisi;
    transform(nopolInput.begin(), nopolInput.end(), nopolInput.begin(), ::toupper);

    Address P = L.first;
    while (P != NULL) {
        string nopolData = P->info.nomorPolisi;
        transform(nopolData.begin(), nopolData.end(), nopolData.begin(), ::toupper);
        if (nopolInput == nopolData) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void deleteFirst(List &L, Address &P) {
    if (L.first != NULL) {
        P = L.first;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
        }
        P->next = NULL;
    }
}

void deleteLast(List &L, Address &P) {
    if (L.first != NULL) {
        P = L.last;
        if (L.first == L.last) {
            L.first = NULL;
            L.last = NULL;
        } else {
            L.last = P->prev;
            L.last->next = NULL;
        }
        P->prev = NULL;
    }
}

void deleteAfter(Address Prec, Address &P) {
    if (Prec != NULL && Prec->next != NULL) {
        P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
    }
}

list.h
#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <algorithm>
using namespace std;

struct Kendaraan {
    string nomorPolisi;
    string warnaKendaraan;
    int tahunPembuatan;
};

typedef Kendaraan Infotype;
typedef struct ElemenList *Address;

struct ElemenList {
    Infotype info;
    Address next;
    Address prev;
};

struct List {
    Address first;
    Address last;
};

void createList(List &L);
Address alokasi(Infotype dataBaru);
void dealokasi(Address &P);
bool isExist(List L, string nomorPolisi);
void insertLast(List &L, Address P);
void printInfo(List L);
Address findElm(List L, string nomorPolisi);

void deleteFirst(List &L, Address &P);
void deleteLast(List &L, Address &P);
void deleteAfter(Address Prec, Address &P);

#endif

main.cpp
#include "list.h"

int main() {
    List daftarKendaraan;
    createList(daftarKendaraan);

    Infotype data;
    Address P;

    cout << "=== INPUT DATA KENDARAAN ===" << endl;

    data.nomorPolisi = "D001";
    data.warnaKendaraan = "hitam";
    data.tahunPembuatan = 90;
    insertLast(daftarKendaraan, alokasi(data));

    data.nomorPolisi = "D002";
    data.warnaKendaraan = "merah";
    data.tahunPembuatan = 90;
    insertLast(daftarKendaraan, alokasi(data));

    data.nomorPolisi = "D003";
    data.warnaKendaraan = "biru";
    data.tahunPembuatan = 90;
    insertLast(daftarKendaraan, alokasi(data));

    data.nomorPolisi = "D004";
    data.warnaKendaraan = "kuning";
    data.tahunPembuatan = 90;
    insertLast(daftarKendaraan, alokasi(data));

    string cari;
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : ";
    cin >> cari;

    Address hapus = findElm(daftarKendaraan, cari);

    if (hapus != NULL) {
        if (hapus == daftarKendaraan.first) {
            deleteFirst(daftarKendaraan, P);
        } else if (hapus == daftarKendaraan.last) {
            deleteLast(daftarKendaraan, P);
        } else {
            deleteAfter(hapus->prev, P);
        }
        cout << "Data dengan nomor polisi " << cari << " berhasil dihapus.\n";
        dealokasi(P);
    } else {
        cout << "Data dengan nomor polisi " << cari << " tidak ditemukan.\n";
    }

    cout << "\nDATA LIST 1\n" << endl;
    printInfo(daftarKendaraan);

    return 0;
}

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan6_Modul6/soal3-1.png)

penjelasan unguided 3
Program ini menerapkan Circular Linked List, di mana elemen terakhir menunjuk kembali ke elemen pertama, membentuk struktur melingkar. Program digunakan untuk menyimpan dan menampilkan data kendaraan dengan urutan yang terus berputar, memungkinkan traversal tanpa batas dari simpul terakhir ke simpul pertama. Operasi yang diimplementasikan meliputi penambahan data di awal atau akhir list serta penghapusan elemen tertentu berdasarkan nomor polisi. Struktur ini efisien untuk sistem yang memerlukan rotasi data secara berulang, seperti sistem antrian atau rotasi parkir kendaraan.

## Kesimpulan

penggunaan struktur data Linked List — baik Single, Doubly, maupun Circular — memberikan fleksibilitas tinggi dalam pengelolaan data dinamis. Setiap jenis linked list memiliki keunggulannya masing-masing: Single Linked List sederhana dan efisien untuk operasi searah, Doubly Linked List memungkinkan penelusuran dua arah serta penghapusan lebih mudah, dan Circular Linked List efektif untuk sistem yang memerlukan perputaran data tanpa henti. Secara keseluruhan, penerapan ketiga jenis linked list ini menunjukkan bagaimana konsep pointer dan hubungan antar-node dapat dimanfaatkan untuk membangun struktur penyimpanan data yang efisien, mudah diperluas, dan adaptif terhadap berbagai kebutuhan aplikasi.

## Referensi
[1] Sofianti, H. A., Manullang, Y. V., Tampubolon, N. A., Naibaho, L. H., & Gunawan, I. (2025). Implementasi Struktur Data Array Dan Linked List Dalam Pengelolaan Data Mahasiswa. Menulis: Jurnal Penelitian Nusantara, 1(6), 871-877.
<br>[2] Sofianti, H. A., Manullang, Y. V., Tampubolon, N. A., Naibaho, L. H., & Gunawan, I. (2025). Implementasi Struktur Data Array Dan Linked List Dalam Pengelolaan Data Mahasiswa. Menulis: Jurnal Penelitian Nusantara, 1(6), 871-877.
<br>...
