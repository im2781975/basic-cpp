//Insert() | bucket_count() | load_factor() | max_size() | size() | emplace() | bucket_search() | count() 
#include <iostream> 
#include <unordered_set> 
using namespace std; 
void print(unordered_set<int>&s)
{
    unordered_set<int>::iterator it;
    for(it=s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<" ";
    }
}
int main() 
{ 
    unordered_set<int> s; 
 
    s.insert(1); 
    s.insert(11); 
    s.insert(111); 
    s.insert(12); 
    s.insert(13); 
    
    cout<<"\n size is: "<<s.size();
    cout <<"\nbucket_count is: "
         <<s.bucket_count();
    cout<<"\nload factor is: "<<s.load_factor() ;
    cout<<"\nMax size is: "<<s.max_size();
 
    s.insert(2); 
    s.insert(22); 
    
    cout<<"\nAfter insertion size is : "<<s.size() ;
    cout <<"\nAfter insertion bucket count is: " << s.bucket_count() ;
    cout <<"\nAfter insertion load factor is: " <<s.load_factor() ;
    int i=0;
    while(i<25)
    {
        s.emplace(i);
        i+=5;
    }
    cout<<"\nImposed emplace(): ";
    print(s);
    cout<<"\nBucket search: ";
    for (auto itr = s.begin(); itr != s.end(); itr++) 
    { 
        cout <<"\nElement "<<(*itr) << " is present in the bucket: "<< s.bucket(*itr);
    }
    if(s.count(22)==1)
        cout<<"\n22 Exit";
    else
        cout<<"\ndoesn't exit";
        
    unordered_set<string>stringSet;
    stringSet.rehash(9);
    //rehash sets the number of buckets in the container to N or more. If N is greater than the current number of buckets in the container (bucket_count), a rehash is forced. The new bucket count can either be equal or greater than N.
    stringSet.insert("code");
    stringSet.insert("in");
    stringSet.insert("c++");
    stringSet.insert("is");
    stringSet.insert("fast");
    
   // array<string,2> myArray { "tenth", "seventh"};

    string myString = "ninth";
 
    stringSet.insert(myString);
    
   // stringSet.insert(myArray.begin(), myArray.end());
 
    stringSet.insert({"fourth","sixth" });
    cout<<"\nmyset contains: ";
    cout<<"\nbucket count is: "<<stringSet.bucket_count();
    string key = "slow";

    if (stringSet.find(key) == stringSet.end())
        cout<<"\n'"<<key<<"' isn't found";
    else
        cout<<"\nFound '"<< key<<"'";

    cout << "\nElements are : ";
    unordered_set<string>::iterator itr;
    for (itr = stringSet.begin(); itr != stringSet.end();
         itr++)
        cout << (*itr) <<" ";
        
    unordered_set<string> ms; 
    
    bool res=ms.key_eq()("a","A"); 
    cout << "\nms.key_eq() is: ";
    
    if (res == 1) 
    cout << "case insensitive"; 
    
    else
        cout << "case sensitive"; 
    return 0; 
} 
