// Initialization, indexing and iteration 
#include <iostream> 
#include <unordered_map> 
using namespace std; 
  
int main() 
{ 
    unordered_map<string, double> umap = {{"A", 1},{"B", 2}, {"C", 3} }; 
    umap["PI"] = 3.14; 
    umap["root2"] = 1.414; 
    umap["root3"] = 1.732; 
    umap["log10"] = 2.302; 
    umap["loge"] = 1.0; 
  
    umap.insert(make_pair("e", 2.718)); 
  
    string key = "PI"; 
    
    if (umap.find(key) == umap.end()) 
    cout << key <<" not found"; 

    else
    cout << "Found " << key;
    
  unordered_map<string, double>::iterator itr; 
  cout << "\nAll Elements : "; 
  for (itr = umap.begin();  
       itr != umap.end(); itr++)  
    
    cout << itr->first << " " << itr->second << endl; 
} 
