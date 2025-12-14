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
