#include "Queue.cpp"
#include "Linked_List.cpp"
#include "Stack.cpp"
#include "BST1.cpp"
int main() {
    int choice;
    int sz, num, item;
    SLL<int> sll;
    queue<int> queue1;
    BST1<int> bst;
    Stack<int> stack1;

        cout << "--Menu--\n";
        cout << "1. Linked List.\n";
        cout << "2. Stack.\n";
        cout << "3. Queue.\n";
        cout << "4. BST.\n";
        cout << "===============================\n";
        cout << "Input your choice: ";
        cin >> choice;
    while (choice < 0 || choice > 4 )
    {
        cout << "===============================\n";
        cout << "Invalid input.\n";
        cout << "===============================\n";
        cout << "--Menu--\n";
        cout << "1. Linked List.\n";
        cout << "2. Stack.\n";
        cout << "3. Queue.\n";
        cout << "4. BST.\n";
        cout << "===============================\n";
        cout << "Input your choice: ";
        cin >> choice;
    }
        switch (choice) {
            case 1: {
                cout << "===============================\n";
                cout << "How many elements do you want to add: ";
                cin >> sz;

                for (int i = 0; i < sz; ++i) {
                    cout << "Input element " << i + 1 << ": ";
                    cin >> num;
                    sll.addToTail(num);
                }
                cout << "===============================\n";
                do {
                    cout << "--Menu SLL--\n";
                    cout << "1. Add To Head.\n";
                    cout << "2. Add To Tail.\n";
                    cout << "3. Remove From Head.\n";
                    cout << "4. Remove From Tail.\n";
                    cout << "5. Get Value At Head.\n";
                    cout << "6. Is Empty.\n";
                    cout << "7. Clear.\n";
                    cout << "8. Display Linked List by using operator << .\n";
                    cout << "9. Pairwise Swap.\n";
                    cout << "10. Remove Duplicates.\n";
                    cout << "11. Exit.\n";
                    cout << "===============================\n";
                    cout << "Input your choice: ";
                    cin >> choice;
                    switch (choice) {
                        case 1: {
                            //Test function addAtHead
                            cout << "===============================\n";
                            cout << "--SLL before adding an item--\n";
                            sll.print();
                            cout << "===============================\n";
                            cout << "Input the item: ";
                            cin >> item;
                            sll.addToHead(item);
                            cout << "===============================\n";
                            cout << "--After adding to the head--\n";
                            sll.print();
                            cout << "===============================\n";
                            break;
                        }
                        case 2: {
                            //Test function addToTail
                            cout << "===============================\n";
                            cout << "--SLL before adding an item--\n";
                            sll.print();
                            cout << "===============================\n";
                            cout << "Input the item: ";
                            cin >> item;
                            sll.addToTail(item);
                            cout << "===============================\n";
                            cout << "--After adding to Tail--\n";
                            sll.print();
                            cout << "===============================\n";
                            break;
                        }
                        case 3: {
                            //Test function RemoveFromHead
                            cout << "===============================\n";
                            cout << "--SLL before remove an item--\n";
                            sll.print();
                            cout << "===============================\n";
                            sll.removeFromHead();
                            cout << "--After Remove From Head--\n";
                            sll.print();
                            cout << "===============================\n";
                            break;
                        }
                        case 4: {
                            //Test function RemoveFromTail
                            cout << "===============================\n";
                            cout << "--SLL before remove an item--\n";
                            sll.print();
                            cout << "===============================\n";
                            sll.removeFromTail();
                            cout << "--After Remove From Tail--\n";
                            sll.print();
                            cout << "===============================\n";
                            break;
                        }
                        case 5: {
                            //Test function GetValueAtHead
                            cout << "===============================\n";
                            cout << "--Get value At Head--\n";
                            int value = sll.getValueAtHead();
                            cout << "Value at head: " << value << endl;
                            cout << "===============================\n";
                            cout << "For check--SLL Elements--\n";
                            sll.print();
                            cout << "===============================\n";
                            break;
                        }
                        case 6: {
                            // Test function is Empty
                            cout << "===============================\n";
                            cout << "Check if the SLL isEmpty.\n";
                            bool check = sll.isEmpty();
                            cout << "The result of the check(1/0): " << check << endl;
                            cout << "===============================\n";
                            break;
                        }
                        case 7: {
                            // Test function clear
                            cout << "===============================\n";
                            cout << "--Sll before clear--\n";
                            sll.print();
                            cout << "===============================\n";
                            sll.clear();
                            cout << "--sll After clear--\n";
                            sll.print();
                            cout << "===============================\n";
                            break;
                        }
                        case 8: {
                            // Test operator <<
                            cout << "===============================\n";
                            cout << "SLL: " << sll << endl;
                            cout << "===============================\n";
                            break;
                        }
                        case 9: {
                            //test function pairWise
                            cout << "===============================\n";
                            cout << "--After use pairwise swap function--\n";
                            sll.pairWise();
                            sll.print();
                            cout << "===============================\n";
                            break;
                        }
                        case 10: {
                            // Test function delete duplicate
                            cout << "===============================\n";
                            cout << "--SLL After delete duplicate-- \n";
                            sll.removeDuplicate();
                            sll.print();
                            cout << "===============================\n";
                            break;
                        }
                        case 11: {
                            exit(0);
                        }
                        default: {
                            cout << "Invalid Input!\n";
                            break;
                        }
                    }
                } while (choice != 11);
                break;
            }
                //--------- Stack --------
            case 2: {
                cout << "===============================\n";
                cout << "How many elements do you want to add: ";
                cin >> sz;

                for (int i = 0; i < sz; ++i) {
                    cout << "Input element" << i + 1 << ":";
                    cin >> num;
                    stack1.Push(num);
                }
                do {
                    cout << "===============================\n";
                    cout << "--Menu Stack--\n";
                    cout << "1.Push.\n";
                    cout << "2.pop.\n";
                    cout << "3.top.\n";
                    cout << "4.empty.\n";
                    cout << "5.reverse.\n";
                    cout << "6.Delete middle.\n";
                    cout << "7.Exit.\n";
                    cout << "===============================\n";
                    cout << "Input what you want: \n";
                    cin >> choice;
                    switch (choice) {
                        case 1: {
                            // Test function Push()
                            cout << "===============================\n";
                            cout << "--Stack elements before push item--\n";
                            stack1.print();
                            cout << "===============================\n";
                            cout << "Input the item you want to push it: \n";
                            cin >> item;
                            stack1.Push(item);
                            cout << "===============================\n";
                            cout << "--Stack elements after push a new item: \n";
                            stack1.print();
                            cout << "===============================\n";
                            break;

                        }
                        case 2: {
                            // Test function pop()
                            cout << "===============================\n";
                            cout << "--Stack before pop the element--\n";
                            stack1.print();
                            cout << "===============================\n";
                            cout << "--Stack After pop--\n";
                            stack1.Pop();
                            stack1.print();
                            cout << "===============================\n";
                            break;
                        }
                        case 3: {
                            // Test function getTop()
                            cout << "===============================\n";
                            cout << "--Stack top is-- " << stack1.Top() << endl;

                            cout << "===============================\n";
                            cout << "For check, Stack elements: ";
                            stack1.print();
                            cout << "===============================\n";
                            break;
                        }
                        case 4: {
                            // Test function Empty()
                            cout << "===============================\n";
                            cout << "--Check if the Stack is Empty-- \n";
                            bool resCheck = stack1.Empty();
                            cout << "The result of the check(1/0): " << resCheck << endl;
                            cout << "===============================\n";
                            break;
                        }
                        case 5: {
                            // Test function reverse
                            cout << "===============================\n";
                            cout << "--Original Stack--\n";
                            stack1.print();
                            cout << "===============================\n";

                            Stack<int> revStack = stack1; // Create a copy of the original stack
                            revStack.reverse(revStack);   // Reversing the copy

                            cout << "--Stack after reverse--\n";
                            revStack.print(); // Print the reversed stack
                            cout << "===============================\n";
                            break;

                        }
                        case 6: {
                            //Test case delete middle
                            cout << "===============================\n";
                            cout << "--Original Stack--\n";
                            stack1.print();
                            cout << "===============================\n";
                            stack<int> stdStack;
                            while (!stack1.Empty()) {
                                stdStack.push(stack1.Top());
                                stack1.Pop();
                            }
                            stack1.delMid(stdStack);
                            while (!stdStack.empty()) {
                                stack1.Push(stdStack.top());
                                stdStack.pop();
                            }
                            cout << "--Stack after deleting middle--\n";
                            stack1.print();
                            cout << "===============================\n";
                            break;
                        }
                        case 7: {
                            exit(0);
                        }
                        default: {
                            cout << "Invalid input.\n";
                            break;
                        }

                    }
                } while (choice != 7);
                break;
            }
                //--- Queue----
            case 3: {
                do {
                    cout << "--Menu Queue--\n";
                    cout << "1. Binary number function.\n";
                    cout << "2. Sorting queue function.\n";
                    cout << "3. Exit.\n";
                    cout << "=============================\n";
                    cout << "Input what you want: \n";
                    cin >> choice;
                    switch (choice) {
                        case 1: {
                            // Test Function Binary number function
                            cout << "=============================\n";
                            cout << "Input the number: \n";
                            cin >> num;
                            binaryNumber(num);
                            cout << endl;
                            cout << "=============================\n";
                            break;
                        }
                        case 2: {
                            // Test function Sorting queue
                            int n;
                            cout << "=============================\n";
                            cout << "What is the size of queue you want: \n";
                            cin >> num;

                            for (int i = 0; i < num; ++i) {
                                cout << "Input the number: \n";
                                cin >> n;
                                queue1.push(n);
                            }
                            mergeSort(queue1);
                            cout << "After Sorting Queue by using (merge Sort): \n";
                            print(queue1);
                            cout << endl;
                            cout << "=============================\n";
                            break;
                        }
                        case 3: {
                            exit(0);
                        }
                        default: {
                            cout << "Invalid Input. \n";
                            break;
                        }
                    }
                } while (choice != 3);
            }
                //---BST---
            case 4: {
                cout << "=============================\n";
                cout << "How many elements do you want to add: \n";
                cin >> sz;
                for (int i = 0; i < sz; ++i) {
                    cout << "input the element: \n";
                    cin >> num;
                    //Insert the elements into BST
                    bst.insertBST(num);
                }
                do {
                    cout << "=============================\n";
                    cout << "The elements in the tree: \n";
                    bst.print();
                    cout << "=============================\n";
                    cout << "--Menu BST--\n";
                    cout << "1.In-order traversal.\n";
                    cout << "2.Searching in the BST.\n";
                    cout << "3.Delete element from the BST.\n";
                    cout << "4.breadth- first traversal. \n";
                    cout << "5.Find minimum Node. \n";
                    cout << "6.Insert a new item. \n";
                    cout << "7.Exit. \n";
                    cout << "=============================\n";
                    cout << "Input choice: \n";
                    cin >> choice;
                    cout << "=============================\n";
                    switch (choice)
                    {
                        case 1:
                        {
                            //Test In-order traversal
                            cout << "In-order traversal of the BST: ";
                            bst.inOrder(bst.getRoot());
                            cout << endl;
                            cout << "=============================\n";
                            break;
                        }
                        case 2:
                        {
                            // Test searching in the BST
                            cout << "Enter the element you want to search for: \n";
                            cin >> item;
                            int *finalSearch = bst.searchBST(item);
                            if (finalSearch) {
                                cout << "Found in the BST: " << *finalSearch << endl;
                            } else {
                                cout << item << " not found in the BST." << endl;
                            }
                            cout << "=============================\n";
                            break;
                        }
                        case 3:
                        {
                            // Test deleting from the BST
                            cout << "Input the item you want to delete it: \n";
                            cin >> item;
                            cout << "=============================\n";
                            cout << "The BST before delete item: \n";
                            bst.print();
                            cout << "=============================\n";
                            if (!bst.searchBST(item)) {
                                cout << "The item " << item << " is not in the BST." << endl;

                            } else {
                                bst.deleteBST(item);
                                cout << "After deleting the item " << item << endl;
                                cout << "BST items: ";
                                bst.inOrder(bst.getRoot());
                                cout << endl;
                            }
                            cout << "=============================\n";
                            break;
                        }
                        case 4:
                        {
                            // Test breadth-first traversal
                            cout << "Breadth-first traversal of the BST: ";
                            bst.breadthFirst();
                            cout << endl;
                            cout << "=============================\n";
                            break;
                        }
                        case 5:
                        {
                            //Find the minimum node
                            node<int> *minNode = bst.findMinNode(bst.getRoot());

                            if (minNode) {
                                cout << "Minimum value in the BST: " << minNode->data << endl;
                            } else {
                                cout << "The BST is empty." << endl;
                            }
                            cout << "=============================\n";
                            break;
                        }
                        case 6:
                        {
                            cout << "--BST before insert a new item-- \n";
                            bst.print();
                            cout << "=============================\n";
                            cout << "Input item: \n";
                            cin >> item;
                            bst.insertBST(item);
                            cout << "=============================\n";
                            cout << "--BST After insert a new item--\n";
                            bst.print();
                            cout << "=============================\n";
                            break;
                        }
                        case 7:
                        {
                            exit(0);
                        }
                        default:
                        {
                            cout << "Invalid Input!\n";
                            break;
                        }
                    }
                } while (choice != 7);
            }
        }

    return 0;
}