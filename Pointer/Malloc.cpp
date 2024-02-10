#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    //Both of these allocate the same number of bytes, which is the amount of bytes 
    //that is required to store 5 int values.The memory allocated by calloc will be zero-initialized, 
    //but the memory allocated with malloc will be uninitialized so reading it would be undefined behavior.
    int *mal = static_cast<int*>(malloc(5*sizeof(int)));
    int *cal = static_cast<int*>(calloc(5,sizeof(int)));
    for(size_t i=0; i<5; i++)
        cout << mal[i] << " ";
    
    // This malloc requests 1 terabyte of dynamic memory,which is unavailable in this case, 
    //and so the allocation fails and returns NULL.
    int *fail =static_cast<int*>(malloc(10000000000000000));
    if(fail==nullptr)
        cout << "Failed";
    else 
        cout << "\n" << fail;
    free(mal);
    free(cal);
}
