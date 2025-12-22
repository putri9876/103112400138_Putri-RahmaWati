# <h1 align="center">Laporan Praktikum Modul 13 - MULTI LINKED LIST </h1>
<p align="center">Putri Rahma Wati-103112400138</p>

Multiple linked list merupakan senarai berantai yang memiliki link atau pointer lebih darisatu. Untuk multiple linked list yang memiliki dua link biasanya disebut sebagai doublylinked list (senarai berantai ganda). Senarai berantai ganda memiliki dua buah pointer yang biasanya masing-masing menunjuk ke simpul sebelumnya dan ke simpulsesudahnya.[1]. Linked list terdiri dari sejumlah node atau simpul yang dihubungkan secara linier dengan bantuan pointer.Multi Linked List adalah pengembangan dari struktur linked list biasa, di mana setiap node tidak hanya memiliki satu pointer untuk menghubungkan node berikutnya, tetapi juga dapat memiliki pointer tambahan yang mengarah ke list lain, seperti list anak atau sublist. Struktur ini memungkinkan representasi data yang bersifat hierarkis atau bertingkat, misalnya data kategori dan item di dalamnya, sehingga satu node parent dapat memiliki list child yang menyimpan elemen terkait. Multi Linked List sering digunakan ketika suatu data membutuhkan lebih dari satu dimensi hubungan, seperti pada pemodelan sparse matrix, struktur menu, pengelompokan data, serta berbagai kasus yang membutuhkan hubungan satu-ke-banyak. Keunggulannya adalah mampu menyimpan data secara efisien tanpa duplikasi dan mendukung berbagai jenis traversal berdasarkan relasi parent–child. Namun, karena memiliki lebih banyak pointer, struktur ini memerlukan manajemen memori yang lebih hati-hati terutama pada operasi insert, delete, dan saat menghindari pointer yang hilang atau tidak valid. Secara keseluruhan, Multi Linked List menjadi struktur data fleksibel untuk menyelesaikan permasalahan kompleks yang tidak dapat ditangani oleh linked list linear biasa.[2]

### A. ...<br/>
#### 1.Multi Linked List adalah pengembangan dari struktur linked list biasa, di mana setiap node tidak hanya memiliki satu pointer untuk menghubungkan node berikutnya, tetapi juga dapat memiliki pointer tambahan yang mengarah ke list lain, seperti list anak atau sublist.
#### 2. mampu menyimpan data secara efisien tanpa duplikasi dan mendukung berbagai jenis traversal berdasarkan relasi parent–child.


## Guided 

### 1. ...

