#include <iostream>
using namespace std;
///class node
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

///class SLL
template<typename T>
class SLL{
private:
    nodeSLL<T> *head, *tail;
public:
    SLL():head(nullptr),tail(nullptr){}
    void addToHead( T item);
    void addToTail(T item);
    void print();
    T removeFromHead();
    T removeFromTail();
    T getValueAtHead();
    bool isEmpty();
    void clear();
    void pairWise();
    void removeDuplicate();
    friend ostream &operator<<(ostream &output, const SLL<T> &sll)
    {
        nodeSLL<T> *curr = sll.head; //creat a pointer refer to head
        while (curr != nullptr)
        {
            output << curr->getInfo() << " "; // store the Info of the nodes in the output
            curr = curr->getNext();//travers to the next node
        }
        return output; // display the data of the nodes
    }
};

/// Function AddToHead
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

/// Function Print
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

/// Function AddToTail
template<typename T>
void SLL<T>::addToTail(T item)
{
    nodeSLL<T>* newNode = new nodeSLL(item, tail);
    newNode->setInfo(item);
    newNode->setNext(nullptr);
    if (!head)
    {
        head = newNode; // Update the first pointer if the list is empty
    } else
    {
        tail->setNext(newNode);
    }

    tail = newNode;
}

/// Function RemoveFromHead
template<typename T>
T SLL<T>::removeFromHead()
{
    if (!head)//in this case the linked list is empty don't have any node
    {
        cout << "SLL is empty. \n";
        return T();
    } else if (!head->getNext()) //in this case the linked list has only one node
    {
        T val = head->getInfo();
        delete head;
        head = tail = nullptr;
        return val;
    } else //in this case the linked list have a many nodes
    {
        nodeSLL<T> *curr = head; //create a new node and make it equal the first node
        head = head->getNext(); //for make first node refer to the node after
        T val = curr->getInfo();
        delete curr;
        return val;
    }

}

template<typename T>
T SLL<T>::removeFromTail()
{
    if (!head) // If the linked list is empty, don't have any nodes
    {
        cout << "SLL is empty. \n";
        return T();
    }
    else if (!head->getNext()) // If the linked list has only one node
    {
        T val = head->getInfo();
        delete head;
        head = tail = nullptr;
        return val;
    }
    else
    {
        nodeSLL<T> *curr = head->getNext();
        nodeSLL<T> *prev = head;

        while (curr->getNext() != nullptr) // Traverse to the second-to-last node
        {
            prev = curr;
            curr = curr->getNext();
        }

        T val = curr->getInfo();
        delete curr;
        prev->setNext(nullptr); // Make the second-to-last node the new tail
        tail = prev; // Update the tail pointer

        return val;
    }
}

template<typename T>
T SLL<T>::getValueAtHead()
{
    if (head) // If the linked list is not empty
    {
        return (head->getInfo()); // Return the head node
    }
    else
    {
        return T();
    }
}

template<typename T>
bool SLL<T>::isEmpty()
{
    return (head == nullptr);
}

template<typename T>
void SLL<T>::clear()
{
    while (head) // still removing node even the head = nullptr
    {
        nodeSLL<T>* temp = head;
        head = head->getNext();
        delete temp;
    }
    tail = nullptr; // after delete all nodes put the tail of SLL = null
}

/// pairWise swap nodes
template<typename T>
void SLL<T>::pairWise()
{
    nodeSLL<T> *curr = head;
    while (curr != nullptr && curr->getNext() != nullptr) //loop even reach the end of the SLL or if the next of the current node to reach to the null
    {
        swap(curr->getInfo(),curr->getNext()->getInfo()); // swap between the current node and the next of the current node
        curr = curr->getNext()->getNext(); //move to the second next of the current node
    }
}

template<typename T>
void SLL<T>::removeDuplicate()
{
    nodeSLL<T> *curr = head;
    while (curr != nullptr && curr->getNext() != nullptr) //loop even reach the end of the SLL or if the next of the current node to reach to the null
    {
        nodeSLL<T> *newNode = curr;
        while (newNode->getNext() != nullptr) {
            if (curr->getInfo() == newNode->getNext()->getInfo()) // check if we have a duplicate element
            {
                nodeSLL<T>* dupNode = newNode->getNext(); //copy the item
                newNode->setNext(dupNode->getNext());
                delete dupNode; // delete the duplicate node
            } else
            {
                newNode = newNode->getNext(); //move to the next node
            }
        }
        curr = curr->getNext();
    }
}


