#include <iostream>
#include <unordered_set>
using namespace std;
int main()
{
    unordered_set <int> uset;
    
    uset.insert(5);
    uset.insert(10);
    uset.insert(15);
    uset.insert(20);
    uset.insert(25);
    
    int bucketCount = uset.bucket_count();
    cout <<"\nBucket size for uset is:  "<< bucketCount;
 
    cout <<"\nBucket number 3 contains "<<uset.bucket_size(3) <<" elements";
    return 0;
}
