#include <bits/stdc++.h> 
using namespace std; 
class cls
{   
    int x;   
}; 
struct gfg 
{ 
  int z; 
  float d; 
  char s[20]; 
}s; 
union un
{ 
    int z; 
    double d; 
}u; 
int main()   
{   
    cls c;   
    cout <<"Size of class std is in bytes  : " << sizeof(c);
    cout << "\nSize of structure is :" <<  sizeof(s) ;
    cout << "\nSize of union is: "<<sizeof(u) ;
  return 0;   
}

