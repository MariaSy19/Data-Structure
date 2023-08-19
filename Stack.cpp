#include <iostream>
using namespace std;
template <typename T>
///class Stack
class Stack{
    struct node
    {
        T item;
        node* next;
    };
    node *top;
public:
    Stack(){top = nullptr;}
    bool Empty();
    void Push(T item);
    void Pop();
    T getTop();
    void reverse(Stack<T> &st);
    void delMid(Stack<T>& stk);
    void pushBack(const T& value); //use in function reverse
    void print();
    int size() const; // use in function delete middle element
};

/// Push Function
template<typename T>
void Stack<T>::Push(T item)
{
    node *newNode = new node; // create a new node
    if (newNode == nullptr) //check allocate memory
    {
        cout << "Stack can't allocate memory.\n";
        return;
    }

    newNode->item = item; // store  item  = the item of the newNode
    newNode->next = top;
    top = newNode;
}

/// Pop Function
template<typename T>
void Stack<T>::Pop()
{
    if (Empty()) //check if the stack is empty or not
    {
        cout << "Stack is Empty..!\n";
        return;
    } else
    {
        node *curr; // create a new node
        curr = top; // store the top element
        top = top->next; // move the top to the next element in the stack
        curr = curr->next = nullptr; // put the value of the next element of the curr = null
        delete curr; // delete the current node
    }
}

///Empty FUnction
template<typename T>
bool Stack<T>::Empty()
{
    return (top == nullptr);
}

/// Print Function
template<typename T>
void Stack<T>::print()
{
    node *curr = top;
    cout << "[";
    while (curr != nullptr)
    {
        cout << curr->item << " "; // display the current element
        curr = curr->next; // move to the next element
    }
    cout << "]";
    cout << endl;
}

/// getTop function
template <typename T>
T Stack<T>::getTop()
{
    if (Empty()) // check if the stack is empty
    {
        cout << "Stack is Empty..!\n";
        return T();
    } else
    {
        return top->item; // display the top element
    }
}

/// reverse function
template <typename T>
void Stack<T>::reverse(Stack<T>& stk)
{
    if (stk.Empty()) // Check if the stack is empty or not
    {
        return;
    }
    T ele = stk.getTop(); // Get the top element of the stack
    stk.Pop();         // Pop the top element, move to the next element
    reverse(stk);      // Recursive function
    stk.pushBack(ele); // Push the top element to the bottom of the stack
}
/// PushBack function
template <typename T>
void Stack<T>::pushBack(const T& val)
{
    if (Empty()) // If the stack is empty
    {
        Push(val); // push  val
    }
    else
    {
        T temp = getTop(); // Get the top element
        Pop();          // Pop the top element
        pushBack(val); // recursion
        Push(temp);     // Push the original top element back
    }
}

/// Function Size
template <typename T>
int Stack<T>::size() const
{
    int count = 0;
    node* curr = top;
    while (curr != nullptr)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

/// Function Delete middle element
template<typename T>
void Stack<T>::delMid(Stack<T>& stk)
{
    if (stk.Empty()) // if the stack is empty
    {
        return;
    }

    Stack<T> tempStack;// Temporary stack for storage

    int midInx = (stk.size()) / 2;

    // Pop and push elements from the original stack to tempStack
    // until the middle index is reached
    while (midInx > 0)
    {
        tempStack.Push(stk.getTop());
        stk.Pop();
        midInx--;
    }

    // Skip the middle element by popping it
    stk.Pop();

    // Copy elements from tempStack back to stk
    while (!tempStack.Empty())
    {
        stk.Push(tempStack.getTop());
        tempStack.Pop();
    }
}
