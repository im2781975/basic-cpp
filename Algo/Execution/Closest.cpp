#include<bits/stdc+.h>
using namespace std;
// Check if Tree A is mirror image of Tree B
int mirrorTree(int *arr, int *ray) {
    int n = 3, e = 2;
    vector <stack <int>> st; vector <queue <int>> qe;
    for(int i = 0; i <= n; i++) {
        st.push(stack <int> ());
        queue <int> q; qe.push(q);
    }
    for(int i = 0; i < 2 * e; i += 2) {
        st[arr[i]].push(arr[i + 1]);
        qe[ray[i]].push(ray[i + 1]);
    }
    for(int i = 1; i <= n; i++) {
        while(!st[i].empty() && !qe[i].empty()) {
            int x = st[i].top(); st[i].pop();
            int y = qe[i].top(); qe[i].pop();
            if(x != y) return 0;
        }
    }
    return 1;
}
int mirrorTree(int *u1, int *v1, int *u2, int *v2) {
    int n = sizeof(u1) / sizeof(u1[0]);
    unordered_map <int, stack <int>> mp;
    for(int i = 0; i < n; i++) mp[u1[i]].push_back(v1[i]);
    for(int i = 0; i < n; i++) {
        if(mp[u2[i]].top() != v2[i]) return 0;
        mp[u2[i]].pop();
    }
    return 1;
}
// find Two elements whose sum is closest to zero
void minsum(int *arr, int n) {
    if(n < 2) return;
    sort(arr, arr + n, [](int a, int b){
        return abs(a) < abs(b); });
    int mini = INT_MAX, x = -1, y = -1;
    for(int i = 1; i < n; i++) {
        if(abs(arr[i - 1] + arr[i]) <= mini) {
            mini = abs(arr[i - 1] + arr[i]);
            x = i - 1; y = i;
        }
    }
    cout << arr[x] << " " << arr[y] << endl;
}
void minsum(int *arr, int n) {
    int tmp = abs(arr[0] + arr[1]);
    int minL = 0, minR = 1;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            int sum = abs(arr[i] + arr[j]);
            if (sum < tmp) {
                tmp = sum; minL = i; minR = j;
            }
        }
    }
    cout << arr[minR] << " " << arr[minL] << endl;
}
void minsum(int *arr, int n) {
    if(n < 2) return;
    sort(arr, arr + n);
    int tmp = INT_MAX, minL = 0, minR = 1;
    int left = 0, right = n - 1;
    while (left < right) {
        int current = abs(arr[left] + arr[right]);
        if (current < minSum) {
            tmp = current;
            minL = left;
            minR = right;
        }
        if (arr[left] + arr[right] < 0) left++;
        else right--;
    }
    cout << arr[minL] << " " << arr[minR] << endl;
}
// find the pair from two sorted arrays such that the sum of pair is closest to a given number x
void printClosestPair(int arr[], int ray[], int m, int n, int x) {
    int l = 0, r = n - 1;
    int minDiff = INT_MAX;
    int resL = -1, resR = -1;
    while (l < m && r >= 0) {
        int sum = arr[l] + ray[r];
        int diff = abs(sum - x);
        if (diff < minDiff) {
            minDiff = diff;
            resL = l; resR = r;
        }
        if (sum > x) r--;
        else l++;
    }
    cout << arr[resL] << " " << ray[resR] << endl;
}
int Bsearch(int *arr, int l, int r, int val) {
    if(l > r) return -1;
    int mid = l + (r - l) >> 2;
    if(arr[mid] == val) return mid;
    else if (arr[mid] > val) return Bsearch(arr, l, mid - 1, val);
    else
        return Bsearch(arr, mid + 1, r, val);
}
void printClosest(int arr[], int ray[], int m, int n, int x) { /*
    for(int i = 0; i < m; i++) {
        int idx = Bsearch(ray, 0, n - 1, x - arr[i]);
        if(idx >= 0 && idx < n && abs(arr[i] + ray[idx] - val) < abs(arr[i] + ray[idx - 1] - x)) printClosest(arr, ray, m, n, val);
        else if(idx > 0 && abs(arr[i] + ray[idx - 1] - val) < abs(arr[i] + ray[idx] - x)) idx--;
    } */
    int diff = INT_MAX;
    int resL, resR;
    int l = 0, r = n - 1;
    while (l < m && r >= 0) {
        if (abs(arr[l] + ray[r] - x) < diff) {
            resL = l; resR = r;
            diff = abs(arr[l] + ray[r] - x);
        }
        if (ar1[l] + ar2[r] > x) r--;
        else l++;
    }
    cout << arr[resL] << " " << ray[resR];
}
// Find Closest Triplet by Max Pairwise Difference
void printClosest(int *arr, int *ray, int *ect, int p, int q, int r) {
    sort(arr, arr + p); sort(ray, ray + q); sort(ect, ect + r);
    int minDiff = INT_MAX;
    int resI = 0, resJ = 0, resK = 0;
    int i = 0, j = 0, k = 0;
    while (i < p && j < q && k < r) {
        int mn = min({arr[i], ray[j], ect[k]});
        int mx = max({arr[i], ray[j], ect[k]});
        int diff = mx - mn;
        if (diff < minDiff) {
            minDiff = diff;
            resI = i; resJ = j; resK = k;
        }
        if (arr[i] == mn) i++;
        else if (ray[j] == mn) j++;
        else k++;
    }
    cout << arr[resI] << " " << ray[resJ] << " " << ect[resK] << endl;
}
void findClosestTriplet(int A[], int B[], int C[], int p, int q, int r) {
    int minDiff = INT_MAX;
    int resA = 0, resB = 0, resC = 0;
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < q; j++) {
            for (int k = 0; k < r; k++) {
                int diff1 = abs(A[i] - B[j]);
                int diff2 = abs(B[j] - C[k]);
                int diff3 = abs(C[k] - A[i]);
                int maxDiff = max({diff1, diff2, diff3});
                if (maxDiff < minDiff) {
                    minDiff = maxDiff;
                    resA = A[i]; resB = B[j]; resC = C[k];
                }
            }
        }
    }
    cout << resA << " " << resB << " " << resC << endl;
}
