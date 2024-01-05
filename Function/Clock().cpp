#include <bits/stdc++.h>
using namespace std;

void fun()
{
    for (int i = 0; i < 10; i++){
    }
}
int main()
{
    // clock_t clock(void) returns the number of clock ticks elapsed after program was launched.
    clock_t start, end;
 
    start = clock();
    fun();
    end = clock();
    
    double time_taken
        = double(end - start)
          / double(CLOCKS_PER_SEC);
  
    cout << "Time taken by program is: " << fixed<<time_taken<< setprecision(5);
    cout << " sec " <<"\n";
  
    return 0;
}
