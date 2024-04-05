// Begüm Filiz Öz, 22203470, Sec 3

#include <cassert>
#include "Stack.h"
Stack::Stack() : topPtr(nullptr) {

}

Stack::Stack(const Stack& aStack) {
    Node<Cage>* origChainPtr = aStack.topPtr;
    if (origChainPtr == nullptr) {
        topPtr = nullptr;
    } else {
        topPtr = new Node<Cage>();
        topPtr->setItem(origChainPtr->getItem());
        Node<Cage> *newChainPtr = topPtr;
        origChainPtr = origChainPtr->getNext();
        while (origChainPtr != nullptr) {
            Cage nextItem = origChainPtr->getItem();
            Node<Cage> *newNodePtr = new Node<Cage>(nextItem);
            newChainPtr->setNext(newNodePtr);
            newChainPtr = newChainPtr->getNext();
            origChainPtr = origChainPtr->getNext();
        }
        newChainPtr->setNext(nullptr);
    }
}
Stack::~Stack()
{
    while(!isEmpty())
        pop();
}
bool Stack::push(const Cage& newCage)
{
    Node<Cage>* newNodePtr = new Node<Cage>(newCage, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;
    return true;
}
bool Stack::pop()
{
    bool result = false;
    if (!isEmpty())
    {
        Node<Cage>* nodeToDeletePtr = topPtr;
        topPtr = topPtr->getNext();
        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        result = true;
    }
    return result;
}
Cage Stack::peek() const {
    assert(!isEmpty());
    return topPtr->getItem();
}
bool Stack::isEmpty() const {
    return topPtr == nullptr;
}
