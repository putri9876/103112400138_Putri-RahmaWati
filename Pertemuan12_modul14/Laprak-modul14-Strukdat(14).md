# <h1 align="center">Laporan Praktikum Modul 14 Graph </h1>
<p align="center">Putri Rahma Wati - 103112400138

## Dasar Teori
Graph adalah jenis struktur data umum yang susunan datanya tidak berdekatan satu sama lain (non-linier). Graph terdiri dari kumpulan simpul berhingga untuk menyimpan data dan antara dua buah simpul terdapat hubungan saling keterkaitan.[1] Graph adalah struktur data non-linear yang terdiri dari dua komponen utama: vertex (simpul) dan edge (sisi) yang menghubungkan vertex. Graph dapat berupa directed (sisi memiliki arah) atau undirected (sisi dua arah), serta dapat memiliki weighted (dengan bobot) atau unweighted (tanpa bobot). Graph juga dapat dikategorikan sebagai cyclic (mengandung siklus) atau acyclic (tanpa siklus), serta connected (semua simpul terhubung) atau disconnected (beberapa simpul tidak terhubung).
Untuk merepresentasikan graph secara komputer, ada dua metode umum: Adjacency Matrix, yaitu matriks n x n yang menunjukkan keberadaan sisi antar vertex, dan Adjacency List, yaitu daftar tetangga untuk setiap vertex yang lebih efisien untuk graph yang jarang sisi (sparse graph).
Traversal atau penelusuran graph dilakukan untuk mengunjungi semua simpul, biasanya menggunakan algoritma BFS (Breadth-First Search) yang menelusuri vertex per level, dan DFS (Depth-First Search) yang menelusuri sedalam mungkin sebelum kembali. Pemilihan metode traversal bergantung pada tujuan aplikasi, seperti pencarian jalur terpendek atau eksplorasi seluruh vertex[2].

## Guided 

### 1. ...

```C++
source code guided 1
```graph.cpp
#include "graph.h"
#include <iostream>
#include <queue> //library queue untuk BFS
#include <stack> //library stack untuk DFS

using namespace std;

//prosedur untuk mengeset first dari graph sebagai NULL
void CreateGraph(Graph &G) {
    G.First = NULL;
}

//alokasi Node baru
adrNode AlokasiNode(infoGraph data) {
    adrNode nodeBaru = new ElmNode;
    nodeBaru->info = data;
    nodeBaru->visited = 0; //isinya 0/1
    nodeBaru->firstEdge = NULL;
    nodeBaru->Next = NULL;
    return nodeBaru;
}

//alokasi Edge baru
adrEdge AlokasiEdge(adrNode nodeTujuan) {
    adrEdge edgeBaru = new ElmEdge;
    edgeBaru->Node = nodeTujuan;
    edgeBaru->Next = NULL;
    return edgeBaru;
}

//Menambahkan Node ke dalam Graph
void InsertNode(Graph &G, infoGraph data) {
    adrNode nodeBaru = AlokasiNode(data);
    if (G.First == NULL) {
        G.First = nodeBaru;
    } else {
        //konsepnya insert last
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != NULL) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeBaru;
    }
}

//function untuk mencari alamat Node berdasarkan infonya
adrNode FindNode(Graph G, infoGraph data) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        if (nodeBantu->info == data) {
            return nodeBantu;
        }
        nodeBantu = nodeBantu->Next;
    }
    return NULL;
}

//prosedur untuk menghubungkan dua Node (Undirected Graph)
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2) {
    adrNode node1 = FindNode(G, info1);
    adrNode node2 = FindNode(G, info2);

    if (node1 != NULL && node2 != NULL) {
        //Hubungkan node1 ke node2
        adrEdge Edge1 = AlokasiEdge(node2);
        Edge1->Next = node1->firstEdge; // Insert First pada list edge
        node1->firstEdge = Edge1;

        //Hubungkan node2 ke node1 (Karena Undirected/Bolak-balik)
        adrEdge Edge2 = AlokasiEdge(node1);
        Edge2->Next = node2->firstEdge;
        node2->firstEdge = Edge2;
    } else {
        cout << "Node tidak ditemukan!" << endl;
    }
}

