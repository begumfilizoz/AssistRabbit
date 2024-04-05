//Begüm Filiz Öz, 22203470, Sec 3

#ifndef NODE_H
#define NODE_H

template<class ItemType>
class Node {
public:
    Node();
    Node(const ItemType& anItem);
    Node(const ItemType& anItem, Node<ItemType>* nextNodePtr);
    void setItem(const ItemType& anItem);
    void setNext(Node<ItemType>* nextNodePtr);
    ItemType& getItem();
    Node<ItemType>* getNext() const;
private:
    ItemType item;
    Node<ItemType>* next;
};
#endif /* Node_h */
