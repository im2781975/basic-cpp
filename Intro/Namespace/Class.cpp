#include<bits/stdc++.h>
using namespace std;
namespace first
{
    class base;
}
class first::base
{ 
    public:
    void display()
    {
        cout<<"\nfirst::base b";
    }
};
namespace second
{
    void display();
    class base
    {
        public:
        void display();
    };
}
void second::base::display()
{
    cout<<"\nabcd";
}
void second::display()
{
    cout<<"\nefgh";
}
int main()
{
    first::base b;
    b.display();
    second::base c;
    second::display();
    c.display();
}
