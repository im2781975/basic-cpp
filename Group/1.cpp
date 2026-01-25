def linearSearch(arr, val):
    i = 0
    while i < len(arr):
        if arr[i] == val:
            return i
        i += 1
    return -1
arr = [1, 2, 7, 5, 9]
val = 5
if linearSearch(arr, val):
    print("Yes")
else:
    print("No")
###
def BinarySearch(arr, l, r, val):
    if l > r:
        return -1
    else:
        mid = (l + r)//2
        if arr[mid] == val:
            return mid
        elif val < arr[mid]:
            return BinarySearch(arr, l, mid -1, val)
        else:
            return BinarySearch(arr, mid + 1, r, val)
arr = [2, 3, 4, 7, 6]
print(BinarySearch(arr, 0, len(arr) - 1, 7))
###
def recursiveMin(arr, l, r):
    if l == r:
        return arr[l]
    else:
        mid = (l + r) //2
        return min(recursiveMin(arr, l, mid), recursiveMin(arr, mid + 1, r))
arr = [2, 3, 1, 5, 4]
print(recursiveMin(arr, 0, len(arr) - 1))

  using namespace std;
int BinarySearch(int arr[], int l, int r, int val){
    if(l > r)
        return -1;
    else{
        int mid = (l + r)/2;
        if(arr[mid] == val)
            return mid;
        if(mid == 0)
            return -1;
        elif(val < arr[mid])
            return BinarySearch(arr, l, mid - 1, val);
        else
            return BinarySearch(arr, mid + 1,  r, val);
    }
}
using namespace std;
int LinearSearch(int arr[], int len, int val){
    int i = 0;
    while(i < len){
        if(arr[i] == val)
            return i;
        i++;
    }
    return -1;
}
using namespace std;
int RecursiveMin(int arr[], int len, int l, int r){
    if(l == r)
        return arr[l];
    else{
        int mid= (l + r)/2;
        return min(RecursiveMin(arr, len, l, mid - 1), RecursiveMin(arr, len, mid + 1, r) );
    }
}
using namespace std;
int BinarySearch(int arr[], int l, int r, int val){
    if(l > r)
        return -1;
    else{
        int mid = (l + r)/2;
        if(arr[mid] == val)
            return mid;
        if(mid == 0)
            return -1;
        elif(val < arr[mid])
            return BinarySearch(arr, l, mid - 1, val);
        else
            return BinarySearch(arr, mid + 1,  r, val);
    }
}
using namespace std;
int RecursiveMin(int arr[], int len, int l, int r){
    if(l == r)
        return arr[l];
    else{
        int mid= (l + r)/2;
        return min(RecursiveMin(arr, len, l, mid - 1), RecursiveMin(arr, len, mid + 1, r) );
    }
}
/**/
using namespace std;
int LinearSearch(int arr[], int len, int val){
    int i = 0;
    while(i < len){
        if(arr[i] == val)
            return i;
        i++;
    }
    return -1;
}
#include <bits/stdc++.h>
using namespace std;

int arr[200005];

int main() {
    ios::sync_with_stdio(false); // Faster I/O
    cin.tie(nullptr);

    int n, q, sum = 0;
    cin >> n >> q;

    // Reading the array and counting non-zero elements
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] != 0) sum++;
    }

    while (q--) {
        int t, v;
        cin >> t >> v;

        if (t == 2) { // Increment operation
            if (arr[v] == 0) sum++;  // Only increase sum if arr[v] was 0
            arr[v]++;
        } 
        else if (t == 1) { // Decrement operation
            if (arr[v] > 0) { 
                arr[v]--;
                if (arr[v] == 0) sum--;  // Decrease sum only when arr[v] becomes 0
            }
        }

        cout << sum << "\n";  // Faster output using cout
    }

    return 0;
}
