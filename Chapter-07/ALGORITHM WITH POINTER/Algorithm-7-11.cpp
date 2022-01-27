/*
page 248
Algorithm 7.11: HEAPSORT(A, N)
An array A with N elements is given.
This algorithm sorts the elements of A.

1. [Build a heap H, using Procedure 7.9.]
Repeat for J = 1 to N – 1:
  Call INSHEAP(A, J, A[J + 1]).
[End of loop.]

2. [Sort A by repeatedly deleting the root of H,
using Procedure 7.10.]
Repeat while N > 1:
  (a) Call DELHEAP(A, N, ITEM).
  (b) Set A[N + 1] := ITEM.
[End of Loop.]

3. Exit.
*/
#include <iostream>
#include <iomanip>
using namespace std;

void swap(int *x, int *y);

class MinHeap
{
    int *harr;
    int capacity;
    int heap_size;

public:
    MinHeap(int capacity);
    void MinHeapify(int);
    int parent(int i)
    {
        return((i -1) / 2);
    }
    int left(int i)
    {
        return (2*i+1);
    }
    int right(int i)
    {
        return (2*i+2);
    }
    int extractMin();
    void decreaseKey(int i, int new_val);
    int getMin()
    {
        return harr[0];
    }
    void deleteKey(int i);
    void insertKey(int k);
};
MinHeap::MinHeap(int capacity)
{
    heap_size = 0;
    capacity = capacity;
    harr = new int[capacity];
}
void MinHeap::insertKey(int k)
{
    if(heap_size == capacity)
    {
        cout << "Overflow: Could not insertKey\n";
        return;
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = k;

    while(i != 0 && harr[parent(i)] > harr[i])
    {
        swap(&harr[i] , &harr[parent(i)]);
        i = parent(i);
    }

}
void MinHeap::decreaseKey(int i, int new_val)
{
    harr[i] = new_val;
    while (i != 0 && harr[parent(i)] > harr[i])
    {
       swap(&harr[i], &harr[parent(i)]);
       i = parent(i);
    }
}
int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return harr[0];
    }
  
    // Store the minimum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[heap_size-1];
    heap_size--;
    MinHeapify(0);
  
    return root;
}
void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    MinHeap h(11);
    for(int i = 0; i < 11; i++)
    {
        h.insertKey(rand()%100);
    }
    for(int i = 0; i < 11; i++)
    {
       cout << h.extractMin() << " ";
    }
}
/*
0 5 24 34 41 58 62 64 67 69 78 
*/