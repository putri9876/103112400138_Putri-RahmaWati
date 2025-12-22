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
