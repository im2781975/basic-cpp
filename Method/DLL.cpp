#include<bits/stdc++.h>
using namespace std;
class node {
    public:
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
