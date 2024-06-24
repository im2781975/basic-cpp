#include <bits/stdc++.h>
using namespace std;
class Line{
    double length;
    public:
    Line(double len);
    void set(double len);
    double get(void);
};
Line::Line(double len){
    length = len;
}
void Line::set(double len){
    length = len;
}
double Line::get(void){
    return length;
}
int main(){
    Line line(10.0);
    cout<<"\nLength of line :" << line.get();
  
  line.set(6.0);
  cout<<"\nLength of line :" << line.get() ;
  return 0;
}
