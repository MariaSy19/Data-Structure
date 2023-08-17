#include <iostream>
using namespace std;
template <class T>

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
    T Top();
    void reverse(Stack<T> &st);
    void delMid(stack<T>& stk);
    void pushBottom(const T& value); //use in function reverse
    void print();
};

template<class T>
void Stack<T>::Push(T item)
{
    node *newNode = new node; // create a new node
    if (newNode == nullptr) //check allocate memory
    {
        cout << "Stack can't allocate memory.\n";
        return;
    }

    newNode->item = item; // store the item entered = the item of the newNode
    newNode->next = top;
    top = newNode;
}

template<class T>
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

template<class T>
bool Stack<T>::Empty()
{
    return (top == nullptr);
}

template<class T>
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

template <class T>
T Stack<T>::Top()
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

template <class T>
void Stack<T>::reverse(Stack<T>& stk)
{
    if (stk.Empty()) // Check if the stack is empty or not
    {
        return;
    }
    T ele = stk.Top(); // Get the top element of the stack
    stk.Pop();         // Pop the top element, move to the next element
    reverse(stk);      // Recursive function
    stk.pushBottom(ele); // Push the top element to the bottom of the stack
}
template <class T>
void Stack<T>::pushBottom(const T& val)
{
    if (Empty()) // If the stack is empty
    {
        Push(val); // push  val
    }
    else
    {
        T temp = Top(); // Get the top element
        Pop();          // Pop the top element
        pushBottom(val); // recursion
        Push(temp);     // Push the original top element back
    }
}
/// Function to delete the middle element of a stack
template<typename T>
void Stack<T>::delMid(stack<T>& stk)
{
    if (stk.empty()) {
        return;
    }

    int stackSize = stk.size(); // Use size() instead of manually counting elements
    stack<T> tempStack;         // Temporary stack for storage

    int midInx = stackSize / 2;

    // Pop and push elements from the original stack to tempStack
    // until the middle index is reached
    while (midInx > 0)
    {
        tempStack.push(stk.top());
        stk.pop();
        midInx--;
    }

    // Skip the middle element by popping it
    stk.pop();

    // Copy elements from tempStack back to stk
    while (!tempStack.empty())
    {
        stk.push(tempStack.top());
        tempStack.pop();
    }
}

