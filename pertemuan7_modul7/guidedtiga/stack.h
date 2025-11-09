#ifndef STACK_H
#define STACK_H

const int MAX = 20;

typedef int Infotype;

struct Stack {
    Infotype info[MAX];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, Infotype x);
void pop(Stack &S, Infotype &x);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, Infotype x);
void getInputStream(Stack &S);

#endif
