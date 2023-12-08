#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    deque<string> dq;
    dq.push_back("1");
    cout<<"Imposed dequeue binary rep: ";
    for (int i = 1; i <= n; i++)
    {
        cout << "\nBinary representation of " << i << ": " <<dq.front();
        string tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp + "0");
        dq.push_back(tmp + "1");
    }
    queue<string> q;
    q.push("1");
    cout<<"\nBased queue binary rep: ";
    for (int i = 1; i <= n; i++)
    {
        cout << "\nBinary representation of " << i << ": " << q.front();
        string tmp = q.front();
        q.pop();
        q.push(tmp + "0");
        q.push(tmp + "1");
    }
    return 0;
}
