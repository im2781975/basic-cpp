//A signal is a message or notification issued to your program by the operating system or another application (or one of its threads).Each signal is assigned a number between 1& 31
#include<bits/stdc++.h>
using namespace std;
  
void signal_handler(int signal_num)
{
    cout << "The interrupt signal is (" << signal_num
         << "). \n";
  
    // It terminates the  program
    exit(signal_num);
}
int main()
{
    // register signal SIGABRT and signal handler
    signal(SIGABRT,signal_handler);
  
    while (true)
        cout << "Hello ..."<<"\n";
    return 0;
}
