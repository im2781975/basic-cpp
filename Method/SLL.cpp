#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int data; node *next;
};
class SLL {
    int sz; node *head;
    public:
    single() : sz(0), head(nullptr) {}
    node *create(int val) {
        node *newnode = new node;
        newnode -> data = val;
        newnode -> next = NULL;
        return newnode;
    }
    void insertfront(int val) {
        node *newnode = create(val);
        sz++; node *curr = head;
        if(!head) head = newnode;
        newnode -> next = head; 
        head = newnode;
    }
    void insertmid(int val) {
        int len = getsize();
        if(len < 2) return;
        node *newnode = new node(val);
        node *curr = head;
        int cnt = 0, mid = len / 2;
        while(cnt < mid) {
            curr = curr -> next; cnt++;
        }
        newnode -> next = curr -> next;
        curr -> next = newnode;
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
    void append(int val) {
        node *newnode = create(val);
        if(!head) {
            head = newnode; return;
        }
        node *curr = head;
        while(curr -> next != nullptr) 
            curr = curr -> next;
        curr -> next = newnode;
        sz++;
    }
    void insertpos(int pos, int val) {
        if(pos < 0 || pos > sz) return;
        if(pos == 0) {
            insertfront(val); return;
        }
        sz++; int idx = 0;
        node *curr = head;
        while(idx != pos - 1) {
            curr = curr -> next; idx++;
        }
        node *newnode = create(val);
        newnode -> next = curr -> next;
        curr -> next = newnode;
    }
    int getval(int pos) {
        if(pos < 0 || pos > sz) return -1;
        int idx = 0; node *curr = head;
        while(curr != nullptr && idx != pos) {
            curr = curr -> next; idx++;
        }
        if(curr != nullptr) return curr -> data;
        /*
        while(curr != nullptr) {
            if(idx == pos) return curr -> data;
            curr = curr -> next;
            idx++;
        } */
        return -1;
    }
    bool getval(int val) {
        node *curr = head;
        while(curr != NULL) {
            if(curr -> data == val) return true;
            curr = curr -> next;
        }
        return false;
    }
    int search(int val) {
        node *curr = head; int idx = 0;
        // search distinct
        while(curr != nullptr) {
            if(curr -> data == val) return idx;
            curr = curr -> next; idx++;
        }
        return -1;
        // search all val
        while(curr != nullptr) {
            if(curr -> data == val) cout << val << " " << idx << endl;
            curr = curr -> next; idx++;
        }
    }
    void removezero() {
        if(!head) return;
        while(head != nullptr && head -> data == 0) {
            node *tmp = head;
            head = head -> next;
            delete tmp; sz--;
        }
        node *prv = head; node *curr = head -> next;
        while(curr != nullptr) {
            if(curr -> data == 0) {
                node *tmp = curr;
                prv -> next = curr -> next;
                curr = curr -> next;
                delete tmp; sz--;
            }
            else {
                prv = curr; curr = curr -> next;
            }
        }
    }
    void removefront() {
        if(!head) return;
        while(head != nullptr) {
            node *curr = head;
            head = head -> next;
            delete curr; sz--;
        }
    }
    void removelast() {
        if(!head) return;
        if(head -> next == nullptr) {
            delete head; head = nullptr;
            sz--; return;
        }
        node *curr = head;
        while(curr -> next -> next != nullptr) curr = curr -> next;
        delete curr -> next;
        curr -> next = nullptr;
        sz--;
    }
    void removeatpos(int pos) {
        if(pos < 0 || pos >= sz) return;
        if(pos == 0) {
            removefront(); return;
        }
        node *curr = head; int idx = 0;
        while(idx < pos - 1) {
            curr = curr -> next; idx++;
        }
        node *tmp = curr -> next;
        curr -> next = tmp -> next;
        delete tmp; sz--;
    }
    void removemid() {
        int len = getsize();
        if(len < 3) return;
        node *curr = head; int mid = len / 2;
        for(int i = 1; i < mid - 1; i++) curr = curr -> next;
        node *tmp = curr -> next;
        curr -> next = tmp -> next;
        delete tmp;
    }
    int getsum() {
        node *curr = head;
        int idx = 0, sum = 0;
        while(cur != nullptr) {
            if(idx % 2 == 1) sum += curr -> data;
            idx++; curr = curr -> next;
        }
        return sum;
    }
    int getlast() {
        if(!head) return -1;
        node *curr = head;
        while(curr != NULL) curr = curr -> next;
        return curr -> data;
    }
    void getsize() {
        int cnt = 0;
        node *curr = head;
        while(curr != NULL) {
            cnt++; curr = curr -> next;
        }
        cout << cnt;
    }
    bool hasDup() {
        node *curr = head;
        while(head != nullptr) {
            node *tmp = curr -> next;
            while(tmp != nullptr) {
                if(curr -> data == tmp -> data) return true;
                tmp = tmp -> next;
            }
            curr = curr -> next;
        }
        return false;
    }
    void sortlist() {
        if(head == nullptr || head -> next == nullptr) return;
        node *curr = head; node *tail = nullptr;
        bool swaped = true;
        do {
            swaped = false;
            while(curr -> next != tail) {
                if(curr -> data > curr -> next -> data) {
                    swap(curr -> data, curr -> next -> data);
                    swaped = true;
                }
                curr = curr -> next;
            } tail = curr;
        } while(swaped);
    }
    void recur(node *curr) {
        if(curr == NULL) return;
        recur(curr -> next);
        cout << curr -> data << " ";
    }
    void reverse() { recur(head); }
    void swapfirst() {
        if(sz >= 2) {
            node *curr = head;
            node *tmp = curr -> next;
            swap(curr -> data, tmp -> data);
        }
    }
    double getavg() {
        node *curr = head;
        int cnt = 0, sum = 0;
        while(curr != NULL) {
            sum += curr -> data;
            cnt++; curr = curr -> next;
        }
        return sum / cnt;
    }
};
class SLL {
    node *head, *tail;
    public:
    SLL() : head(nullptr), tail(nullptr) {}
    void insertfront(int val) {
        node *newnode = new node(val);
        if(head == NULL) head = tail = newnode;
        else {
            newnode -> next = head;
            head = newnode;
        }
    }
    void insertlast(int val) {
        node *newnode = new node(val);
        if(head == NULL) head = tail = newnode;
        else {
            tail -> next = newnode;
            tail = newnode;
        }
    }
    void removeback() {
        if(!head) return;
        else if(head == tail) {
            delete head;
            head = tail = NULL;
        }
        else {
            node *curr = head;
            while(curr -> next != tail) curr = curr -> next;
            delete tail; tail = curr;
            tail -> next = nullptr;
        }
    }
}
