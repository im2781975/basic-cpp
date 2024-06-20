#include <bits/stdc++.h>
using namespace std;
string Erase_First_Last(string s){
    s.erase(s.begin());
    s.pop_back();
    return s;
}
string EraseFirstLast(string &s){
    s.erase(s.begin());
    s.pop_back();
    return s;
}
void Swap(int &x, int &y){
    int z = x;
    x = y;
    y = z;
}
int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;
    string ans = EraseFirstLast(s);
    cout << "\nAfter Erase_First_Last string is: " << ans;

    Erase_First_Last(s);
    cout << "\nAfter EraseFirstLast (using address) string is: " << s;

    int a, b;
    cout << "\nEnter integers: ";
    cin >> a >> b;
    Swap(a, b);
    cout << "\nAfter swap() integers are: " << a << " " << b;
    
    string a ="ibrahim";
    string b ="Molla";
    cout<<a[0] <<" " <<a[1];
    string c= a + b;
    cout<<"\nAfter concatenate string is: " << c ;
    cout<< "\nSizeof string is: " << a.size();
    for(int i = 0; i < a.size(); i++)
        a[i] = a[i] +1;
        //'a' + 1 = 'b'
    
    cout<< "\nAfter add string is: " <<a;
    a.pop_back();
    cout<< "\nAfter pop_back string is: " << a ;
    
    b.erase(b.begin()+ 0);
    cout <<"\nAfter erase B is: " << b;
    c.erase(c.begin());
    cout <<"\nAfter erase front string is: " << c;
    c.erase(c.begin()+ c.size() -1);
    cout<< "\nAfter erase back string is: " << c;
    c.pop_back()
    return 0;
}
