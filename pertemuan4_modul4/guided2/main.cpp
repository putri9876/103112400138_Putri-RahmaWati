#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    // Perhatikan: nodeE TIDAK perlu diinisialisasi ke Nil di sini karena sudah dialokasikan di bawah.
    address nodeA, nodeB, nodeC, nodeD, nodeE; 
    createList(List);

    dataMahasiswa mhs;

    // Alokasi
    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    // Insert
    insertFirst(List, nodeA);               // List: A
    insertLast(List, nodeB);                // List: A -> B
    insertAfter(List, nodeC, nodeA);        // List: A -> C -> B
    insertAfter(List, nodeD, nodeC);        // List: A -> C -> D -> B
    insertLast(List, nodeE);                // List: A -> C -> D -> B -> E

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    // Delete
    delFirst(List);                         // Hapus A. List: C -> D -> B -> E
    delLast(List);                          // Hapus E. List: C -> D -> B
    // Perhatikan: delAfter membutuhkan parameter nodeHapus (nodeD) sebagai address&
    // Ini adalah cara untuk memastikan memori nodeD di-dealokasi dan pointer D di-set ke Nil
    delAfter(List, nodeD, nodeC);           // Hapus D (setelah C). List: C -> B

    cout << "--- ISI LIST SETELAH DILAKUKAN DELETE ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    // Hapus Seluruh List
    deleteList(List);
    cout << "--- ISI LIST SETELAH DILAKUKAN HAPUS LIST ---" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}