//prosedur untuk memutuskan hubungan dua node
void DisconnectNode(adrNode node1, adrNode node2) {
    if (node1 != NULL && node2 != NULL) {
        adrEdge edgeBantu = node1->firstEdge;
        adrEdge PrevE = NULL;

        //Cari edge yang mengarah ke node2 di dalam list milik node1
        while (edgeBantu != NULL && edgeBantu->Node != node2) {
            PrevE = edgeBantu;
            edgeBantu = edgeBantu->Next;
        }

        if (edgeBantu != NULL) { //jika Edge ditemukan
            if (PrevE == NULL) {
                //Hapus edge pertama
                node1->firstEdge = edgeBantu->Next;
            } else {
                //Hapus edge di tengah/akhir
                PrevE->Next = edgeBantu->Next;
            }
            delete edgeBantu;
        }
    }
}

//prosedur untuk menghapus Node X beserta semua edge yang berhubungan dengannya
void DeleteNode(Graph &G, infoGraph X) {
    //1. Cari Node yang akan dihapus (nodeHapus)
    adrNode nodeHapus = FindNode(G, X);
    if (nodeHapus == NULL) {
        cout << "Node tidak ditemukan." << endl;
        return;
    }

    //2. Hapus semua Edge yang MENGARAH ke nodeHapus (Incoming Edges)
    //cek setiap node di graph, apakah punya edge ke nodeHapus
    adrNode nodeLainnya = G.First;
    while (nodeLainnya != NULL) {
        DisconnectNode(nodeLainnya, nodeHapus); //putus hubungan nodeLainnya ke nodeHapus
        nodeLainnya = nodeLainnya->Next;
    }

    //3. Hapus semua Edge yang KELUAR dari nodeHapus (Outgoing Edges)
    //Deallokasi list edge milik nodeHapus
    adrEdge edgeBantu = nodeHapus->firstEdge;
    while (edgeBantu != NULL) {
        adrEdge tempE = edgeBantu;
        edgeBantu = edgeBantu->Next;
        delete tempE;
    }
    nodeHapus->firstEdge = NULL;

    //4. Hapus nodeHapus dari List Utama Graph
    if (G.First == nodeHapus) {
        //jika nodeHapus di awal
        G.First = nodeHapus->Next;
    } else {
        //jika nodeHapus di tengah/akhir
        adrNode nodeBantu = G.First;
        while (nodeBantu->Next != nodeHapus) {
            nodeBantu = nodeBantu->Next;
        }
        nodeBantu->Next = nodeHapus->Next;
    }

    //5. delete nodeHapus
    delete nodeHapus;
}

//Menampilkan isi Graph (Adjacency List) 
void PrintInfoGraph(Graph G) {
    adrNode nodeBantu = G.First;
    while (nodeBantu != NULL) {
        cout << "Node " << nodeBantu->info << " terhubung ke: ";
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            cout << edgeBantu->Node->info << " "; //Akses info dari node tujuan
            edgeBantu = edgeBantu->Next;
        }
        cout << endl;
        nodeBantu = nodeBantu->Next;
    }
}

//Reset status visited sebelum traversal
void ResetVisited(Graph &G) {
    adrNode nodeReset = G.First;
    while (nodeReset != NULL) {
        nodeReset->visited = 0;
        nodeReset = nodeReset->Next;
    }
}

//traversal Breadth First Search / BFS (Menggunakan Queue)
void PrintBFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    queue<adrNode> Qyu;
    
    //Enqueue start
    Qyu.push(StartNode);
    StartNode->visited = 1;

    cout << "BFS Traversal: ";
    while (!Qyu.empty()) {
        adrNode nodeBantu = Qyu.front();
        Qyu.pop();
        cout << nodeBantu->info << " - ";

        //Cek semua tetangga atau edge nya
        adrEdge edgeBantu = nodeBantu->firstEdge;
        while (edgeBantu != NULL) {
            if (edgeBantu->Node->visited == 0) {
                edgeBantu->Node->visited = 1;
                Qyu.push(edgeBantu->Node);
            }
            edgeBantu = edgeBantu->Next;
        }
    }
    cout << endl;
}

