#include<bits/stdc++.h>
using namespace std;
void print(queue <int> q) {
    queue <int> tmp = q;
    while(!tmp.empty()) {
        cout << tmp.front() << " "; tmp.pop();
    } cout << endl;
}
void queu() {
    queue <int> p, q;
    for(int i = 1; i < 6; i++) {
        q.push(i * 2); p.push(i * 3);
    }
    print(q); print(p);
    cout << q.size() << " " << q.front() << " " << q.back() << endl;
    q.pop(); q.swap(p);
    cout << q.empty() << endl;
    queue <char> pq; pq.push('a'); pq.push('b');
    cout << pq.size() << " " << pq.front() << " " << pq.back() << endl;
    pq.pop(); cout << pq.empty() << endl;
}
void Binaryrepr(int n) {
    deque <string> dq;
    dq.push_back("1");
    for(int i = 1; i <= n; i++) {
        cout << dq.front() << endl;
        string tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp + "0");
        dq.push_back(tmp + "1");
    }
    queue <string> q; q.push("1");
    for(int i = 1; i <= n; i++) {
        cout << q.front() << endl;
        string tmp = q.front(); q.pop();
        q.push(tmp + "0"); q.push(tmp + "1");
    }
}
void ladderarr(int n) {
    deque <int> ladder;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        ladder.push_back(x);
    }
    sort(ladder.begin(), ladder.end());
    while(!ladder.empty()) {
        cout << ladder.front() << " "; ladder.pop_front();
    }
    cout << endl;
}
void print(deque <int> dq) {
    deque <int> ::iterator it = dq.begin();
    while(it != dq.end()) {
        cout << *it << " "; it++;
    }
}
void deque() {
    deque <int> dq;
    for(int i = 1; i <= 10; i++) {
        dq.push_front(i * 2); dq.push_back(i * 3);
    }
    cout << dq.size() << " " << dq.max_size() << " " << dq.at(3) << endl;
    cout << dq.front() << " " << dq.back() << endl;
    dq.pop_front(); dq.pop_back();
    cout << *max_element(dq.begin(), dq.end()) << endl;
    cout << *min_element(dq.begin(), dq.end());
    reverse(dq.begin(), dq.end());
}
void print(priority_queue<int>& pq)
{
    priority_queue<int> temp=pq;
    while (!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
}
void print(priority_queue <int> pq) {
    priority_queue <int> tmp = pq;
    while(!tmp.empty()) {
        cout << tmp.top() << " "; tmp.pop();
    } cout << endl;
}
void priorityQ() {
    int dig; string ing;
    priority_queue <int> p;
    priority_queue <string> q;
    dig = 20; cout << dig << endl;
    p.push(dig); dig = 30; p.push(dig);
    cout << p.top() << endl;
    
    ing = "Hello"; cout << ing << endl;
    q.push(ing); ing = "Hi"; q.push(ing);
    cout << q.top() << endl;
    
    priority_queue <int> x;
    int arr[6] = {10, 11, 12, 13, 14, 15};
    for(int i = 0; i < 6; i++) pq.push(arr[i]);
    x.swap(p);
    cout << x.size() << " " << x.top() << endl;
    x.pop();
    x = priority_queue <int> ();
    for(int i = 15; i <= 22; i++) x.emplace(i);
    swap(p, x);
    priority_queue <int, vector <int>,
    greater <int>> gq(arr, arr + 6);
    while(!gq.empty()) {
        cout << gq.top() << " ";
        gq.pop();
    }
}
