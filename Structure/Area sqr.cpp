#include<bits/stdc++.h>
using namespace std;
struct GFG {
    int x,y;
};
struct square {
//object left & right is declared with 'GFG'.
    struct GFG left;
    struct GFG right;
};
void area_Square(struct square s)
{
    int area=(s.right.x)*(s.left.x);
    cout << area <<"\n";
}
int main()
{
    struct square s = { { 4, 4 }, { 4, 4 } };
    area_Square(s);
    return 0;
}
