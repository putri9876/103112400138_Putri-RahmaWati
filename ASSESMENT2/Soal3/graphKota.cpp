#include "graphKota.h"

void createGraph(GraphKota &G) {
    G.First = nullptr;
}

adrKota alokasiNode(string nama) {
    adrKota P = new ElmKota;
    P->namaKota = nama;
    P->visited = 0;
    P->firstEdge = nullptr;
    P->next = nullptr;
    return P;
}

adrEdge alokasiEdge(adrKota tujuan, int jarak) {
    adrEdge E = new ElmEdge;
    E->kotaTujuan = tujuan;
    E->jarak = jarak;
    E->next = nullptr;
    return E;
}

void insertNode(GraphKota &G, adrKota P) {
    if (G.First == nullptr) {
        G.First = P;
    } else {
        adrKota last = G.First;
        while (last->next != nullptr) last = last->next;
        last->next = P;
    }
}

adrKota findNode(GraphKota G, string nama) {
    adrKota P = G.First;
    while (P != nullptr) {
        if (P->namaKota == nama) return P;
        P = P->next;
    }
    return nullptr;
}

void connectNode(adrKota U, adrKota V, int jarak) {
    if (U != nullptr && V != nullptr) {
        // Karena Undirected, hubungkan U ke V dan V ke U
        adrEdge E1 = alokasiEdge(V, jarak);
        E1->next = U->firstEdge;
        U->firstEdge = E1;

        adrEdge E2 = alokasiEdge(U, jarak);
        E2->next = V->firstEdge;
        V->firstEdge = E2;
    }
}

void disconnectNode(adrKota U, adrKota V) {
    if (U == nullptr || V == nullptr) return;
    // Hapus edge dari U ke V
    adrEdge prev = nullptr, curr = U->firstEdge;
    while (curr != nullptr && curr->kotaTujuan != V) {
        prev = curr; curr = curr->next;
    }
    if (curr != nullptr) {
        if (prev == nullptr) U->firstEdge = curr->next;
        else prev->next = curr->next;
        delete curr;
    }
    // Hapus sebaliknya (V ke U)
    prev = nullptr; curr = V->firstEdge;
    while (curr != nullptr && curr->kotaTujuan != U) {
        prev = curr; curr = curr->next;
    }
    if (curr != nullptr) {
        if (prev == nullptr) V->firstEdge = curr->next;
        else prev->next = curr->next;
        delete curr;
    }
}

void deleteNode(GraphKota &G, string nama) {
    adrKota P = findNode(G, nama);
    if (P == nullptr) return;
    // 1. Putus semua hubungan edge dari kota lain ke P
    adrKota temp = G.First;
    while (temp != nullptr) {
        disconnectNode(temp, P);
        temp = temp->next;
    }
    // 2. Hapus node P dari list kota
    if (G.First == P) G.First = P->next;
    else {
        adrKota prev = G.First;
        while (prev->next != P) prev = prev->next;
        prev->next = P->next;
    }
    delete P;
}

void printGraph(GraphKota G) {
    cout << "=== REPRESENTASI ADJACENCY LIST GRAPH ===" << endl;
    adrKota P = G.First;
    while (P != nullptr) {
        cout << "Node " << P->namaKota << " terhubung ke: ";
        adrEdge E = P->firstEdge;
        while (E != nullptr) {
            cout << E->kotaTujuan->namaKota << "(" << E->jarak << " KM)";
            if (E->next != nullptr) cout << ", ";
            E = E->next;
        }
        cout << endl;
        P = P->next;
    }
}

void resetVisited(GraphKota &G) {
    adrKota P = G.First;
    while (P != nullptr) {
        P->visited = 0;
        P = P->next;
    }
}

void printBFS(GraphKota G, string startNode) {
    adrKota start = findNode(G, startNode);
    if (start == nullptr) return;
    queue<adrKota> q;
    resetVisited(G);
    start->visited = 1;
    q.push(start);
    cout << "BFS Traversal: ";
    while (!q.empty()) {
        adrKota curr = q.front(); q.pop();
        cout << curr->namaKota << " - ";
        adrEdge E = curr->firstEdge;
        while (E != nullptr) {
            if (E->kotaTujuan->visited == 0) {
                E->kotaTujuan->visited = 1;
                q.push(E->kotaTujuan);
            }
            E = E->next;
        }
    }
    cout << endl;
}

void printDFS(GraphKota G, string startNode) {
    adrKota start = findNode(G, startNode);
    if (start == nullptr) return;
    stack<adrKota> s;
    resetVisited(G);
    s.push(start);
    cout << "DFS Traversal: ";
    while (!s.empty()) {
        adrKota curr = s.top(); s.pop();
        if (curr->visited == 0) {
            curr->visited = 1;
            cout << curr->namaKota << " - ";
            adrEdge E = curr->firstEdge;
            while (E != nullptr) {
                if (E->kotaTujuan->visited == 0) s.push(E->kotaTujuan);
                E = E->next;
            }
        }
    }
    cout << endl;
}