```C++
source code guided 1
```main.cpp
#include "mll.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Inisialisasi List
    listInduk L;
    createListInduk(L);
    cout << "=== MENU RESTORAN DIBUAT ===" << endl << endl;

    // 2. Membuat Data Parent (Kategori Makanan)
    // Kita simpan pointer-nya agar mudah memasukkan anak nanti
    NodeParent Kat1 = alokasiNodeParent("K01", "Makanan Berat");
    insertFirstParent(L, Kat1);

    NodeParent Kat2 = alokasiNodeParent("K02", "Minuman");
    insertAfterParent(L, Kat2, Kat1);

    NodeParent Kat3 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(L, Kat3);
    
    cout << endl;

    // 3. Memasukkan Data Child (Menu Makanan) ke Kategori Tertentu
    
    // --> Isi Kategori Makanan Berat (K01)
    NodeChild Mkn1 = alokasiNodeChild("M01", "Nasi Goreng Spesial", 25000);
    insertFirstChild(Kat1->L_Anak, Mkn1);

    NodeChild Mkn2 = alokasiNodeChild("M02", "Ayam Bakar Madu", 30000);
    insertLastChild(Kat1->L_Anak, Mkn2);

    // --> Isi Kategori Minuman (K02)
    NodeChild Min1 = alokasiNodeChild("D01", "Es Teh Manis", 5000);
    insertLastChild(Kat2->L_Anak, Min1);
    
    NodeChild Min2 = alokasiNodeChild("D02", "Jus Alpukat", 15000);
    insertFirstChild(Kat2->L_Anak, Min2);

    // --> Isi Kategori Dessert (K03)
    NodeChild Des1 = alokasiNodeChild("S01", "Puding Coklat", 10000);
    insertLastChild(Kat3->L_Anak, Des1);
    cout << endl;

    cout << "=== TAMPILAN AWAL MENU ===" << endl;
    printStrukturMLL(L);
    cout << endl;

    // 4. Test Pencarian (Find)
    cout << "=== TEST PENCARIAN ===" << endl;
    findParentByID(L, "K02"); // Cari Kategori Minuman
    cout << "---------------------------" << endl;
    findChildByID(L, "M01");  // Cari Nasi Goreng
    cout << "---------------------------" << endl;
    findChildByID(L, "X99");  // Cari data ngawur (harus not found)
    cout << "---------------------------" << endl;
    cout << endl;

    // 5. Test Update Data
    cout << "=== TEST UPDATE ===" << endl;
    // Update Nama Kategori (Parent)
    // Mengubah "Dessert" menjadi "Makanan Penutup"
    updateDataParentByID(L, "K03", "Makanan Penutup");
    cout << "---------------------------" << endl;
    
    // Update Data Makanan (Child)
    // Mengubah "Nasi Goreng Spesial" jadi "Nasgor Gila", harga naik jadi 28000
    updateDataChildByID(L, "M01", "Nasgor Gila", 28000);
    cout << "---------------------------" << endl;
    
    cout << "\n=== SETELAH UPDATE ===" << endl;
    // Kita cek apakah data berubah
    printListInduk(L); // Cek nama kategori saja
    cout << endl;
    printListAnak(L, Kat1); // Cek list anak di kategori 1
    cout << endl;

    // 6. Test Penghapusan (Delete)
    cout << "=== TEST DELETE ===" << endl;
    
    // Hapus Child: Hapus Jus Alpukat (D02) dari Minuman
    cout << "> Menghapus Child D02..." << endl;
    deleteFirstChild(Kat2->L_Anak); 
    
    // Hapus Parent: Hapus Kategori Dessert/Makanan Penutup (K03)
    // DeleteLastParent akan menghapus elemen terakhir (K03)
    cout << "> Menghapus Parent Terakhir (K03)..." << endl;
    deleteLastParent(L); 

    cout << "\n=== TAMPILAN AKHIR MENU ===" << endl;
    printStrukturMLL(L);

    return 0;
}
```mll.cpp
#include "mll.h"
#include <iostream>
#include <string>

using namespace std;

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk){
    if(LInduk.first == NULL){
        return true;
    } else {
        return false;
    }
}

bool isEmptyAnak(listAnak LAnak){
    if(LAnak.first == NULL){
        return true;
    } else {
        return false;
    }
}

void createListInduk(listInduk &LInduk) {
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak) {
    LAnak.first = LAnak.last = NULL;
}

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori) {
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->isidata.idKategori = idKategori;
    nodeBaruParent->isidata.namaKategori = namaKategori;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga) {
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->isidata.idMakanan = idMakanan;
    nodeBaruChild->isidata.namaMakanan = namaMakanan;
    nodeBaruChild->isidata.harga = harga;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak) {
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void dealokasiNodeParent(NodeParent &nodeInduk) {
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->next = LInduk.first;
        LInduk.first->prev = nodeBaruParent;
        LInduk.first = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan pertama di list Induk!" << endl;
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent) {
    if(isEmptyInduk(LInduk) == true) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent) {
    if(nodePrevParent == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevParent == LInduk.last){
            insertLastParent(LInduk, nodeBaruParent);
            return;
        } else {
            nodeBaruParent->next = nodePrevParent->next;
            nodeBaruParent->prev = nodePrevParent;
            (nodePrevParent->next)->prev = nodeBaruParent;
            nodePrevParent->next = nodeBaruParent;
            cout << "Node parent "<< nodeBaruParent->isidata.namaKategori << " berhasil ditambahkan kedalam list induk setelah node parent "<< nodePrevParent->isidata.namaKategori << endl;
        }
    }
}

void deleteFirstParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.first;
        if (LInduk.first == LInduk.last) { // KASUS KHUSUS 1 ELEMEN
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.first = LInduk.first->next;
            LInduk.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node pertama list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteLastParent(listInduk &LInduk){
    if(isEmptyInduk(LInduk) == true){
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeHapus = LInduk.last;
        if (LInduk.first == LInduk.last) {
            LInduk.first = NULL;
            LInduk.last = NULL;
        } else {
            LInduk.last = LInduk.last->prev;
            nodeHapus->prev = NULL;
            LInduk.last->next = NULL;
        }
        if(nodeHapus->L_Anak.first != NULL){
            hapusListAnak(nodeHapus->L_Anak);
        }
        dealokasiNodeParent(nodeHapus);
        cout << "Node terakhir list induk berhasil dihapus beserta anak-anaknya!" << endl;
    }
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->isidata.namaKategori << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findParentByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        int index = 1;
        int ketemu = false;
        while(nodeBantu != NULL){
            if(nodeBantu->isidata.idKategori == IDCari){
                cout << "Data ID parent ditemukan pada list induk posisi ke-" << index << "!" << endl;
                cout << "ID : " << nodeBantu->isidata.idKategori << endl;
                cout << "Posisi dalam list induk : posisi ke-" << index << endl;
                cout << "Nama Kategori : " << nodeBantu->isidata.namaKategori << endl;
                ketemu = true;
                break;
            } else {
                nodeBantu = nodeBantu->next;
                index++;
            }
        }
        if(!ketemu){
            cout << "Data ID parent tidak ditemukan didalam list induk!" << endl;
        }
    }
}

void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantu = LInduk.first;
        bool ketemu = false;
        while (nodeBantu != NULL) {
            if (nodeBantu->isidata.idKategori == IDCari) {
                // Proses Update
                nodeBantu->isidata.namaKategori = newNamaKategori;
                cout << "Update Parent Berhasil!" << endl;
                cout << "Node parent dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                cout << "Nama Kategori baru  : " << newNamaKategori << endl;
                ketemu = true;
                break; 
            } else {
                nodeBantu = nodeBantu->next;
            }
        }
        if (!ketemu) {
            cout << "Parent dengan ID " << IDCari << " tidak ditemukan" << endl;
        }
    }
}

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->next = LAnak.first;
        LAnak.first->prev = nodeBaruChild;
        LAnak.first = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan pertama di list Anak!" << endl;
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild) {
    if(isEmptyAnak(LAnak)) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild) {
    if(nodePrevChild == NULL) {
        cout << "Node Prev Parent tidak valid!" << endl;
    } else {
        if(nodePrevChild == LAnak.last){
            insertLastChild(LAnak, nodeBaruChild);
            return;
        } else {
            nodeBaruChild->next = nodePrevChild->next;
            nodeBaruChild->prev = nodePrevChild;
            (nodePrevChild->next)->prev = nodeBaruChild;
            nodePrevChild->next = nodeBaruChild;
            cout << "Node child "<< nodeBaruChild->isidata.namaMakanan << " berhasil ditambahkan kedalam list anak setelah node child "<< nodePrevChild->isidata.namaMakanan << endl;
        }
    }
}

void deleteFirstChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.first;
        if (LAnak.first == LAnak.last) { // KASUS KHUSUS 1 ELEMEN
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.first = LAnak.first->next;
            LAnak.first->prev = NULL;
            nodeHapus->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node pertama list anak berhasil dihapus!" << endl;
    }
}

void deleteLastChild(listAnak &LAnak){
    if(isEmptyAnak(LAnak) == true){
        cout << "List anak kosong!" << endl;
    } else {
        NodeChild nodeHapus = LAnak.last;
        if (LAnak.first == LAnak.last) {
            LAnak.first = NULL;
            LAnak.last = NULL;
        } else {
            LAnak.last = LAnak.last->prev;
            nodeHapus->prev = NULL;
            LAnak.last->next = NULL;
        }
        dealokasiNodeChild(nodeHapus);
        cout << "Node terakhir list anak berhasil dihapus!" << endl;
    }
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(isEmptyAnak(LAnak) == true){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->isidata.namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(isEmptyInduk(LInduk) == true){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->isidata.idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->isidata.namaKategori << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent : " << nodeBantuParent->isidata.idKategori << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama kategori : " << nodeBantuParent->isidata.namaKategori << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga) {
    if (isEmptyInduk(LInduk) == true) {
        cout << "List Induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        bool ketemu = false;
        // Loop Parent (karena child ada di dalam parent)
        while (nodeBantuParent != NULL) {
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            // Loop Child
            while (nodeBantuChild != NULL) {
                if (nodeBantuChild->isidata.idMakanan == IDCari) {
                    // Proses Update
                    nodeBantuChild->isidata.namaMakanan = newNamaMakanan;
                    nodeBantuChild->isidata.harga = newHarga;
                    cout << "Update Child Berhasil!" << endl;
                    cout << "Lokasi : Ada di dalam Parent " << nodeBantuParent->isidata.namaKategori << endl;
                    cout << "Node child dengan ID " << IDCari << " berhasil diupdate menjadi : " << endl;
                    cout << "Nama Makanan Baru  : " << newNamaMakanan << endl;
                    cout << "Harga Baru : " << newHarga << endl;
                    ketemu = true;
                    break; // Break loop child
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                }
            }
            if (ketemu){
                break; // Break loop parent jika sudah ketemu di dalam
            } else {
                nodeBantuParent = nodeBantuParent->next;
            }
        }
        if (!ketemu) {
            cout << "Child dengan ID " << IDCari << " tidak ditemukan di parent manapun." << endl;
        }
    }
}

//operasi print
void printStrukturMLL(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;

            //print list anak dari node parentnya
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                    cout << "      Harga : " << nodeBantuChild->isidata.harga << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}

void printListInduk(listInduk &LInduk) {
    if(isEmptyInduk(LInduk)) {
        cout << "List induk Kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int index = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << index << " ===" << endl;
            cout << "ID Kategori : " << nodeBantuParent->isidata.idKategori << endl;
            cout << "Nama Kategori : " << nodeBantuParent->isidata.namaKategori << endl;
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            index++;
        }
    }
}

void printListAnak(listInduk &LInduk, NodeParent nodeInduk) {
    if(isEmptyInduk(LInduk) == true || nodeInduk == NULL){
        cout << "List induk kosong atau node induk tidak valid!" << endl;
    } else {
        NodeChild nodeBantuChild = nodeInduk->L_Anak.first;
        if(nodeBantuChild == NULL) {
            cout << "node parent " << nodeInduk->isidata.namaKategori << " tidak memiliki list anak!" << endl;
        } else {
            cout << "=== List Anak Node Parent " << nodeInduk->isidata.namaKategori << " ===" << endl;
            int index = 1;
            while(nodeBantuChild != NULL) {
                cout << "Child " << index << " :" << endl;
                cout << "ID Makanan : " << nodeBantuChild->isidata.idMakanan << endl;
                cout << "Nama Makanan : " << nodeBantuChild->isidata.namaMakanan << endl;
                cout << "Harga : " << nodeBantuChild->isidata.harga << endl;
                cout << "---------------------------" << endl;
                nodeBantuChild = nodeBantuChild->next;
                index++;
            }
        }
    }
}

//operasi hapus list
void hapusListInduk(listInduk &LInduk) {
    NodeParent nodeBantu = LInduk.first;
    while(nodeBantu != NULL) {
        NodeParent nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        //panggil prosedur hapusListAnak() untuk menghapus child-child nya
        hapusListAnak(nodeHapus->L_Anak);
        dealokasiNodeParent(nodeHapus);
    }
    LInduk.first = LInduk.last = NULL;
}

void hapusListAnak(listAnak &LAnak) {
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

```mll.h
#ifndef MLL_H
#define MLL_H

