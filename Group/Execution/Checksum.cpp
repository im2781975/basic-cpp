// takes n integer & counts the number of inversions in the array using Merge. Two elements a[i] and a[j] form an inversion if i < j and a[i] > a[j].
//number of inversions in an array is a measure of how far the array is from being sorted.
#include<bits/stdc++.h>
using namespace std;
int trg, tot_count;

int pairSum(vector<int>a, vector<int>b)
{
    //it will count unique pair sum.like vect_a={1,2,3};b={1,2,3};sum =a[i]+b[i].sum will be unique
    int n = a.size() + b.size(), ix1 = 0, ix2 = 0, sum = 0;
    for(int i = 0 ; i < n; i++) 
    {
        if(ix1==a.size()||ix2==b.size()) 
        {
            break;
        }
        if (a[ix1] <= b[ix2]) 
        {
            ix1++;
        } 
        else 
        {
            sum += a.size() - ix1;
            ix2++;
        }
    }
    return sum;
}
vector<int>merged(vector<int>a, vector<int>b)
{
    int n = a.size() + b.size(), ix1= 0, ix2 = 0;
    vector<int>v;
    for(int i = 0 ; i < n; i++) 
    {
        if(ix1 == a.size()) 
        {
            v.push_back(b[ix2]);
            ix2++;
        } 
        else if (ix2 == b.size() || a[ix1] < b[ix2]) 
        {
            v.push_back(a[ix1]);
            ix1++;
        } 
        else 
        {
            v.push_back(b[ix2]);
            ix2++;
        }
    }
    return v;
}
vector<int>merge_sort(vector<int>v)
{
    int n = v.size();
    vector<int>a,b;

    if (n <= 1) return v;

    for(int i = 0 ; i < n/2; i++)
        a.push_back(v[i]);

    for(int i = n/2; i < n; i++)
        b.push_back(v[i]);

    vector<int>sorted_a = merge_sort(a);
    vector<int>sorted_b = merge_sort(b);

    tot_count += pairSum(sorted_a, sorted_b);

    return merged(sorted_a, sorted_b);
}
int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0 ; i < n; i++)
        cin>>v[i];

    vector<int>ans = merge_sort(v);
    cout<< tot_count << endl;
}
#include<bits/stdc++.h>
using namespace std;
int trg;
bool isPossible = false;

bool pairSum(vector<int>a,vector<int>b)
{
    int n = a.size() + b.size(), ix1 = 0, ix2 = b.size() - 1;
    for(int i = 0 ; i < n; i++) {
        if(ix1 == a.size() || ix2 < 0) {
            break;
        }
        if (a[ix1] + b[ix2] > trg) {
            ix2--;
        } else if (a[ix1] + b[ix2] < trg) {
            ix1++;
        } else {
            return true;
        }
    }

    return false;
}

vector<int>merged(vector<int>a, vector<int>b)
{
    int n = a.size() + b.size(), ix1= 0, ix2 = 0;
    vector<int>v;

    for(int i = 0 ; i < n; i++) {
        if(ix1 == a.size()) {
            v.push_back(b[ix2]);
            ix2++;
        } else if (ix2 == b.size() || a[ix1] < b[ix2]) {
            v.push_back(a[ix1]);
            ix1++;
        } else {
            v.push_back(b[ix2]);
            ix2++;
        }
    }

    return v;
}

