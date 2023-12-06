// generate () | generate_n()
#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

int gen() 
{ 
    static int i = 0; 
    return ++i; 
} 
using namespace std; 
int main() 
{
    vector<int> v(5); 
    generate(v.begin(), v.end(), gen); 
    
    cout<<"After impose generate(): ";
    vector<int>::iterator it; 
    for (it = v.begin(); it != v.end(); ++it) { 
        cout << *it << " "; 
    }
    
    cout<<"\nAfter impose generate_n(): ";
    generate_n(v.begin(),5,gen);
    for(it=v.begin(); it!=v.end(); it++)
    {
        cout<<*it<<" ";
    }
    return 0; 
} 
