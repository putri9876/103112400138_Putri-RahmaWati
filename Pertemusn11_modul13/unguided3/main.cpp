#include "MultiLL.h"

int main(){
    listParent LP;
    createListParent(LP);

    insertLastParent(LP, allocNodeParent("G001", "Aves"));
    insertLastParent(LP, allocNodeParent("G002", "Mamalia"));
    insertLastParent(LP, allocNodeParent("G003", "Pisces"));
    insertLastParent(LP, allocNodeParent("G004", "Amfibi"));
    insertLastParent(LP, allocNodeParent("G005", "Reptil"));

    insertLastChild(LP.first->L_Child,
        allocNodeChild("AV001", "Cendrawasih", "Hutan", true, 0.3));

    insertLastChild(LP.first->L_Child,
        allocNodeChild("AV002", "Bebek", "Air", true, 2));

    NodeParent P2 = LP.first->next;

    insertLastChild(P2->L_Child,
        allocNodeChild("M001", "Harimau", "Hutan", true, 200));

    insertLastChild(P2->L_Child,
        allocNodeChild("M003", "Gorila", "Hutan", false, 160));

    insertLastChild(P2->L_Child,
        allocNodeChild("M002", "Kucing", "Darat", true, 4));

    NodeParent P4 = P2->next->next;

    insertLastChild(P4->L_Child,
        allocNodeChild("AM001", "Kodok", "Sawah", false, 0.2));

    printMLLStructure(LP);

    cout << endl;
    searchHewanByEkor(LP, false);

    cout << endl;
    deleteAfterParent(LP, P2->next);
    printMLLStructure(LP);

    return 0;
}
