// A divide and conquer program in C++ 
// to find the smallest distance from a 
// given set of points. 
 
#include <bits/stdc++.h>
using namespace std;
 
// A structure to represent a Point in 2D plane 
class Point 
{ 
    public:
    int x, y; 
}; 
 
/* Following two functions are needed for library function qsort(). 
Refer: http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
 
// Needed to sort array of points 
// according to X coordinate 
int compareX(const void* a, const void* b) 
{ 
    Point *p1 = (Point *)a, *p2 = (Point *)b; 
    return (p1->x - p2->x); 
} 
 
// Needed to sort array of points according to Y coordinate 
int compareY(const void* a, const void* b) 
{ 
    Point *p1 = (Point *)a, *p2 = (Point *)b; 
    return (p1->y - p2->y); 
} 
 
// A utility function to find the 
// distance between two points 
float dist(Point p1, Point p2) 
{ 
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + 
                (p1.y - p2.y)*(p1.y - p2.y) 
            ); 
} 
 
// A Brute Force method to return the 
// smallest distance between two points 
// in P[] of size n 
float bruteForce(Point P[], int n) 
{ 
    float min = FLT_MAX; 
    for (int i = 0; i < n; ++i) 
        for (int j = i+1; j < n; ++j) 
            if (dist(P[i], P[j]) < min) 
                min = dist(P[i], P[j]); 
    return min; 
} 
 
// A utility function to find 
// minimum of two float values 
float min(float x, float y) 
{ 
    return (x < y)? x : y; 
} 
 
 
// A utility function to find the 
// distance between the closest points of 
// strip of given size. All points in 
// strip[] are sorted according to 
// y coordinate. They all have an upper
// bound on minimum distance as d. 
// Note that this method seems to be 
// a O(n^2) method, but it's a O(n) 
// method as the inner loop runs at most 6 times 
float stripClosest(Point strip[], int size, float d) 
{ 
    float min = d; // Initialize the minimum distance as d 
 
    qsort(strip, size, sizeof(Point), compareY); 
 
    // Pick all points one by one and try the next points till the difference 
    // between y coordinates is smaller than d. 
    // This is a proven fact that this loop runs at most 6 times 
    for (int i = 0; i < size; ++i) 
        for (int j = i+1; j < size && (strip[j].y - strip[i].y) < min; ++j) 
            if (dist(strip[i],strip[j]) < min) 
                min = dist(strip[i], strip[j]); 
 
    return min; 
} 
 
// A recursive function to find the 
// smallest distance. The array P contains 
// all points sorted according to x coordinate 
float closestUtil(Point P[], int n) 
{ 
    // If there are 2 or 3 points, then use brute force 
    if (n <= 3) 
        return bruteForce(P, n); 
 
    // Find the middle point 
    int mid = n/2; 
    Point midPoint = P[mid]; 
 
    // Consider the vertical line passing 
    // through the middle point calculate 
    // the smallest distance dl on left 
    // of middle point and dr on right side 
    float dl = closestUtil(P, mid); 
    float dr = closestUtil(P + mid, n - mid); 
 
    // Find the smaller of two distances 
    float d = min(dl, dr); 
 
    // Build an array strip[] that contains 
    // points close (closer than d) 
    // to the line passing through the middle point 
    Point strip[n]; 
    int j = 0; 
    for (int i = 0; i < n; i++) 
        if (abs(P[i].x - midPoint.x) < d) 
            strip[j] = P[i], j++; 
 
    // Find the closest points in strip. 
    // Return the minimum of d and closest 
    // distance is strip[] 
    return min(d, stripClosest(strip, j, d) ); 
} 
 
// The main function that finds the smallest distance 
// This method mainly uses closestUtil() 
float closest(Point P[], int n) 
{ 
    qsort(P, n, sizeof(Point), compareX); 
 
    // Use recursive function closestUtil()
    // to find the smallest distance 
    return closestUtil(P, n); 
} 
 
// Driver code 
int main() 
{ 
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]); 
    cout << "The smallest distance is " << closest(P, n); 
    return 0; 
} 
#include <iostream>
#include <vector>
#include <algorithm>

struct Element {
    int value;
    int originalIndex;
};

bool compareElements(const Element& a, const Element& b) {
    return a.value < b.value;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Element> elements(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i].value;
        elements[i].originalIndex = i;
    }

    std::sort(elements.begin(), elements.end(), compareElements);

    std::cout << "Value " << elements[0].value << ", Previous Index " << elements[0].originalIndex << std::endl;
    for (int i = 1; i < n; ++i) {
        if (elements[i].value == elements[i - 1].value) {
            std::cout << "Value " << elements[i].value << ", Previous Index " << elements[i - 1].originalIndex << std::endl;
        } else {
            std::cout << "Value " << elements[i].value << ", Previous Index " << elements[i].originalIndex << std::endl;
        }
    }

    return 0;
}
// C++ program to do range minimum
// query in O(1) time with
// O(n Log n) extra space and 
// O(n Log n) preprocessing time
#include <bits/stdc++.h>
using namespace std;
#define MAX 500
 
// lookup[i][j] is going to 
// store index of minimum value in
// arr[i..j]. Ideally lookup 
// table size should not be fixed
// and should be determined using 
// n Log n. It is kept
// constant to keep code simple.
int lookup[MAX][MAX];
 
// Structure to represent a query range
struct Query {
    int L, R;
};
 
// Fills lookup array 
// lookup[][] in bottom up manner.
void preprocess(int arr[], int n)
{
    // Initialize M for the 
    // intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][0] = i;
 
    // Compute values from smaller 
    // to bigger intervals
    for (int j = 1; (1 << j) <= n; j++) 
    {
        // Compute minimum value for 
        // all intervals with size
        // 2^j
        for (int i = 0; (i + (1 << j) - 1) < n; i++) 
        {
            // For arr[2][10], we 
            // compare arr[lookup[0][3]]
            // and arr[lookup[3][3]]
            if (arr[lookup[i][j - 1]]
                < arr[lookup[i + (1 << (j - 1))][j - 1]])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j]
                    = lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}
 
// Returns minimum of arr[L..R]
int query(int arr[], int L, int R)
{
    // For [2,10], j = 3
    int j = (int)log2(R - L + 1);
 
    // For [2,10], we compare arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    if (arr[lookup[L][j]]
        <= arr[lookup[R - (1 << j) + 1][j]])
        return arr[lookup[L][j]];
 
    else
        return arr[lookup[R - (1 << j) + 1][j]];
}
 
// Prints minimum of given 
// m query ranges in arr[0..n-1]
void RMQ(int arr[], int n, Query q[], int m)
{
    // Fills table lookup[n][Log n]
    preprocess(arr, n);
 
    // One by one compute sum of all queries
    for (int i = 0; i < m; i++) 
    {
        // Left and right boundaries 
        // of current range
        int L = q[i].L, R = q[i].R;
 
        // Print sum of current query range
        cout << "Minimum of [" << L << ", "
             << R << "] is "
             << query(arr, L, R) << endl;
    }
}
 
// Driver code
int main()
{
    int a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
    int n = sizeof(a) / sizeof(a[0]);
    Query q[] = { { 0, 4 }, { 4, 7 }, { 7, 8 } };
    int m = sizeof(q) / sizeof(q[0]);
    RMQ(a, n, q, m);
    return 0;
}
// C++ program to do range 
// minimum query in O(1) time with
// O(n*n) extra space and O(n*n) 
// preprocessing time.
#include <bits/stdc++.h>
using namespace std;
#define MAX 500
 
// lookup[i][j] is going to store 
// index of minimum value in
// arr[i..j]
int lookup[MAX][MAX];
 
// Structure to represent a query range
struct Query {
    int L, R;
};
 
// Fills lookup array lookup[n][n] 
// for all possible values
// of query ranges
void preprocess(int arr[], int n)
{
    // Initialize lookup[][] for the 
    // intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][i] = i;
 
    // Fill rest of the entries in bottom up manner
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++)
 
            // To find minimum of [0,4],
            // we compare minimum
            // of arr[lookup[0][3]] with arr[4].
            if (arr[lookup[i][j - 1]] < arr[j])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = j;
    }
}
 
// Prints minimum of given m 
// query ranges in arr[0..n-1]
void RMQ(int arr[], int n, Query q[], int m)
{
    // Fill lookup table for 
    // all possible input queries
    preprocess(arr, n);
 
    // One by one compute sum of all queries
    for (int i = 0; i < m; i++) 
    {
        // Left and right boundaries 
        // of current range
        int L = q[i].L, R = q[i].R;
 
        // Print sum of current query range
        cout << "Minimum of [" << L 
             << ", " << R << "] is "
             << arr[lookup[L][R]] << endl;
    }
}
 
// Driver code
int main()
{
    int a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
    int n = sizeof(a) / sizeof(a[0]);
    Query q[] = { { 0, 4 }, { 4, 7 }, { 7, 8 } };
    int m = sizeof(q) / sizeof(q[0]);
    RMQ(a, n, q, m);
    return 0;
}
// working of for_each loop
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printx2(int a)
{
    cout << a * 2 << " ";
}

struct Class2
{
    void operator() (int a)
    {
        cout << a * 3 << " ";
    }
} ob1;
 
int main()
{
    int arr[5] = { 1, 5, 2, 4, 3 };
    cout << "Multiple of 2 of elements are : ";
    for_each(arr, arr + 5,printx2);
    cout << "\n";
    
    cout << "Multiple of 3 of elements are : ";
    for_each(arr, arr + 5, ob1);
     
    cout << "\n";
     
    vector<int> arr1{4, 5, 8, 3,1};
    cout << "Multiple of 2 of elements are : ";
    for_each(arr1.begin(), arr1.end(), printx2);
    cout<<"\n";
    
    cout << "Multiple of 3 of elements are : ";
    for_each(arr1.begin(), arr1.end(), ob1);
    cout<<"\n";
     
}
// Program to compute sum of ranges for different range
// queries
#include <bits/stdc++.h>
using namespace std;
 
// Variable to represent block size. This is made global
// so compare() of sort can use it.
int block;
 
// Structure to represent a query range
struct Query
{
    int L, R;
};
 
// Function used to sort all queries so that all queries 
// of the same block are arranged together and within a block,
// queries are sorted in increasing order of R values.
bool compare(Query x, Query y)
{
    // Different blocks, sort by block.
    if (x.L/block != y.L/block)
        return x.L/block < y.L/block;
 
    // Same block, sort by R value
    return x.R < y.R;
}
 
// Prints sum of all query ranges. m is number of queries
// n is size of array a[].
void queryResults(int a[], int n, Query q[], int m)
{
    // Find block size
    block = (int)sqrt(n);
 
    // Sort all queries so that queries of same blocks
    // are arranged together.
    sort(q, q + m, compare);
 
    // Initialize current L, current R and current sum
    int currL = 0, currR = 0;
    int currSum = 0;
 
    // Traverse through all queries
    for (int i=0; i<m; i++)
    {
        // L and R values of current range
        int L = q[i].L, R = q[i].R;
 
        // Remove extra elements of previous range. For
        // example if previous range is [0, 3] and current
        // range is [2, 5], then a[0] and a[1] are subtracted
        while (currL < L)
        {
            currSum -= a[currL];
            currL++;
        }
 
        // Add Elements of current Range
        while (currL > L)
        {
            currSum += a[currL-1];
            currL--;
        }
        while (currR <= R)
        {
            currSum += a[currR];
            currR++;
        }
 
        // Remove elements of previous range.  For example
        // when previous range is [0, 10] and current range
        // is [3, 8], then a[9] and a[10] are subtracted
        while (currR > R+1)
        {
            currSum -= a[currR-1];
            currR--;
        }
 
        // Print sum of current range
        cout << "Sum of [" << L << ", " << R
             << "] is "  << currSum << endl;
    }
}
 
// Driver program
int main()
{
    int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    int n = sizeof(a)/sizeof(a[0]);
    Query q[] = {{0, 4}, {1, 3}, {2, 4}};
    int m = sizeof(q)/sizeof(q[0]);
    queryResults(a, n, q, m);
    return 0;
}
// C++ Program to compute sum of ranges for different range
// queries.
#include <bits/stdc++.h>
using namespace std;
 
// Structure to represent a query range
struct Query
{
    int L, R;
};
 
// Prints sum of all query ranges. m is number of queries
// n is the size of the array.
void printQuerySums(int a[], int n, Query q[], int m)
{
    // One by one compute sum of all queries
    for (int i=0; i<m; i++)
    {
        // Left and right boundaries of current range
        int L = q[i].L, R = q[i].R;
 
        // Compute sum of current query range
        int sum = 0;
        for (int j=L; j<=R; j++)
            sum += a[j];
 
        // Print sum of current query range
        cout << "Sum of [" << L << ", "
            << R << "] is "  << sum << endl;
    }
}
 
// Driver program
int main()
{
    int a[] = {1, 1, 2, 1, 3, 4, 5, 2, 8};
    int n = sizeof(a)/sizeof(a[0]);
    Query q[] = {{0, 4}, {1, 3}, {2, 4}};
    int m = sizeof(q)/sizeof(q[0]);
    printQuerySums(a, n, q, m);
    return 0;
}
// A C++ program to check if any two intervals overlap
#include <algorithm>
#include <iostream>
using namespace std;
 
// An interval has start time and end time
struct Interval {
    int start;
    int end;
};
 
// Function to check if any two intervals overlap
bool isIntersect(Interval arr[], int n)
{
 
    int max_ele = 0;
 
    // Find the overall maximum element
    for (int i = 0; i < n; i++) {
        if (max_ele < arr[i].end)
            max_ele = arr[i].end;
    }
 
    // Initialize an array of size max_ele
    int aux[max_ele + 1] = { 0 };
    for (int i = 0; i < n; i++) {
 
        // starting point of the interval
        int x = arr[i].start;
 
        // end point of the interval
        int y = arr[i].end;
        aux[x]++, aux[y + 1]--;
    }
    for (int i = 1; i <= max_ele; i++) {
        // Calculating the prefix Sum
        aux[i] += aux[i - 1];
 
        // Overlap
        if (aux[i] > 1)
            return true;
    }
 
    // If we reach here, then no Overlap
    return false;
}
 
// Driver program
int main()
{
    Interval arr1[] = { { 1, 3 }, { 7, 9 }, { 4, 6 }, { 10, 13 } };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
 
    isIntersect(arr1, n1) ? cout << "Yes\n" : cout << "No\n";
 
    Interval arr2[] = { { 6, 8 }, { 1, 3 }, { 2, 4 }, { 4, 7 } };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    isIntersect(arr2, n2) ? cout << "Yes\n" : cout << "No\n";
 
    return 0;
}
// A C++ program to check if any two intervals overlap
#include <algorithm>
#include <iostream>
using namespace std;
 
// An interval has start time and end time
struct Interval {
    int start;
    int end;
};
 
// Compares two intervals according to their starting time.
// This is needed for sorting the intervals using library
// function std::sort(). See http:// goo.gl/iGspV
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start) ? true : false;
}
 
// Function to check if any two intervals overlap
bool isIntersect(Interval arr[], int n)
{
    // Sort intervals in increasing order of start time
    sort(arr, arr + n , compareInterval);
 
    // In the sorted array, if start time of an interval
    // is less than end of previous interval, then there
    // is an overlap
    for (int i = 1; i < n; i++)
        if (arr[i - 1].end > arr[i].start)
            return true;
 
    // If we reach here, then no overlap
    return false;
}
 
// Driver program
int main()
{
    Interval arr1[] = { { 1, 3 }, { 7, 9 }, { 4, 6 }, { 10, 13 } };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    isIntersect(arr1, n1) ? cout << "Yes\n" : cout << "No\n";
 
    Interval arr2[] = { { 6, 8 }, { 1, 3 }, { 2, 4 }, { 4, 7 } };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    isIntersect(arr2, n2) ? cout << "Yes\n" : cout << "No\n";
 
    return 0;
}
// C++ implementation to find k numbers with most
// occurrences in the given array
 
#include <bits/stdc++.h>
using namespace std;
 
// Comparison function defined for the priority queue
struct compare {
    bool operator()(pair<int, int> p1, pair<int, int> p2)
    {
        // If frequencies of two elements are same
        // then the larger number should come first
        if (p1.second == p2.second)
            return p1.first < p2.first;
 
        // Insert elements in the priority queue on the
        // basis of decreasing order of frequencies
        return p1.second < p2.second;
    }
};
 
// Function to print the k numbers with most occurrences
void print_N_mostFrequentNumber(int arr[], int N, int K)
{
    // unordered_map 'mp' implemented as frequency hash
    // table
    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
        mp[arr[i]]++;
 
    // priority queue 'pq' implemented as max heap on the
    // basis of the comparison operator 'compare' element
    // with the highest frequency is the root of 'pq' in
    // case of conflicts, larger element is the root
    priority_queue<pair<int, int>, vector<pair<int, int> >,
                   compare>
        pq(mp.begin(), mp.end());
 
    // Display the top k numbers
    cout << K << " numbers with most occurrences are:\n";
    for (int i = 1; i <= K; i++) {
        cout << pq.top().first << " ";
        pq.pop();
    }
}
 
// Driver's code
int main()
{
    int arr[] = { 3, 1, 4, 4, 5, 2, 6, 1 };
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 2;
 
    // Function call
    print_N_mostFrequentNumber(arr, N, K);
    return 0;
}
// find number of unique Triangles 
#include <bits/stdc++.h> 
using namespace std; 

typedef pair<int, int> iPair; 

struct Triangle 
{ 
    int a, b, c; 
}; 
 
void sort3(int &a, int &b, int &c) 
{ 
    vector<int> arr({a, b, c}); 
    sort(arr.begin(), arr.end()); 
    a = arr[0]; b = arr[1]; c = arr[2]; 
} 
  
// Function returns the number of unique Triangles 
int countUniqueTriangles(struct Triangle arr[], int n) 
{ 
    // A set which consists of unique Triangles 
    set < pair< int, iPair > > s; 
 
    for (int i=0; i<n; i++) 
    { 
        // Find three sides and sort them 
        int a = arr[i].a, b = arr[i].b, c = arr[i].c; 
        sort3(a, b, c); 
        s.insert({a, {b, c}}); 
    } 

    return s.size(); 
} 

int main() 
{ 
    // An array of structure to store sides of 6 Triangles 
    struct Triangle arr[] = {{3, 2, 2}, {3, 4, 5}, {1, 2, 2}, 
        {2, 2,3},{5,4,3},{6,4, 5}}; 
    int n = sizeof(arr)/sizeof(Triangle); 
  
    cout << "Number of Unique Triangles are "
         << countUniqueTriangles(arr, n); 
    return 0; 
} 
//STL sort() using our own comparator
#include <bits/stdc++.h>
using namespace std;

struct Interval {
    int start, end;
};
 
bool compareInterval(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}
 
int main()
{
    Interval arr[]
        = { { 6, 8 }, { 1, 9 }, { 2, 4 }, { 4, 7 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    
    sort(arr, arr + n, compareInterval);
 
    cout << "Intervals sorted by start time : ";
    for (int i = 0; i < n; i++)
        cout << "[" << arr[i].start << "," << arr[i].end
             << "] ";
 
    return 0;
}