//Traversal Depth First Search / DFS (Menggunakan Stack)
void PrintDFS(Graph G, infoGraph StartInfo) {
    ResetVisited(G);
    adrNode StartNode = FindNode(G, StartInfo);
    
    if (StartNode == NULL) return;

    stack<adrNode> Stak;
    
    Stak.push(StartNode);

    cout << "DFS Traversal: ";
    while (!Stak.empty()) {
        adrNode nodeBantu = Stak.top();
        Stak.pop();

        if (nodeBantu->visited == 0) {
            nodeBantu->visited = 1;
            cout << nodeBantu->info << " - ";

            //masukkan tetangga ke stack
            adrEdge edgeBantu = nodeBantu->firstEdge;
            while (edgeBantu != NULL) {
                if (edgeBantu->Node->visited == 0) {
                    Stak.push(edgeBantu->Node);
                }
                edgeBantu = edgeBantu->Next;
            }
        }
    }
    cout << endl;
}
graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include<iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode{
    infoGraph info; //menyimpan data node (misal: char/int)
    int visited; //penanda untuk tranversal (0/1) (penanda apakah node sudah dikungi)
    adrEdge firstEdge; //pointer ke edge pertama yg terhubung
    adrNode Next; //pointer ke node berikutnya daam graph
};

struct ElmEdge{
    adrNode Node; //pointer yang menunjuk ke lokasi node tujuan
    adrEdge Next; //pointer ke edge berikutnya (jika satu node memiliki banyak cabang)
};

struct Graph{
    adrNode First; //pointer ke node pertama dalam list graph
};

void CreateGraph(Graph &G); //prosedur untuk mengeset first dari graph sebagai NULL
adrNode AlokasiNode(infoGraph data); //alokasi Node Baru
adrEdge AlokasiEdge(adrNode nodeTujuan); //alokasi edge baru

void InsertNode(Graph &G, infoGraph data); //menambahkan Node kedalam graph
adrNode FindNode(Graph G, infoGraph data); // function untuk mencari alamat Node berdasarkan 
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2); // prosedur untuk menghubungkan
void DisconnectNode(adrNode node1, adrNode node2); // untuk memutuskan hubungan dua buat node
void DeleteNode(Graph &G, infoGraph X); //prosedur untuk menghapus node X beserta semua edge

void PrintInfoGraph(Graph G); //menampilkan isi graph (Adjaceny list)
void ResetVisited(Graph &G); // reset stats visited sebelum traversak
void PrintBFS(Graph G, infoGraph StartInfo); //traversal breadh first search /bfs
void PrintDFS(Graph G,infoGraph StartInfo); //traversal breadh first search /bfs

#endif
main.cpp
#include "graph.h"
#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G, 'A');
    InsertNode(G, 'B');
    InsertNode(G, 'C');
    InsertNode(G, 'D');
    InsertNode(G, 'E');
    InsertNode(G, 'F');

    ConnectNode(G, 'A', 'B');
    ConnectNode(G, 'A', 'D');
    ConnectNode(G, 'B', 'C');
    ConnectNode(G, 'D', 'C');
    ConnectNode(G, 'B', 'E');
    ConnectNode(G, 'C', 'E');
    ConnectNode(G, 'C', 'F');
    ConnectNode(G, 'E', 'F');

    cout << " === REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << " === HASIL TRAVERSAL ===" << endl;
    //mulai traversal dari node A
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');
    cout << endl;

    cout << " === HAPUS NODE E ===" << endl;
    DeleteNode(G, 'E');
    if(FindNode(G, 'E')== NULL){
        cout << "Node E berhasil terhapus" << endl;
    } else {
        cout << "Node E tidak berhasil terhapus" << endl;
    }
    cout << endl;

    cout << "=== REPRESENTASI ADJACENCY LIST ===" << endl;
    PrintInfoGraph(G);
    cout << endl;

    cout << "===HASIL TRAVERSAL ===" << endl;
    PrintBFS(G, 'A');
    PrintDFS(G, 'A');

    return 0;

}
penjelasan singkat guided 1 
program mengimplementasi ADT Graph menggunakan adjacency list di C++. Prosedur yang dibuat meliputi pembuatan graph, alokasi node dan edge, penyisipan node, penghubungan node, hingga penghapusan node beserta edge yang terhubung. Selain itu, terdapat implementasi traversal BFS dan DFS menggunakan struktur data queue dan stack. Hal ini memberikan pemahaman dasar bagaimana graph direpresentasikan secara dinamis dan bagaimana algoritma penelusuran bekerja pada struktur graph
## Unguided 

### 1. Buatlah implementasi ADT Graph pada file “graph.cpp” dan cobalah hasil implementasi ADT
pada file “main.cpp”

```C++
source code unguided 1
```graph.cpp
#include "graph.h"

void CreateGraph(Graph &G) {
    G.first = NULL;
}

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL) {
            Q = Q->Next;
        }
        Q->Next = P;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = AllocateEdge(N2);
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = AllocateEdge(N1);
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}
graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);

