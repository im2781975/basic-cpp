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
//C++ code to implement the above approach
#include <iostream>
 
// Define a structure for a node in a linked list
struct Node {
  int data;
  Node *next;
};
 
// Function to insert a new node at the end of the linked list
void push(Node **head, int data) {
  Node *newNode = new Node();
  newNode->data = data;
  newNode->next = nullptr;
 
  if (*head == nullptr) {
    *head = newNode;
    return;
  }
 
  Node *last = *head;
  while (last->next != nullptr) {
    last = last->next;
  }
 
  last->next = newNode;
}
 
// Function to print the linked list
void printList(Node *head) {
  Node *current = head;
  while (current != nullptr) {
    std::cout << current->data << " ";
    current = current->next;
  }
  std::cout << std::endl;
}
 
// Function to sort the linked list containing 0's, 1's, and 2's
void sortList(Node *head) {
  int count[3] = {0, 0, 0};
 
  // Count the number of 0's, 1's, and 2's in the linked list
  Node *current = head;
  while (current != nullptr) {
    count[current->data]++;
    current = current->next;
  }
 
  // Overwrite the linked list with the sorted elements
  current = head;
  int i = 0;
  while (current != nullptr) {
    if (count[i] == 0) {
      i++;
    } else {
      current->data = i;
      count[i]--;
      current = current->next;
    }
  }
}
 
int main() {
  Node *head = nullptr;
 
  // Insert some elements into the linked list
    push(&head, 0); 
    push(&head, 1); 
    push(&head, 0); 
    push(&head, 2); 
    push(&head, 1); 
    push(&head, 1); 
    push(&head, 2); 
    push(&head, 1); 
    push(&head, 2); 
 
  std::cout << "Linked List before Sorting: "<<std::endl;
  printList(head);
 
  sortList(head);
 
  std::cout << "Linked List after Sorting: "<<std::endl;
  printList(head);
 
  return 0;
}
// A program to take numbers from different machines and print them in sorted order 
#include <stdio.h> 
 
// A Linked List node 
struct ListNode 
{ 
 int data; 
 struct ListNode* next; 
}; 
 
// A Min Heap Node 
struct MinHeapNode 
{ 
 ListNode* head; 
}; 
 
// A Min Heao (Collection of Min Heap nodes) 
struct MinHeap 
{ 
 int count; 
 int capacity; 
 MinHeapNode* array; 
}; 
 
// A function to create a Min Heap of given capacity 
MinHeap* createMinHeap( int capacity ) 
{ 
 MinHeap* minHeap = new MinHeap; 
 minHeap->capacity = capacity; 
 minHeap->count = 0; 
 minHeap->array = new MinHeapNode [minHeap->capacity]; 
 return minHeap; 
} 
 
/* A utility function to insert a new node at the beginning 
of linked list */
void push (ListNode** head_ref, int new_data) 
{ 
 /* allocate node */
 ListNode* new_node = new ListNode; 
 
 /* put in the data */
 new_node->data = new_data; 
 
 /* link the old list off the new node */
 new_node->next = (*head_ref); 
 
 /* move the head to point to the new node */
 (*head_ref) = new_node; 
} 
 
// A utility function to swap two min heap nodes. This function 
// is needed in minHeapify 
void swap( MinHeapNode* a, MinHeapNode* b ) 
{ 
 MinHeapNode temp = *a; 
 *a = *b; 
 *b = temp; 
} 
 
// The standard minHeapify function. 
void minHeapify( MinHeap* minHeap, int idx ) 
{ 
 int left, right, smallest; 
 left = 2 * idx + 1; 
 right = 2 * idx + 2; 
 smallest = idx; 
 
 if ( left < minHeap->count && 
  minHeap->array[left].head->data < 
  minHeap->array[smallest].head->data 
 ) 
  smallest = left; 
 
 if ( right < minHeap->count && 
  minHeap->array[right].head->data < 
  minHeap->array[smallest].head->data 
 ) 
  smallest = right; 
 
 if( smallest != idx ) 
 { 
  swap( &minHeap->array[smallest], &minHeap->array[idx] ); 
  minHeapify( minHeap, smallest ); 
 } 
} 
 
// A utility function to check whether a Min Heap is empty or not 
int isEmpty( MinHeap* minHeap ) 
{ 
 return (minHeap->count == 0); 
} 
 
// A standard function to build a heap 
void buildMinHeap( MinHeap* minHeap ) 
{ 
 int i, n; 
 n = minHeap->count - 1; 
 for( i = (n - 1) / 2; i >= 0; --i ) 
  minHeapify( minHeap, i ); 
} 
 
// This function inserts array elements to heap and then calls 
// buildHeap for heap property among nodes 
void populateMinHeap( MinHeap* minHeap, ListNode* *array, int n ) 
{ 
 for( int i = 0; i < n; ++i ) 
  minHeap->array[ minHeap->count++ ].head = array[i]; 
 
 buildMinHeap( minHeap ); 
} 
 
