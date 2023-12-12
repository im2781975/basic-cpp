#include <iostream>
#include <utility>
using namespace std;
 
int main()
{
    pair<int, char> P;
    pair<string, double> Q("abcdefg", 1.23);
    pair<string, double> R;
 
    P.first = 100;
    P.second = 'G';
 
    R = make_pair("Abcdefg", 4.56);
 
    cout <<"\nP.first :"<<P.first << "  "<< "P.second :"<<P.second ;
    cout <<"\nQ.first :"<<Q.first << "  "<< "Q.second :"<<Q.second ;
    cout <<"\nR.first :"<<R.first << "  "<< "R.second :"<<R.second ;
    
    pair<string, double> S;
    S.first= Q.first + R.first;
    S.second= Q.second + R.second;
    
    cout <<"\nS.first :"<<S.first << "  "<< "S.second :"<<S.second ;
    
    pair<string, int> A;
    A = make_pair(string("Ibrahim"), 1);
    pair<string, int> B("Aslam",3);
    pair<string, int> C(B);
    pair<int, int> D(5, 10);
 
    B.first = "Molla";
    B.second = 2;
 
    cout <<"\nA.first :"<<A.first << "  "<< "A.second :"<<A.second ;
    cout <<"\nB.first :"<<B.first << "  "<< "B.second :"<<B.second ;
    cout <<"\nC.first :"<<C.first << "  "<< "C.second :"<<C.second ;
    cout <<"\nD.first :"<<D.first << "  "<< "D.second :"<<D.second <<"\nmade for showing addition. The sum of the values in this pair is "<< D.first + D.second ;
 
    cout << "\nConcatenation of the value first value of A, B & C is: "<< A.first + C.first + B.first ;
    
    cout << "\nBefore swapping, "
         << "A has " << A.first << " and B has "
         << B.first ;
         
    cout << "\nWe can also swap pairs (but type of pairs should be same) : " ;
    
    swap(A, B);
    cout << "\nAfter swapping A has " << A.first << "& B has "<< B.first;
}
