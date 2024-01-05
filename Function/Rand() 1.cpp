//generate test cases for matrix filled with random numbers
#include<bits/stdc++.h>
using namespace std;

 //Define the number of runs for the test data generated
#define RUN 3

// Define the range of the test data
#define MAX 10

// Define the maximum rows in matrix
#define MAXROW 10
 
//Define the max columns in matrix
#define MAXCOL 10
int main()
{
//freopen ("Test_Cases_Random_Matrix.in", "w", stdout);
    srand(time(NULL));
 
    for (int i=1; i<=RUN; i++)
    {
        int row = 1+rand() % MAXROW;
        int col = 1+rand() % MAXCOL;
        
        cout<<"row: "<<row<<",col: "<<col<<"\n";
        
        for (int j=1; j<=row; j++)
        {
            for (int k=1; k<=col; k++)
                cout<<rand() % MAX<<" ";
                
            cout<<"\n";
        }
        cout<<"\n";
    }
    // fclose(stdout);
    return(0);
}
