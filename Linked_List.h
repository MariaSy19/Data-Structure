#ifndef UNTITLED49_LINKED_LIST_H
#define UNTITLED49_LINKED_LIST_H
#include <iostream>
using namespace std;
template<typename T>
class nodeSLL
{
private:
    T info;
    nodeSLL<T> *next;
public:
    nodeSLL(T data, nodeSLL* n = nullptr) : info(data), next(n) {}
    nodeSLL *getNext() { return next; }
    void setNext(nodeSLL* n) { next = n; }
    T& getInfo() { return info; }
    void setInfo(T val) { info = val; }
};

template<typename T>
class SLL{
private:
    nodeSLL<T> *head, *tail;
public:
    SLL():head(nullptr),tail(nullptr){}
    void addToHead( T item);
    void print();
};

template<typename T>
void SLL<T>::addToHead(T item)
{
    nodeSLL<T>* newNode = new nodeSLL(item, head);
    newNode->setInfo(item); // Update the info value of the new node

    // If the linked list is empty
    if (!head)
    {
        head = tail = newNode;
    }
    else
    {
        head = newNode; // Update the first pointer to the new node
    }
}

template<typename T>
void SLL<T>::print()
{
    nodeSLL<T> *cur = head;
    while (cur != nullptr)
    {
        cout << cur->getInfo() << " ";
        cur = cur->getNext();
    }
    cout << endl;
}


#endif //UNTITLED49_LINKED_LIST_H
