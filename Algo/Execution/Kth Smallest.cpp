// returns kth smallest index in the matrix
int kthSmallest(int mat[4][4], int n, int k) {
    //  We know the answer lies between the first and the last element So do a binary search on answer based on the number of elements
    // our current element is greater than the elements in the matrix
    int l = mat[0][0], r = mat[n - 1][n - 1];
 
    while (l <= r) {
        int mid = l + (r - l) / 2;
        int greaterThanOrEqualMid = getElementsGreaterThanOrEqual(mid, n, mat);
 
        if (greaterThanOrEqualMid >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return l;
}
// returns count of elements in matrix less than of equal to num
int getElementsGreaterThanOrEqual(int num, int n, int mat[4][4]) {
    int ans = 0;
 
    for (int i = 0; i < n; i++) {
        // if num is less than the first element then no more element in matrix further are less than or equal to num
        if (mat[i][0] > num) {
            return ans;
        }
        // if num is greater than last element, it is greater than all elements in that row
        if (mat[i][n - 1] <= num) {
            ans += n;
            continue;
        }
        // This contain the col index of last element in matrix less than of equal to num
        int greaterThan = 0;
        for (int jump = n / 2; jump >= 1; jump /= 2) {
            while (greaterThan + jump < n &&
                   mat[i][greaterThan + jump] <= num) {
                greaterThan += jump;
            }
        }
        ans += greaterThan + 1;
    }
    return ans;
}
// kth largest element in a 2d array sorted row-wise & column-wise
int kthSmallest(int mat[4][4], int n, int k)
{
    
    auto cmp = [&](pair<int,int> a,pair<int,int> b){
        return mat[a.first][a.second] > mat[b.first][b.second];
    };
    //DECLARING priority_queue AND PUSHING FIRST ROW IN IT
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    for(int i=0; i<n; i++){
        pq.push({i,0});
    }
    for(int i=1; i<k; i++){
        auto p = pq.top();
        pq.pop();
        //AFTER POPPING, WE'LL PUSH NEXT ELEMENT OF THE ROW IN THE HEAP
        if(p.second+1 < n) pq.push({p.first,p.second + 1});
    }
    // ON THE k'th ITERATION, pq.top() will be our answer.
    return mat[pq.top().first][pq.top().second];
}
int kthSmallest(int arr[], int N, int K)
{
    // Create a max heap (priority queue)
    priority_queue<int> pq;
    // Iterate through the array elements
    for (int i = 0; i < N; i++) {
        // Push the current element onto the max heap
        pq.push(arr[i]);
 
        // If the size of the max heap exceeds K, remove the largest element
        if (pq.size() > K)
            pq.pop();
    }
    // Return the Kth smallest element (top of the max heap)
    return pq.top();
}
int kthSmallest(int arr[][4], int n, int k)
{
    // Create a min-heap (priority queue) to store elements in sorted order
    priority_queue<int, vector<int>, greater<int> > pq;
    // Add all elements of the 2D array to the min-heap
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pq.push(arr[i][j]);
        }
    }
    int c = 0;
    while (!pq.empty()) {
        int temp = pq.top();
        pq.pop();
        c++;
 
        if (c == k)
            return temp;
    }
    // If kth smallest element not found, return -1
    return -1;
}
int kthSmallest(int mat[4][4], int n, int k)
{
 
    int a[n*n];
    int v = 0;
 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            a[v] = mat[i][j];
            v++;
        }
    } 
    sort(a, a + (n*n));
    int result = a[k - 1];
    return result;
}
int kthSmallest(vector<vector<int>>& matrix, int k) {
// vector<vector<int>> matrix = {{1,5,9},{10,11,13},{12,13,15}};
      int k = 8;
    priority_queue<int, vector<int>, greater<int>> minH;
    
    for (auto& row : matrix)
        for (int num : row) {
            minH.push(num);
            if (minH.size() > k) minH.pop();
        }
    
    return minH.top();
}
// nth smallest in the array
int count(vector<int>& nums, int& mid)
{
    int cnt = 0;
 
    for (int i = 0; i < nums.size(); i++)
        if (nums[i] <= mid)
            cnt++;
 
    return cnt;
}
int kthSmallest(vector<int> nums, int& k) {
    int low = INT_MAX;
    int high = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        low = min(low, nums[i]);
        high = max(high, nums[i]);
    }
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (count(nums, mid) < k)
            low = mid + 1;
 
        else
            high = mid;
    }
    return low;
}
// Nth smallest
int kthSmallest(int arr[], int l, int r, int k) {
    int pos = partition(arr, l, r);
    
    if (pos == l + k - 1)
        return arr[pos];
    else if (pos > l + k - 1)
        return kthSmallest(arr, l, pos - 1, k);
    else
        return kthSmallest(arr, pos + 1, r, k - (pos - l + 1));
}
int partition(int arr[], int l, int r) {
    int pivot = arr[r], i = l;
    for (int j = l; j < r; j++)
        if (arr[j] <= pivot)
            swap(arr[i++], arr[j]);
    swap(arr[i], arr[r]);
    return i;
}
// This function returns the kth smallest element in an array
int kthSmallest(int arr[], int n, int k) {
    // First, find the maximum element in the array
    int max_element = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_element) {
            max_element = arr[i];
        }
    }
    // Create an array to store the frequency of each  element in the input array
    int freq[max_element + 1] = {0};
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }
    // Keep track of the cumulative frequency of elements in the input array
    int count = 0;
    for (int i = 0; i <= max_element; i++) {
        if (freq[i] != 0) {
            count += freq[i];
            if (count >= k) {
                // If we have seen k or more elements, return the current element
                return i;
            }
        }
    }
    return -1;
}
// Function to return K'th smallest element in a given array
int kthSmallest(int arr[], int N, int K)
{
    // Sort the given array
    sort(arr, arr + N);
    // Return k'th element in the sorted array
    return arr[K - 1];
}
int findMedian(int arr[], int n) {
    sort(arr, arr + n);
    return arr[n/2];
}
int partition(int arr[], int l, int r, int x) {
    // Find x or use last element as fallback
    int pivotIdx = l;
    for (int i = l; i <= r; i++)
        if (arr[i] == x) {
            pivotIdx = i;
            break;
        }
    swap(&arr[pivotIdx], &arr[r]);
    
    int pivot = arr[r], i = l;
    for (int j = l; j < r; j++)
        if (arr[j] <= pivot)
            swap(&arr[i++], &arr[j]);
    swap(&arr[i], &arr[r]);
    return i;
}
int kthSmallest(int arr[], int l, int r, int k) {
    if (k > 0 && k <= r - l + 1) {
        int n = r - l + 1;
        int numGroups = (n + 4) / 5;
        int median[numGroups];
        
        // Groups of 5 (or less for last)
        int i = 0;
        for (; i < n/5; i++)
            median[i] = findMedian(arr + l + i*5, 5);
        if (i*5 < n)
            median[i++] = findMedian(arr + l + i*5, n%5);
        
        int medOfMed = (i == 1) ? median[0] : kthSmallest(median, 0, i-1, i/2);
        int pos = partition(arr, l, r, medOfMed);
        
        if (pos - l == k - 1) return arr[pos];
        if (pos - l > k - 1) return kthSmallest(arr, l, pos - 1, k);
        return kthSmallest(arr, pos + 1, r, k - (pos - l + 1));
    }
    return INT_MAX;
}
// kth smallest
int partition(int arr[], int l, int r) {
    int pivot = arr[r], i = l;
    for (int j = l; j < r; j++)
        if (arr[j] <= pivot)
            swap(arr[i++], arr[j]);
    swap(arr[i], arr[r]);
    return i;
}
int kthSmallest(int arr[], int l, int r, int k) {
    int pos = partition(arr, l, r);
    if (pos == l + k - 1) return arr[pos];
    if (pos > l + k - 1) return kthSmallest(arr, l, pos - 1, k);
    return kthSmallest(arr, pos + 1, r, k - (pos - l + 1));
}

