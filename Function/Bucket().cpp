#include <iostream>
#include <unordered_set>
#include <unordered_map>
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
    cout<< "\nElements of uset is: ";
    for(auto it = uset.begin(); it!=uset.end(); it++)
    {
        cout <<*it <<" ";
    }
    cout<< "\nSize of uset is: " <<uset.size();
    uset.clear();
    cout<< "\nImplemented clear uset is: " << uset.size();
    unordered_map<string,string> umap = { {"AB","CD"},{"EF","GH"},
    {"IJ","KL"},{"MN","OP"},{"QR","ST"}, {"UV","WX"} };

    int n = umap.bucket_count();
    cout << "\numap has " << n << " buckets ";

    for (int i=0; i<n; ++i)
    {
        cout << "\nBucket " << i+1 << " contains: ";
        for (auto it = umap.begin(i); it!=umap.end(i); ++it)
            cout << it->first << " " << it->second <<" ";
    }
}
