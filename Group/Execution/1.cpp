#include <bits/stdc++.h>
using namespace std;

struct Point { int x, y; };

float dist(Point a, Point b) {
    return hypot(a.x - b.x, a.y - b.y);
}

float brute(vector<Point>& p, int l, int r) {
    float min_d = INFINITY;
    for (int i = l; i < r; i++)
        for (int j = i+1; j < r; j++)
            min_d = min(min_d, dist(p[i], p[j]));
    return min_d;
}

float strip(vector<Point>& p, int size, float d) {
    sort(p.begin(), p.begin() + size, [](Point a, Point b){ return a.y < b.y; });
    float min_d = d;
    for (int i = 0; i < size; i++)
        for (int j = i+1; j < size && p[j].y - p[i].y < min_d; j++)
            min_d = min(min_d, dist(p[i], p[j]));
    return min_d;
}

float closest(vector<Point>& p, int l, int r) {
    if (r - l <= 3) return brute(p, l, r);
    
    int mid = (l + r) / 2;
    Point mid_p = p[mid];
    
    float dl = closest(p, l, mid);
    float dr = closest(p, mid, r);
    float d = min(dl, dr);
    
    vector<Point> strip;
    for (int i = l; i < r; i++)
        if (abs(p[i].x - mid_p.x) < d)
            strip.push_back(p[i]);
    
    return min(d, strip(strip, strip.size(), d));
}

int main() {
    vector<Point> p = {{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}};
    sort(p.begin(), p.end(), [](Point a, Point b){ return a.x < b.x; });
    cout << fixed << setprecision(2) << closest(p, 0, p.size()) << endl;
}
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
 // C++ program to do range  minimum query
int st[500][9];  // sparse table: st[i][j] = min index in [i, i+2^j)

void build(int arr[], int n) {
    for (int i = 0; i < n; i++) st[i][0] = i;
    
    for (int j = 1; (1<<j) <= n; j++)
        for (int i = 0; i + (1<<j) - 1 < n; i++)
            st[i][j] = arr[st[i][j-1]] < arr[st[i+(1<<(j-1))][j-1]] ? 
                      st[i][j-1] : st[i+(1<<(j-1))][j-1];
}

int query(int arr[], int L, int R) {
    int j = 31 - __builtin_clz(R-L+1);  // log2 floor
    return arr[st[L][j]] <= arr[st[R-(1<<j)+1][j]] ? 
           st[L][j] : st[R-(1<<j)+1][j];
}

int main() {
    int arr[] = {7,2,3,0,5,10,3,12,18};
    int n = 9;
    
    build(arr, n);
    
    vector<pair<int,int>> queries = {{0,4}, {4,7}, {7,8}};
    for (auto [l,r] : queries)
        cout << "Minimum of [" << l << "," << r << "] is " << arr[query(arr,l,r)] << endl;
}
int dp[500][500];

void build(int arr[], int n) {
    for (int i = 0; i < n; i++) dp[i][i] = i;
    
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            dp[i][j] = arr[dp[i][j-1]] < arr[j] ? dp[i][j-1] : j;
}

int query(int arr[], int l, int r) {
    return arr[dp[l][r]];
}

int main() {
    int arr[] = {7,2,3,0,5,10,3,12,18};
    int n = 9;
    
    build(arr, n);
    
    vector<pair<int,int>> q = {{0,4},{4,7},{7,8}};
    for (auto [l,r] : q)
        cout << "Minimum of [" << l << "," << r << "] is " << arr[query(arr,l,r)] << endl;
}
// Program to compute sum of ranges for different range
int block_size;
bool cmp(pair<int,int> a, pair<int,int> b) {
    int ba = a.first / block_size, bb = b.first / block_size;
    return ba != bb ? ba < bb : a.second < b.second;
}

