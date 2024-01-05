#include<bits/stdc++.h>
using namespace std;
//Define the number of runs for the test data generated
#define RUN 5
// Define the range of the test data generated
#define MAX 100
int main()
{
    //freopen("Test_Cases.in", "w", stdout);
    // For random values every time
    srand(time(NULL));
    for (int i=1; i<=RUN; i++)
    cout<<rand()%MAX<<" ";
  
    //fclose(stdout);
    return(0);
}
