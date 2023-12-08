#include <bits/stdc++.h>
using namespace std;

void print(priority_queue<int>& pq)
{
    priority_queue<int> temp=pq;
    while (!temp.empty()){
        cout << temp.top() << " ";
        temp.pop();
    }
}

int main()
{
    priority_queue<int> pq1;
    priority_queue<int> pq2;
    int arr[6]={10,11,12,13,14,15};
    for(int i=0; i<6; i++)
    {
        pq1.push(arr[i]);
    }
    pq1.push(1);
    pq1.push(2);
    pq1.push(3);
    pq1.push(4);

    pq2.push(3);
    pq2.push(5);
    pq2.push(7);
    pq2.push(9);
    cout << "Before swap() pq1: ";
    print(pq1);
    cout <<"\nBefore swap() pq2: ";
    print(pq2); 

    cout << "\npq1.size(): " << pq1.size();
    cout << "\npq1.top(): " << pq1.top();
    cout << "\npq1.pop(): ";
    pq1.pop();
    print(pq1);
    
    pq2 = priority_queue<int>(); 
    
    // Clear the priority queue by 
    pq2.emplace(15);
    pq2.emplace(16);
    pq2.emplace(17);
    pq2.emplace(18);
    pq2.emplace(19);
    pq2.emplace(20);
    print(pq2);
    swap(pq1,pq2);
    cout << "\nAfter swap() pq1: ";
    print(pq1);

    cout << "\nAfter swap() pq2: ";
    print(pq2); 
}
