// Difference between pre & post increment overload operator
#include <bits/stdc++.h>
using namespace std;
class Base{
    int count;
    public:
    Base(int i):count(i){}
    Base operator++(int){
        return (count++);
    }
    Base operator++(){
        count += 1;
        return count;
    }
    void Display(){
        cout << "count: " << count << "\n";
    }
};
int main(){
    Base i(5);
    Base post(5);
    Base pre(5);
 
    pre = ++i;
    cout << "Result of i is: ";
    i.Display();
    cout <<"\nResult of Pre Incr is: ";
    pre.Display();
    //Increament Of the value
    i++; 
    i++;
    post = i++;
    
    cout << "\nResults of post increment : ";
    post.Display();
    cout << "\nAnd results of i , here we see difference: ";
    i.Display();
}