#include <iostream>
#include <string>

using namespace std;

struct DataMakanan {
    string idMakanan;
    string namaMakanan;
    float harga;
};

struct KategoriMakanan {
    string idKategori;
    string namaKategori;
};

typedef struct nodeParent *NodeParent; //alias pointer ke struct nodeParent
typedef struct nodeChild *NodeChild;  // alias pointeer ke struct nodeChild

struct nodeChild { //node child
    DataMakanan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listAnak {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    KategoriMakanan isidata;
    NodeParent next;
    NodeParent prev;
    listAnak L_Anak;
};

struct listInduk {
    NodeParent first;
    NodeParent last;
};

//isEmpty & create list
bool isEmptyInduk(listInduk LInduk);
bool isEmptyAnak(listAnak LAnak);
void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &LAnak);

//alokasi & dealokasi
NodeParent alokasiNodeParent(string idKategori, string namaKategori);
NodeChild alokasiNodeChild(string idMakanan, string namaMakanan, float harga);
void dealokasiNodeChild(NodeChild &nodeAnak);
void dealokasiNodeParent(NodeParent &nodeInduk);

//operasi pada parent
void insertFirstParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void insertAfterParent(listInduk &LInduk, NodeParent nodeBaruParent, NodeParent nodePrevParent);

