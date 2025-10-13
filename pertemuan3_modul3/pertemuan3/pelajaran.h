// header guard digunakan untuk mencegah file header yang sama 
// di include lebihbdari sekali dalam satu program

#ifndef PELAJARAN_H_
#define PELAJARAN_H_

#include <iostream>
#include <string>
using namespace std;

//deklarasi ADT pelajaran
struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

//function untuk membuat data pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel);

//prosedur untuk menampilkan data pelajaran
void tampil_pelajaran(pelajaran pel);

#endif
