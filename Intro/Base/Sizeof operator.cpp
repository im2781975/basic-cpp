#include <bits/stdc++.h> 
using namespace std; 
int main()  
{   
    cout <<"\nsizeof(char) :"<< sizeof(char) << "Bytes" ;
    cout <<"\nsizeof(int) :"<< sizeof(int) << "Bytes" ;
    cout <<"\nsizeof(float) :"<< sizeof(float) << "Bytes" ;
    cout <<"\nsizeof(double) :"<< sizeof(double) << "Bytes" ;
    cout <<"\nsizeof(long) :"<< sizeof(long) << "Bytes" ;
    
    int i = 5; 
    long l = 9; 
    double d = 10.2; 
    float f = 2.5;
    cout<<"\nsizeof(i*sizeof(d)): "<< sizeof(i*sizeof(d)) << "Bytes";
    cout <<"\nsizeof(i+f) :"<< sizeof(i+f) << "Bytes";
    cout <<"\nsizeof(i+l) :"<< sizeof(i+l) << "Bytes";
    cout <<"\nsizeof(i+d) :"<< sizeof(i+d) << "Bytes";
    cout <<"\nsizeof(l+d) :"<< sizeof(l+d) << "Bytes";
    
    int *a = new int(10); 
    char *g = new char('g'); 
    double *db = new double(7.5);
    
    cout <<"\nsizeof(a) :"<<sizeof(a)<< "Bytes";
    cout <<"\nsizeof(*a) :"<<sizeof(*a)<< "Bytes";
    cout <<"\nsizeof(g) :"<<sizeof(g)<< "Bytes";
    cout <<"\nsizeof(*g) :"<<sizeof(*g)<< "Bytes";
    cout <<"\nsizeof(db) :"<<sizeof(db)<< "Bytes";
    cout <<"\nsizeof(*db) :"<<sizeof(*db) << "Bytes";
}
