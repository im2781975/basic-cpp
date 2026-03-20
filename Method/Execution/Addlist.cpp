#include<bits/stdc++.h>
using namespace std;
struct node {
    public:
    int data; node *next;
};
node *create(int val) {
    node *newnode = new node(val);
    newnode -> next = NULL;
    return newnode;
}
node *reverse(node *head) {
    node *prv = NULL, *curr = head, *next;
    while(curr) {
        next = curr -> next;
        curr -> next = prv;
        prv = curr; curr = next;
    }
    return prv;
}
node *reverse(node *head) {
    if(head == NULL || head -> next == NULL) return head;
    node *res = reverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return res;
}
void push(node **head, int val) {
    node *newnode = create(val);
    newnode -> next = *head;
    *head = newnode;
}
void insertafter(node *prv, int data) {
    if(!prv) return;
    node *newnode = create(val);
    newnode -> next = prv -> next;
    prv -> next = newnode;
}
node *addOne(node *head) {
    head = reverse(head);
    node *curr = head; int carry = 1;
    while(curr && carry) {
        int sum = curr -> data + carry;
        curr -> data = sum % 10;
        carry = sum / 10;
        curr = curr -> next;
    }
    // if(carry) push(&head, 1);
    if(carry) {
        node *newnode = create(1);
        newnode -> next = head;
        head = newnode;
    }
    return reverse(head);
}
int addwith(node *head) {
    if(head == NULL) return 1;
    int res = head -> data + addwith(head -> next);
    head -> data = res % 10;
    return (res / 10);
}
node *addOne(node *head) {
    int carry = addwith(head);
    if(carry) {
        node *newnode = create(carry);
        newnode -> next = head;
        return newnode;
    }
    return head;
}
node *addTwolist(node *x, node *y) {
    node *res = NULL, *prv = NULL, *tmp;
    int carry = 0, sum;
    while(x != NULL || y != NULL) {
        sum = carry + (x ? x -> data : 0) + (y ? y -> data : 0);
        carry = (sum >= 10) ? 1 : 0;
        sum = sum % 10;
        tmp = create(sum);
        if(res == NULL) res = tmp;
        else prv -> next = tmp;
        prv = tmp;
        if(x) x = x -> next;
        if(y) y = y -> next;
    }
    if(carry > 0) tmp -> next = create(carry);
    return res;
}
node *addTwolist(node *x, node *y) {
    // x = reverse(x); y = reverse(y);
    node dummy(0);
    node *tail = &dummy;
    int carry = 0;
    while(x || y || carry) {
        int sum = carry;
        if(x) sum += x -> data, x = x -> next;
        if(y) sum += y -> data, y = y -> next;
        carry = sum / 10;
        tail -> next = create(sum % 10);
        tail = tail -> next;
    }
    // return reverse(dummy.next);
    return dummy.next;
}
void printlist(node *head) {
    while(head) {
        cout << head -> data << " ";
        head = head -> next;
    }
}
class node {
    public:
    int data; node *next;
};
void push(node **head, int val) {
    node *newnode = new node{val, *head};
    *head = newnode;
}
// Insert at beginning of circular list
void pushcircular(node *&head, int val) {
    node *newnode = new node{data, head};
    if(!head) head = newnode;
    else {
        node *tail = head;
        while(tail -> next != head) tail = tail -> next;
        tail -> next = newnode;
    }
    head = newnode;
}
void deletelist(node **head) {
    node *curr = *head;
    while(curr) {
        node *tmp = curr -> next;
        delete curr; curr = curr -> next;
    }
    *head = nullptr;
}
void deletenode(node **head, int pos) {
    if(!*head || pos < 0) return;
    if(pos == 0) {
        node *tmp = *head;
        *head = (*head) -> next;
        delete tmp; return;
    }
    node *curr = head;
    for(int i = 0; i < pos - 1 && curr -> next; ++i) curr = curr -> next;
    if(curr -> next) {
        node *tmp = curr -> next;
        curr -> next = tmp -> next;
        delete tmp;
    }
}
void deletenode(node *head) {
    if(head == NULL) return;
    else {
        node *tmp = head -> next;
        head -> data = tmp -> data;
        head -> next = tmp -> next;
        tmp = NULL;
    }
}
void deleteOddnode(node *head) {
    if(!head) return;
    node *curr = head;
    node *tmp = curr -> next;
    while(curr && tmp) {
        curr -> next = tmp -> next; delete(tmp);
        curr = curr -> next;
        if(curr) tmp = curr -> next;
    }
}
void deleteAlt(Node *head) {
    if (!head || !head->next) return;
    
    Node* prev = head;
    while (prev && prev->next) {
        prev->next = prev->next->next;
        prev = prev->next;
    }
}
void deleteOddnode(node *head) {
    if(!head || !head -> next) return;
    node *curr = head;
    while(curr && curr -> next) {
        curr -> next = curr -> next -> next;
        curr = curr -> next;
    }
}
void deleteOddnode(node *head) {
    if(!head || !head -> next) return;
    head -> next = head -> next -> next;
    delete head -> next;
    deleteOddnode(head -> next);
}
void deletekey(node **head, int key) {
    if(!*head) return;
    if((*head) -> data == key) {
        node *tmp = *head;
        *head = tmp -> next;
        delete tmp; return;
    }
    node *curr = *head;
    while(curr -> next && curr -> next -> data != key) curr = curr -> next;
    if(curr -> next) {
        node *tmp = curr -> next;
        curr -> next = tmp -> next;
        delete tmp;
    }
}
node *deletekthnode(node *head, int k) {
    if(!head || k <= 0) return nullptr;
    if(k == 1) {
        while(head) {
            node *tmp = head;
            head = head -> next; delete tmp;
        }
        return nullptr;
    }
    node *curr = head, *prv = nullptr;
    /* int cnt = 0;
    while(curr != NULL) {
        cnt++;
        if(k == cnt) {
            delete prv -> next;
            prv -> next = curr -> next;
            cnt = 0;
        }
        if(cnt != 0) prv = curr;
        curr = prv -> next;
    } */
    while(curr) {
        for(int i = 1; i < k && curr -> next; i++) {
            prv = curr; curr = curr -> next;
        }
        if(!curr -> next) break;
        prv -> next = curr -> next -> next;
        delete curr -> next;
        curr = prv -> next;
    }
    return head;
}
void append(node **head, int val) {
    node *newnode = new node(data, nullptr);
    if(!*head) {
        *head = newnode; return;
    }
    node *curr = *head;
    while(curr -> next) curr = curr -> next;
    curr -> next = newnode;
}
void makecircular(node *head) {
    node *curr = head;
    while(curr -> next != NULL) curr = curr -> next;
    curr -> next = head;
}
node *swapfirstlast(node *head) {
    if(!head || head -> next == head) return head;
    node *curr = head, *tmp = curr -> next;
    while(tmp -> next != head) {
        curr = tmp; tmp = tmp -> next;
    }
    if(curr == head) {
        tmp -> next = head; head -> next = tmp;
        return tmp;
    }
    curr -> next = head;
    head -> next = tmp -> next;
    tmp -> next = head;
    return tmp;
}
bool isCircular(node *head) { 
    if (head == nullptr) return false;
    node *slow = head;
    node *fast = head -> next;
    while(fast != nullptr && fast -> next != nullptr) {
        if(slow == fast) return true;
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return false;
}
