#include<bits/stdc++.h>
using namespace std;
void arr_char_type()
{
    char arr[6] = { 'G', 'e', 'e', 'k', 's', '\0' };
 
    int i = 0;
    while (arr[i]) {
        cout<< arr[i] << " ";
        
        i++;
    }
}

void arr_derived_type()
{
    int arr[5]; 
    arr[0] = 5; 
    arr[2] = -10; 
  
    // this is same as arr[1] = 2 
    arr[3 / 2] = 2; 
  
    arr[3] = arr[0]; 
  
    cout<<arr[0]<<" "<<arr[1]<<" "<<arr[2]<<" "<<arr[3]; 
  
}
int main()
{
    cout<< "char type [] : ";
    arr_char_type();
    
    cout<< "\n derived type [] : ";
    arr_derived_type();
    
    return 0;
}