vector<int>merge_sort(vector<int>v)
{
    int n = v.size();
    vector<int>a,b;

    if (n <= 1) return v;

    for(int i = 0 ; i < n/2; i++)
        a.push_back(v[i]);

    for(int i = n/2; i < n; i++)
        b.push_back(v[i]);

    vector<int>sorted_a = merge_sort(a);
    vector<int>sorted_b = merge_sort(b);

    isPossible = isPossible | pairSum(sorted_a, sorted_b);

    return merged(sorted_a, sorted_b);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i = 0 ; i < n; i++)
        cin>>v[i];

    cin>>trg;
    vector<int>ans = merge_sort(v);

    isPossible ? cout<< "YES" : cout << "NO";
    cout << endl;
}
//check if there exist two distinct elements in the sorted array whose sum is equal to 'k'.
//If such elements exist, output "Yes"; otherwise, output "No".
#include<bits/stdc++.h>
using namespace std;
bool found = false;
int k;
vector<int> merge(vector<int> a)
{
    int n = a.size();
    if (a.size() <= 1)
        return a;
    
    vector<int> b, c;
    int mid = a.size() / 2;
    for (int i = 0; i < mid; i++)
        b.push_back(a[i]);
    
    for (int i = mid; i < a.size(); i++)
        c.push_back(a[i]);
    
    vector<int> sorted_b = merge(b);
    vector<int> sorted_c = merge(c);
    vector<int> sorted_a;
    int idx1 = 0, idx2 = 0;
    
    for (int i = 0; i < a.size(); i++)
    {
        if (idx1 == sorted_b.size())
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
        else if (idx2 == sorted_c.size())
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else if (sorted_b[idx1] > sorted_c[idx2])
        {
            sorted_a.push_back(sorted_b[idx1]);
            idx1++;
        }
        else
        {
            sorted_a.push_back(sorted_c[idx2]);
            idx2++;
        }
    }
    if (sorted_a.size() == n)
    {
        int i = 0, j = n - 1;
        if (sorted_a[i] + sorted_a[j] > k)
            j--;
        else if (sorted_a[i] + sorted_a[j] < k)
            i++;
        else
            found = true;
    }
    return sorted_a;
}
void print(vector<int> res)
{
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    int arr[n + 2];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    cin >> k;
    vector<int> ar(arr, arr + n);
    vector<int> ans = merge(ar);
    if (found == true)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
//takes n integer & an integer k, and checks if there are two numbers in the array which sums to k.
#include<bits/stdc++.h>
using namespace std;
vector<int>merged(vector<int>a, vector<int>b)
{
    vector<int>output;
    int idx1 = 0;
    int idx2 = 0;
    int n = a.size() + b.size();

    for(int i=0; i<n; i++)
    {
        if(idx1 == a.size())
        {
            output.push_back(b[idx2]);
            idx2++;
        }
        else if(idx2 == b.size())
        {
            output.push_back(a[idx1]);
            idx1++;
        }
        else if(a[idx1] > b[idx2])
        {
            output.push_back(b[idx2]);
            idx2++;
        }
        else
        {
            output.push_back(a[idx1]);
            idx1++;
        }
    }
    return output;
}

vector<int>devide_arr(vector<int>p)
{
    vector<int>part_1;
    vector<int>part_2;

    if(p.size() <= 1)
        return p;

    int len = p.size();
    for(int i =0; i<len/2; i++)
    {
        part_1.push_back(p[i]);
    }
    for(int i=len/2; i<len; i++)
    {
        part_2.push_back(p[i]);
    }

    vector<int>Sorted_part_1 = devide_arr(part_1);
    vector<int>Sorted_part_2 = devide_arr(part_2);

    return merged(Sorted_part_1, Sorted_part_2);
}

bool two_point(vector<int>arr, int fnd)
{
    int len = arr.size();
    int ix1 = 0;
    int ix2 = len - 1;


    while(ix1<ix2)
    {
        if(arr[ix1] + arr[ix2] == fnd)
            return true;
        else if(arr[ix1] + arr[ix2] > fnd)
        {
            ix2--;
        }
        else if(arr[ix1] + arr[ix2] < fnd)
        {
            ix1++;
        }

    }
    return false;

}


int main()
{
    int r, x, k;
    vector<int>p;
    cin >> r;

    for(int i=0; i<r; i++)
    {
        cin >> x;
        p.push_back(x);
    }
    cin >> k;
    vector<int>ans = devide_arr(p);

    if(two_point(ans, k))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}


