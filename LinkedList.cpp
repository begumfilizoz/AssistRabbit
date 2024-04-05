// Begüm Filiz Öz, 22203470, Sec 3

#include <string>
#include <iostream>
#include "LinkedList.h"
#include "Cage.h"
#include "LabelledInt.h"
#include "LabelledString.h"

using namespace std;

template<class ItemType>
int LinkedList<ItemType>::getItemCount() {
    return itemCount;
}
template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const {
    if (itemCount == 0)
    {
        return true;
    }
    return false;
}
template<class ItemType>
string LinkedList<ItemType>::getName() {
    return name;
}
template<class ItemType>
void LinkedList<ItemType>::setName(string newName) {
    name = newName;
}
template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAtConst(int position) const
{
    Node<ItemType>* curPtr = headptr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();
    return curPtr;
}


template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position)  {
    Node<ItemType>* curPtr = headptr;
    for (int skip = 1; skip < position; skip++)
        curPtr = curPtr->getNext();
    return curPtr;
}
template<class ItemType>
LinkedList<ItemType>::LinkedList() : headptr(nullptr), itemCount(0) {}
template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position){
    Node<ItemType>* nodePtr = getNodeAt(position);
    return nodePtr->getItem();
}
template<class ItemType>
void LinkedList<ItemType>::clear()
{
    while (!isEmpty())
        remove(1);
}
template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
    clear();
}
template<class ItemType>
int LinkedList<ItemType>::getPosition(string name, bool exist) {// first get position of the item with this id, then execute other methods
    if (itemCount == 0){ return 1; }
    for (int i = 1; i <= itemCount; i++)
    {
        if (exist)
        {
            if (name == this->getNodeAt(i)->getItem().getName())
            {
                return i;
            }
        }
        else
        {
            if (i < itemCount)
            {
                if (name > this->getNodeAt(i)->getItem().getName() && name < this->getNodeAt(i+1)->getItem().getName())
                {
                    return i + 1;
                }
                else if (name < this->getNodeAt(i)->getItem().getName() && name < this->getNodeAt(i+1)->getItem().getName())
                {
                    return i;
                }
            }
            else
            {
                if (name > this->getNodeAt(i)->getItem().getName())
                {
                    return i + 1;
                }
                else
                {
                    return i;
                }
            }

        }
    }
    return -1;
}
template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
    if (ableToInsert)
    {
        Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
        if (newPosition == 1)
        {
            newNodePtr->setNext(headptr);
            headptr = newNodePtr;
        }
        else
        {
            Node<ItemType>* prevptr = getNodeAt(newPosition - 1);
            newNodePtr->setNext(prevptr->getNext());
            prevptr->setNext(newNodePtr);
        }
        itemCount++;
    }
    return ableToInsert;
}
template<class ItemType>
bool LinkedList<ItemType>::remove(int position) {
    bool ableToRemove = (position >= 1) && (position <= itemCount);
    if (ableToRemove)
    {
        Node<ItemType>* curptr = nullptr;
        if (position == 1)
        {
            curptr = headptr;
            headptr = headptr->getNext();
        }
        else
        {
            Node<ItemType>* prevptr = getNodeAt(position - 1);
            curptr = prevptr->getNext();
            prevptr->setNext(curptr->getNext());
        }
        curptr->setNext(nullptr);
        delete curptr;
        curptr = nullptr;
        itemCount--;
    }
    return ableToRemove;
}
template<class ItemType>
bool LinkedList<ItemType>::nameExists(string name) {
    for (int i = 1; i <= itemCount; i++)
    {
        if (name == this->getNodeAt(i)->getItem().getName())
        {
            return true;
        }
        else
        {
            if (i == itemCount )
                return false;
        }
    }
    return false;
}
template<class ItemType>
int LinkedList<ItemType>::getLength()
{
    return itemCount;
}
template<class ItemType>
int LinkedList<ItemType>::getLengthConst() const
{
    return itemCount;
}
template<class ItemType>
bool LinkedList<ItemType>::nameExistsConst(string name) const{
    for (int i = 1; i <= itemCount; i++)
    {
        if (name == this->getNodeAtConst(i)->getItem().getName())
        {
            return true;
        }
        else
        {
            if (i == itemCount )
                return false;
        }
    }
    return false;
}
template<class ItemType>
int LinkedList<ItemType>::getPositionConst(string name, bool exist) const{// first get position of the item with this id, then execute other methods
    if (itemCount == 0){ return 1; }
    for (int i = 1; i <= itemCount; i++)
    {
        if (exist)
        {
            if (name == this->getNodeAtConst(i)->getItem().getName())
            {
                return i;
            }
        }
        else
        {
            if (i < itemCount)
            {
                if (name > this->getNodeAtConst(i)->getItem().getName() && name < this->getNodeAtConst(i+1)->getItem().getName())
                {
                    return i + 1;
                }
                else if (name > this->getNodeAtConst(i)->getItem().getName() && name > this->getNodeAtConst(i+1)->getItem().getName())
                {
                    return i;
                }
            }
            else
            {
                if (name > this->getNodeAtConst(i)->getItem().getName())
                {
                    return i + 1;
                }
                else
                {
                    return i;
                }
            }

        }
    }
    return -1;
}
template<class ItemType>
bool LinkedList<ItemType>::isPosEmpty(int pos)
{
    if (getNodeAt(pos) == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

template class LinkedList<Cage>;
template class LinkedList<LinkedList <Cage>>;
template class LinkedList<LabelledInt>;
template class LinkedList<LabelledString>;


