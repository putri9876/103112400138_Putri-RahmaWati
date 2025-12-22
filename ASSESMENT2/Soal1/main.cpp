#include "BST.h"

int main() {
    BST tree;

    tree.insertNode(50, "Monitor LED", 10);
    tree.insertNode(30, "Keyboard RGB", 20);
    tree.insertNode(70, "Mouse Gaming", 15);
    tree.insertNode(20, "Kabel HDMI", 50);
    tree.insertNode(40, "Headset 7.1", 12);
    tree.insertNode(60, "Webcam HD", 8);
    tree.insertNode(80, "Speaker BT", 5);

    cout << "InOrder  : "; tree.inOrder();
    cout << "PreOrder : "; tree.preOrder();
    cout << "PostOrder: "; tree.postOrder();

    tree.searchById(40);
    tree.searchById(99);
    tree.searchByProduct("Webcam HD");
    tree.searchByProduct("Printer");

    tree.findMin();
    tree.findMax();

    tree.deleteNode(20);
    cout << "InOrder setelah delete 20: ";
    tree.inOrder();

    tree.deleteNode(30);
    cout << "InOrder setelah delete 30: ";
    tree.inOrder();

    tree.deleteNode(50);
    cout << "InOrder setelah delete 50: ";
    tree.inOrder();

    tree.deleteTree();
    cout << "InOrder setelah deleteTree: ";
    tree.inOrder();

    return 0;
}