void deleteFirstParent(listInduk &LInduk);
void deleteLastParent(listInduk &LInduk);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

void findParentByID(listInduk &LInduk, string IDCari);
void updateDataParentByID(listInduk &LInduk, string IDCari, string newNamaKategori);

//operasi pada child
void insertFirstChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void insertAfterChild(listAnak &LAnak, NodeChild nodeBaruChild, NodeChild nodePrevChild);
void deleteFirstChild(listAnak &LAnak);
void deleteLastChild(listAnak &LAnak);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev);
void findChildByID(listInduk &LInduk, string IDCari);
void updateDataChildByID(listInduk &LInduk, string IDCari, string newNamaMakanan, float newHarga);

//operasi print
void printStrukturMLL(listInduk &LInduk);
void printListInduk(listInduk &LInduk);
void printListAnak(listInduk &LInduk, NodeParent nodeInduk);

//operasi hapus list
void hapusListInduk(listInduk &LInduk);
void hapusListAnak(listAnak &LAnak);

#endif

penjelasan singkat guided 1
Multi Linked List yang terdiri dari node parent sebagai kategori makanan dan node child sebagai data menu. Praktikum ini menunjukkan bagaimana list induk diinisialisasi, kemudian node parent ditambahkan dengan operasi insertFirst, insertAfter, dan insertLast. Setelah itu, setiap parent diisi dengan beberapa child menggunakan operasi insert di awal maupun akhir list anak. dan mendemonstrasikan cara menampilkan struktur MLL secara lengkap, melakukan pencarian parent dan child berdasarkan ID, meng-update data tertentu, serta menghapus node parent atau child. Melalui rangkaian langkah ini, mahasiswa memahami bagaimana hubungan hierarkis parent–child bekerja dalam Multi Linked List serta bagaimana pointer next dan prev menghubungkan setiap node.

## Unguided 

### 1. Buatlah ADT Multi Linked List sebagai berikut didalam file “MultiLL.h” 

```C++
source code unguided 1
```main.cpp
#include "MultiLL.h"

