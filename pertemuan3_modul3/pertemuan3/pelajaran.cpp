#include "pelajaran.h"

//implementasi function create_pelajaran
pelajaran create_pelajaran(string namaMapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namaMapel;  //parameter lgsg dimasukin ke struct
    p.kodeMapel = kodepel;
    return p;
}

//implementasi prosedur tampil_pelajaran
void tampil_pelajaran(pelajaran pel) { //pemanggilan menggunakan pel
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai : " << pel.kodeMapel << endl;
}
