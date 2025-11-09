#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, Infotype x) {
    if (S.top < MAX - 1) {
        S.top++;
        S.info[S.top] = x;
    } else {
        cout << "Stack penuh!" << endl;
    }
}

void pop(Stack &S, Infotype &x) {
    if (S.top >= 0) {
        x = S.info[S.top];
        S.top--;
    } else {
        cout << "Stack kosong!" << endl;
    }
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    Infotype x;

    while (S.top >= 0) {
        pop(S, x);
        push(temp, x);
    }

    S = temp;
}

void pushAscending(Stack &S, Infotype x) {
    Stack temp;
    createStack(temp);
    Infotype y;

    while (S.top >= 0 && S.info[S.top] < x) {
        pop(S, y);
        push(temp, y);
    }

    push(S, x);

    while (temp.top >= 0) {
        pop(temp, y);
        push(S, y);
    }
}
