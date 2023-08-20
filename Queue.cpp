#include <bits/stdc++.h>
using namespace std;
/// point one ' binary number '
int binaryNumber(int num)
{
    for (int i = 1; i <= num; ++i)
    {
        int num2 = i; // current number
        int bnr = 0; // binary number representation
        int base = 1;
        while (num2 > 0) // convert from decimal number to binary number
        {
            int rem = num2 % 2; // calculate remainder
            bnr += rem * base; // add reminder to binary
            num2 /= 2;
            base *= 10; // increase base to move to the next position
        }
        cout << bnr << " "; // display the binary number 
    }

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
        } else
        {
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
    while (!queue1.empty())
    {
        cout << queue1.front() << " ";
        queue1.pop();
    }
}





