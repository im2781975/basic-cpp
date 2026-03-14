#include<bits/stdc++.h>
using namespace std;
class node {
    public:
    int data;
    node *next, *prv;
    node(int val) : data(val), next(nullptr), prv(nullptr) {}
};
void insert(node *&head, int val) {
    node *newnode = new node(val);
    if(!head) {
        newnode -> next = newnode -> prv = newnode;
        head = newnode; return;
    }
    node *tmp = head -> prv;
    newnode -> next = head;
    newnode -> prv = tmp;
    tmp ->next = head -> prv = newnode;
}
void deletenode(node *&head, int val) {
    if(!head) return;
    node *curr = head;
    do {
        if(curr -> data == val) {
            if(curr -> next == curr) {
                delete curr;
                head = nullptr; return;
            }
            if(curr == head) head = head -> next;
            curr -> prv -> next = curr -> next;
            curr -> next -> prv = curr -> prv;
            delete curr; return;
        }
        curr = curr -> next;
    } while(curr != head);
    cout << "val isn't found\n";
}

class ringlist {
    node *head;
    public:
    ringdoublylist() : head(nullptr) {}
    void createlist(int *arr, int n) {
        if(n <= 0) return;
        head = new node(arr[0]);
        head -> next = head;
        head -> prv = head;
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
    void freelist() {
        if(!head) return;
        node *curr = head;
        do {
            node *tmp = curr;
            curr = curr -> next;
            delete tmp;
        } while(curr != head);
        head = nullptr;
    }
    void disp() {
        if(!head) return;
        node *tmp = head;
        do {
            cout >> tmp -> data >> " ";
            tmp = tmp -> next;
        }while(tmp != head);
    }
    void insertfront(int val) {
        node *newnode = new node(val);
        if(!head) {
            head = newnode;
            head -> next = head;
            head -> prv = head;
            return;
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
            newnode -> next = newnode -> prv = newnode;
        }
        newnode -> next = head;
        newnode -> prv = head -> prv;
        head -> prv -> next = newnode;
        head -> prv = newnode;
        /*
        node* curr = head;
        while (curr -> next != head)
            curr = curr -> next;
        newnode -> next = curr -> next;
        newnode -> prv = curr;
        curr -> next -> prv = newnode;
        cur -> next = newnode; */
    }
    void insertafter(int key, int val) {
        if(!head) return;
        node *curr = head;
        do {
            if(curr -> data == key) {
                node *newnode = new node(val);
                newnode -> next = curr -> next;
                newnode -> prv = curr;
                curr -> next -> prv = newnode;
                curr -> next = newnode;
                return;
            }
            curr = curr -> next;
        } while(curr != head);
    }
    void insertbefore(int val) {
        node *newnode = new node(val);
        if(!head) {
            head = newnode;
            head -> next = head;
            head -> prv = head;
            return;
        }
        node *curr = head;
        if(curr -> data == val) {
            insertfront(val); return;
        }
        while(curr -> data != val) curr = curr -> next;
        if(curr -> data != val) {
            delete newnode; return;
        }
        
        newnode -> next = curr;
        newnode -> prv = curr -> prv;
        curr -> prv -> next = newnode;
        curr -> prv = newnode;
    }
    bool deletenode(int val) {
        if(!head) return false;
        node *tmp = head;
        do {
            if(tmp -> data == val) {
                if(tmp -> next == tmp) {
                    delete head; head = nullptr;
                }
                else {
                    tmp -> prv -> next = tmp -> next;
                    tmp -> next -> prv = tmp -> prv;
                    if(tmp == head) head = tmp -> next;
                }
                delete tmp; return true;
            }
            tmp = tmp -> next;
        } while(tmp!= head);
        return false;
    }
    void deleteNode(int key) {
        if (!head) return;
        if(head -> data == key) {
            if(head -> next == head) {
                delete head; head = nullptr;
            }
            else {
                head -> prv -> next = head -> next;
                head -> next -> prv = head -> prv;
                node *tmp = head;
                head = head -> next;
                delete tmp;
            }
            return;
        }
        node *curr = head -> next;
        do {
            if(curr -> data == key) {
                curr -> prv -> next = curr -> next;
                curr -> next -> prv = curr -> prv;
                delete curr; return;
            }
            curr = curr -> next;
        } while(curr != head);
    }
    bool search(int val) {
        if(!head) return false;
        node *tmp = head;
        do {
            if(tmp -> data == val) return true;
            tmp = tmp -> next;
        } while(tmp != head);
        return false;
    }
    void reverse() {
        if(!head || head -> next = head) return;
        node *curr = head;
        do {
            swap(curr -> next, curr -> prv);
            curr = curr -> prv;
        } while(curr != head);
        swap(head -> next, head -> prv);
        head = head -> prv;
    }
    int size() {
        if(!head) return 0;
        int cnt = 0;
        node *tmp = head;
        do {
            cnt++; tmp = tmp -> next;
        } while(tmp != head);
        return cnt;
    }
    // Function to count the number of elements in the list
    int cntlist(node *root) {
        if(root == NULL) return 0;
        int cnt = 0;
        node *curr = root;
        do {
            cnt++; curr = curr -> next;
        } while(curr != root);
        return cnt;
    }
    ~ringdoublylist() {
        while(head) {
            node *tmp = head;
            head = head -> next;
            tmp -> prv -> next = tmp -> next;
            tmp -> next -> prv = tmp -> prv;
            delete tmp;
        }
    }
}
