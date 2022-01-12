
/*
page 148
Algorithm 5.15: DELTWL(INFO, FORW, BACK, START, AVAIL, LOC)

1. [Delete node.]
Set FORW[BACK[LOC]] := FORW[LOC] and
BACK[FORW[LOC]] := BACK[LOC].

2. [Return node to AVAIL list.]
Set FORW[LOC] := AVAIL and AVAIL := LOC.

3. Exit.
*/
#include<iostream>
#include<string>
#include<iomanip>

using namespace std;
 
// Structure of a Node
typedef struct _node {
    int data;
   _node* next;
   _node* prev;
}NODE;
 
// Function to INSERT node in the list
void INSERT(NODE** START, int value)
{
    // If the list is empty, create a single node
    // circular and doubly list
    if (*START == NULL) {
        NODE* NEW = new NODE;
        NEW->data = value;
        NEW->next = NEW->prev = NEW;
        *START = NEW;
        return;
    }
 
    // If list is not empty
 
    /* Find LAST node */
    NODE* LAST = (*START)->prev;
 
    // Create Node dynamically
   NODE* NEW = new NODE;
    NEW->data = value;
 
    // Start is going to be next of NEW
    NEW->next = *START;
 
    // Make new node previous of START
    (*START)->prev = NEW;
 
    // Make LAST previous of new node
    NEW->prev = LAST;
 
    // Make new node next of old LAST
    LAST->next = NEW;
}
 
// Function to delete a given node from the list
void DELETE_NODE(NODE** START, int key)
{
    // If list is empty
    if (*START == NULL)
        return;
 
    // Find the required node
    // Declare two pointers and initialize them
    NODE *CURRENT = *START, *PREV = NULL;
    while (CURRENT->data != key) {
        // If node is not present in the list
        if (CURRENT->next == *START) {
            cout << "\nList doesn't have node with value "<< key;
            return;
        }
 
        PREV = CURRENT;
        CURRENT = CURRENT->next;
    }
 
    // Check if node is the only node in list
    if (CURRENT->next == *START && PREV == NULL) {
        (*START) = NULL;
        delete CURRENT;
        return;
    }
 
    // If list has more than one node,
    // check if it is the first node
    if (CURRENT == *START) {
        // Move PREV to LAST node
        PREV = (*START)->prev;
 
        // Move START ahead
        *START = (*START)->next;
 
        // Adjust the pointers of PREV and START node
        PREV->next = *START;
        (*START)->prev = PREV;
        delete CURRENT;
    }
 
    // check if it is the LAST node
    else if (CURRENT->next == *START) {
        // Adjust the pointers of PREV and START node
        PREV->next = *START; // line number 80 PREV was update0
        (*START)->prev = PREV;
        delete CURRENT;
    }
    else {
        // create new pointer, points to next of CURRENT node
        NODE* PTR = CURRENT->next;
 
        // Adjust the pointers of PREV and PTR node
        PREV->next = PTR;
        PTR->prev = PREV;
        delete CURRENT;
    }
}
 
// Function to DISPLAY list elements
void DISPLAY(NODE* START)
{
    NODE* PTR = START;
 
    while (PTR->next != START) {
        cout << PTR->data << " ";
        PTR = PTR->next;
    }
    cout << PTR->data << " " << endl;
}
 
// Driver program to test above functions
int main()
{
    // Start with the empty list
    NODE* START = NULL;
 
    // Created linked list will be 4->5->6->7->8
    INSERT(&START, 4);
    INSERT(&START, 5);
    INSERT(&START, 6);
    INSERT(&START, 7);
    INSERT(&START, 8);
 
    cout << "List Before Deletion: ";
    DISPLAY(START);
 
    // Delete the node which is not present in list
    DELETE_NODE(&START, 9);
    cout << "\nList After Deletion: ";
    DISPLAY(START);
 
    // Delete the first node
    DELETE_NODE(&START, 4);
    cout << "\nList After Deleting "<<  4;
    DISPLAY(START);
 
    // Delete the LAST node
    DELETE_NODE(&START, 8);
    cout << "\nList After Deleting" <<  8;
    DISPLAY(START);
 
    // Delete the middle node
    DELETE_NODE(&START, 6);
    cout << "\nList After Deleting "<<  6;
    DISPLAY(START);
 
    return 0;
}
/*
output 
List Before Deletion: 4 5 6 7 8      

List doesn't have node with value = 9
List After Deletion: 4 5 6 7 8       

List After Deleting 45 6 7 8

List After Deleting85 6 7

List After Deleting 65 7
*/
