// Begüm Filiz Öz, 22203470, Sec 3

#ifndef ASSGN4_STACK_H
#define ASSGN4_STACK_H
#include "Cage.h"
#include "Node.h"


class Stack {
private:
    Node<Cage>* topPtr;
public:
    Stack();
    Stack(const Stack& aStack);
    ~Stack();
    bool isEmpty() const;
    bool push(const Cage& cage);
    bool pop();
    Cage peek() const;
    //bool doesExist(string name);
};


#endif //ASSGN4_STACK_H
