//push() | pop() | swap() | size() | front() | back() | swap() empty() 
#include <iostream>
#include <queue>
using namespace std;
 
void print_queue(queue<int> q)
{
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front()<<" ";
        temp.pop();
    }
}
void print_queue(queue<char> q)
{
    queue<char> temp = q;
    while (!temp.empty()) {
        cout << temp.front()<<" ";
        temp.pop();
    }
}
int main()
{
    queue<int> q1;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    cout <<"First queue is : ";
    print_queue(q1);
   
    queue<int> q2;
    q2.push(4);
    q2.push(5);
    q2.push(6);
 
    cout<<"\nSecond queue is : ";
    print_queue(q2);

    cout <<"\nQueue size() : "<<q1.size();
   
    cout << "\nQueue front() : " <<   q1.front();
    cout << "\nQueue back() : " <<   q1.back();
   
    cout <<"\nAfter Queue pop() :";
    q1.pop();
    print_queue(q1);
   
    q1.swap(q2);
    cout << "\nAfter swap() first queue is: ";
    print_queue(q1);
    cout << "\nAfter swap() second queue is: ";
    print_queue(q2);
    cout<<"\nis empty: ";
    cout<<q1.empty(); 
    
    queue<char>q;
    q.push('a');
    q.push('b');
    q.push('c');
    cout<<"\nElements of queue is: ";
    print_queue(q);
    cout<<"\nq.front: "<<q.front();
    q.pop();
    q.pop();

    cout<<"\nAfter pop() q.front(): "<<q.front() ;
    cout<<"\nAfter pop() queue_print(): ";
    print_queue(q);
    return 0;
}
