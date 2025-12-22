#include "BST.h"

Node::Node(int id, string nama, int s) {
    idProduk = id;
    namaProduk = nama;
    stok = s;
    left = right = NULL;
}

BST::BST() {
    root = NULL;
}

Node* BST::insert(Node* node, int id, string nama, int stok) {
    if (node == NULL)
        return new Node(id, nama, stok);

    if (id < node->idProduk)
        node->left = insert(node->left, id, nama, stok);
    else if (id > node->idProduk)
        node->right = insert(node->right, id, nama, stok);

    return node;
}

void BST::insertNode(int id, string nama, int stok) {
    root = insert(root, id, nama, stok);
}

Node* BST::searchById(Node* node, int id) {
    if (node == NULL || node->idProduk == id)
        return node;

    if (id < node->idProduk)
        return searchById(node->left, id);
    else
        return searchById(node->right, id);
}

void BST::searchById(int id) {
    Node* result = searchById(root, id);
    if (result)
        cout << "Ditemukan: ID=" << result->idProduk
             << ", Nama=" << result->namaProduk
             << ", Stok=" << result->stok << endl;
    else
        cout << "Produk dengan ID " << id << " tidak ditemukan" << endl;
}

void BST::searchByProduct(Node* node, string nama) {
    if (node == NULL) return;

    searchByProduct(node->left, nama);

    if (node->namaProduk == nama)
        cout << "Ditemukan: ID=" << node->idProduk
             << ", Nama=" << node->namaProduk
             << ", Stok=" << node->stok << endl;

    searchByProduct(node->right, nama);
}

void BST::searchByProduct(string nama) {
    cout << "Pencarian produk: " << nama << endl;
    searchByProduct(root, nama);
}

Node* BST::findMin(Node* node) {
    while (node && node->left != NULL)
        node = node->left;
    return node;
}

Node* BST::findMax(Node* node) {
    while (node && node->right != NULL)
        node = node->right;
    return node;
}

void BST::findMin() {
    Node* min = findMin(root);
    if (min)
        cout << "ID Terkecil: " << min->idProduk << endl;
}

void BST::findMax() {
    Node* max = findMax(root);
    if (max)
        cout << "ID Terbesar: " << max->idProduk << endl;
}

Node* BST::deleteNode(Node* node, int id) {
    if (node == NULL) return node;

    if (id < node->idProduk)
        node->left = deleteNode(node->left, id);
    else if (id > node->idProduk)
        node->right = deleteNode(node->right, id);
    else {
        if (node->left == NULL) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == NULL) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = findMin(node->right);
        node->idProduk = temp->idProduk;
        node->namaProduk = temp->namaProduk;
        node->stok = temp->stok;
        node->right = deleteNode(node->right, temp->idProduk);
    }
    return node;
}

void BST::deleteNode(int id) {
    root = deleteNode(root, id);
}

void BST::inOrder(Node* node) {
    if (node == NULL) return;
    inOrder(node->left);
    cout << node->idProduk << " ";
    inOrder(node->right);
}

void BST::preOrder(Node* node) {
    if (node == NULL) return;
    cout << node->idProduk << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void BST::postOrder(Node* node) {
    if (node == NULL) return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->idProduk << " ";
}

void BST::inOrder() {
    inOrder(root);
    cout << endl;
}

void BST::preOrder() {
    preOrder(root);
    cout << endl;
}

void BST::postOrder() {
    postOrder(root);
    cout << endl;
}

void BST::deleteTree(Node* node) {
    if (node == NULL) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void BST::deleteTree() {
    deleteTree(root);
    root = NULL;
}