int main(){
    listParent LP;
    createListParent(LP);

    insertLastParent(LP, allocNodeParent("G001", "Aves"));
    insertLastParent(LP, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    insertLastParent(LP, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    insertLastChild(LP.first->L_Child,
        allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));

    insertLastChild(LP.first->L_Child,
        allocNodeChild("AV002", "Bebek", "Air", true, 2));

    NodeParent P2 = LP.first->next;

    insertLastChild(P2->L_Child,
        allocNodeChild("M001", "Harimau", "Hutan", true, 200));

    insertLastChild(P2->L_Child,
        allocNodeChild("M003", "Gorila", "Hutan", false, 160));

    insertLastChild(P2->L_Child,
        allocNodeChild("M002", "Kucing", "Darat", true, 4));

    NodeParent P4 = P2->next->next;

    insertLastChild(P4->L_Child,
        allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    printMLLStructure(LP);

    cout << endl;
    searchHewanByEkor(LP, false);

    cout << endl;
    deleteAfterParent(LP, P2->next);  
    printMLLStructure(LP);

    return 0;
}

```MultiLL.cpp
#include "MultiLL.h"

bool isEmptyParent(listParent L){
    return (L.first == NULL);
}

bool isEmptyChild(listChild L){
    return (L.first == NULL);
}

void createListParent(listParent &L){
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L){
    L.first = NULL;
    L.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight){
    NodeChild P = new nodeChild;
    P->isidata.idHewan = idHwn;
    P->isidata.namaHewan = namaHwn;
    P->isidata.habitat = habitat;
    P->isidata.ekor = tail;
    P->isidata.bobot = weight;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void deallocNodeParent(NodeParent &P){
    delete P;
    P = NULL;
}

void deallocNodeChild(NodeChild &P){
    delete P;
    P = NULL;
}

void insertFirstParent(listParent &L, NodeParent P){
    if(isEmptyParent(L)){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastParent(listParent &L, NodeParent P){
    if(isEmptyParent(L)){
        insertFirstParent(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstParent(listParent &L){
    if(!isEmptyParent(L)){
        NodeParent P = L.first;
        if(L.first == L.last){
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
        }
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &L, NodeParent Prec){
    if(Prec != NULL && Prec->next != NULL){
        NodeParent P = Prec->next;
        Prec->next = P->next;

        if(P == L.last){
            L.last = Prec;
        } else {
            P->next->prev = Prec;
        }

        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void insertFirstChild(listChild &L, NodeChild P){
    if(isEmptyChild(L)){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(listChild &L, NodeChild P){
    if(isEmptyChild(L)){
        insertFirstChild(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstChild(listChild &L){
    if(!isEmptyChild(L)){
        NodeChild P = L.first;
        if(L.first == L.last){
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
        }
        deallocNodeChild(P);
    }
}

void deleteAfterChild(listChild &L, NodeChild Prec){
    if(Prec != NULL && Prec->next != NULL){
        NodeChild P = Prec->next;
        Prec->next = P->next;

        if(P == L.last){
            L.last = Prec;
        } else {
            P->next->prev = Prec;
        }

        deallocNodeChild(P);
    }
}

void deleteListChild(listChild &L){
    while(!isEmptyChild(L)){
        deleteFirstChild(L);
    }
}

void printMLLStructure(listParent L){
    NodeParent P = L.first;
    int nomor = 1;

    while(P != NULL){
        cout << "== Parent " << nomor << " ==" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        if(isEmptyChild(P->L_Child)){
            cout << "(tidak ada child)" << endl;
        } else {
            cout << "== Child ==" << endl;

            NodeChild C = P->L_Child.first;
            int nc = 1;
            while(C != NULL){
                cout << " > Child " << nc << endl;
                cout << "   ID Hewan : " << C->isidata.idHewan << endl;
                cout << "   Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "   Habitat : " << C->isidata.habitat << endl;
                cout << "   Ekor : " << (C->isidata.ekor ? "True" : "False") << endl;
                cout << "   Bobot : " << C->isidata.bobot << endl;
                C = C->next;
                nc++;
            }
        }

        cout << "--------------------------" << endl;
        P = P->next;
        nomor++;
    }
}

void searchHewanByEkor(listParent L, bool tail){
    NodeParent P = L.first;
    cout << "== Hewan dengan ekor " << (tail ? "TRUE" : "FALSE") << " ==" << endl;

    while(P != NULL){
        NodeChild C = P->L_Child.first;
        while(C != NULL){
            if(C->isidata.ekor == tail){
                cout << C->isidata.idHewan << " - " 
                     << C->isidata.namaHewan << " (" 
                     << P->isidata.namaGolongan << ")" 
                     << endl;
            }
            C = C->next;
        }
        P = P->next;
    }
}

```MultiLL.h
#ifndef MULTILL_H_INCLUDED
#define MULTILL_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeChild *NodeChild;
typedef struct nodeParent *NodeParent;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent L);
bool isEmptyChild(listChild L);

void createListParent(listParent &L);
void createListChild(listChild &L);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &P);
void deallocNodeChild(NodeChild &P);

void insertFirstParent(listParent &L, NodeParent P);
void insertLastParent(listParent &L, NodeParent P);
void deleteFirstParent(listParent &L);
void deleteAfterParent(listParent &L, NodeParent Prec);

void insertFirstChild(listChild &L, NodeChild P);
void insertLastChild(listChild &L, NodeChild P);
void deleteFirstChild(listChild &L);
void deleteAfterChild(listChild &L, NodeChild Prec);

void printMLLStructure(listParent L);
void deleteListChild(listChild &L);

void searchHewanByEkor(listParent L, bool tail);

#endif

### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1]https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan11_modul13/unguided1_1.png
##### Output 2
![Screenshot Output Unguided 1_2] https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan11_modul13/unguided1_2.png


##### Output 3
![Screenshot Output Unguided 1_3] https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan11_modul13/unguided1_3.png

penjelasan unguided 1 
membangun ADT Multi Linked List dari awal untuk kasus golongan hewan (parent) dan data hewan (child). Mahasiswa membuat struktur node parent–child, fungsi alokasi, pengecekan list kosong, operasi insert parent–child, delete, dan print struktur. Setelah semua ADT siap, mahasiswa mengisi data golongan hewan dan menambahkan beberapa hewan ke masing-masing parent, lalu mencetak struktur lengkapnya. Tugas ini bertujuan melatih mahasiswa memahami dasar relasi hierarkis pada Multi Linked List dan memastikan setiap operasi berjalan dengan benar.

### 2. (Tambahkan prosedur searchHewanByEkor(input/output LParent : 
listParent, input tail : Boolean) yang digunakan untuk melakukan operasi 
SEARCHING hewan-hewan yang memiliki EKOR FALSE (pencarian dilakukan dengan 
menelusuri list child yang ada pada masing-masing node parent). Kemudian panggil 
prosedur tersebut pada main.cpp. )

```C++
source code unguided 2
```main.cpp
#include "MultiLL.h"

