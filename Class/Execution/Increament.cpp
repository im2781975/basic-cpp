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
// operator overloading using dot operator
class Complex{
    int real, img;
    public:
    Complex(int real, int img){
        this->real = real;
        this->img = img;
    }
    void print(){
        cout << real << " +i" << img << "\n";
    }
    Complex operator + (Complex b){
        Complex c(0, 0);
        c.real = this->real + b.real;
        c.img = this->img + b.img;
        return c;
    }
    friend Complex operator +(Complex &, Complex &);
};
Complex operator+(Complex &a, Complex &b){
    return Complex(a.real + b.real, a.img + b.img);
}
int main(){
    Complex a(8 , 9);
    Complex b(6, 9);
    Complex c = a + b;
    c.print();
    
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