// Return minimum element from all linked lists 
ListNode* extractMin( MinHeap* minHeap ) 
{ 
 if( isEmpty( minHeap ) ) 
  return NULL; 
 
 // The root of heap will have minimum value 
 MinHeapNode temp = minHeap->array[0]; 
 
 // Replace root either with next node of the same list. 
 if( temp.head->next ) 
  minHeap->array[0].head = temp.head->next; 
 else // If list empty, then reduce heap size 
 { 
  minHeap->array[0] = minHeap->array[ minHeap->count - 1 ]; 
  --minHeap->count; 
 } 
 
 minHeapify( minHeap, 0 ); 
 return temp.head; 
} 
 
// The main function that takes an array of lists from N machines 
// and generates the sorted output 
void externalSort( ListNode *array[], int N ) 
{ 
 // Create a min heap of size equal to number of machines 
 MinHeap* minHeap = createMinHeap( N ); 
 
 // populate first item from all machines 
 populateMinHeap( minHeap, array, N ); 
 
 while ( !isEmpty( minHeap ) ) 
 { 
  ListNode* temp = extractMin( minHeap ); 
  printf( "%d ",temp->data ); 
 } 
} 
 
// Driver program to test above functions 
int main() 
{ 
 int N = 3; // Number of machines 
 
 // an array of pointers storing the head nodes of the linked lists 
 ListNode *array[N]; 
 
 // Create a Linked List 30->40->50 for first machine 
 array[0] = NULL; 
 push (&array[0], 50); 
 push (&array[0], 40); 
 push (&array[0], 30); 
 
 // Create a Linked List 35->45 for second machine 
 array[1] = NULL; 
 push (&array[1], 45); 
 push (&array[1], 35); 
 
 // Create Linked List 10->60->70->80 for third machine 
 array[2] = NULL; 
 push (&array[2], 100); 
 push (&array[2], 80); 
 push (&array[2], 70); 
 push (&array[2], 60); 
 push (&array[2], 10); 
 
 // Sort all elements 
 externalSort( array, N ); 
 
 return 0; 
} 
// An efficient program to print all anagrams together
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define NO_OF_CHARS 26
 
// Structure to represent list node for indexes of words in
// the given sequence. The list nodes are used to connect
// anagrams at leaf nodes of Trie
struct IndexNode
{
    int index;
    struct IndexNode* next;
};
 
// Structure to represent a Trie Node
struct TrieNode
{
    bool isEnd;  // indicates end of word
    struct TrieNode* child[NO_OF_CHARS]; // 26 slots each for 'a' to 'z'
    struct IndexNode* head; // head of the index list
};
 
 
// A utility function to create a new Trie node
struct TrieNode* newTrieNode()
{
    struct TrieNode* temp = new TrieNode;
    temp->isEnd = 0;
    temp->head = NULL;
    for (int i = 0; i < NO_OF_CHARS; ++i)
        temp->child[i] = NULL;
    return temp;
}
 
/* Following function is needed for library function qsort(). Refer
   http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
int compare(const void* a, const void* b)
{  return *(char*)a - *(char*)b; }
 
/* A utility function to create a new linked list node */
struct IndexNode* newIndexNode(int index)
{
    struct IndexNode* temp = new IndexNode;
    temp->index = index;
    temp->next = NULL;
    return temp;
}
 
// A utility function to insert a word to Trie
void insert(struct TrieNode** root, char* word, int index)
{
    // Base case
    if (*root == NULL)
        *root = newTrieNode();
 
    if (*word != '\0')
        insert( &( (*root)->child[tolower(*word) - 'a'] ), word+1, index );
    else  // If end of the word reached
    {
        // Insert index of this word to end of index linked list
        if ((*root)->isEnd)
        {
            IndexNode* pCrawl = (*root)->head;
            while( pCrawl->next )
                pCrawl = pCrawl->next;
            pCrawl->next = newIndexNode(index);
        }
        else  // If Index list is empty
        {
            (*root)->isEnd = 1;
            (*root)->head = newIndexNode(index);
        }
    }
}
 
// This function traverses the built trie. When a leaf node is reached,
// all words connected at that leaf node are anagrams. So it traverses
// the list at leaf node and uses stored index to print original words
void printAnagramsUtil(struct TrieNode* root, char *wordArr[])
{
    if (root == NULL)
        return;
 
    // If a lead node is reached, print all anagrams using the indexes
    // stored in index linked list
    if (root->isEnd)
    {
        // traverse the list
        IndexNode* pCrawl = root->head;
        while (pCrawl != NULL)
        {
            printf( "%s ", wordArr[ pCrawl->index ] );
            pCrawl = pCrawl->next;
        }
    }
 
    for (int i = 0; i < NO_OF_CHARS; ++i)
        printAnagramsUtil(root->child[i], wordArr);
}
 
