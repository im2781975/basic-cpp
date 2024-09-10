
#include<bits/stdc++.h>
using namespace std;
class shape
{
    protected:
    int length;
    int width;
    
    public:
    shape(int l,int w)
    {
        length=l;
        width=w;
    }
    int get_area()
    {
        return length*width;
    }
};
class square:public shape
{
    public:
    square(int l=0,int w=0):shape(l,w){}
    int get_area()
    {
        int area=length*width;
        return area;
    }
};
class rectangle:public shape
{
    public:
    rectangle(int l=0,int w=0):shape(l,w){}
    int get_area()
    {
        int area=length*width;
        return area;
    }
};
int main()
{
    shape *s;
    square sq(2,5);
    s=&sq;
    cout<<"area of square: "<<s->get_area();
    rectangle rt(7,8);
    s=&rt;
    cout<<"\narea of rectangle: "<<s->get_area();
    
}
