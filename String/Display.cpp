#include <bits/stdc++.h>
using namespace std;
void print(char colour[][10], int size)
{
    for (int i = 0;i < size; i++)
        cout << colour[i] <<" ";
}
int main()
{
    char colour[4][10] = { "A", "B", "C", "D" };
    cout << "\nusing char: ";
    print(colour, 4);

    string color[4]= {"E", "F", "G", "H"};
    cout << "\nusing string: ";
    for (int i = 0; i < 4; i++)
        cout << color[i] <<" ";

    vector<string> colur{"I", "J","K"};
    colur.push_back("L");
    cout << "\nusing vector: ";
    for (int i = 0;i < colur.size(); i++)
        cout << colur[i] << " ";

    array< string ,4 >clour {"M","N", "O"};
    cout << "\nLimited string: ";
    for (int i = 0; i < 4; i++)
        cout << clour[i] <<" ";
        
    return 0;
}
