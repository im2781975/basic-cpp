#include<bits/stdc++.h>
using namespace std;
struct node {
    int data; node *next;
}
void push(node **head, int val) {
    node *newnode = new node();
    newnode -> data = val; 
    newnode -> next = *head;
    *head =  newnode;
}
void printrandom(node *head) {
    if(!head) return;
    srand(time(NULL));
    int res = head -> data, n = 1;
    node *curr = head;
    while(curr) {
        n++; 
        if(rand() % n == 0) res = curr -> data;
        curr = curr -> next;
    }
    cout << res;
}
void printrandom(node *head) {
    node *curr = head;
    vector <int> vec;
    while(curr) {
        vec.push_back(curr -> data);
        curr = curr -> next;
    }
    int idx = rand() % (vec.size());
    cout << vec[idx] << endl;
}
node *insertfront(node *head, int data) {
    node *newnode = new node(data);
    newnode -> next = head; return newnode;
}
void rearrange(node **head) {
    node *odd = nullptr, *even = nullptr;
    node *curr = *head;
    while(curr) {
        if(curr -> data % 2 == 0) even = insertfront(even, curr -> data);
        else odd = insertfront(odd, curr -> data);
        curr = curr -> next;
    }
    node *res = nullptr;
    node *currOdd = odd, *currEven = even;
    bool takeOdd = true;
    while(currOdd || currEven) {
        if(takeOdd && currOdd) {
            res = insertfront(res, currOdd -> data);
            currOdd = currOdd -> next;
        }
        else if(currEven){
            res = insertfront(res, currEven -> data);
            currEven = currEven -> next;
        }
        else takeOdd = !takeOdd;
    }
    *head = res;
}
void reverse(node **head) {
    node *prv = nullptr, *curr = *head;
    while(curr) {
        node *tmp = curr -> next;
        curr -> next = prv; 
        prv = curr; curr = tmp;
    }
}
void rearrange(node **head) {
    node *slow = *head, *fast = *head;
    while(fast -> next && fast -> next -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    node *head2 = slow -> next;
    slow -> next = nullptr;
    reverse(&head2);
    node *p1 = *head, *p2 = *head2;
    while (p1 && p2) {
        node* next1 = p1->next;
        node* next2 = p2->next;
        
        p1->next = p2; p2->next = next1;
        p1 = next1; p2 = next2;
    }
}
void rearrange(node **head, node *last) {
    if(!last) return;
    rearrange(head, last -> next);
    if(!(*head) || !(*head) -> next) return;
    if ((*head) != last && (*head) -> next != last) {
        node *tmp = (*head) -> next;
        (*head) -> next = last;
        last -> next = tmp;
        *head = tmp;
    }
    else (*head) -> next = nullptr;
}
void rearrange(node **head) {
    node *prv = nullptr, *curr = *head;
    while(curr && curr -> next) {
        node *tmp = curr -> next;
        curr -> next = tmp -> next;
        tmp -> next = curr;
        if(prv) prv -> next = curr;
        else *head = tmp;
        prv = tmp; curr = tmp -> next;
    }
}
void rearrangeOddEven(node *head) {
    stack <node*> odd, even;
    node *curr = head; int pos = 1;
    while(curr) {
        if ((curr -> data % 2 != 0) != (pos % 2 != 0)) {
            if (curr -> data % 2 == 0)  even.push(curr);
            else odd.push(curr);
        }
        curr = curr->next; pos++;
    }
    while (!odd.empty() && !even.empty()) {
        swap(odd.top() -> data, even.top() -> data);
        odd.pop(); even.pop();
    }
}
void removeDup(node *head) {
    unordered_set <int> st;
    node *curr = head, *prv = nullptr;
    while(curr) {
        if(st.count(curr -> data)) {
            prv -> next = curr -> next;
            node *del = curr;
            curr = curr -> next;
            delete del;
        }
        else {
            st.insert(curr -> data);
            prv = curr; curr = curr -> next;
        }
    } /*
    while(curr) {
        if(st.find(curr -> data) != st.end()) {
            prv -> next = curr -> next;
            delete curr;
        }
        else {
            st.insert(curr -> data); prv = curr;
        }
        curr = prv -> next;
    } */
}
void removeallDup(node *&head) {
    node *dummy = new node;
    dummy -> next = head;
    node *prv = dummy, *curr = head;
    while(curr) {
        while(curr -> next && prv -> next -> data == curr -> next -> data) curr = curr -> next;
        if(prv -> next == curr) prv = prv -> next;
        else prv -> next = curr -> next;
        curr = curr -> next;
    }
    head = dummy -> next;
    delete head;
}
void printUnique(Node* head) {
    unordered_set<int> seen;
    while (head) {
        if (seen.find(head->data) == seen.end()) {
            cout << head->data << " ";
            seen.insert(head->data);
        }
        head = head->next;
    }
    cout << endl;
}
node *deletedup(node *head) {
    if(!head) return head;
    set <int> st; 
    node *curr = head, *prv = NULL;
    while(curr) {
        if(st.count(curr -> val)) 
            prv -> next = curr -> next;
        else {
            st.insert(curr -> val); prv = curr;
        }
        curr = curr -> next;
    }
    return head;
}
void removedup(node *head) {
    node *curr = head;
    while(curr && curr -> next) {
        if(curr -> data == curr -> next -> data) {
            node *tmp = curr -> next -> next;
            delete curr -> next; curr -> next = tmp;
        }
        else curr = curr -> next;
    }
}
node *removeDup(node *head) {
    if(!head) return head;
    node *prv = head, *curr = head -> next;
    while(curr) {
        if(curr -> data != prv -> data) {
            prv -> next = curr; prv = curr;
        }
        curr = curr -> next;
    }
    prv -> next = nullptr;
    return head;
}
void removeDup(node *head) {
    if(!head || !head -> next) return;
    if(head -> data == head -> next -> data) {
        node *del = head -> next;
        head -> next = head -> next -> next;
        delete(del);
        removeDup(head);
    }
    else removeDup(head -> next);
}
void removeDup(node *head) {
    node *curr = head;
    while(curr && curr -> next) {
        node *tmp = curr;
        while(tmp -> next) {
            if(curr -> data == tmp -> next -> data) {
                node *dup = tmp -> next;
                tmp -> next = tmp -> next -> next;
                delete dup;
            }
            else tmp = tmp -> next;
        }
    }
}
// delete mid node
struct node {
    int x, y; node *next;
};
void push(node **head, int x, int y) {
    node *newnode = new node();
    newnode -> x = x; newnode -> y = y;
    newnode -> next = *head;
    *head = newnode;
}
void deletenode(node *prv, node *del) {
    prv -> next = del -> next;
    delete del;
}
node *removemidpoint(node *head) {
    if (!head || !head->next || !head->next->next) return head;
    node *prv = head, *curr = head -> next;
    while(curr && curr -> next) {
        bool isHorizontal = (prv -> y == curr -> y);
        bool isVertical = (prev -> x == curr -> x);
        if (isHorizontal || isVertical) {
            // Remove middle points on same line
            while (curr -> next && 
                   ((isHorizontal && curr->y == curr->next->y) ||
                    (isVertical && curr->x == curr->next->x))) {
                deleteNode(prev, curr);
                curr = prev->next;
            }
        }
        prv = curr; curr = curr->next;
    }
    return head;
}
Node* removeMiddlePoints(Node* head) {
    if (!head || !head->next || !head->next->next) return head;
    
    Node* prev = head;
    while (prev && prev->next && prev->next->next) {
        Node* curr = prev->next;
        // Vertical line
        if (prev->x == curr->x) {
            while (curr->next && curr->x == curr->next->x) {
                Node* next = curr->next;
                prev->next = next;
                delete curr;
                curr = next;
            }
        }
        // Horizontal line  
        else if (prev->y == curr->y) {
            while (curr->next && curr->y == curr->next->y) {
                Node* next = curr->next;
                prev->next = next;
                delete curr;
                curr = next;
            }
        }
        prev = curr;
    }
    return head;
}
