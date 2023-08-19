using namespace std;
///class for node
template<typename T>
class node
{
public:
    node():leftChild(nullptr),rightChild(nullptr){}
    node<T> *leftChild;
    node<T> *rightChild;
    T data;
};
///class for BST
template<typename T>
class BST1 {
private:
    node<T> *root;
public:
    BST1():root(nullptr){}
    node<T> *getRoot() const;

    void setRoot(node<T> *root);
    T *searchBST( const T& item) const;
    void breadthFirst();
    void insertBST(const T& item);
    void deleteBST(const T& item);
    void inOrder(node<T> *ptr);
    void print();
    node<T>*deleteNode(node<T>* root, const T& item);
    node<T>*findMinNode(node<T>* root);
};
///=================================================
///implementation functions
///=================================================



///setter method
template<typename T>
void BST1<T>::setRoot(node<T> *root)
{
    BST1::root = root;
}

///getter method
template<typename T>
node<T> *BST1<T>::getRoot() const
{
    return root;
}

///Search function
template<typename T>
T* BST1<T>::searchBST(const T& item) const
{
    node<T> *curr = root;
    while (curr != nullptr)  //current node != null
    {
        if (curr->data == item)  // if the data in the current node  = item
        {
            return &(curr->data); // Return the address of the data of the current node
        } else if (curr->data > item)  // if the data in the current node greater than the item value
        {
            curr = curr->leftChild; // then the current node = current.leftChild
        } else //otherWise
        {
            curr = curr->rightChild; // the current node = current. rightChild
        }
    }
    return nullptr; // Item not found, return nullptr
}

/// Function breadth-first traversal
template<typename T>
void BST1<T>::breadthFirst()
{
    if (root == nullptr) //check  tree is empty
        return;

    queue<node<T>*> queue1; //create a queue for store the nodes for traversal
    queue1.push(root); // initial value

    while (!queue1.empty()) // check queue is empty
    {
        node<T> *curr = queue1.front();
        queue1.pop();
        cout << curr->data << " "; // show the value of the current node

        if (curr->leftChild) // if the current node in the leftSubtree
            queue1.push(curr->leftChild); // push  the leftChild of the current node in the queue

        if (curr->rightChild)// if the current node in the rightSubtree
            queue1.push(curr->rightChild);// push  the rightChild of the current node in the queue
    }
}

/// Function to insert an item into the BST
template<typename T>
void BST1<T>::insertBST(const T& item)
{
    node<T>* newNode = new node<T>; //create a new node
    newNode->data = item;
    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    node<T>* curr = root;
    node<T>* prev = nullptr;

    while (curr != nullptr)
    {
        prev = curr;
        if (item < curr->data)
            curr = curr->leftChild;
        else if (item > curr->data)
            curr = curr->rightChild;
        else
        {
            cout << "The insert item is already in the list. Duplicates aren't allowed." << endl;
            delete newNode;
            return;
        }
    }

    if (item < prev->data)
        prev->leftChild = newNode;
    else
        prev->rightChild = newNode;
}

/// delete an item from the BST
template<typename T>
void BST1<T>::deleteBST(const T& item)
{
    root = deleteNode(root, item);
}

/// in-order traversal
template<typename T>
void BST1<T>::inOrder(node<T>* ptr) //left root right
{
    if (ptr == nullptr)
        return;

    inOrder(ptr->leftChild);
    cout << ptr->data << " ";
    inOrder(ptr->rightChild);
}
///print function
template<typename T>
void BST1<T>::print()
{
    inOrder(getRoot());
    cout << endl;
}

///delete node from tree function
template<typename T>
node<T>* BST1<T>::deleteNode(node<T>* root, const T& item)
{
    if (root == nullptr)
    {
        return root; // Base case -> empty tree
    }

    // search  item
    if (item < root->data)   //item less than root
    {
        root->leftChild = deleteNode(root->leftChild, item);
    } else if (item > root->data)  // item greater than the root
    {
        root->rightChild = deleteNode(root->rightChild, item);
    } else
    {
        // Node with only one child or no child
        if (root->leftChild == nullptr)
        {
            node<T>* temp = root->rightChild;
            delete root;
            return temp;
        } else if (root->rightChild == nullptr)
        {
            node<T>* temp = root->leftChild;
            delete root;
            return temp;
        }

        // in the case node with two children
        node<T>* temp = findMinNode(root->rightChild); //get successor

        // copy  successor's content to  node
        root->data = temp->data;

        // Delete the successor
        root->rightChild = deleteNode(root->rightChild, temp->data);
    }

    return root;
}
///Find the minimum Node in the BST  function
template<typename T>
node<T>* BST1<T>::findMinNode(node<T>* root)
{
    if (root == nullptr) {
        return nullptr; // Return nullptr for an empty tree
    }

    while (root->leftChild != nullptr) {
        root = root->leftChild; // Traverse to the leftmost node
    }

    return root;
}

