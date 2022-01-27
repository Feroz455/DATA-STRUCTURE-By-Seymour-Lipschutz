/*
7.11 Consider the minheap H in Fig. 7.82(a). 
(H is a minheap, since the smaller elements 
are on top of the heap, rather than the larger 
elements.) Describe the heap after ITEM = 11 
is inserted into H.

First insert ITEM as the next node in the complete 
tree, that is, as the left child of node 44. Then 
repeatedly compare ITEM with its parent. Since 
11 < 44, interchange 11 and 44. Since 11 < 22, 
interchange 11 and 22. Since 11 > 8, ITEM = 11 
has found its appropriate place in the heap. Figure 
7.82(b) shows the updated heap H. The shaded edges 
indicate the path of ITEM up the tree.
*/
#include<iomanip>
#include<iostream>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
class MinHeap
{
    int *HeapArr;
    int capacity;
    int heap_size;
    public:
    MinHeap(int capacity);
    void MinHeapify(int);
    int parent(int i)
    {
        return ((i-1)/2);
    }
    int left(int i)
    {
        return (2*i+1);
    }
    int right(int i)
    {

        return (2*i+2);
    }
    int getMin()
    {
        return HeapArr[0];
    }
    int extractMin();
    void deleteKey(int i);
    void insertKey(int k);
    void decreseKey(int i, int new_val);
};
MinHeap::MinHeap(int capacity)
{
    heap_size = 0;
    this->capacity = capacity;
    HeapArr = new int[capacity];
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
    HeapArr[i] = k;
    while((i != 0) && HeapArr[parent(i)] > HeapArr[i])
    {
        swap(&HeapArr[i],&HeapArr[parent(i)]);
        i = parent(i);
    }
}
void MinHeap::decreseKey(int i, int new_val)
{
    HeapArr[i] = new_val;
    while (i != 0 && HeapArr[parent(i)] > HeapArr[i])
    {
       swap(&HeapArr[i], &HeapArr[parent(i)]);
       i = parent(i);
    }
}
int MinHeap::extractMin()
{
    if(heap_size <= 0)
    {
        return INT_MAX;
    }
    if(heap_size == 1)
    {
        heap_size--;
        return HeapArr[0];
    }
    int root = HeapArr[0];
    HeapArr[0] = HeapArr[heap_size-1];
    heap_size--;
    MinHeapify(0);
    return root;
}
void MinHeap::deleteKey(int i)
{
    decreseKey(i, INT_MIN);
    extractMin();
}
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && HeapArr[l] < HeapArr[i])
        smallest = l;
    if (r < heap_size && HeapArr[r] < HeapArr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&HeapArr[i], &HeapArr[smallest]);
        MinHeapify(smallest);
    }
}
int main()
{
    MinHeap H(11);
    int temp;
    for(int i = 0; i < 11; i++)
    {
        cin >> temp;
        H.insertKey(temp);
    }
    for(int i = 0; i < 11; i++)
    {
        cout << H.extractMin() << " ";
    }
}

/*
55
33
25
22
44
8
33
40
55
44
99
8 22 25 33 33 40 44 44 55 55 99
*/
