#include "dllplaylist.h"

float calculatePopularityScore(int playCount, float rating) {
    return (0.8 * playCount) + (20.0 * rating); 
}

bool isEmpty(List L) {
    return L.head == nullptr;
}

List createList() {
    List L;
    L.head = nullptr;
    L.tail = nullptr;
    return L;
}

Node* allocate(Song S) {
    Node* newNode = new Node;
    newNode->info = S;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void deallocate(Node* P) {
    delete P;
}

void insertFirst(List &L, Song S) {
    Node* P = allocate(S);
    if (isEmpty(L)) { L.head = L.tail = P; } 
    else {
        P->next = L.head;
        L.head->prev = P;
        L.head = P;
    }
}

void insertLast(List &L, Song S) {
    if (isEmpty(L)) { insertFirst(L, S); } 
    else {
        Node* P = allocate(S);
        P->prev = L.tail;
        L.tail->next = P;
        L.tail = P;
    }
}

void insertAfter(List &L, Node* Q, Song S) {
    if (Q == nullptr) return; 
    if (Q == L.tail) { insertLast(L, S); } 
    else {
        Node* P = allocate(S);
        P->next = Q->next;
        Q->next->prev = P;
        P->prev = Q;
        Q->next = P;
    }
}

void insertBefore(List &L, Node* Q, Song S) {
    if (Q == nullptr) return; 
    if (Q == L.head) { insertFirst(L, S); } 
    else {
        Node* P = allocate(S);
        P->next = Q;
        Q->prev = P;
        P->prev = Q->prev;
        Q->prev->next = P;
    }
}

void deleteFirst(List &L, Song &S) {
    if (isEmpty(L)) return;
    Node* P = L.head;
    S = P->info; 
    if (L.head == L.tail) { L.head = L.tail = nullptr; } 
    else {
        L.head = P->next;
        L.head->prev = nullptr;
    }
    deallocate(P);
}

void deleteLast(List &L, Song &S) {
    if (isEmpty(L)) return;
    if (L.head == L.tail) { deleteFirst(L, S); } 
    else {
        Node* P = L.tail;
        S = P->info; 
        L.tail = P->prev;
        L.tail->next = nullptr;
        deallocate(P);
    }
}

void deleteAfter(List &L, Node* Q, Song &S) {
    if (Q == nullptr || Q->next == nullptr) return;
    Node* P = Q->next;
    S = P->info; 
    if (P == L.tail) { deleteLast(L, S); } 
    else {
        Q->next = P->next;
        P->next->prev = Q;
        deallocate(P);
    }
}

void deleteBefore(List &L, Node* Q, Song &S) {
    if (Q == nullptr || Q->prev == nullptr) return;
    if (Q->prev == L.head) { deleteFirst(L, S); } 
    else {
        Node* P = Q->prev;
        S = P->info; 
        P->prev->next = Q;
        Q->prev = P->prev;
        deallocate(P);
    }
}

Node searchNodeAtPosition(List L, int posisi) {
    if (isEmpty(L) || posisi < 1) return nullptr;
    Node* P = L.head;
    int count = 1;
    while (P != nullptr && count < posisi) {
        P = P->next;
        count++;
    }
    return P; 
}

void updateAtPosition(List &L, int posisi, Song S) {
    Node* P = searchNodeAtPosition(L, posisi);
    if (P != nullptr) {
        P->info = S;
        std::cout << "Node pada posisi " << posisi << " berhasil di-update." << std::endl;
    }
}
void viewListSimple(List L, const std::string& title) {
    std::cout << "\n--- " << title << " ---" << std::endl;
    if (isEmpty(L)) {
        std::cout << "List kosong." << std::endl;
        return;
    }
    Node* P = L.head;
    int posisi = 1;
    while (P != nullptr) {
        float score = calculatePopularityScore(P->info.PlayCount, P->info.Rating);
        std::cout << posisi << ". " << P->info.Title << " (" << P->info.Artist 
                  << ") [Score: " << std::fixed << std::setprecision(2) << score << "]" << std::endl;
        P = P->next;
        posisi++;
    }
}

void searchByPopularityRangeSimple(List L, float minScore, float maxScore) {
    std::cout << "\n--- Hasil Pencarian Kustom (Score " << minScore << " - " << maxScore << ") ---" << std::endl;
    Node* P = L.head;
    bool found = false;
    
    while (P != nullptr) {
        float score = calculatePopularityScore(P->info.PlayCount, P->info.Rating);
        if (score >= minScore && score <= maxScore) {
            std::cout << "- " << P->info.Title << " (" << P->info.Artist 
                      << ") [Score: " << std::fixed << std::setprecision(2) << score << "]" << std::endl;
            found = true;
        }
        P = P->next;
    }

    if (!found) {
        std::cout << "Tidak ditemukan lagu dalam rentang tersebut." << std::endl;
    }
}