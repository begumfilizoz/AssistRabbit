// Begüm Filiz Öz, 22203470, Sec 3

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <string>
#include <iostream>
#include "Node.h"
using namespace std;

template<class ItemType>
class LinkedList {
private:
    Node<ItemType>* headptr;
    int itemCount;
    string name;

public:
    Node<ItemType>* getNodeAt(int position);
    Node<ItemType>* getNodeAtConst(int position) const;
    LinkedList();
    virtual ~LinkedList();
    bool isEmpty() const;
    int getLength();
    string getName();
    int getLengthConst() const;
    void setName(string newName);
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();
    ItemType getEntry(int position);
    int getPosition(string name, bool exist);
    int getPositionConst(string name, bool exist) const;
    ItemType replace(int position, const ItemType& newEntry);
    bool nameExists(string name);
    bool nameExistsConst(string name) const;
    int getItemCount();
    bool isPosEmpty(int pos);
};

#endif /* LinkedList_h */
