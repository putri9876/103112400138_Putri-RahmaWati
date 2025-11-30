#include <iostream>
#include "bstree.h"
using namespace std;

address alokasi(infotype x){
    address P = new Node;
    if(P != Nil){
        P->info = x;
        P->left = Nil;
        P->right = Nil;
    }
    return P;
}

void insertNode(address &root, infotype x){
    if(root == Nil){
        root = alokasi(x);
    }
    else {
        if(x < root->info)
            insertNode(root->left, x);
        else if(x > root->info)
            insertNode(root->right, x);
        else
            return; 
    }
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << "-";
        printInorder(root->right);
    }
}

int hitungNode(address root){
    if(root == Nil)
        return 0;
    return 1 + hitungNode(root->left) + hitungNode(root->right);
}

int hitungTotal(address root){
    if(root == Nil)
        return 0;
    return root->info + hitungTotal(root->left) + hitungTotal(root->right);
}

int hitungKedalaman(address root, int level){
    if(root == Nil)
        return level;

    int leftDepth  = hitungKedalaman(root->left, level + 1);
    int rightDepth = hitungKedalaman(root->right, level + 1);

    return (leftDepth > rightDepth ? leftDepth : rightDepth);
}