int main(){
    listParent LP;
    createListParent(LP);

    insertLastParent(LP, allocNodeParent("G001", "Aves"));
    insertLastParent(LP, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    insertLastParent(LP, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    insertLastChild(LP.first->L_Child,
        allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));

    insertLastChild(LP.first->L_Child,
        allocNodeChild("AV002", "Bebek", "Air", true, 2));

    NodeParent P2 = LP.first->next;

    insertLastChild(P2->L_Child,
        allocNodeChild("M001", "Harimau", "Hutan", true, 200));

    insertLastChild(P2->L_Child,
        allocNodeChild("M003", "Gorila", "Hutan", false, 160));

    insertLastChild(P2->L_Child,
        allocNodeChild("M002", "Kucing", "Darat", true, 4));

    NodeParent P4 = P2->next->next;

    insertLastChild(P4->L_Child,
        allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    printMLLStructure(LP);

    cout << endl;
    searchHewanByEkor(LP, false);

    cout << endl;
    deleteAfterParent(LP, P2->next);  
    printMLLStructure(LP);

    return 0;
}

```MultiLL.cpp
#include "MultiLL.h"

bool isEmptyParent(listParent L){
    return (L.first == NULL);
}

bool isEmptyChild(listChild L){
    return (L.first == NULL);
}

void createListParent(listParent &L){
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L){
    L.first = NULL;
    L.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight){
    NodeChild P = new nodeChild;
    P->isidata.idHewan = idHwn;
    P->isidata.namaHewan = namaHwn;
    P->isidata.habitat = habitat;
    P->isidata.ekor = tail;
    P->isidata.bobot = weight;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void deallocNodeParent(NodeParent &P){
    delete P;
    P = NULL;
}

void deallocNodeChild(NodeChild &P){
    delete P;
    P = NULL;
}

void insertFirstParent(listParent &L, NodeParent P){
    if(isEmptyParent(L)){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastParent(listParent &L, NodeParent P){
    if(isEmptyParent(L)){
        insertFirstParent(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstParent(listParent &L){
    if(!isEmptyParent(L)){
        NodeParent P = L.first;
        if(L.first == L.last){
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
        }
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &L, NodeParent Prec){
    if(Prec != NULL && Prec->next != NULL){
        NodeParent P = Prec->next;
        Prec->next = P->next;

        if(P == L.last){
            L.last = Prec;
        } else {
            P->next->prev = Prec;
        }

        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void insertFirstChild(listChild &L, NodeChild P){
    if(isEmptyChild(L)){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(listChild &L, NodeChild P){
    if(isEmptyChild(L)){
        insertFirstChild(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstChild(listChild &L){
    if(!isEmptyChild(L)){
        NodeChild P = L.first;
        if(L.first == L.last){
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
        }
        deallocNodeChild(P);
    }
}

void deleteAfterChild(listChild &L, NodeChild Prec){
    if(Prec != NULL && Prec->next != NULL){
        NodeChild P = Prec->next;
        Prec->next = P->next;

        if(P == L.last){
            L.last = Prec;
        } else {
            P->next->prev = Prec;
        }

        deallocNodeChild(P);
    }
}

void deleteListChild(listChild &L){
    while(!isEmptyChild(L)){
        deleteFirstChild(L);
    }
}

void printMLLStructure(listParent L){
    NodeParent P = L.first;
    int nomor = 1;

    while(P != NULL){
        cout << "== Parent " << nomor << " ==" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        if(isEmptyChild(P->L_Child)){
            cout << "(tidak ada child)" << endl;
        } else {
            cout << "== Child ==" << endl;

            NodeChild C = P->L_Child.first;
            int nc = 1;
            while(C != NULL){
                cout << " > Child " << nc << endl;
                cout << "   ID Hewan : " << C->isidata.idHewan << endl;
                cout << "   Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "   Habitat : " << C->isidata.habitat << endl;
                cout << "   Ekor : " << (C->isidata.ekor ? "True" : "False") << endl;
                cout << "   Bobot : " << C->isidata.bobot << endl;
                C = C->next;
                nc++;
            }
        }

        cout << "--------------------------" << endl;
        P = P->next;
        nomor++;
    }
}

void searchHewanByEkor(listParent L, bool tail){
    NodeParent P = L.first;
    int posParent = 1;

    while(P != NULL){

        NodeChild C = P->L_Child.first;
        int posChild = 1;

        while(C != NULL){

            if(C->isidata.ekor == tail){

                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << posChild << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;
                cout << "----------------------------" << endl << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << posParent << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "----------------------------" << endl << endl;
            }

            C = C->next;
            posChild++;
        }

        P = P->next;
        posParent++;
    }
}

```MultiLL.h
#ifndef MULTILL_H_INCLUDED
#define MULTILL_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeChild *NodeChild;
typedef struct nodeParent *NodeParent;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent L);
bool isEmptyChild(listChild L);

void createListParent(listParent &L);
void createListChild(listChild &L);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &P);
void deallocNodeChild(NodeChild &P);

void insertFirstParent(listParent &L, NodeParent P);
void insertLastParent(listParent &L, NodeParent P);
void deleteFirstParent(listParent &L);
void deleteAfterParent(listParent &L, NodeParent Prec);

void insertFirstChild(listChild &L, NodeChild P);
void insertLastChild(listChild &L, NodeChild P);
void deleteFirstChild(listChild &L);
void deleteAfterChild(listChild &L, NodeChild Prec);

void printMLLStructure(listParent L);
void deleteListChild(listChild &L);

void searchHewanByEkor(listParent L, bool tail);

#endif

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1]https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan11_modul13/unguided2_1.png)

##### Output 2
![Screenshot Output Unguided 2_2] https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan11_modul13/unguided2_2.png)

##### Output 3
![Screenshot Output Unguided 2_3] https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan11_modul13/unguided2_3.png)


penjelasan unguided 2
enambahkan fitur baru yaitu prosedur searchHewanByEkor(), yang bertugas mencari hewan dengan kondisi ekor FALSE. Proses pencarian dilakukan dengan menelusuri seluruh node parent dan child. Jika ditemukan, program mencetak informasi lengkap mengenai hewan beserta posisi parent tempat hewan tersebut berada. Setelah menambahkan prosedur ini, mahasiswa memanggilnya dari main.cpp untuk menampilkan hasil pencarian. Tugas ini bertujuan melatih kemampuan traversing hierarkis dan filtering data berdasarkan kondisi tertentu.


