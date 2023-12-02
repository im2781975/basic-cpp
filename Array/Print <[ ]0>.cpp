#include <iostream>
using namespace std;
void print_arr()
{
    
    int a[] { 40,50,60,70, 80,90 };
    
    cout<< "\nElements of [] : ";
    
    for (auto element: a)
        cout << element << " ";
}

void condition()
{
    cout<<"\nConditional [] : ";
    for (int i=0, j=10, k=20;(i+j+k) <100; j++, k--, i += k)
    {
        cout <<"i="<< i << " " << " j="<<j << " " << "k="<<k <<"\n";
    }
}
 
void display()
{
    int arr[5];

    for (int i = 0; i < 7; i++) 
        arr[i] = i * i - 2 * i + 1;

    cout<<"\nEnter elements: ";
    for (int i = 0; i < 7; i++) 
    
      cout<< arr[i] << " ";
}
int main()
{
    print_arr();
    
    condition();

    display();
    
    return 0;
}
