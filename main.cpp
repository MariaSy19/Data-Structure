#include "Queue.cpp"
#include "BST1.h"
#include "Linked_List.h"
int main() {
    int choice;
    int sz, num, item;
    SLL<int> sll;
    queue<int> queue1;
    BST1<int> bst;
    do {
        cout << "--Menu--\n";
        cout << "1. Linked List.\n";
        cout << "2. Queue.\n";
        cout << "3. BST.\n";
        cout << "4. Exit.\n";
        cout << "Input your choice: ";
        cin >> choice;
    while (choice < 1 || choice > 4)
    {
        cout << "Invalid Input!\n";
        cout << "1.Linked List.\n";
        cout << "2.Queue.\n";
        cout << "3.BST.\n";
        cout << "4.Exit.\n";
        cout << "Input what you want: \n";
        cin >> choice;
    }
    switch (choice)
    {
        case 1:
        {
            SLL<int> sll;
            cout << "=============================\n";
            cout << "How many elements do you want to added..\n";
            cin >> sz;
            for (int i = 0; i < sz; ++i)
            {
                cout << "input the element: \n";
                cin >> num;
                //Insert the elements into BST
                sll.addToHead(num);
            }
            cout << "--Menu SLL--\n";
            cout << "1.Add To Head.\n";
            cout << "=============================\n";
            cout << "Input what you want: \n";
            cin >> choice;
            switch (choice)
            {
                case 1:
                {
                    cout << "--SLL before add Item--\n";
                    sll.print();
                    cout << "=============================\n";
                    cout << "Input the item: \n";
                    cin >> item;
                    sll.addToHead(item);
                    cout << "=============================\n";
                    cout << "--After add to head--\n";
                    sll.print();
                    cout << "=============================\n";
                    break;
                }
                case 2:
                {
                    exit(0);
                }
                default:
                {
                    cout << "Invalid Input!\n";
                    break;
                }
            }
        }
        case 2:
        {
            cout << "--Menu Queue--\n";
            cout << "1. Binary number function.\n";
            cout << "2. Sorting queue function.\n";
            cout << "=============================\n";
            cout << "Input what you want: \n";
            cin >> choice;
            queue<int> queue1; // Create an instance of the Queue class

                if (choice == 1) {
                    int num;
                    cout << "Input the number: \n";
                    cin >> num;
                    binaryNumber(num);
                    cout << endl;
                    cout << "=============================\n";
                } else if (choice == 2)
                {
                    int num, n;
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
                }

            break;
        }
        case 3:
        {
            BST1<int> bst;

            cout << "=============================\n";
            cout << "How many elements do you want to added..\n";
            cin >> sz;
            for (int i = 0; i < sz; ++i) {
                cout << "input the element: \n";
                cin >> num;
                //Insert the elements into BST
                bst.insertBST(num);
            }
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
                while (choice < 1 || choice > 7) {
                    cout << "Invalid Input!.\n";
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
                }
                switch (choice) {
                    case 1: {  //Test In-order traversal
                        cout << "In-order traversal of the BST: ";
                        bst.inOrder(bst.getRoot());
                        cout << endl;
                        cout << "=============================\n";
                        break;
                    }
                    case 2: {
                        // Test searching in the BST
                        cout << "Enter the element want to search it: \n";
                        cin >> item;
                        int *finalSearch = bst.searchBST(item);
                        if (finalSearch) {
                            cout << "Found in the BST: " << bst.searchBST(item)<< endl;
                        } else {
                            cout << item << " not found in the BST." << endl;
                        }
                        cout << "=============================\n";
                        break;
                    }
                    case 3: {
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
                    case 4: {
                        // Test breadth-first traversal
                        cout << "Breadth-first traversal of the BST: ";
                        bst.breadthFirst();
                        cout << endl;
                        cout << "=============================\n";
                        break;
                    }
                    case 5: {
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
                    case 6: {
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
                    case 7: {
                        exit(0);
                    }
                    default: {
                        cout << "Invalid Input!\n";
                        break;
                    }
                }

        }
        case 4:
        {
            exit(0);
        }
        default:
            cout << "Invalid choice." << endl;
            break;
    }

    } while (choice != 4);
            return 0;
}

