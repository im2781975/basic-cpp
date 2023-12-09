//Insert() | bucket_count() | load_factor() | max_size() | size() | emplace() | bucket_search() | count() 
#include <iostream> 
#include <unordered_set> 
using namespace std; 
void print(unordered_set<int>s)
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

    stringSet.insert("code");
    stringSet.insert("in");
    stringSet.insert("c++");
    stringSet.insert("is");
    stringSet.insert("fast");
 
    string key = "slow";

    if (stringSet.find(key) == stringSet.end())
        cout<<"\n'"<<key<<"' isn't found";
    else
        cout<<"\nFound '"<< key<<"'";

    cout << "Elements are : ";
    unordered_set<string>::iterator itr;
    for (itr = stringSet.begin(); itr != stringSet.end();
         itr++)
        cout << (*itr) <<" ";
    return 0; 
} 