### 3. (Lakukan operasi DELETE dengan menghapus node G004 yang ada pada list parent (list 
child dari node tersebut juga terhapus), kemudian lakukan lagi operasi PRINT dengan 
memanggil prosedur printMLLStructure(). Sehingga bentuk dari multi linked 
listnya berubah menjadi seperi ini : )

```C++
source code unguided 3
```main.cpp
#include "MultiLL.h"

int main(){
    listParent LP;
    createListParent(LP);

    insertLastParent(LP, allocNodeParent("G001", "Aves"));
    insertLastParent(LP, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    insertLastParent(LP, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    insertLastChild(LP.first->L_Child,
        allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));

    insertLastChild(LP.first->L_Child,
        allocNodeChild("AV002", "Bebek", "Air", true, 2));

    NodeParent P2 = LP.first->next;

    insertLastChild(P2->L_Child,
        allocNodeChild("M001", "Harimau", "Hutan", true, 200));

    insertLastChild(P2->L_Child,
        allocNodeChild("M003", "Gorila", "Hutan", false, 160));

    insertLastChild(P2->L_Child,
        allocNodeChild("M002", "Kucing", "Darat", true, 4));

    NodeParent P4 = P2->next->next;

    insertLastChild(P4->L_Child,
        allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    printMLLStructure(LP);

    cout << endl;
    searchHewanByEkor(LP, false);

    cout << endl;
    deleteAfterParent(LP, P2->next);
    printMLLStructure(LP);

    return 0;
}

```MultiLL.cpp
#include "MultiLL.h"

bool isEmptyParent(listParent L){
    return (L.first == NULL);
}

bool isEmptyChild(listChild L){
    return (L.first == NULL);
}

void createListParent(listParent &L){
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L){
    L.first = NULL;
    L.last = NULL;
}

NodeParent allocNodeParent(string idGol, string namaGol){
    NodeParent P = new nodeParent;
    P->isidata.idGolongan = idGol;
    P->isidata.namaGolongan = namaGol;
    P->next = NULL;
    P->prev = NULL;
    createListChild(P->L_Child);
    return P;
}

NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight){
    NodeChild P = new nodeChild;
    P->isidata.idHewan = idHwn;
    P->isidata.namaHewan = namaHwn;
    P->isidata.habitat = habitat;
    P->isidata.ekor = tail;
    P->isidata.bobot = weight;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void deallocNodeParent(NodeParent &P){
    delete P;
    P = NULL;
}

void deallocNodeChild(NodeChild &P){
    delete P;
    P = NULL;
}

void insertFirstParent(listParent &L, NodeParent P){
    if(isEmptyParent(L)){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastParent(listParent &L, NodeParent P){
    if(isEmptyParent(L)){
        insertFirstParent(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstParent(listParent &L){
    if(!isEmptyParent(L)){
        NodeParent P = L.first;
        if(L.first == L.last){
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
        }
        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void deleteAfterParent(listParent &L, NodeParent Prec){
    if(Prec != NULL && Prec->next != NULL){
        NodeParent P = Prec->next;
        Prec->next = P->next;

        if(P == L.last){
            L.last = Prec;
        } else {
            P->next->prev = Prec;
        }

        deleteListChild(P->L_Child);
        deallocNodeParent(P);
    }
}

void insertFirstChild(listChild &L, NodeChild P){
    if(isEmptyChild(L)){
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLastChild(listChild &L, NodeChild P){
    if(isEmptyChild(L)){
        insertFirstChild(L, P);
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void deleteFirstChild(listChild &L){
    if(!isEmptyChild(L)){
        NodeChild P = L.first;
        if(L.first == L.last){
            L.first = NULL;
            L.last = NULL;
        } else {
            L.first = P->next;
            L.first->prev = NULL;
        }
        deallocNodeChild(P);
    }
}

void deleteAfterChild(listChild &L, NodeChild Prec){
    if(Prec != NULL && Prec->next != NULL){
        NodeChild P = Prec->next;
        Prec->next = P->next;

        if(P == L.last){
            L.last = Prec;
        } else {
            P->next->prev = Prec;
        }

        deallocNodeChild(P);
    }
}

void deleteListChild(listChild &L){
    while(!isEmptyChild(L)){
        deleteFirstChild(L);
    }
}

void printMLLStructure(listParent L){
    NodeParent P = L.first;
    int nomor = 1;

    while(P != NULL){
        cout << "== Parent " << nomor << " ==" << endl;
        cout << "ID Golongan : " << P->isidata.idGolongan << endl;
        cout << "Nama Golongan : " << P->isidata.namaGolongan << endl;

        if(isEmptyChild(P->L_Child)){
            cout << "(tidak ada child)" << endl;
        } else {
            cout << "== Child ==" << endl;

            NodeChild C = P->L_Child.first;
            int nc = 1;
            while(C != NULL){
                cout << " > Child " << nc << endl;
                cout << "   ID Hewan : " << C->isidata.idHewan << endl;
                cout << "   Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "   Habitat : " << C->isidata.habitat << endl;
                cout << "   Ekor : " << (C->isidata.ekor ? "True" : "False") << endl;
                cout << "   Bobot : " << C->isidata.bobot << endl;
                C = C->next;
                nc++;
            }
        }

        cout << "--------------------------" << endl;
        P = P->next;
        nomor++;
    }
}

void searchHewanByEkor(listParent L, bool tail){
    NodeParent P = L.first;
    int posParent = 1;

    while(P != NULL){
        NodeChild C = P->L_Child.first;
        int posChild = 1;

        while(C != NULL){
            if(C->isidata.ekor == tail){

                cout << "Data ditemukan pada list anak dari node parent "
                     << P->isidata.namaGolongan
                     << " pada posisi ke-" << posChild << "!" << endl;

                cout << "--- Data Child ---" << endl;
                cout << "ID Child : " << C->isidata.idHewan << endl;
                cout << "Posisi dalam list anak : posisi ke-" << posChild << endl;
                cout << "Nama Hewan : " << C->isidata.namaHewan << endl;
                cout << "Habitat : " << C->isidata.habitat << endl;
                cout << "Ekor : " << (C->isidata.ekor ? 1 : 0) << endl;
                cout << "Bobot : " << C->isidata.bobot << endl;
                cout << "----------------------------" << endl << endl;

                cout << "--- Data Parent ---" << endl;
                cout << "ID Parent : " << P->isidata.idGolongan << endl;
                cout << "Posisi dalam list induk : posisi ke-" << posParent << endl;
                cout << "Nama golongan : " << P->isidata.namaGolongan << endl;
                cout << "----------------------------" << endl << endl;
            }
            C = C->next;
            posChild++;
        }

        P = P->next;
        posParent++;
    }
}

```MultiLL.h
#ifndef MULTILL_H_INCLUDED
#define MULTILL_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeChild *NodeChild;
typedef struct nodeParent *NodeParent;

struct nodeChild {
    dataHewan isidata;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan isidata;
    NodeParent next;
    NodeParent prev;
    listChild L_Child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

bool isEmptyParent(listParent L);
bool isEmptyChild(listChild L);

void createListParent(listParent &L);
void createListChild(listChild &L);

NodeParent allocNodeParent(string idGol, string namaGol);
NodeChild allocNodeChild(string idHwn, string namaHwn, string habitat, bool tail, float weight);

void deallocNodeParent(NodeParent &P);
void deallocNodeChild(NodeChild &P);

void insertFirstParent(listParent &L, NodeParent P);
void insertLastParent(listParent &L, NodeParent P);
void deleteFirstParent(listParent &L);
void deleteAfterParent(listParent &L, NodeParent Prec);

void insertFirstChild(listChild &L, NodeChild P);
void insertLastChild(listChild &L, NodeChild P);
void deleteFirstChild(listChild &L);
void deleteAfterChild(listChild &L, NodeChild Prec);

void printMLLStructure(listParent L);
void deleteListChild(listChild &L);

void searchHewanByEkor(listParent L, bool tail);

#endif

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1] https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan11_modul13/unguided3_1.png)

##### Output 2
![Screenshot Output Unguided 3_1] https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan11_modul13/unguided3_2.png)

