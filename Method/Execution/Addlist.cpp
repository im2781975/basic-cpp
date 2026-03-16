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
