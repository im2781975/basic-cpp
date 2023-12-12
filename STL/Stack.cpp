#include <iostream>
#include <stack>
using namespace std;
void reverseStack(stack<int>& originalStack) {
    stack<int> tempStack;

    while (!originalStack.empty()) {
        int temp = originalStack.top();
        originalStack.pop();
        tempStack.push(temp);
    }

    while (!tempStack.empty()) {
        int temp = tempStack.top();
        tempStack.pop();
        originalStack.push(temp);
    }
}
void decrease_size(stack<int>& s) {
    int array_cap = s.size(); // Get the current array capacity
    int stack_size = 0;
    stack<int> temp_stack;
    
    while (!s.empty()) {
        temp_stack.push(s.top());
        s.pop();
        stack_size++;
    }
    // Check if stack_size is less than array_cap/2
    if (stack_size < array_cap / 2) {
        int new_array_cap = array_cap / 2;
        stack<int> new_stack;
        while (!temp_stack.empty() && new_stack.size() < new_array_cap) {
            new_stack.push(temp_stack.top());
            temp_stack.pop();
        }
        // Copy elements from the new_stack to the original stack
        while (!new_stack.empty()) {
            s.push(new_stack.top());
            new_stack.pop();
        }
    }
}
void sort_stack(stack<int>& s) {
    stack<int> temp_stack;
    
    while (!s.empty()) {
        int temp = s.top();
        s.pop();

        while (!temp_stack.empty() && temp_stack.top() > temp) {
            s.push(temp_stack.top());
            temp_stack.pop();
        }

        temp_stack.push(temp);
    }
    // Copy elements back to the original stack
    while (!temp_stack.empty()) {
        s.push(temp_stack.top());
        temp_stack.pop();
    }
}
void print(stack<int>s)
{
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}
void print(stack<char>s)
{
    while(s.empty() == false)
    {
        cout << s.top() << " ";
        s.pop();
    }
}
int main() {
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);
    int n=5;
    s.push(n);
    sort_stack(s);
    cout<<"\nStack size(): "<<s.size();
    cout<<"\nElements are: ";
    print(s);
    cout<<"\nElements after reverse: ";
    reverseStack(s);
    print(s);
    return 0;
}
