#ifndef LIST_H
#define LIST_H
#define Nil NULL 

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama;
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; // memberikan nama alias dataMahasiswa untuk struct mahasiswa  

typedef struct node *address; //mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk list dari linked listnya, isi setiap node adalah data * pointer
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini liked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist list);
void createList(linkedlist list);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist list);
void insertFirst(linkedlist &List,address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prey);
void insertLast(linkedlist &List, address nodeBaru);

void delfirst(linkedlist &List);
void dellast(linkedlist &List);
void delAfter(linkedlist &list, address nodeHapus, address nodeProv);
int nbLIst(linkedlist List);
void deleteList(linkedlist &List);

#endif