#endif
main.cpp
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G,'A');
    InsertNode(G,'B');
    InsertNode(G,'C');
    InsertNode(G,'D');
    InsertNode(G,'E');
    InsertNode(G,'F');
    InsertNode(G,'G');
    InsertNode(G,'H');

    adrNode A = G.first;
    adrNode B = A->Next;
    adrNode C = B->Next;
    adrNode D = C->Next;
    adrNode E = D->Next;
    adrNode F = E->Next;
    adrNode Gg = F->Next;
    adrNode H = Gg->Next;

    ConnectNode(A,B);
    ConnectNode(A,C);
    ConnectNode(B,D);
    ConnectNode(B,E);
    ConnectNode(C,F);
    ConnectNode(C,Gg);
    ConnectNode(D,H);
    ConnectNode(E,H);
    ConnectNode(F,H);
    ConnectNode(Gg,H);

    PrintInfoGraph(G);

    return 0;
}
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1]https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan12_modul14/unguided1_1.jpg

penjelasan unguided 1 
mengimplementasikan ADT Graph secara mandiri dengan fokus pada pembuatan node, penyisipan node, penghubungan node, dan menampilkan adjacency list. Implementasi ini menekankan pemahaman tentang struktur data graph secara linier dan bagaimana setiap node menyimpan daftar edge ke node lain, serta memperkuat konsep insert last pada linked list node graph. Praktikum ini melatih kemandirian mahasiswa dalam membangun struktur graph tanpa panduan langsung.

### 2. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.

```C++
source code unguided 2
```graph.cpp
#include "graph.h"

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL) {
            Q = Q->Next;
        }
        Q->Next = P;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = AllocateEdge(N2);
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = AllocateEdge(N1);
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintDFS(Graph G, adrNode N) {
    if (N != NULL && N->visited == 0) {
        cout << N->info << " ";
        N->visited = 1;

        adrEdge E = N->firstEdge;
        while (E != NULL) {
            PrintDFS(G, E->Node);
            E = E->Next;
        }
    }
}
graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void PrintDFS(Graph G, adrNode N);

#endif

main.cpp
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G,'A');
    InsertNode(G,'B');
    InsertNode(G,'C');
    InsertNode(G,'D');
    InsertNode(G,'E');
    InsertNode(G,'F');
    InsertNode(G,'G');
    InsertNode(G,'H');

    adrNode A = G.first;
    adrNode B = A->Next;
    adrNode C = B->Next;
    adrNode D = C->Next;
    adrNode E = D->Next;
    adrNode F = E->Next;
    adrNode Gg = F->Next;
    adrNode H = Gg->Next;

    ConnectNode(A,B);
    ConnectNode(A,C);
    ConnectNode(B,D);
    ConnectNode(B,E);
    ConnectNode(C,F);
    ConnectNode(C,Gg);
    ConnectNode(D,H);
    ConnectNode(E,H);
    ConnectNode(F,H);
    ConnectNode(Gg,H);

    cout << "DFS : ";
    PrintDFS(G, A);

    return 0;
}

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan12_modul14/unguided2_1.jpg)

penjelasan unguided 2
mengimplementasi prosedur DFS (Depth First Search) untuk menelusuri graph. Mahasiswa membuat prosedur rekursif yang menandai node sebagai visited sebelum menelusuri node tetangga. Dengan latihan ini, mahasiswa memahami cara traversal rekursif pada graph dan pentingnya status visited agar traversal tidak memasuki loop tak terbatas pada graph yang memiliki siklus.

### 3. Buatlah prosedur untuk menampilkanhasil penelusuran DFS.
prosedur PrintBFS (Graph G, adrNode N);

```C++
source code unguided 3
```graph.cpp
#include "graph.h"
#include <queue>

adrNode AllocateNode(infoGraph X) {
    adrNode P = new ElmNode;
    P->info = X;
    P->visited = 0;
    P->firstEdge = NULL;
    P->Next = NULL;
    return P;
}

adrEdge AllocateEdge(adrNode N) {
    adrEdge E = new ElmEdge;
    E->Node = N;
    E->Next = NULL;
    return E;
}

void CreateGraph(Graph &G) {
    G.first = NULL;
}

