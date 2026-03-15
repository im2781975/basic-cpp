#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node *nxt; node *prv;
    node(int val) : data(val), nxt(nullptr), prv(nullptr){}
};
class CDLL {
    private: node *head;
    public:
    CDLL() : head(nullptr){}
    ~CDLL() { clear(); }
    void createlist(int *arr, int n) {
        clear();
        if(n <= 0) return;
        head = new node(arr[0]);
        head -> prv = head;
        head -> next = head;
        node *tail = head;
        for(int i = 1; i < n; i++) {
            node *newnode = new node(arr[i]);
            newnode -> next = head;
            newnode -> prv = tail;
            tail -> next = newnode;
            head -> prv = newnode;
            tail = newnode;
        }
    }
    void clear() {
        while(head) {
            node *curr = head;
            head = head -> next;
            if(head) {
                head -> prv = curr -> prv;
                curr -> prv -> nxt = head;
            }
            delete curr;
        }
    }
    void insertfront(int val) {
        node *newnode = new node(val);
        if(!head) {
            head = newnode;
            head -> next = head;
            head -> prv = head; return;
        }
        newnode -> next = head;
        newnode -> prv = head -> prv;
        head -> prv -> next = newnode;
        head -> prv = newnode;
        head = newnode;
    }
    void insertEnd(int val) {
        node *newnode = new node(val);
        if(!head) {
            head = newnode;
            head -> next = head;
            head -> prv = head; return;
        }
        newnode -> next = head -> next;
        newnode -> prv = head -> prv;
        head -> prv -> next = newnode;
        head -> prv = newnode;
    }
    bool insertafter(int key, int val) {
        if(!head) return false;
        node *curr = head;
        do {
            if(curr -> data == key) {
                node *newnode = new node(val);
                newnode -> next = curr -> next;
                newnode -> prv = curr;
                curr -> next -> prv = newnode;
                curr -> next = newnode;
                return true;
            }
            curr = curr -> next;
        } while(curr != head);
        return false;
    }
    bool insertbefore(int key, int val) {
        if(!head) return false;
        node *curr = head;
        do {
            if(curr -> data == key) {
                node *newnode = new node(val);
                newnode -> next = curr;
                newnode -> prv = curr -> prv;
                curr -> prv -> next = newnode;
                curr -> prv = newnode;
                return true;
            }
            curr = curr -> next;
        } while(curr != head);
        return false;
    }
    bool deletenode(int val) {
        if(!head) return false;
        node *curr = head;
        do {
            if(curr -> data == val) {
                if(curr -> next == curr) {
                    delete head; head = nullptr;
                }
                else {
                    curr -> prv -> next = curr -> next;
                    curr -> next -> prv = curr -> prv;
                    if(curr == head) head = head -> next;
                }
                delete curr; return true;
            }
            curr = curr -> next;
        } while(curr != head);
        return false;
    }
    void deletefront() {
        if(!head || head -> next == head) {
            delete head; head = nullptr;
            return;
        }
        node *curr = head;
        head -> prv -> next = head -> next;
        head -> next -> prv = head -> prv;
        head = head -> next;
        delete curr;
    }
    void deleteEnd() {
        if(!head || head -> next == head) {
            delete head; head = nullptr;
            return;
        }
        node *tmp = head -> prv;
        tmp -> prv -> next = head;
        head -> prv = tmp -> prv;
        delete tmp;
    }
    bool search(int val) {
        if(!head) return false;
        node *curr = head;
        do {
            if(curr -> data == val) return true;
            curr = curr -> next;
        } while(curr != head);
        return false;
    }
    void reverse() {
        if(!head || head -> next == head) return;
        node *curr = head;
        do {
            swap(curr -> next, curr -> prv);
            curr = curr -> prv;
        } while(curr != head);
        head = head -> prv;
    }
    void disp() {
        if(!head) return;
        node *curr = head;
        do {
            cout << curr -> data << " ";
            curr = curr -> next;
        } while(curr != head);
    }
    void disprev() {
        if(!head) return;
        node *curr = head -> prv;
        do {
            cout << curr -> data << " ";
            curr = curr -> prv;
        } while(curr != head -> prv);
    }
    int size() {
        if(!head) return 0;
        int cnt = 0;
        node *curr = head;
        do {
            cnt++; curr = curr -> next;
        } while(curr != head);
        return cnt;
    }
    bool isempty() {
        return head == nullptr;
    }
    bool insertatpos(int pos, int val) {
        int len = size(); 
        if(pos < 1 || pos > len + 1) return false;
        if(pos == 1) {
            insertfront(val); return true;
        }
        node *curr = head;
        for(int i = 1; i < pos - 1; i++) 
            curr = curr -> next;
        node *newnode = new node(val);
        newnode -> next = curr -> next;
        newnode -> prv = curr;
        curr -> next -> prv = newnode;
        curr -> next = newnode;
        return true;
    }
    node *getnodeat(int pos) {
        if(pos < 1 || pos > size()) return nullptr;
        node *curr = head;
        for(int i = 1; i < pos; i++) 
            curr = curr -> next;
        return curr;
    }
};
