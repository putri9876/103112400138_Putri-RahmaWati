# <h1 align="center">Laporan Praktikum Modul 7 STACK 
<p align="center">Putri Rahma Wati-103112400138

## Dasar Teori
Stack adalah struktur data linier yang mengikuti prinsip LIFO (Last In First Out), di mana elemen yang terakhir dimasukkan akan menjadi elemen pertama yang dikeluarkan [1].
Stack sering digunakan untuk proses seperti undo-redo, fungsi rekursif, dan pemeriksaan tanda kurung dalam ekspresi matematika.
Operasi dasar dalam stack terdiri dari:
Push: menambahkan elemen ke bagian atas stack.
Pop: menghapus elemen paling atas dari stack.
Peek / Top: melihat elemen paling atas tanpa menghapusnya.
Implementasi stack dapat dilakukan dengan linked list atau array statis [2].


### A. ...<br/>
...
#### 1.Menggunakan variabel top untuk melacak posisi data teratas. Metode ini sederhana dan cepat, namun kapasitasnya terbatas karena ukuran array bersifat tetap.
#### 2. Setiap elemen disimpan dalam node yang saling terhubung melalui pointer. Ukurannya fleksibel dan dapat bertambah sesuai kebutuhan, namun memerlukan memori tambahan untuk pointer

## Guided 

### 1. ...

```C++
source code guided 1
``main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}

stack.cpp
#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void view(stack listStack){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}

stack.h
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif
penjelasan singkat guided 1
Program ini mengimplementasikan stack menggunakan struktur linked list dinamis.
Setiap elemen stack disimpan dalam node yang memiliki dua atribut: dataAngka (isi data) dan next (penunjuk ke node berikutnya).

### 2. ...

```C++
source code guided 2
```main.cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 9);
    pushAscending(S, 3);
    pushAscending(S, 2);

    printInfo(S); 

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S); 

    return 0;
}

stack.cpp 

penjelasan singkat guided 2
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, Infotype x) {
    if (S.top < MAX - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

void pop(Stack &S, Infotype &x) {
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    Infotype x;

    while (S.top >= 0) {
        pop(S, x);
        push(temp, x);
    }

    S = temp;
}

void pushAscending(Stack &S, Infotype x) {
    Stack temp;
    createStack(temp);
    Infotype y;

    while (S.top >= 0 && S.info[S.top] < x) {
        pop(S, y);
        push(temp, y);
    }

    push(S, x);

    while (temp.top >= 0) {
        pop(temp, y);
        push(S, y);
    }
}
stack.h
#ifndef STACK_TABLE
#define STACK_TABLE

#include <iostream>
using namespace std;

//ubah kapasitas sesuai kebutuhan
const int MAX = 10;

struct stackTable{
    int data[MAX];
    int top; // -1 = kosong
};

bool isEmpty(stackTable s);
bool isFull(stackTable s);
void createStack(stackTable &s);

void push(stackTable &s, int angka);
void pop(stackTable &s);
void update(stackTable &s, int posisi);
void view(stackTable s);
void searchData(stackTable s, int data);

#endif
penjelasan singkat guided 2
Program ini menggunakan stack berbasis array statis dengan fitur tambahan pushAscending dan balikStack
pushAscending:menjaga data tetap urut saat dimasukkan.
balikStack:membalik urutan isi stack.
Output menunjukkan perubahan isi stack sebelum dan sesudah dibalik.

## Unguided 

### 1. (isi dengan soal unguided 1)

```C++
source code unguided 1
```main.cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 9);
    push(S, 2);
    push(S, 4);
    push(S, 3);

    printInfo(S);     

    balikStack(S);
    printInfo(S);     

    return 0;
}

stack.cpp
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, Infotype x) {
    if (S.top < MAX - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

void pop(Stack &S, Infotype &x) {
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    Infotype x;

    while (S.top >= 0) {
        pop(S, x);
        push(temp, x);
    }

    S = temp;
}

stack.h

### Output Unguided 1 :
#ifndef STACK
#define STACK
#define Nil NULL

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);

void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif

##### Output 1
![Screenshot Output Unguided 1
_1)(https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan7_Modul7/unguided1.png)


penjelasan unguided 1 
Program ini menguji pemahaman dasar tentang operasi stack seperti push, pop, dan balikStack
Tujuannya adalah untuk memperlihatkan bagaimana elemen dimasukkan dan dikeluarkan sesuai prinsip LIFO.
Setelah beberapa data dimasukkan, fungsi balikStac dijalankanuntuk membalik urutan elemen di dalam stack.
Melalui program ini, pengguna dapat memahami dasar dari manajemen data dalam stack serta efek operasi pembalikan.

### 2. (isi dengan soal unguided 2)

```C++
source code unguided 2
``main.cpp 
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 9);
    pushAscending(S, 3);
    pushAscending(S, 2);

    printInfo(S); 

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S); 

    return 0;
}
stack.cpp
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, Infotype x) {
    if (S.top < MAX - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

void pop(Stack &S, Infotype &x) {
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    Infotype x;

    while (S.top >= 0) {
        pop(S, x);
        push(temp, x);
    }

    S = temp;
}

void pushAscending(Stack &S, Infotype x) {
    Stack temp;
    createStack(temp);
    Infotype y;

    while (S.top >= 0 && S.info[S.top] < x) {
        pop(S, y);
        push(temp, y);
    }

    push(S, x);

    while (temp.top >= 0) {
        pop(temp, y);
        push(S, y);
    }
}
stack.h
#ifndef STACK_H
#define STACK_H

const int MAX = 20;

typedef int Infotype;

struct Stack {
    Infotype info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, Infotype x);
void pop(Stack &S, Infotype &x);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, Infotype x); 

#endif

### Output Unguided 2 :
##### Output 1
![Screenshot Output Unguided 2
_1)(https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan7_Modul7/unguided2_1.png)
)

