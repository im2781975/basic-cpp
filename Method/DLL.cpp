#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node *next; node *prv;
};
class DBLL {
    public:
    node *head; int sz;
    DBLL() : head(nullptr), sz(0) {}
    node *create(int val) {
        node *newnode = new node;
        newnode -> next = nullptr;
        newnode -> prv = nullptr;
        newnode -> data = val; return newnode;
    }
    void insertfront(int val) {
        node *newnode = create(val); sz++;
        if(head == NULL) {
            head = newnode; return;
        }
        node *curr = head;
        newnode -> next = curr;
        curr -> prv = newnode;
        head = newnode;
    }
    void append(int val) {
        node *newnode = create(val); sz++;
        if(!head) {
            head = newnode; return;
        }
        node *curr = head;
        while(curr -> next != NULL) curr = curr -> next;
        curr -> next = newnode;
        newnode -> prv = curr;
    }
    void disp() {
        node *curr = head;
        while(curr != NULL) {
            cout << curr -> data << " ";
            curr = curr -> next;
        }
    }
    int search(int val) {
        node *curr = head; int idx = 0;
        // search distinct
        while(curr != NULL) {
            if(curr -> data == val) return idx;
            curr = curr -> next; idx++;
        }
        // search idx
        while(curr != NULL) {
            if(curr -> data == val) cout << val << " " << idx << endl;
            curr = curr -> next; idx++;
        }
    }
    void insertpos(int val, int pos) {
        if(pos < 0 || pos > sz) return;
        if(pos == 0) {
            append(val); return;
        }
        node *curr = head; int idx = 0;
        while(idx != pos - 1) {
            if(curr == NULL) return;
            curr = curr -> next;
            idx++;
        }
        if(!curr) return;
        node *newnode = create(val);
        newnode -> next = curr -> next;
        newnode -> prv = curr;
        curr -> next = newnode; sz++;
    }
    void removefront() {
        if(!head) return;
        sz--; node *curr = head;
        head = curr -> next; delete curr;
    }
    void removeIdx(int pos) {
        if(pos < 0 || pos >= sz) return;
        if(pos == 0) {
            head = head -> next; 
            delete head -> prv; 
            head -> prv = NULL;
            sz--; return;
        }
        node *curr = head; int idx = 0;
        while(idx != pos - 1) {
            curr = curr -> next; idx++;
        }
        node *tmp = curr -> next;
        curr -> next = tmp -> next;
        if(tmp -> next) tmp -> next -> prv = curr;
        delete tmp; sz--;
    }
    void removeval(int val) {
        node *curr = head;
        while(curr != NULL) {
            if(curr -> data == val) {
                node *tmp = curr;
                if(curr -> prv != NULL) curr -> prv -> next = curr -> next;
                if(curr -> next != NULL) curr -> next -> prv = curr -> prv;
                if(curr == head) head = curr -> next;
                curr = curr -> next; sz--;
                delete tmp;
            }
            else curr = curr -> next;
        }
    }
    int getsize() {
        int cnt = 0;
        node *curr = head;
        while(curr != NULL) {
            cnt++; curr = curr -> next;
        }
        return cnt;
    }
    void insertafter(int key, int val) {
        node *curr = head;
        while(curr != NULL) {
            if(curr -> data == key) break;
            curr = curr -> next;
        }
        if(curr == NULL) sz++;
        node *newnode = create(val);
        newnode -> next = curr -> next;
        curr -> next = newnode;
    }
    void recurrev(node *curr) {
        if(curr == NULL) return;
        recurrev(curr -> next);
        cout << curr -> data << " ";
    }
    void reverse() {
        if(!head || !head -> next) return;
        node *prv = NULL, *curr = head, *nxt;
        while(curr) {
            next = curr -> next;
            curr -> next = prv;
            curr -> prv = next;
            prv = curr; curr = next;
        }
        head = prv;
    }
    void swapIdx(int i, int j) {
        if(i < 0 || i >= sz || j < 0 || j >= sz) return;
        node *curr = head, *tmp = head;
        int idx = 0;
        while(idx != i) {
            curr = curr -> next; idx++;
        }
        idx = 0;
        while(idx != j) {
            tmp = tmp -> next; idx++;
        }
        swap(curr -> data, tmp -> data);
    }
};
class node {
    public:
    int data;
    node *next; node *prv;
    node(int val) : data(val), next(nullptr), prv(nullptr) {}
};
class DBLL {
    public:
    node *head, *tail; int sz;
    DBLL() : head(nullptr), tail(nullptr), sz(0);
    void insertfront(int val) {
        node *newnode = newnode(val);
        if(head == nullptr) head = tail = newnode;
        else {
            newnode -> next = head; 
            head -> prv = newnode;
            head = newnode;
        }
        sz++;
    }
    void append(int val) {
        node *newnode = new node(val);
        if(head == nullptr) head = tail = newnode;
        else {
            tail -> next = newnode;
            newnode -> prv = tail;
            tail = newnode;
        }
        sz++;
    }
	void push(int x) {
        Node* n = new Node{x};
        n->next = head;
        if (head) head->prev = n;
        head = n;
        ++count;
    }
    
