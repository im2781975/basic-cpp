#include<bits/stdc++.h>
// sort a linked list 0s, 1s or 2s 
using namespace std;
class node {
    public:
    int data; node *nxt;
};
void sortList(node *head) {
    int cnt[3] = {0, 0, 0};
    node *ptr = head;
    while(ptr != NULL) {
        cnt[ptr -> data] += 1;
        ptr = ptr -> nxt;
    }
    int i = 0; ptr = head;
    while(ptr != NULL) {
        if(cnt[i] == 0) ++i;
        else {
            ptr -> data = i;
            --cnt[i];
            ptr = ptr -> nxt;
        }
    }
}
void push(node **ter, int val) {
    node *new_node = new node();
    new_node -> data = val;
    new_node -> nxt = (*ter);
    (*ter) = new_node;
}
void pushend(node **ter, int val) {
    node *new_node = new node();
    new_node -> data = val;
    new_node -> nxt = nullptr;
    if(*ter == nullptr) {
        *ter = new_node; return;
    }
    node *last = *ter;
    while(last -> nxt != nullptr) last = last -> nxt;
    last -> nxt = new_node;
}
void print(node *nd) {
    while(nd != NULL) {
        cout << nd -> data << " ";
        nd = nd -> nxt;
    }
    cout << endl;
}
int main() {
    node *head = NULL;
    push(&head, 2);    push(&head, 1);
    push(&head, 0);    push(&head, 2);
    push(&head, 1);    push(&head, 2);
    push(&head, 0);    push(&head, 1);
    print(head);
    push(&head, 1); sortList(head);
    print(head);
}
struct node {
    int data; node *nxt;
};
struct Compare {
    bool operator() (const node *a, const node *b) { a -> data > b -> data; }
};
node *create(int val) {
    node *newnode = new node;
    newnode -> data = val;
    newnode -> nxt = nullptr;
    return newnode;
}
void push(node **head, int data) {
    if(*head == nullptr) *head = create(data);
    else {
        node *newnode = create(data);
        newnode -> nxt = *head;
        *head = newnode;
    }
}
void print(node *head) {
    while(head != nullptr) {
        cout << head -> data << " "; head = head -> nxt;
    }
}
node *merged(vector <node*> &lst) {
    node *tmp = create(0);
    node *tail = tmp;
    priority_queue <node*, vector <node*>, Compare> minHeap;
    for(node *l : lst) {
        if(l != nullptr) minHeap.push(l);
    }
    while(!minHeap().empty()) {
        node *nd = minHeap.top();
        minHeap.pop();
        
        tail -> nxt = nd; tail = tail -> nxt;
        if (nd ->nxt != nullptr)
            minHeap.push(nd -> nxt);
    }
    return tmp -> nxt;
}
void externalSort(node* arr[], int N) {
    vector <node*> lists(arr, arr + N);
    node* sortedList = merged(lists);
    print(sortedList);
}
int main() {
    node * array[3];
    array[0] = nullptr; array[1] = nullptr;
    array[2] = nullptr;
    push(&array[0], 50);
    push(&array[0], 40);
    push(&array[1], 45);
    push(&array[1], 35);
    push(&array[2], 100);
    push(&array[2], 80);
    externalSort(array, 3);
}
// reverse a string using stack
using namespace std;
string rev(string str) {
    stack <char> st;
    for(char c : str) st.push(c);
    string result;
    while (!st.empty()) {
    result += st.top(); st.pop();
    }
    return result;
}
void stacksort(stack <int> st) {
    stack <int> tmp;
    while(!st.empty()) {
        int x = st.top(); st.pop();
        while(!tmp.empty() && tmp.top() > x) {
            st.push(tmp.top()); tmp.pop();
        }
        st.push(x);
    }
    while(!tmp.empty()) {
        st.push(tmp.top()); tmp.pop();
    }
}
void stackreverse(stack <int> st) {
    stack <int> tmp;
    while(!st.empty()) {
        int x = st.top(); st.pop(); tmp.push(x);
    }
    while(!tmp.empty()) {
        int x = tmp.top(); tmp.pop(); st.push(x);
    }
}
void decreasesize(stack <int> st) {
    int cap = st.size(), sz = 0;
    stack <int> tmp;
    while(!st.empty()) {
        tmp.push(st.top()); st.pop(); sz++;
    }
    if(sz < cap / 2) {
        int newcap = cap / 2;
        stack <int> newst;
        while(!tmp.empty() && newst.size() < newcap) {
            newst.push(tmp.top()); tmp.pop();
        }
        while(!newst.empty()) {
            st.push(newst.top()); newst.pop();
        }
    }
}
// conversion
int func(char ch) {
    if(ch == '+' || ch == '-') return 0;
    return 1;
}
void conversion(string str, stack <char> st) {
    string res = " ";
    for(int i = 0; i < str.size(); i++) {
        char ch = str[i];
        if(ch >= 'a' && ch <= 'z') res += ch;
        else {
            while(st.size() && func(st.top()) >= func(ch)) {
                res += st.top(); st.pop();
            }
            st.push(ch);
        }
    }
    while(st.size()) {
        res += st.top(); st.pop();
    }
    cout << res << endl;
}
