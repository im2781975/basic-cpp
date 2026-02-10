#include<bits/stdc++.h>
using namespace std;
void print(list <int> &lst) {
    list <int> ::iterator it;
    it = lst.begin();
    while(it != lst.end()) {
        cout << *it << " "; ++it;
    }
}
void Insert(list <int> lst, int idx, int val) {
    auto it = lst.begin(); advance(it, idx);
    lst.insert(it, val);
}
void Delete(list <int> lst, int idx) {
    auto it = lst.begin(); advance(it, idx);
    lst.erase(it);
}
int deleteval(list <int> lst, int val) {
    list <int> ::iterator it;
    for(it = lst.begin(); it != lst.end();){
        if(*it == val) it = lst.erase(it);
        else ++it;
    }
}
void File() {
    list <int> x, y, z;
    list <int> ::iterator it;
    for(int i = 1; i < 10; i++) {
        x.push_back(i * 2); y.push_back(i * 3);
    }
    x.swap(y);
    it = x.begin();
    advance(it, 2); x.unique();
    x.splice(it, y); 
    cout << x.front() << " " << x.back();
    x.pop_front();    x.pop_back();.
    x.push_front(15); x.push_back(20);
    Insert(x, 1, 100); Delete(y, 2);
    x.reverse();    y.sort();
    x.remove_if([](int a) {return a % 2 != 0;});
    cout << x.size() << " ";
    for(int i = 1; i <= 10; i++) z.emplace_back(i)
    for(int i = 2; i <= 20; i += 2) z.emplace_front(i);
    it = z.begin(); advance(it, 3);
    z.emplace(it, 100);
    deleteval(z, 100);
}
int getval(list <int> lst, int idx) {
    list <int> ::iterator it = lst.begin();
    advance(it, idx);
    while(it != lst.end()) return *it;
    return -1;
}
bool search(list <int> lst, int val) {
    list <int> ::iterator it = lst.begin();
    while(it != lst.end()) {
        if(*it == val) return true;
        it++;
    }
    return false;
}
void forwardList() {
    forward_list <int> x, y, z;
    forward_list <int> ::iterator it;
    x.assign({1, 2, 3}); x.assign(5, 10);
    y.assign(x.begin(), x.end()); z = x;
    x.splice_after(x.begin(), z);
    x.merge(z); x.sort(); x.unique();
    it = x.insert_after(x.begin(), {1, 2, 3});
    it = x.erase_after(it);
    // it = x.erase_after(x.begin(), x.end());
    x.remove(5);
    y.remove_if([](int a) {return a % 2 != 0;});
    y.clear();
    int idx = 3; cout << getval(x, idx);
    cout << (search(lst, 3) ? "True" : "False");
}

