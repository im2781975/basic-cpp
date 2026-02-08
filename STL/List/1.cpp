// C++ Program to sort a linked list 0s, 1s or 2s 
#include <bits/stdc++.h>
using namespace std;
 
/* Link list node */
class Node 
{ 
    public:
    int data; 
    Node* next; 
}; 
 
// Function to sort a linked list of 0s, 1s and 2s 
void sortList(Node *head) 
{ 
    int count[3] = {0, 0, 0}; // Initialize count of '0', '1' and '2' as 0 
    Node *ptr = head; 
 
    /* count total number of '0', '1' and '2' 
    * count[0] will store total number of '0's 
    * count[1] will store total number of '1's 
    * count[2] will store total number of '2's */
    while (ptr != NULL) 
    { 
        count[ptr->data] += 1; 
        ptr = ptr->next; 
    } 
 
    int i = 0; 
    ptr = head; 
 
    /* Let say count[0] = n1, count[1] = n2 and count[2] = n3 
    * now start traversing list from head node, 
    * 1) fill the list with 0, till n1 > 0 
    * 2) fill the list with 1, till n2 > 0 
    * 3) fill the list with 2, till n3 > 0 */
    while (ptr != NULL) 
    { 
        if (count[i] == 0) 
            ++i; 
        else
        { 
            ptr->data = i; 
            --count[i]; 
            ptr = ptr->next; 
        } 
    } 
} 
 
/* Function to push a node */
void push (Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = new Node();
 
    /* put in the data */
    new_node->data = new_data; 
 
    /* link the old list of the new node */
    new_node->next = (*head_ref); 
 
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 
 
/* Function to print linked list */
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        cout << node->data << " "; 
        node = node->next; 
    } 
    cout << endl; 
} 
 
/* Driver code*/
int main(void) 
{ 
    Node *head = NULL; 
    push(&head, 0); 
    push(&head, 1); 
    push(&head, 0); 
    push(&head, 2); 
    push(&head, 1); 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 1); 
    push(&head, 2); 
 
    cout << "Linked List before Sorting\n"; 
    printList(head); 
 
    sortList(head); 
 
    cout << "Linked List after Sorting\n"; 
    printList(head); 
 
    return 0; 
} 
// C++ program to implement Tree Sort 
#include<bits/stdc++.h> 
  
using namespace std; 
  
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// A utility function to create a new BST Node 
struct Node *newNode(int item) 
{ 
    struct Node *temp = new Node; 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 
  
// Stores inorder traversal of the BST 
// in arr[] 
void storeSorted(Node *root, int arr[], int &i) 
{ 
    if (root != NULL) 
    { 
        storeSorted(root->left, arr, i); 
        arr[i++] = root->key; 
        storeSorted(root->right, arr, i); 
    } 
} 
  
/* A utility function to insert a new 
   Node with given key in BST */
Node* insert(Node* node, int key) 
{ 
    /* If the tree is empty, return a new Node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) Node pointer */
    return node; 
} 
  
// This function sorts arr[0..n-1] using Tree Sort 
void treeSort(int arr[], int n) 
{ 
    struct Node *root = NULL; 
  
    // Construct the BST 
    root = insert(root, arr[0]); 
    for (int i=1; i<n; i++) 
        root = insert(root, arr[i]); 
  
    // Store inorder traversal of the BST 
    // in arr[] 
    int i = 0; 
    storeSorted(root, arr, i); 
} 
  
// Driver Program to test above functions 
int main() 
{ 
    //create input array 
    int arr[] = {5, 4, 7, 2, 11}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    treeSort(arr, n); 
  
        for (int i=0; i<n; i++) 
       cout << arr[i] << " "; 
  
    return 0; 
} 
