// raise() function
#include<bits/stdc++.h>
using namespace std;
void signal_handler(int signal_num)
{
    cout << "Interrupt signal is (" << signal_num << ").\n";
    
    exit(signal_num);
}
int main()
{
    int count = 0;
    signal(SIGSEGV,signal_handler);
    // register signal SIGSEGV and signal handler
    while (++count) {
        cout << "Hello..." <<"\n";
        if (count == 5)
            raise(SIGSEGV);
    }
    return 0;
}