    // Insert end (FIXED)
    void append(int x) {
        Node* n = new Node{x};
        if (!head) {
            head = n;
            ++count;
            return;
        }
        Node* t = head;
        for (; t->next; t = t->next);
        t->next = n;
        n->prev = t;
        ++count;
    }
    
    // Insert after node
    void insertAfter(Node* p, int x) {
        if (!p) return;
        Node* n = new Node{x};
        n->next = p->next;
        p->next = n;
        n->prev = p;
        if (n->next) n->next->prev = n;
        ++count;
    }
    
    // Insert before node
    void insertBefore(Node* n, int x) {
        if (!n) return;
        Node* p = new Node{x};
        p->prev = n->prev;
        n->prev = p;
        p->next = n;
        if (p->prev) p->prev->next = p;
        else head = p;
        ++count;
    }
    
    // Sorted insert (unchanged, perfect)
    void sortedInsert(int val) {
        Node* n = new Node{val};
        Node *prevv = nullptr, *curr = head;
        while (curr && curr->data < val) {
            prevv = curr;
            curr = curr->next;
        }
        n->prev = prevv;
        n->next = curr;
        if (prevv) prevv->next = n;
        else head = n;
        if (curr) curr->prev = n;
        ++count;
    }
    void insertmid(int val) {
        node *newnode = new node(val);
        if(sz == 0) head = tail = newnode;
        else {
            node *curr = head;
            for(int i = 0; i < sz / 2; i++) curr = curr -> next;
            newnode -> prv = curr -> prv;
            newnode -> next = curr -> next;
            if(curr -> prv) curr -> prv -> next = newnode;
            else head = newnode;
            curr -> next -> prv = newnode;
            curr -> next = newnode;
        }
        sz++; /*
        if(head == NULL) {
            head = tail = newnode; return;
        }
        node *curr = head;
        for(int i = 0; i < sz / 2; i++) curr = curr -> next;
        newnode -> next = curr;
        newnode -> prv = curr -> prv;
        if(curr -> prv) curr -> prv -> next = newnode;
        else head = newnode;
        curr -> prv = newnode;
        if(curr == tail) tail = newnode;
        sz++; */
    }
    void removeback() {
        if(tail == nullptr) return;
        /*
        node *tmp = tail;
        tail = tail -> prv; delete tmp;
        if(tail == nullptr) head = nullptr;
        else tail -> next = nullptr; */
        if(head == tail) head = tail = nullptr;
        else {
            node *tmp = tail;
            tail = tail -> prv;
            tail -> next = nullptr; delete tmp;
        }
        sz--;
    }
    void erase(int val) {
        node *curr = head;
        while(curr) {
            if(curr -> data == val) {
                if(curr -> prv) curr -> prv -> next = curr -> next;
                else head = curr -> next;
                if(curr -> next) curr -> next -> prv = curr -> prv;
                else tail = curr -> prv;
                delete curr; sz--;
                return;
            }
            curr = curr -> next;
        }
        cout << "doesn't exits";
    }
    void removefront() {
        if(head == nullptr) return;
        if(head == tail) head = tail = nullptr;
        else {
            node *tmp = head;
            head = head -> next;
            head -> prv = nullptr;
            delete tmp;
        }
        sz--;
    }
    void removemid() {
        if(sz == 0) return;
        node *curr = head;
        for(int i = 0; i < sz / 2; i++) curr = curr -> next;
        if(curr -> prv) curr -> prv -> next = curr -> next;
        else head = curr -> next;
        if(curr -> next) curr -> next -> prv = curr -> prv;
        else tail = curr -> prv;
        delete curr;
        sz--;
    }
    bool ispalindrome() {
        node *curr = head;
        node *tmp = head;
        while(tmp && tmp -> next) {
            curr = curr -> next;
            tmp = tmp -> next -> next;
        }
        node *left = head;
        node *right = tmp;
        while(right) {
            if(left -> data != right -> data) return false;
            left = left -> next;
            right = right -> prv;
        }
        return true;
    }
    int getmax() {
        if(sz == 0) return -1;
        int mx = head -> data;
        node *curr = head -> next;
        while(curr != NULL) {
            if(curr -> data > mx) mx = curr -> data;
            curr = curr -> next;
        }
        return mx;
    }
    void deletemax() {
        if(sz == 0) return;
        node *curr = head;
        while(curr) {
            if(curr -> data == getmax()) {
                node *tmp = curr;
                curr = curr -> next;
                if(tmp -> prv) tmp -> prv -> next = tmp -> next;
                else head = tmp -> next;
                if(tmp -> next) tmp -> next -> prv = tmp -> prv;
                else tail = tmp -> prv;
                delete tmp; sz--;
                return;
            }
            curr = curr -> next;
        }
    }
    ~DBLL() {
        node *curr = head;
        while(curr != NULL) {
            node *tmp = curr;
            curr = curr -> next;
            delete tmp;
        }
    }
};
