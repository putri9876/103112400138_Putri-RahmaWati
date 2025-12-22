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
