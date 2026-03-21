#include<bits/stdc++.h>
//find length or count of nodes in a linked list
class node {
    public:
    int data; node *next;
}
void push(node **head, int val) {
    node *newnode = new node();
    newnode -> data = val;
    newnode -> next = *head;
    *head = newnode;
}
int getcnt(node *head, int cnt = 0) {
    if(!head) return cnt;
    getcnt(head -> next, cnt + 1);
}
int getcnt(node *head) {
    if(!head) return 0;
    else return 1 + getcnt(head -> next);
}
int getcnt(node *head) {
    int cnt = 0;
    node *curr = head;
    while(curr != NULL) {
        cnt++; curr = curr -> next;
    }
    return cnt;
}
int cntOccurance(node *head, int val) {
    node *curr = head; int cnt = 0;
    while(curr != NULL) {
        if(curr -> data == val) cnt++;
        curr = curr -> next;
    }
    return cnt;
}
struct node {
    int data; node *next;
}
void nthfromlast(node *head, int n) {
    node *curr = head, *tmp = head;
    for(int i = 0; i < n && curr; i++) 
        curr = curr -> next;
    if(!curr) return nullptr;
    while(curr -> next) {
        curr = curr -> next;
        tmp = tmp -> next;
    }
    return tmp;
}
// Returns true if first list is present in second list
bool findlist(node *first, node *duo) {
    while(duo) {
        node *curr = first, *tmp = duo;
        while(curr && tmp && curr -> data == tmp -> data) {
            curr = curr -> next;
            tmp = tmp -> next;
        }
        if(!curr) return true;
        duo = duo -> next;
    }
    return false;
}
bool detectloop(node *head) {
    node *newnode = new node();
    while(head) {
        if(head -> next == newnode) return true;
        if(!head -> next) return false;
        node *tmp = head -> next;
        head -> next = newnode;
        head = tmp;
    }
    return false;
}
int dist(node *first, node *last) {
    int cnt = 0; node *curr = first;
    while(curr != last) {
        cnt += 1; curr = curr -> next;
    }
    return cnt + 1;
}
bool detectloop(node *head) {
    node *newnode = new node();
    node *first = head, *last = head;
    int currlen = 0, prvlen = -1;
    while(currlen > prvlen && last) {
        prvlen = currlen;
        currlen = dist(first, last);
        last = last -> next;
    }
    if(!last) return false;
    else return true;
}
bool detectloop(node *head) {
    unordered_set <node*> st;
    while(head != NULL) {
        if(st.find(head) != st.end()) return true;
        st.insert(head); head = head -> next;
    }
    return false;
}
node *findloopstart(node *head) {
    node *slow = head, *fast = head;
    while(fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) break;
    }
    if(!fast || !fast -> next) return nullptr;
    slow = head;
    while(slow != fast) {
        slow = slow -> next;
        fast = fast -> next;
    }
    return slow;
}
int cntnodes(node *head) {
    node *slow = head; node *fast = head;
    while(slow && fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) {
            int cnt = 1;
            fast = slow -> next;
            while(fast != slow) {
                cnt++; fast = fast -> next;
            }
            return cnt;
        }
    }
    return 0;
}
// finding n-th node from the end.
void nthfromend(int n) {
    node *slow = head, *fast = head;
    for(int i = 0; i < n && fast; i++) fast = fast -> next;
    if(!fast) {
        cout << n << " list length"; return;
    }
    while(fast -> next) {
        slow = slow -> next;
        fast = fast -> next;
    }
    cout << "Node " << n << " from end: " << slow -> data << endl;
}
int cntOccurance(node *head, int key) {
    if(!head) return 0;
    return (head -> data == key) + cntOccurance(head -> next, key);
}
int cntrotation(node *head) {
    int rotation = 0;
    while(head -> next && head -> data > head -> next -> data) {
        rotation++; head = head -> next;
    }
    return rotation;
}
// count nodes in loop
node *newnode(int key) {
    return new node{key, nullptr};
}
int cntnodesInloop(node *head) {
    unordered_set <node*> st;
    node *curr = head;
    while(curr) {
        if(st.count(curr)) {
            int cnt = 0;
            node *tmp = curr;
            do {
                cnt++; curr = curr -> next;
            } while(curr != tmp);
            return cnt;
        }
        st.insert(cnt);
        curr = curr -> next;
    }
}
// Count nodes in circular list
int cntnodes(node *head) {
    if(!head) return 0;
    int cnt = 0;
    node *tmp = head;
    do {
        cnt++; tmp = tmp -> next;
    } while(tmp != head)
    return cnt;
}
bool detectloop(node *head) {
    node *slow = head, *fast = head;
    while(slow && fast && fast -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
        if(slow == fast) return true;
    }
    return false;
}
//find n'th node in linked list 
int getNth(node *head, int idx) {
    node *curr = head; int cnt = 0;
    while(curr != NULL) {
        if(cnt == idx) return curr -> data;
        cnt++; curr = curr -> next;
    }
    assert(0);
}
node *getintersection(node *top, node *head) {
    unordered_set <int> st;
    node *res = nullptr;
    while(top) {
        st.insert(top -> data); top = top -> next;
    } 
    while(head) {
        if(st.count(head -> data)) {
            node *tmp = new node{head -> data, res};
            res = tmp;
        } 
        head = head -> next;
    } 
    return res;
}
node *getunion(node *top, node *head) {
    unordered_set <int> st;
    node *res = nullptr;
    while(top) {
        st.insert(top -> data); top = top -> next;
    }
    while(head) {
        st.insert(head -> data); head = head -> next;
    }
    for(int x : st) res = new node{x, res};
    return res;
}
node *getunion(node *a, node *b) {
    node dummy{0, nullptr};
    node *tail = &dummy;
    while(a || b) {
        int val = (a && (!b || a -> data <= b -> data)) ? a -> data : b -> data;
        tail -> next = new node(val);
        tail = tail -> next;
        
        if(a && a -> data == val) a = a -> next;
        if(b && b -> data == val) b = b -> next;
    }
    return dummy.next;
}
bool ispresent(node *a, node *b) {
    node *tmp = head;
    while(tmp!= NULL) {
        if(tmp -> data == val) return true;
        tmp = tmp -> next;
    }
    return false;
}
node *intersectionpoint(node *a, node *b) {
    node *curr = a, *tmp = b;
    while(curr != tmp) {
        curr = curr ? curr -> next : b;
        tmp = tmp ? tmp -> next : a;
    }
    return curr; 
}
node *intersectionpoint(node *a, node *b) {
    unordered_set <node*> st;
    while(a) {
        st.insert(a); a = a -> next;
    }/*
    while(b) {
        if(st.find(b) != st.end()) {
            cout << b -> data << " "; break;
        }
        b = b -> next;
    } */
    while(b) {
        if(st.count(b)) return b;
        b = b -> next;
    }
    return nullptr;
}
node *intersecPoint(node *a, node *b) {
    stack <node*> s1, s2;
    while(a) {
        s1.push(a); a = a -> next;
    }
    while(b) {
        s2.push(b); b = b -> next;
    }
    while(!s1.empty() && !s2.empty() && s1.top() == s2.top()) {
        node *common = s1.top(); s1.pop(); s2.pop();
        if(!s1.empty() && !s2.empty() && s1.top() == s2.top()) return common;
    }
    return nullptr;
}
struct node {
    int data; node *next; bool vis;
    node(int val) : data(val), next(nullptr), vis(false) {}
};
int intersectionpoint(node *a, node *b) {
    node *tmp = a;
    while(tmp) {
        tmp -> vis = true; tmp = tmp -> next;
    }
    tmp = b;
    while(tmp) {
        if(tmp -> vis) return tmp -> data;
        else tmp -> vis = true;
        tmp = tmp -> next;
    }
}
node *intersectionpoint(node *a, node *b) {
    while(b) {
        node *tmp = a; 
        while(tmp) {
            if(tmp == b) return b;
            tmp = tmp -> next;
        }
        b = b -> next;
    }
    return NULL;
}
Node* getIntersectionNode(Node* h1, Node* h2) {
    int len1 = 0, len2 = 0;
    for (Node* p = h1; p; p = p->next) len1++;
    for (Node* p = h2; p; p = p->next) len2++;
    if (len1 > len2) {
        for (int i = 0; i < len1-len2; i++) h1 = h1->next;
    } else {
        for (int i = 0; i < len2-len1; i++) h2 = h2->next;
    }
    while (h1 && h2 && h1 != h2) {
        h1 = h1->next;
        h2 = h2->next;
    }
    return h1;  
}
