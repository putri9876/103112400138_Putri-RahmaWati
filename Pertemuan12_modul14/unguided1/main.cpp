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