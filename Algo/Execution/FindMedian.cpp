#include<bits/stdc++.h>
using namespace std;
// finds the minimum number of dice rolls needed to reach position 30 on a 5x6 board (30 squares)
int tmp[35];
int func(int pos, unordered_map<int, int>& board) {
    if (pos >= 30) return 0;
    if (tmp[pos] != -1) return tmp[pos];
    
    int minThrows = INT_MAX;
    for (int dice = 1; dice <= 6; dice++) {
        int next = pos + dice;
        
        if (board.count(next)) {
            if (board[next] < next) continue; 
            next = board[next]; 
        }
        int throws = func(next, board);
        if (throws != INT_MAX)  
            minThrows = min(minThrows, throws + 1);
    }
    return tmp[pos] = minThrows;
}
int func(int i, unordered_map <int, int> mp) {
    if(i >= 30) return 0;
    else if(tmp[i] != -1) return tmp[i];
    int mini = INT_MAX;
    for(int j = 1; j <= 6; j++) {
        int k = i + j;
        if(mp.count(k) > 0) {
            if(mp[k] < k) continue;
            k = mp[k];
        }
        mini = min(mini, func(k, mp) + 1);
    }
    tmp[i] = mini;
    return tmp[i];
}

int minthrow(int n, vector <int> arr) {
    /* int N = 8;
    vector <int> arr{ 3,  22, 5,  8, 11, 26, 20, 29, 17, 4,  19, 7, 27, 1,  29, 9 };
 
    cout << minthrow(N, arr) << endl; */
    for(int i = 0; i < 31; i++) tmp[i] = -1;
    unordered_map <int, int> board;
    for(int i = 0; i < 2 * n; i += 2) 
        board[arr[i]] = arr[i + 1];
    return func(1, board);
}
// find the maximum rectangular area under given histogram with n bars 
int maxarea(int *arr, int n) {
    stack <int> st; st.push(-1);
    int area = arr[0], i = 0;
    vector <int> left(n, -1), right(n, n);
    while(i < n) {
        while(!st.empty() && st.top() != -1 && arr[st.top()] > arr[i]) {
            right[st.top()] = i;
            st.pop();
        }
        if(i > 0 && arr[i] == arr[i - 1])
            left[i] = left[i - 1];
        else left[i] = st.top();
        st.push(i); i++;
    }
    for(int j = 0; j < n; j++)
        area = max(arr[j] * (right[j] - left[j] - 1));
    return area;
}
int maxarea(int n, int *hist) {
    stack <int> st;
    int mxarea = 0, tp, area, i = 0;
    while (i < n) { 
        if (st.empty() || hist[st.top()] <= hist[i]) st.push(i++); 
        else { 
            tp = st.top(); st.pop(); 
            area = hist[tp] * (st.empty() ? i : i - st.top() - 1);
            if (maxarea < area) maxarea = area; 
        }
    }
    while (s.empty() == false) { 
        tp = st.top(); st.pop(); 
        area = hist[tp] * (st.empty() ? i : i - st.top() - 1);
        if (maxarea < area) maxarea = area; 
    }
    return maxarea; 
}
// finds the maximum profit path from src to dst node using at most K edges 
//in a graph where edges have negative costs (profits).
int maxcost(int n, vector <vector <int>> adj, int src, int dst, int k) {
    vector <int> tmp(n, INT_MAX); tmp[src] = 0;
    tmp[src] = 0;
    for(int i = 0; i <= k; i++) {
        vector<int> c(tmp);
        for(auto v : adj) {
            int a = v[0], b = v[1], d = v[2];
            tmp[b] = min(tmp[b], c[a] == INT_MAX ? INT_MAX : c[a] - d);
        }
    }
    if (tmp[dst] != INT_MAX) return -temp[dst];
    return -1;
}
int getmedian(int *ar1, int *ar2, int n, int m) {
    int i = 0, j = 0, cnt;
    int m1 = -1, m2 = -1;
    /* for (count = 0; count <= n; count++) {
        if (i == n) {
            m1 = m2; m2 = ar2[0];
            break;
        }
        else if (j == n) {
            m1 = m2; m2 = ar1[0];
            break;
        }
        if (ar1[i] <= ar2[j]) {
            m1 = m2; m2 = ar1[i]; i++;
        }
        else {
            m1 = m2; m2 = ar2[j]; j++;
        }
    }
    return (1.0 * (m1 + m2)) / 2; */
    
    for (count = 0; count <= (m + n) / 2; count++) {
        m2 = m1;
        if (i != n && j != m) {
            m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
        }
        else if (i < n) m1 = ar1[i++];
        else m1 = ar2[j++];
    }
    if ((m + n) % 2 == 1) return m1;
    else return (m1 + m2) / 2;
}
int getMedian(int *arr, int n) {
    if(n % 2 == 0) {
        int z = n / 2, e = arr[z];
        int q = arr[z - 1];
        return ((e + q) >> 1);
    }
    else return arr[round(n / 2)];
}
double medianOfTwoSortedArrays(vector <int> & A, vector <int> & B) {
    if (A.size() > B.size()) return medianOfTwoSortedArrays(B, A);
    
    int n = A.size(), m = B.size();
    int total = n + m;
    int half = (total + 1) / 2;
    int left = 0, right = n;
    
    while (left <= right) {
        int midA = (left + right) / 2;
        int midB = half - midA;
        
        int leftA = midA == 0 ? INT_MIN : A[midA-1];
        int rightA = midA == n ? INT_MAX : A[midA];
        int leftB = midB == 0 ? INT_MIN : B[midB-1];
        int rightB = midB == m ? INT_MAX : B[midB];
      
        if (leftA <= rightB && leftB <= rightA) {
            if (total % 2 == 1)
                return max(leftA, leftB);
            return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
        }
        else if (leftA > rightB)
            right = midA - 1;
        else
            left = midA + 1;
    }
    return 0.0;
}
double findMedian(vector<int>& A, vector<int>& B) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : A) pq.push(x);
    for (int x : B) pq.push(x);
    
    int total = A.size() + B.size();
    int target1 = total / 2;
    int target2 = (total - 1) / 2;
    
    // Pop to first middle element
    for (int i = 0; i <= target2; i++) {
        pq.pop();
    }
    if (total % 2 == 1) {
        return pq.top();
    }
    int mid1 = pq.top(); pq.pop();
    int mid2 = pq.top();
    return (mid1 + mid2) / 2.0;
}
int findmedian(int *ar1, int *ar2, int n) {
    int j = 0, i = n - 1;
    while(ar1[i] > ar2[i] && j < n && i > -1) swap(ar1[i--], ar2[j++]);
    sort(ar1, ar1 + n); sort(ar2, ar2 + n);
    return (ar1[n - 1] + ar2[0]) / 2;
}
double findMedian(int arr1[], int n, int arr2[], int n2) {
    int total = n + n2;
    // Find median position(s)
    auto findKth = [&](int k) -> int {
        int low = -1e9, high = 1e9;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int count = upper_bound(arr1, arr1 + n, mid) - arr1 +
                       upper_bound(arr2, arr2 + n2, mid) - arr2;
            if (count >= k) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    };
    if (total % 2 == 1)
        return findKth(total / 2 + 1);
    int mid1 = findKth(total / 2);
    int mid2 = findKth(total / 2 + 1);
    return (mid1 + mid2) / 2.0;
}
