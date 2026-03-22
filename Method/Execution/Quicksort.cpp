#include<bits/stdc++.h>
using namespace std;
struct node {
    int data; node *next;
};
void push(node **head, int val) {
    node *newnode = new node();
    newnode -> data = val;
    newnode -> next = *head;
    *head = newnode;
}
bool areIdentical(node *a, node *b) {
    if(!a && !b) return false;
    if(a && b) return a -> data == b -> data && areIdentical(a -> next, b -> next);
    return false;
}
bool areIdentical(node *a, node *b) {
    while(a && b) {
        if(a -> data != b -> data) return false;
        a = a -> next; b = b -> next;
    }
    return (!a && !b);
}
bool iscircular(node *head) {
    if(!head) return true;
    node *tmp = head -> next;
    while(tmp != NULL && tmp != head) tmp = tmp -> next;
    return (tmp == head);
}
bool issublist(node *list, node *sub) {
    if(!sub) return true;
    if(!list) return false;
    if(list -> data == sub -> data) {
        if(issublist(list -> next, sub -> next)) return true;
    }
    return issublist(list -> next, sub);
}
bool Ispalindrome(node *head) {
    node *curr = head;
    stack <int> st;
    while(curr) {
        st.push(curr -> data); curr = curr -> next;
    }
    curr = head;
    while(curr) {
        if(curr -> data != st.top()) return false;
        st.pop();
    }
    return true;
}
//make middle node as head of  linked list
void makemiddleheap(node **head) {
    if(!*head) return;
    node *slow = *head, *fast = *head, *prv = nullptr;
    while(fast && fast -> next) {
        prv = slow; slow = slow -> next;
        fast = fast -> next -> next;
    }
    prv -> next = slow -> next;
    slow -> next = *head;
    *head = slow;
}
// merge two sorted linked lists
void mergelist(node *a, node *&b) {
    while(a && b) {
        if(a -> data > b -> data) {
            swap(a -> data, b -> data);
            if(b -> data && b -> data > b -> next -> data) {
                node *tmp = b -> next;
                b -> next = tmp -> next;
                tmp -> next = b; b = tmp;
            }
        }
        a = a -> next
    }
}
// arrange linked list in zigzag fashion
void zigzag(node *head) {
    bool greater = false;
    node *curr = head;
    while(curr -> next) {
        if(greater) {
            if(curr -> data > curr -> next -> data) swap(curr -> data, curr -> next -> data);
        }
        else {
            if(curr -> data < curr -> next -> data) swap(curr -> data, curr -> next -> data);
        }
        greater = !greater;
    }
}
node* zigzag(node* head, bool flag)
{
    if (!head || !head->next)
        return head;
    if (flag == 1) {
        if (head->data > head->next->data)
            swap(head->data, head->next->data);
        return zigzag(head->next, !flag);
    }
    else {
        if (head->data < head->next->data)
            swap(head->data, head->next->data);
        return zigzag(head->next, !flag);
    }
}
node *zigzag(node *head, bool flag) {
    if(!head || !head -> next) return head;
    if(flag) {
        if(head -> data > head -> next -> data) swap(head -> data, head -> next -> data);
        return zigzag(head -> next, !flag);
    }
    else {
        if(head -> data < head -> next -> data) swap(head -> data, head -> next -> data);
        return zigzag(head -> next, !flag);
    }
}
struct node {
    char data; node* next;
};
bool Ispalindrome(node **left, node *right) {
    if(!right) return true;
    if(!(Ispalindrome(left, right -> next))) return false;
    bool match = right -> data == (*left) -> data;
    (*left) = (*left) -> next;
    return match;
}
bool palindrome(node *head) {
    return Ispalindrome(&head, head);
}
void push(Node** head, char data) {
    *head = new Node{data, *head};
}
void reverse(node **head) {
    node *prv = nullptr, *curr = *head;
    while(curr) {
        *head = curr -> next;
        curr -> next = prv;
        prv = curr; curr = *head;
    }
    *head = prv;
}
bool compare(node *a, node *b) {
    while(a && b) {
        if(a -> data != b -> data) return false;
        a = a -> next; b = b -> next;
    }
    return !a && !b;
}
bool ispalindrome(node *head) {
    if(!head || !head -> next) return true;
    node *slow = head, *fast = head, *prv = head;
    while(fast -> next && fast -> next -> next) {
        prv = slow; slow = slow -> next;
        fast = fast -> next -> next;
    }
    node *zweithalf = slow -> next;
    prv -> next = nullptr;
    node *mid = fast -> next ? slow : nullptr;
    if(mid) slow = slow -> next;
    reverse(&zweithalf);
    bool res = compare(head, zweithalf);
    reverse(&zweithalf);
    prv -> next = mid? (mid -> next == zweithalf) : zweithalf;
    return res;
}
// Split list into front and back halves using slow/fast pointers
void splitList(node *head, node **front, node **back) {
    node *slow = head, *fast = head -> next;
    while(fast) {
        fast = fast -> next;
        if(fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
    }
    *front = head;
    *back = slow -> next;
    slow -> next = NULL;
}
void reverse(node **head) {
    node *prv = NULL, *curr = *head;
    while(curr) {
        node *next = curr -> next;
        curr -> next = prv;
        prv = curr; curr = next;
    }
    *head = prv;
}
node *modifylist(node *head) {
    if(!head || !head -> next) return head;
    node *front, *back;
    splitlist(head, &front, &back);
    reverse(&back);
    node *f = front, *b = back;
    while(b) {
        // front[i] -= back[i]
        f -> data -= b -> data;
        f = f -> next; b = b -> next;
    }
    reverse(&back);
    node *tail = front;
    while(tail -> next) tail = tail -> next;
    tail -> next = back;
    return front;
}
// Find middle using slow/fast pointers
node *findmid(node *head) {
    node *slow = head, *fast = head;
    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}
int getlen(node *head) {
    int len = 0; node *curr = head;
    while(curr != NULL) {
        len++; curr = curr -> next;
    }
    return len;
}
void printmid(node *head) {
    if(head) {
        int len = getlen(head); node *curr = head;
        int mid = len / 2;
        while(mid--) curr = curr -> next;
        cout << curr -> data << endl;
    }
}
void printmid(node *head) {
    if(!head) return;
    int cnt = 0; node *curr = head;
    while(curr) {
        cnt++; curr = curr -> next;
    }
    curr = head;
    for(int i = 0; i < cnt / 2; i++) curr = curr -> next;
    cout << curr -> data << endl;
}
void modifylist(node *head, node *mid) {
    stack <int> st; node *tmp = mid;
    while(tmp) {
        st.push(tmp -> data); tmp = tmp -> next;
    }
    tmp = head;
    while(!st.empty()) {
        tmp -> data -= st.top();
        st.pop(); tmp = tmp -> next;
    }
}
// move last element to front
void moveTofront(node **head) {
    if(!*head || !(*head) -> next) return;
    node *seclast = NULL, *last = *head;
    while(last -> next) {
        seclast = last; last = last -> next;
    }
    seclast -> next = NULL; 
    last -> next = *head; *head = last;
}
// pairwise swap elements in a given linked list
void pairwiseswap(node *head) {
    node *curr = head;
    while(curr && curr -> next) {
        swap(curr -> data, curr -> next -> data);
        curr = curr -> next -> next;
    }
}
// Count common prefix length between two lists
int cntfreq(node *a, node *b) {
    int cnt = 0;
    while(a && b && a -> data == b -> data) {
        cnt++; 
        a = a -> next; b = b -> next;
    }
    return cnt;
}
// Find longest palindromic sublist
int maxlength(node *head) {
    int maxlen = 0;
    node *prv = nullptr, *curr = head;
    while(curr) {
        node *tmp = curr -> next;
        curr -> next = prv;
        maxlen = max(maxlen, 2 * cntfreq(prv, tmp) + 1);
        maxlen = max(maxlen, 2 * cntfreq(curr, tmp) + 1);
        prv = curr; curr = tmp;
    }
    return maxlen;
}
// partition a linked list around a given value
// Partition: <x | >=x (preserves order)
node *partition(node *head, int x) {
    node *minhead = nullptr, *mintail = nullptr, largetail = nullptr;
    node *curr = head;
    while(curr) {
        node *tmp = curr -> next;
        if(curr -> data < x) {
            if(!minhead) minhead = head;
            else mintail -> next = curr;
            mintail = curr ; curr -> next = nullptr;
        }
        else {
            if(!largetail) largetail = curr;
            else largetail -> next = curr;
            largetail = curr; curr -> next = nullptr;
        }
    }
    if (minhead) {
        mintail -> next = largeail ? largetail : nullptr;
        return minhead;
    }
    return largetail ? largetail : nullptr;
}
// Quicksort
node *gettail(node *head) {
    while(head && head -> next) head = head -> next;
    return head;
}
node *partition(node *head, node *end, node *chief, node *last) {
    node *pivot = end, *prv = nullptr;
    node *curr = head, *tail = pivot;
    while(curr != pivot) {
        if(curr -> data < pivot -> data) {
            if(!*chief) *chief = curr;
            prv = curr; curr = curr -> next;
        }
        else {
            if(prv) prv -> next = curr -> next;
            node *next = curr -> next;
            curr -> next = nullptr;
            tail -> next = curr;
            tail = curr; curr = next;
        }
    }
    if(!*chief) *chief = pivot;
    *last = tail; return pivot;
}
node* quickSortRecur(node* head, node* end) {
    if (!head || head == end) return head;
    
    Node *newHead = nullptr, *newEnd = nullptr;
    Node* pivot = partition(head, end, &newHead, &newEnd);
    
    if (newHead != pivot) {
        Node* tmp = newHead;
        while (tmp->next != pivot) tmp = tmp->next;
        tmp->next = nullptr;
        newHead = quickSortRecur(newHead, tmp);
        gettail(newHead)->next = pivot;
    }
    // Sort right half
    pivot->next = quickSortRecur(pivot->next, newEnd);
    return newHead;
}
void quickSort(Node** head) {
    *head = quickSortRecur(*head, gettail(*head));
}
