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
    cout<<"using char: ";
    print(colour, 4);
    cout<<"\n";

    string color[4]= { "E","F", "G", "H" };
      cout<<"using string: ";
  for (int i = 0; i < 4; i++)
      cout << color[i] <<" ";
      cout<<"\n";

    vector<string> colur{"I", "J","K"};
  colur.push_back("L");
  cout<<"using vector: ";
  for (int i=0;i<colur.size(); i++)
      cout << colur[i] << " ";
      cout<<"\n";

   array<string,4>clour{"M","N", "O"};
  cout<<"Limited string: ";
  for (int i = 0; i < 4; i++)
      cout << clour[i] <<" ";
      cout<<"\n";
    return 0;
}
