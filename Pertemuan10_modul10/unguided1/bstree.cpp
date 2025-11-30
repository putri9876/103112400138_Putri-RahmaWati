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
    } else {
        if(x < root->info){
            insertNode(root->left, x);
        } 
        else if(x > root->info){
            insertNode(root->right, x);
        }
    }
}

void printInorder(address root){
    if(root != Nil){
        printInorder(root->left);
        cout << root->info << "-";
        printInorder(root->right);
    }
}