penjelasan unguided 2
Di dalamnya digunakan dua fungsi utama, yaitu pushAscending() dan balikStack(), dengan output otomatis tanpa perlu input dari pengguna.
Langkah-langkah yang dilakukan program
Menampilkan pesan pembuka “Hello world!”
Mengisi stack dengan data yang disusun dari besar ke kecil.
Menampilkan isi stack sebelum dibalik
Menjalankan fungsi balikStack() untuk membalik urutan data.
Menampilkan hasil stack setelah dibalik.

### 3. (isi dengan soal unguided 3)

```C++
source code unguided 3
```main.cpp
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    getInputStream(S);
    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

stack.cpp
#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, Infotype x) {
    if (S.top < MAX - 1) {
        S.top++;
        S.info[S.top] = x;
    }
}

void pop(Stack &S, Infotype &x) {
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    Infotype x;
    while (S.top >= 0) {
        pop(S, x);
        push(temp, x);
    }
    S = temp;
}

void pushAscending(Stack &S, Infotype x) {
    Stack temp;
    createStack(temp);
    Infotype y;
    while (S.top >= 0 && S.info[S.top] < x) {
        pop(S, y);
        push(temp, y);
    }
    push(S, x);
    while (temp.top >= 0) {
        pop(temp, y);
        push(S, y);
    }
}

void getInputStream(Stack &S) {
    char ch;
    while (true) {
        ch = cin.get();
        if (ch == '\n') break;
        if (isdigit(ch)) {
            int x = ch - '0';
            push(S, x);
        }
    }
}
stack.h
#ifndef STACK_H
#define STACK_H

const int MAX = 20;

typedef int Infotype;

struct Stack {
    Infotype info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, Infotype x);
void pop(Stack &S, Infotype &x);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, Infotype x);
void getInputStream(Stack &S);

#endif

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3
_1)(https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan7_Modul7/unguided3_1.png)
)
penjelasan unguided 3
ditambahkan fitur input dinamis menggunakan stream, di mana data angka dibaca langsung dari keyboard.
Setelah semua data dimasukkan, program akan membalik urutan data di dalam stack menggunakan balikStack().
Dengan cara ini, pengguna dapat melihat bagaimana stack memproses data secara real-time, dari input pengguna sampai hasil akhir setelah dibalik.
Program ini menjadi contoh penerapan stack yang lebih interaktif dan realistis dalam pengolahan data. 
## Kesimpulan
dapat disimpulkan bahwa stack merupakan salah satu struktur data penting yang bekerja dengan prinsip LIFO (Last In First Out), di mana elemen terakhir yang dimasukkan akan menjadi elemen pertama yang keluar. Implementasi stack dapat dilakukan dengan linked list untuk penyimpanan dinamis maupun dengan array untuk penyimpanan statis. Melalui berbagai percobaan guided dan unguided, terlihat bahwa operasi dasar seperti push, pop, dan balikStack() dapat dikembangkan menjadi fungsi yang lebih kompleks seperti pushAscending() atau input berbasis stream. Praktikum ini membantu memahami bagaimana stack bekerja secara logis dan teknis, serta bagaimana konsep abstrak struktur data dapat diterapkan dalam program nyata menggunakan bahasa C++.

## Referensi
[1] https://www.geeksforgeeks.org/dsa/stack-data-structure/ [2] https://www.trivusi.web.id/2022/07/struktur-data-stack.html
<br>...
