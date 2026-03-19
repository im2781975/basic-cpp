#include<bits/stdc++.h>
using namespace std;
struct node {
    int data;
    node *left, *right;
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};
node *create(int val) {
    return new node(val);
}
void rightview(node *root) {
    if(!root) return;
    queue <node*> q; q.push(root);
    while(!q.empty()) {
        int sz = q.size(); 
        node *last = nullptr;
        while(sz--) {
            node *cur = q.front(); q.pop();
            last = cur;
            if(cur -> left) q.push(cur -> left);
            if(cur -> right) q.push(cur -> right)
        }
        cout << last -> data << " ";
    }
}
void rightview(node *root, int level = 1, int maxl = 0) {
    static int ml = 0;
    if(!root || level <= ml) return;
    cout << root -> data << " "; ml = level;
    rightview(root -> right, level + 1, maxl);
    rightview(root -> left, level + 1, maxl);
}
// morris traversal
vector <int> rightview(node *root) {
    vector <int> res;
    node *curr = root;
    while(curr) {
        if(!curr -> right){
            res.push_back(curr -> val);
            curr = curr -> left;
        }
        else {
            node *tmp = curr -> right;
            while(tmp -> left && tmp -> left != curr) tmp = tmp -> left;
            if(!tmp -> left) {
                tmp -> left = curr;
                curr = curr -> right;
            }
            else {
                tmp -> left = nullptr;
                res.push_back(curr -> val);
                curr = curr -> left;
            }
        }
    }
    return res;
}
void leftview(node *root) {
    if(!root) return;
    queue <node*> q; q.push(root);
    while(!q.empty()) {
        int sz = q.size(); 
        node *last = nullptr;
        while(sz--) {
            node *cur = q.front(); q.pop();
            if(!last) last = cur;
            if(cur -> left) q.push(cur -> left);
            if(cur -> right) q.push(cur -> right)
        }
        cout << last -> data << " ";
    }
}
node *buildTree(vector <int> arr, int idx) { /*
    vector <int> arr = {1, 2, 4, -1, -1, 5, -1, -1, 3, 6, -1, -1, 7, -1, -1};
    int idx = 0;
    node* root = buildTree(arr, idx);
    levelOrder(root); */
    if(idx >= arr.size() || arr[idx] == -1) {
        idx++; return nullptr;
    }
    node *root = create(arr[idx++]);
    root -> left = buildTree(arr, idx);
    root -> right = buildTree(arr, idx);
    return root;
}
void levelorder(node *root) {
    if(!root) return;
    queue <node*> q; q.push(root);
    while(!q.empty()) {
        node *curr = q.front(); q.pop();
        cout << curr -> data << " ";
        if(curr -> left) q.push(curr -> left);
        if(curr -> right) q.push(curr -> right);
    }
}
void inorder(node *root) {
    if(root) {
        inorder(root -> left);
        cout << root -> data << " ";
        inorder(root -> right);
    }
}
void preorder(node *root) {
    if(root) {
        cout << root -> data << " ";
        preorder(root -> left);
        preorder(root -> right);
    }
}
void postorder(node *root) {
    if(root) {
        postorder(root -> left);
        postorder(root -> right);
        cout << root -> data << " ";
    }
}
int mindepth(node *root) {
    if(!root) return 0;
    if(!root -> left && !root -> right) return 1;
    int l = root -> left ? mindepth(root -> left) : INT_MAX;
    int r = root -> right ? mindepth(root -> right) : INT_MAX;
    return min(l, r) + 1;
}
int mindepth(node *root) {
    if(!root) return 0;
    queue <node*> q; q.push(root);
    int depth = 0;
    while(!q.empty()) {
        depth++;
        int sz = q.size();
        while(sz--) {
            node *curr = q.front(); q.pop();
            if(!curr -> left && !curr -> right) return depth;
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
            
        }
    }
    return depth;
}
struct qItem {
    node *nd;
    int depth;
};
int minDepth(node* root) {
    if (!root) return 0;
    queue <qItem> q; q.push({root, 1});
    while (!q.empty()) {
        qItem curr = q.front(); q.pop();
       
        if (!curr.nd -> left && !curr.nd -> right) return curr.depth;
        if(curr.nd -> left) q.push({curr.nd -> left, curr.depth + 1});
        if(curr.nd -> right) q.push({curr.nd -> right, curr.depth + 1});
    }
    return 0;

// Iterative function to print all nodes between two given levels in a binary Node
void printnode(node *root, int start, int end) {
    if(root == NULL) return;
    queue <node*> q; q.push(root);
    int level = 0;
    while(!q.empty()) {
        level++; int sz = q.size();
        while(sz != 0) {
            node *curr = q.front(); q.pop();
            if(level >= start && level <= end) cout << curr -> data << " ";
            if(curr -> left) q.push(curr -> left);
            if(curr -> right) q.push(curr -> right);
            sz--;
        }
        if(level >= start && level <= end) cout << endl;
    }
}
void printnode(node *root, int start, int end, vector <vector <int>> res, int level) {
    if(root == NULL) return;
    printnode(root ->left, start, end, res, level + 1);
    if(level >= start && level <= end) 
        res[level - start].push_back(root -> data)
    printnode(root ->right, start, end, res, level + 1);
}
int maxnodelevel(node *root) {
    if(!root) return -1;
    queue <node*> q; q.push(root);
    int level = 0, maxnode = 0, res = 0;
    while (!q.empty()) {
        int size = q.size();
        if (size > maxnode) {
            maxnode = size;
            res = level;
        }
        while(size--) {
            node *tmp = q.front(); q.pop();
            if(tmp -> left) q.push(tmp -> left);
            if(tmp -> right) q.push(tmp -> right);
        }
        level++;
    }
    return res;
}
// find the level having maximum number of Nodes
int maxnodelevel(node *root) {
    unordered_map <int, int> levelcnt;
    function <void(node*, int)> dfs = [&](node *tmp, int depth) {
        if(!tmp) return;
        levelcnt[depth]++;
        dfs(tmp -> left, depth + 1);
        dfs(tmp -> right, depth + 1);
    }
    dfs(root, 0);
    int maxCount = 0, maxLevel = 0;
    for(auto& [level, count] : levelcnt) {
        if(count > maxCount) {
            maxCount = count;
            maxLevel = level;
        }
    }
    return maxLevel;
}
class node {
    public:
    int data;
    node *next, *prv;
    node(int val) : data(val), next(nullptr), prv(nullptr) {}
}
node *push(node *&head, int val) {
    node *newnode = new node(val);
    newnode -> next = head;
    if(head) head -> prv = newnode;
    head = newnode; return head;
}
node *revgroups(node *head, int k) {
    node *curr = head, *chief = nullptr;
    int cnt = 0;
    while(curr && cnt < k) {
        node *tmp = curr -> next;
        push(chief, curr -> data);
        curr = tmp; cnt++;
    }
    if(curr) {
        head -> next = revgroups(curr, k);
        if(head -> next) head -> next -> prv = head;
    }
    chief -> prv = nullptr; return chief;
}
node *revgroups(node *head, int k) {
    if(!head) return head;
    node *curr = head;
    node *res = nullptr, *prvgrptail = nullptr;
    while(curr) {
        node *grphead = nullptr;
        node *grptail = curr;
        int cnt = 0;
        while(curr && cnt < k) {
            node *tmp = curr -> next;
            curr -> next = grphead;
            curr -> prv = tmp;
            grphead = curr; curr = tmp;
            cnt++;
        }
        if(!res) {
            res = grphead; res -> prv = nullptr;
        }
        else {
            prvgrptail -> next = grphead;
            grphead -> prv = prvgrptail;
        }
        prvgrptail = grptail;
    }
    return res;
}
node *revgroups(node *head, int k) {
    if(!head) return;
    node *chief = nullptr, *curr = head;
    int cnt = 0;
    while(curr && cnt < k) {
        node *tmp = curr -> next;
        curr -> next = chief;
        curr -> prv = tmp;
        chief = curr; curr = tmp; cnt++;
    }
    if(curr) {
        node *res = revgroups(curr, k);
        chief -> next = res;
        if(res) res -> prv = chief;
    }
    return chief;
}
void rev(node *&head) {
    node *curr = head;
    while(curr) {
        swap(curr -> next, curr -> prv);
        curr = curr -> prv;
    }
    if(head) head = head -> prv;
}
node *rev() {
    if(!head) return head;
    stack <int> st;
    node *curr = head;
    while(curr != NULL) {
        st.push(curr -> data) curr = curr -> next;
    }
    curr = head;
    while(curr) {
        curr -> data = st.top(); st.pop();
        curr = curr -> next;
    }
    return head;
}
node *insertatend(node *head, int data) {
    node *newnode = new node(data);
    if(!head) return newnode;
    node *tail = head;
    while(tail -> next) tail = tail -> next;
    tail -> next = newnode;
    newnode -> prv = tail; return head;
}
node *gethead() { return head; }
void rotate(node *&head, int pos) {
    if(!head || pos == 0) return;
    node *curr = head;
    for(int i = 0; i < pos && curr; i++) { curr = curr -> next;
        if(!curr) return;
    }
    if(!curr) return;
    node *tmp = head;
    while(tmp -> next) tmp = tmp -> next;
    tmp -> next = head; head -> prv = tmp;
    if(curr -> prv) curr -> prv -> next = nullptr;
    curr -> prv = nullptr;
    head = curr;
}
// convert a given Binary tree to Doubly Linked List
void BTtoDLL(node *root, node *&head) {
    if(root == NULL) return;
    BTtoDLL(root -> right, head);
    root -> right = head;
    if(head != NULL) head -> left = root;
    head = root;
    BTtoDLL(root -> left, head);
}
node *concat(node *left, node *right) {
    if(!left) return right;
    if(!right) return left;
    node *lefttail = left -> prv;
    node *righttail = right -> next;
    
    lefttail -> next = right;
    right -> prv = lefttail;
    left -> prv = righttail;
    righttail -> next = left;
    return left;
}
node *BTtoDLL(node *root) {
    if(!root) return nullptr;
    node *left = BTtoDLL(root -> prv);
    node *right = BTtoDLL(root -> next);
    root -> prv = root -> next = root;
    return concat(concat(left, root), right);
}
void disp(node *head) {
    if(!head) return;
    node *curr = head;
    do {
        cout << curr -> data << " ";
        curr = curr -> next;
    } while(curr != head);
    cout << " ";
}
