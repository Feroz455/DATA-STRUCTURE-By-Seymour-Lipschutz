/*
page 273
7.34  Consider the complete tree T with N = 10 nodes in Fig. 7.104. 
Suppose a maxheap is formed out of T by applying
for J = 1, 2, …, N – 1. (Assume T is stored sequentially in the array A.) Find the final maxheap.
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Data structure to store a max-heap node
struct PriorityQueue
{
private:
    // vector to store heap elements
    vector<int> A;

    // return parent of `A[i]`
    // don't call this function if `i` is already a root node
    int PARENT(int i)
    {
        return (i - 1) / 2;
    }

    // return left child of `A[i]`
    int LEFT(int i)
    {
        return (2 * i + 1);
    }

    // return right child of `A[i]`
    int RIGHT(int i)
    {
        return (2 * i + 2);
    }

    // Recursive heapify-down algorithm.
    // The node at index `i` and its two direct children
    // violates the heap property
    void heapify_down(int i)
    {
        // get left and right child of node at index `i`
        int left = LEFT(i);
        int right = RIGHT(i);

        int largest = i;

        // compare `A[i]` with its left and right child
        // and find the largest value
        if (left < size() && A[left] > A[i])
        {
            largest = left;
        }

        if (right < size() && A[right] > A[largest])
        {
            largest = right;
        }

        // swap with a child having greater value and
        // call heapify-down on the child
        if (largest != i)
        {
            swap(A[i], A[largest]);
            heapify_down(largest);
        }
    }

    // Recursive heapify-up algorithm
    void heapify_up(int i)
    {
        // check if the node at index `i` and its parent violate the heap property
        if (i && A[PARENT(i)] < A[i])
        {
            // swap the two if heap property is violated
            swap(A[i], A[PARENT(i)]);

            // call heapify-up on the parent
            heapify_up(PARENT(i));
        }
    }

public:
    // return size of the heap
    unsigned int size()
    {
        return A.size();
    }

    // Function to check if the heap is empty or not
    bool empty()
    {
        return size() == 0;
    }

    // insert key into the heap
    void push(int key)
    {
        // insert a new element at the end of the vector
        A.push_back(key);

        // get element index and call heapify-up procedure
        int index = size() - 1;
        heapify_up(index);
    }

    // Function to remove an element with the highest priority (present at the root)
    void pop()
    {
        try
        {
            // if the heap has no elements, throw an exception
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                                   "index is out of range(Heap underflow)");
            }

            // replace the root of the heap with the last element
            // of the vector
            A[0] = A.back();
            A.pop_back();

            // call heapify-down on the root node
            heapify_down(0);
        }
        // catch and print the exception
        catch (const out_of_range &oor)
        {
            cout << endl
                 << oor.what();
        }
    }

    // Function to return an element with the highest priority (present at the root)
    int top()
    {
        try
        {
            // if the heap has no elements, throw an exception
            if (size() == 0)
            {
                throw out_of_range("Vector<X>::at() : "
                                   "index is out of range(Heap underflow)");
            }

            // otherwise, return the top (first) element
            return A.at(0); // or return A[0];
        }
        // catch and print the exception
        catch (const out_of_range &oor)
        {
            cout << endl
                 << oor.what();
        }
    }
};

// Max Heap implementation in C++
int main()
{
    PriorityQueue pq;

    // Note: The element's value decides priority

    pq.push(30);
    pq.push(50);
    pq.push(33);
    pq.push(40);
    pq.push(60);
    pq.push(22);
    pq.push(55);
    pq.push(22);
    pq.push(60);
    pq.push(11);
    cout << "Size is " << pq.size() << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}
/*
Size is 10
60 60 55 50 40 33 30 22 22 11
*/