// The main function that prints all anagrams together. wordArr[] is input
// sequence of words.
void printAnagramsTogether(char* wordArr[], int size)
{
    // Create an empty Trie
    struct TrieNode* root = NULL;
 
    // Iterate through all input words
    for (int i = 0; i < size; ++i)
    {
        // Create a buffer for this word and copy the word to buffer
        int len = strlen(wordArr[i]);
        char *buffer = new char[len+1];
        strcpy(buffer, wordArr[i]);
 
        // Sort the buffer
        qsort( (void*)buffer, strlen(buffer), sizeof(char), compare );
 
        // Insert the sorted buffer and its original index to Trie
        insert(&root,  buffer, i);
    }
 
    // Traverse the built Trie and print all anagrams together
    printAnagramsUtil(root, wordArr);
}
 
 
// Driver program to test above functions
int main()
{
    char* wordArr[] = {"cat", "dog", "tac", "god", "act", "gdo"};
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    return 0;
}
// An efficient program to print all anagrams together
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
 
#define NO_OF_CHARS 26
 
// Structure to represent list node for indexes of words in
// the given sequence. The list nodes are used to connect
// anagrams at leaf nodes of Trie
struct IndexNode
{
    int index;
    struct IndexNode* next;
};
 
// Structure to represent a Trie Node
struct TrieNode
{
    bool isEnd;  // indicates end of word
    struct TrieNode* child[NO_OF_CHARS]; // 26 slots each for 'a' to 'z'
    struct IndexNode* head; // head of the index list
};
 
 
// A utility function to create a new Trie node
struct TrieNode* newTrieNode()
{
    struct TrieNode* temp = new TrieNode;
    temp->isEnd = 0;
    temp->head = NULL;
    for (int i = 0; i < NO_OF_CHARS; ++i)
        temp->child[i] = NULL;
    return temp;
}
 
/* Following function is needed for library function qsort(). Refer
   http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
int compare(const void* a, const void* b)
{  return *(char*)a - *(char*)b; }
 
/* A utility function to create a new linked list node */
struct IndexNode* newIndexNode(int index)
{
    struct IndexNode* temp = new IndexNode;
    temp->index = index;
    temp->next = NULL;
    return temp;
}
 
// A utility function to insert a word to Trie
void insert(struct TrieNode** root, char* word, int index)
{
    // Base case
    if (*root == NULL)
        *root = newTrieNode();
 
    if (*word != '\0')
        insert( &( (*root)->child[tolower(*word) - 'a'] ), word+1, index );
    else  // If end of the word reached
    {
        // Insert index of this word to end of index linked list
        if ((*root)->isEnd)
        {
            IndexNode* pCrawl = (*root)->head;
            while( pCrawl->next )
                pCrawl = pCrawl->next;
            pCrawl->next = newIndexNode(index);
        }
        else  // If Index list is empty
        {
            (*root)->isEnd = 1;
            (*root)->head = newIndexNode(index);
        }
    }
}
 
// This function traverses the built trie. When a leaf node is reached,
// all words connected at that leaf node are anagrams. So it traverses
// the list at leaf node and uses stored index to print original words
void printAnagramsUtil(struct TrieNode* root, char *wordArr[])
{
    if (root == NULL)
        return;
 
    // If a lead node is reached, print all anagrams using the indexes
    // stored in index linked list
    if (root->isEnd)
    {
        // traverse the list
        IndexNode* pCrawl = root->head;
        while (pCrawl != NULL)
        {
            printf( "%s ", wordArr[ pCrawl->index ] );
            pCrawl = pCrawl->next;
        }
    }
 
    for (int i = 0; i < NO_OF_CHARS; ++i)
        printAnagramsUtil(root->child[i], wordArr);
}
 
// The main function that prints all anagrams together. wordArr[] is input
// sequence of words.
void printAnagramsTogether(char* wordArr[], int size)
{
    // Create an empty Trie
    struct TrieNode* root = NULL;
 
    // Iterate through all input words
    for (int i = 0; i < size; ++i)
    {
        // Create a buffer for this word and copy the word to buffer
        int len = strlen(wordArr[i]);
        char *buffer = new char[len+1];
        strcpy(buffer, wordArr[i]);
 
        // Sort the buffer
        qsort( (void*)buffer, strlen(buffer), sizeof(char), compare );
 
        // Insert the sorted buffer and its original index to Trie
        insert(&root,  buffer, i);
    }
 
    // Traverse the built Trie and print all anagrams together
    printAnagramsUtil(root, wordArr);
}
 
 
// Driver program to test above functions
int main()
{
    char* wordArr[] = {"cat", "dog", "tac", "god", "act", "gdo"};
    int size = sizeof(wordArr) / sizeof(wordArr[0]);
    printAnagramsTogether(wordArr, size);
    return 0;
}
