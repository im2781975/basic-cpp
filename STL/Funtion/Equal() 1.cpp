// use of bool equal (InputIterator1 first1, InputIterator1 last1,
// InputIterator2 first2, BinaryPredicate pred);
 
#include <bits/stdc++.h>
using namespace std;

bool pred(int i, int j)
{
    return (i != j);
}
int main()
{
    int v1[]{ 10, 20, 30, 40, 50 };
    vector<int> vector_1 (v1, v1 + sizeof(v1) / sizeof(int) );
 
    cout << "Vector contains : ";
    for (unsigned int i = 0; i < vector_1.size(); i++)
        cout << " " << vector_1[i];
    cout << "\n";
 
    // using std::equal()
    // Comparison based on pred
    if ( equal (vector_1.begin(), vector_1.end(), v1, pred) )
        cout << "The contents of both sequences are equal.\n";
    else
        printf("The contents of both sequences differ.");
 
}
