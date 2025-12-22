#include "graphKota.h"

int main() {
    GraphKota G;
    createGraph(G);

    insertNode(G, alokasiNode("Jakarta"));
    insertNode(G, alokasiNode("Bogor"));
    insertNode(G, alokasiNode("Depok"));
    insertNode(G, alokasiNode("Tangerang"));
    insertNode(G, alokasiNode("Bekasi"));

    connectNode(findNode(G, "Jakarta"), findNode(G, "Tangerang"), 24);
    connectNode(findNode(G, "Jakarta"), findNode(G, "Depok"), 21);
    connectNode(findNode(G, "Jakarta"), findNode(G, "Bekasi"), 16);
    connectNode(findNode(G, "Jakarta"), findNode(G, "Bogor"), 42);
    connectNode(findNode(G, "Bogor"), findNode(G, "Bekasi"), 60);
    connectNode(findNode(G, "Bogor"), findNode(G, "Depok"), 22);
    connectNode(findNode(G, "Depok"), findNode(G, "Bekasi"), 25);
    connectNode(findNode(G, "Depok"), findNode(G, "Tangerang"), 30);
    connectNode(findNode(G, "Tangerang"), findNode(G, "Bekasi"), 45);

    printGraph(G);
    cout << endl;

    deleteNode(G, "Depok");

    printGraph(G);
    cout << endl;

    cout << "=== HASIL TRAVERSAL BFS & DFS ===" << endl;
    printBFS(G, "Tangerang");
    printDFS(G, "Tangerang");

    return 0;
}