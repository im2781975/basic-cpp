#include<bits/stdc++.h>
using namespace std;
int main()
{
    int *p; 
    int (*ptr)[5]; 
    int arr[5];
    p = arr;
    
    ptr = &arr; 
    
    cout<< "Address is: \n";
    for(int i= 0; i< 5; i++)
    {
        cout << "p =" << p <<", ptr = "<< ptr<< "\n";
        p++; 
        ptr++;
    }
    cout << "sizeof(p) : "<< sizeof(p) <<
            ", sizeof(*p) : " << sizeof(*p) ;
    cout << "\nsizeof(ptr): "<< sizeof(ptr) <<", sizeof(*ptr): " << sizeof(*ptr) ;
     
    int ar[3][4] = { {10, 11, 12, 13}, {20, 21, 22, 23}, 
        {30, 31, 32, 33} };
    int (*pr)[4];
    pr = ar;
    cout<< "\nAddress of pointer: \n";
    cout << pr<< " "<< pr + 1<< " "<< pr + 2 ;
    
    cout<<"\nAddress of pointer: \n";
  cout << *pr<< " "<< *(pr + 1)<< " "<< *(pr + 2) ;
  
  cout<<"\nElements of pointer: ";
  cout << **pr<< " "<< *(*(pr + 1) + 2)<< " "<< *(*(pr + 2) + 3) ;
  cout<<"\nElements of pointer specific posotion: ";
  cout << pr[0][0]<< " "<< pr[1][2]<< " "<< pr[2][3]<< endl;
    return 0;
}
