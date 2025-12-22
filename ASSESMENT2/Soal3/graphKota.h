#ifndef GRAPHKOTA_H
#define GRAPHKOTA_H

#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

typedef struct ElmKota *adrKota;
typedef struct ElmEdge *adrEdge;

struct ElmKota {
    string namaKota;
    int visited; // 0/1
    adrEdge firstEdge;
    adrKota next;
};

struct ElmEdge {
    adrKota kotaTujuan;
    int jarak;
    adrEdge next;
};

struct GraphKota {
    adrKota First;
};

void createGraph(GraphKota &G);
adrKota alokasiNode(string nama);
adrEdge alokasiEdge(adrKota tujuan, int jarak);
void insertNode(GraphKota &G, adrKota P);
adrKota findNode(GraphKota G, string nama);
void connectNode(adrKota U, adrKota V, int jarak);
void disconnectNode(adrKota U, adrKota V);
void deleteNode(GraphKota &G, string nama);
void printGraph(GraphKota G);

void resetVisited(GraphKota &G);
void printBFS(GraphKota G, string startNode);
void printDFS(GraphKota G, string startNode);

#endif