##### Output 3
![Screenshot Output Unguided 3_1] https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan11_modul13/unguided3_3.png)


penjelasan unguided 3
melakukan operasi delete pada node parent dengan ID G004 (Amfibi). Penghapusan dilakukan dengan fungsi deleteAfterParent(), yang otomatis menghapus seluruh child milik parent tersebut. Setelah itu, struktur Multi Linked List dicetak ulang untuk melihat perubahan hasil delete. Hasil keluaran menunjukkan bahwa node parent Amfibi beserta child-nya berhasil terhapus, sehingga struktur list berkurang satu bagian. Tugas ini membuktikan bahwa proses delete pada parent sekaligus menghapus child berjalan dengan benar dalam Multi Linked List.

## Kesimpulan
...memahami konsep dasar hingga implementasi lanjutan dari Multi Linked List sebagai struktur data hierarkis yang terdiri dari node parent dan child. Melalui Guided, mahasiswa mempelajari cara membuat, menelusuri, mengubah, mencari, dan menghapus node dalam struktur parent–child menggunakan pointer next dan prev, sehingga memahami bagaimana data yang saling terkait dapat diorganisir secara dinamis. Kemudian pada Unguided 1, mahasiswa menerapkan teori tersebut ke dalam kasus baru yaitu golongan hewan dan data hewan, dengan membangun ADT lengkap, mengisi data parent–child, dan mencetak struktur hasilnya. Pada Unguided 2, kemampuan traversing dan filtering diperkuat melalui pembuatan fungsi searchHewanByEkor(), yang menelusuri seluruh parent dan child untuk menemukan hewan dengan kondisi tertentu. Selanjutnya pada Unguided 3, mahasiswa menguji operasi delete pada node parent sekaligus seluruh child di dalamnya, membuktikan bahwa penghapusan pada struktur hierarkis harus dilakukan dengan hati-hati agar tidak meninggalkan memory leak atau pointer yang tidak valid. Secara keseluruhan, seluruh tahap praktikum ini memberikan pemahaman menyeluruh mengenai cara membangun dan mengelola Multi Linked List secara efisien, serta menunjukkan bagaimana struktur data ini dapat digunakan untuk merepresentasikan data bertingkat dalam berbagai konteks nyata.

## Referensi
[1] https://firmaninformatika.blogspot.com/2014/11/referensi-multiple-linked-list-multi.html
<br>
[2] Wisesty, U. N., Nurrahmi, H., Yunanto, P. E., Rismala, R., & Sthevanie, F. (2025). STRUKTUR DATA MENGGUNAKAN C++. PENERBIT KBM INDONESIA.
<br>...
