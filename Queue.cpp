#include <bits/stdc++.h>
using namespace std;
/// point one ' binary number '
int binaryNumber(int num)
{
    queue<string> queue1;
    queue1.push("1"); //initial value for queue
    while(num--)
    {
        string currNum =queue1.front();//store the front number in a queue in the currNum
        queue1.pop();//remove the front element from the queue
        cout<<currNum << " "; //print the current binary number
        queue1.push(currNum + "0"); //Enqueue the binary number with '0' append
        queue1.push(currNum + "1"); //Enqueue the binary number with '1' append
    }
    return 0;
}

///Sorting queue function

void merge(queue<int> &l, queue<int> &r, queue<int> &resQueue) // l = left , r = right
{
    while (!l.empty() && !r.empty()) //compare the left element and the right element in the queue
    {
        if (l.front() <= r.front())  // if the left element is smaller than the right element
        {
            resQueue.push(l.front()); // push the left in the new queue
            l.pop(); //then pop the element
        } else {
            resQueue.push(r.front());
            r.pop();
        }
    }

    while (!l.empty())  // if the left side of queue !become empty
    {
        resQueue.push(l.front());
        l.pop();
    }

    while (!r.empty())  // if the right side of the queue !become empty
    {
        resQueue.push(r.front());
        r.pop();
    }
}

void mergeSort(queue<int> &queue1)
{
    if (queue1.size() <= 1) // base case
        return;

    queue<int> l, r;

    int middle = queue1.size() / 2;
    for (int i = 0; i < middle; ++i)
    {
        l.push(queue1.front());
        queue1.pop();
    }

    while (!queue1.empty())
    {
        r.push(queue1.front());
        queue1.pop();
    }
    mergeSort(l);
    mergeSort(r);
    merge(l, r, queue1);
}

///print function
void print (queue<int> &queue1)
{
    while (!queue1.empty()) {
        cout << queue1.front() << " ";
        queue1.pop();
    }
}





