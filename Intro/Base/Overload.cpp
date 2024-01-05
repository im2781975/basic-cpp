#include <iostream>
using namespace std;
void test(int var)
{
    cout<<"\nInteger number: "<<var;
}
void test(float var)
{
    cout <<"\nFloat number: "<< var;
}
void test(int var1, float var2)
{
    cout << "\nInteger & float number is: " << var1 <<" , " <<var2;
}
void test(char var)
{
    cout<<"\nChar value: "<<var ;
}
void print(int i)
{
    cout <<"\nHere is int " << i;
}
void print(double f)
{
    cout << "\nHere is float " << f;
}
void print(char const* c)
{
    cout << "\nHere is char* " << c;
}
void print(float s,float t)
{
    cout << "\nFunction with float called ";
}
void print(int s,int t)
{
    cout << "\nFunction with int called ";
}
int main()
{
    int a = 5;
    float b = 5.5;
    char c='a';
    test(a);
    test(b);
    test(a, b);
    test(c);
    print(10);
    print(10.10);
    print("ten");
    print (3.7f,9.8f);
    return 0;
}
