// apply() | sum() | swap() | shift() | cshift
#include<iostream>
#include<valarray> 
using namespace std;
void print(valarray<int>val)
{
    for(int i=0; i<val.size(); i++)
    {
        cout<<val[i]<<" ";
    }
}
int main()
{
    valarray<int> varr = { 10, 2, 20, 1, 30 };
    valarray<int> varr1, varr2, varr3, varr4;
    
    varr1 = varr.apply([](int x){return x=x+5;});

    cout << "\nImposed apply(),varr1 is: ";
    print(varr1);
    cout << "\nSum of varr is: " <<varr.sum();

    cout << "\nSum of varr1 is: "<<varr1.sum();
    
    cout<<"\nBefore swap varr is: ";
    print(varr);
    cout<<"\nBefore swap varr1 is: ";
    print(varr1);
    
    //varr.swap(varr1);
    swap(varr,varr1);
    cout<<"\nAfter swap varr is: ";
    print(varr);
    cout<<"\nAfter swap varr1 is: ";
    print(varr1);
    
    varr2 = varr.shift(-2);
    varr3 = varr.cshift(-3);
    varr4 = varr.cshift(3);
    cout<<"\nAfter shift varr2 is: ";
    print(varr2);
    cout<<"\nAfter cshift varr3 is: ";
    print(varr3);
    cout<<"\nAfter cshift varr4 is: ";
    print(varr4);
    
    return 0; 
}