int main() {
    vector<int> arr = {1,1,2,1,3,4,5,2,8};
    vector<pair<int,int>> queries = {{0,4},{1,3},{2,4}};
    
    block_size = sqrt(arr.size());
    sort(queries.begin(), queries.end(), cmp);
    
    int L=0, R=-1, sum=0;
    
    for (auto [ql, qr] : queries) {
        while (L < ql) sum -= arr[L++];
        while (L > ql) sum += arr[--L];
        while (R < qr) sum += arr[++R];
        while (R > qr) sum -= arr[R--];
        
        cout << "Sum of [" << ql << "," << qr << "] is " << sum << endl;
    }
}
// sum array ranges
int main() {
    vector<int> arr = {1,1,2,1,3,4,5,2,8};
    vector<pair<int,int>> q = {{0,4},{1,3},{2,4}};
    
    for (auto [l,r] : q) {
        int sum = 0;
        for (int i=l; i<=r; i++) sum += arr[i];
        cout << "Sum of [" << l << "," << r << "] is " << sum << endl;
    }
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
bool overlaps(vector<pair<int,int>>& ivs) {
    sort(ivs.begin(), ivs.end());  // sort by start
    
    for (int i = 1; i < ivs.size(); i++)
        if (ivs[i].first <= ivs[i-1].second)
            return true;
    return false;
}

int main() {
    vector<pair<int,int>> no = {{1,3},{7,9},{4,6},{10,13}};
    cout << (overlaps(no) ? "Yes" : "No") << endl;  // No
    
    vector<pair<int,int>> yes = {{6,8},{1,3},{2,4},{4,7}};
    cout << (overlaps(yes) ? "Yes" : "No") << endl;  // Yes
}
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
int main() {
    vector<int> arr = {3,1,4,4,5,2,6,1};
    int k = 2;
    
    unordered_map<int,int> freq;
    for (int x : arr) freq[x]++;
    
    vector<pair<int,int>> f(freq.begin(), freq.end());
    sort(f.begin(), f.end(), [](auto& a, auto& b){
        return a.second > b.second || (a.second == b.second && a.first > b.first);
    });
    
    cout << k << " numbers with most occurrences are:
";
    for (int i = 0; i < k; i++) cout << f[i].first << " ";
}
int main() {
    vector<tuple<int,int,int>> triangles = {
        {3,2,2}, {3,4,5}, {1,2,2}, {2,2,3}, {5,4,3}, {6,4,5}
    };
    
    set<tuple<int,int,int>> unique;
    for (auto [a,b,c] : triangles) {
        vector<int> sides = {a,b,c};
        sort(sides.begin(), sides.end());
        unique.emplace(sides[0], sides[1], sides[2]);
    }
    
    cout << "Number of Unique Triangles are " << unique.size();
}
int main() {
    vector<array<int,3>> triangles = {
        {3,2,2}, {3,4,5}, {1,2,2}, {2,2,3}, {5,4,3}, {6,4,5}
    };
    
    sort(triangles.begin(), triangles.end());
    auto it = unique(triangles.begin(), triangles.end());
    triangles.erase(it, triangles.end());
    
    cout << "Number of Unique Triangles are " << triangles.size();
}
int main() {
    vector<pair<int,int>> ivs = {{6,8},{1,9},{2,4},{4,7}};
    sort(ivs.begin(), ivs.end());  // sorts by first (start)
    
    cout << "Intervals sorted by start time: ";
    for (auto [s,e] : ivs)
        cout << "[" << s << "," << e << "] ";
}
struct Block {
    int min_val, start_idx, end_idx;
};

int main() {
    vector<int> arr(100005);
    // Read N and arr[1..N] from file
    
    int n = arr.size(), block_size = sqrt(n), num_blocks = (n + block_size - 1) / block_size;
    vector<Block> blocks(num_blocks + 1);
    
    // Step 1: Sort each block
    for (int b = 1; b <= num_blocks; b++) {
        int start = (b-1) * block_size + 1;
        int end = min(start + block_size - 1, n);
        
        sort(arr.begin() + start - 1, arr.begin() + end);
        blocks[b] = {arr[start-1], start-1, end-1};
    }
    
    // Step 2: Sort blocks by min value
    sort(blocks.begin() + 1, blocks.begin() + 1 + num_blocks, 
         [](const Block& a, const Block& b) { return a.min_val < b.min_val; });
    
    // Step 3: Merge blocks into final sorted array (simplified extraction)
    vector<int> output;
    for (int i = 1; i <= n; i++) {
        // Extract smallest from first block, shift blocks
        output.push_back(blocks[1].min_val);
        // Logic to advance first block's pointer and re-sort blocks
    }
    
double total_time;
    	clock_t start, end;
    	start = clock();
    	//time count starts
    	srand(time(NULL));
end = clock();
    	//time count stops
    	total_time = ((double) (end - start)) / CLK_TCK;
    	//calulate total time
    	printf("\nTime taken ---> : %f", total_time);
    	return 0;
}
using namespace std;
int Fib(int n){
    if(n == 1 || n == 2)
        return 1;
    int first = 1, sec = 1, fib;
    for(int i = 2; i <= n; i++){
        fib = first + sec;
        first = sec;
        sec = fib;
    }
    return fib;
}
/**/
using namespace std;
int Fact(int n){
    int fact = 1;
    for(int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}
/**/

/***/

using namespace std;
void Hanoi(int n, int a, int b, int c){
    if(n == 1)
        cout << a << " " << c << "\n";
    else{
        Hanoi(n - 1, a, b, c);
        cout << a << " " << c << "\n";
        Hanoi(n - 1, b, c, a);
    }
}
/**/
using namespace std;
int Fib(int n){
    if(n == 1 || n == 2)
        return 1;
    int first = 1, sec = 1, fib;
    for(int i = 2; i <= n; i++){
        fib = first + sec;
        first = sec;
        sec = fib;
    }
    return fib;
}
/**/
using namespace std;
int Fact(int n){
    int fact = 1;
    for(int i = 2; i <= n; i++)
        fact *= i;
    return fact;
}
using namespace std;
void Hanoi(int n, int a, int b, int c){
    if(n == 1)
        cout << a << " " << c << "\n";
    else{
        Hanoi(n - 1, a, b, c);
        cout << a << " " << c << "\n";
        Hanoi(n - 1, b, c, a);
    }
}
int Min(int x, int y, int z)
{
        return min(min(x,y),z);
}
int editDis(string s1, string s2, int m, int n)
{
        int dp[m+1][n+1];
        for(int i=0; i<=m; i++){
                for(int j=0; i<=n; j++){
                        if(i==0)
                                dp[i][j]=j;
                        else if(j==0)
                                dp[i][j]=i;
                        else
                                dp[i][j]=1 + Min(dp[i][j-1],dp[i-1][j],dp[i-1][j-1]);
                }
        }
        return dp[m][n];
}
#include <bits/stdc++.h>
using namespace std;

bool isValid(int deg[], int n) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(deg[i] < 0 || deg[i] >= n) return false;
        sum += deg[i];
    }
    return sum % 2 == 0;
}

void printGraph(int deg[], int n) {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    
    // Havel-Hakimi: connect highest degrees first
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if(deg[i] > 0 && deg[j] > 0) {
                mat[i][j] = mat[j][i] = 1;
                deg[i]--; deg[j]--;
            }
        }
    }
    
    // Print matrix
    cout << "Adjacency Matrix:
";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) 
            cout << mat[i][j] << " ";
        cout << "
";
    }
}

int main() {
    int deg[] = {2, 2, 1, 1, 1};
    int n = 5;
    
    if(isValid(deg, n)) {
        printGraph(deg, n);
    } else {
        cout << "Invalid degree sequence
";
    }
}
