#include<iostream>
using namespace std;
int main() 
{
    char name[25];
    cout<<"Enter string: ";
    cin.getline(name, 125);
    clog<< name;
    
    char ch[25];
    cout<<"\nEnter char array: ";
    cin.get(ch,25);
    cerr<< ch;
    
    char c[22];
    cout<<"\nEnter char: ";
    //Only for reading 
    cin.read(c, 10);
    cout<< ch;
}

