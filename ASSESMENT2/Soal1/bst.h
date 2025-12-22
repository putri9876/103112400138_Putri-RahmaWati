#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int idProduk;
    string namaProduk;
    int stok;
    Node *left, *right;

    Node(int id, string nama, int s);
};

class BST {
private:
    Node* root;

    Node* insert(Node* node, int id, string nama, int stok);
    Node* searchById(Node* node, int id);
    void searchByProduct(Node* node, string nama);
    Node* findMin(Node* node);
    Node* findMax(Node* node);
    Node* deleteNode(Node* node, int id);
    void inOrder(Node* node);
    void preOrder(Node* node);
    void postOrder(Node* node);
    void deleteTree(Node* node);

public:
    BST();
    void insertNode(int id, string nama, int stok);
    void searchById(int id);
    void searchByProduct(string nama);
    void findMin();
    void findMax();
    void deleteNode(int id);
    void inOrder();
    void preOrder();
    void postOrder();
    void deleteTree();
};

#endif
