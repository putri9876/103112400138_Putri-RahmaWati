#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 9);
    push(S, 2);
    push(S, 4);
    push(S, 3);

    printInfo(S);     

    balikStack(S);
    printInfo(S);     

    return 0;
}