void InsertNode(Graph &G, infoGraph X) {
    adrNode P = AllocateNode(X);
    if (G.first == NULL) {
        G.first = P;
    } else {
        adrNode Q = G.first;
        while (Q->Next != NULL) {
            Q = Q->Next;
        }
        Q->Next = P;
    }
}

void ConnectNode(adrNode N1, adrNode N2) {
    adrEdge E1 = AllocateEdge(N2);
    E1->Next = N1->firstEdge;
    N1->firstEdge = E1;

    adrEdge E2 = AllocateEdge(N1);
    E2->Next = N2->firstEdge;
    N2->firstEdge = E2;
}

void PrintInfoGraph(Graph G) {
    adrNode P = G.first;
    while (P != NULL) {
        cout << P->info << " -> ";
        adrEdge E = P->firstEdge;
        while (E != NULL) {
            cout << E->Node->info << " ";
            E = E->Next;
        }
        cout << endl;
        P = P->Next;
    }
}

void PrintBFS(Graph G, adrNode N) {
    queue<adrNode> Q;
    Q.push(N);
    N->visited = 1;

    while (!Q.empty()) {
        adrNode P = Q.front();
        Q.pop();
        cout << P->info << " ";

        adrEdge E = P->firstEdge;
        while (E != NULL) {
            if (E->Node->visited == 0) {
                E->Node->visited = 1;
                Q.push(E->Node);
            }
            E = E->Next;
        }
    }
}
graph.h
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmEdge {
    adrNode Node;
    adrEdge Next;
};

struct ElmNode {
    infoGraph info;
    int visited;
    adrEdge firstEdge;
    adrNode Next;
};

struct Graph {
    adrNode first;
};

void CreateGraph(Graph &G);
void InsertNode(Graph &G, infoGraph X);
void ConnectNode(adrNode N1, adrNode N2);
void PrintInfoGraph(Graph G);
void PrintBFS(Graph G, adrNode N);

#endif
main.cpp
#include "graph.h"

int main() {
    Graph G;
    CreateGraph(G);

    InsertNode(G,'A');
    InsertNode(G,'B');
    InsertNode(G,'C');
    InsertNode(G,'D');
    InsertNode(G,'E');
    InsertNode(G,'F');
    InsertNode(G,'G');
    InsertNode(G,'H');

    adrNode A = G.first;
    adrNode B = A->Next;
    adrNode C = B->Next;
    adrNode D = C->Next;
    adrNode E = D->Next;
    adrNode F = E->Next;
    adrNode Gg = F->Next;
    adrNode H = Gg->Next;

    ConnectNode(A,B);
    ConnectNode(A,C);
    ConnectNode(B,D);
    ConnectNode(B,E);
    ConnectNode(C,F);
    ConnectNode(C,Gg);
    ConnectNode(D,H);
    ConnectNode(E,H);
    ConnectNode(F,H);
    ConnectNode(Gg,H);

    cout << "BFS : ";
    PrintBFS(G, A);

    return 0;
}

### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 1] https://github.com/putri9876/103112400138_Putri-RahmaWati/blob/main/Pertemuan12_modul14/unguided3_1.jpg)
 

penjelasan unguided 3
menekankan implementasi prosedur BFS (Breadth First Search) menggunakan queue untuk menelusuri graph. Mahasiswa belajar bagaimana algoritma BFS menelusuri node per level, menandai node yang sudah dikunjungi, dan memastikan semua node terjangkau dari node awal. Praktikum ini melatih kemampuan mahasiswa dalam mengaplikasikan algoritma penelusuran graph non-rekursif secara sistematis.
## Kesimpulan
...
implementasi ADT Graph menggunakan adjacency list memberikan representasi yang efisien untuk menyimpan node dan edge secara dinamis. Guided dan unguided praktikum memperkenalkan konsep dasar pembuatan node, penyisipan node, penghubungan node, serta penghapusan node beserta edge yang terkait. Selain itu, implementasi traversal DFS dan BFS membantu memahami bagaimana penelusuran graph dilakukan secara rekursif maupun menggunakan struktur data tambahan seperti stack dan queue. Praktikum ini memperkuat pemahaman mahasiswa mengenai struktur data graph, konsep adjacency list, dan algoritma penelusuran yang penting dalam pengembangan program berbasis graph.

## Referensi
[1] https://www.trivusi.web.id/2022/07/struktur-data-graph.html 
<br>
[2] https://medium.com/@hammam.mudhoffar/mengetahui-struktur-data-graph-aee22bf68afa
<br>...
