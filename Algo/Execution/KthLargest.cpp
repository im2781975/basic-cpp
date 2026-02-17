// print next greater number of Q queries
void nextGreater(int *arr, int *nxt, int n) {
    /*int nxt[n] = { 0 };
    nextGreater(nxt, arr, n);
    cout << Query(arr, nxt, n, 3) << " "; */
    stack <int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            nxt[st.top()] = i; st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        nxt[st.top()] = 1; st.pop();
    }
}
int Query(int arr[], int next[], int idx) {
    return next[idx] == -1 ? -1 : arr[next[idx]];
}
// find Right smaller element of next greater element
void nextGreater(int arr[], int next[], int n, char order) {
    stack<int> s;
    for (int i = n-1; i >= 0; i--) {
        while (!s.empty() && ((order=='G' ? arr[s.top()] <= arr[i] : arr[s.top()] >= arr[i])))
            s.pop();
        next[i] = s.empty() ? -1 : s.top();
        s.push(i);
    }
}
void nextSmallerOfNextGreater(int arr[], int n) {
    int NG[n], RS[n];
    nextGreater(arr, NG, n, 'G');
    nextGreater(arr, RS, n, 'S');
    
    for (int i = 0; i < n; i++) {
        int idx = NG[i] != -1 && RS[NG[i]] != -1 ? RS[NG[i]] : -1;
        cout << (idx == -1 ? -1 : arr[idx]) << " ";
    }
}
//print next greater number of Q queries 
void nextGreater(int arr[], int query[], int n, int q) {
    for (int i = 0; i < q; i++) {
        int k = query[i];
        bool found = false;
        for (int j = k + 1; j < n; j++) {
            if (arr[j] > arr[k]) {
                cout << arr[j] << " ";
                found = true;
                break;
            }
        }
        if (!found) cout << -1 << " ";
    }
}
vector <int> nextGreater(vector <int> vec) {
    vector <int> res; stack <int> st;
    for(int i = vec.size() - 1; i >= 0; i--) {
        while(!st.empty() && st.top() <= vec[i]) st.pop();
        res.push_back(st.empty() ? -1 : st.top());
        st.push(vec[i]);
    }
    reverse(res.begin(), res.end()); return res;
}
void nextGreaterFreq(int *arr, int *res, int n) {
    unordered_map <int, int> freq;
    for(int i = 0; i < n; i++) freq[arr[i]]++;
    stack <pair <int, int>> st;
    for(int i = n - 1; i >= 0; i--) {
        while(!st.empty() && st.top().second <= freq[arr[i]]) st.pop();
        res[i] = st.empty() ? -1 : st.top().first;
        st.push({arr[i], freq[arr[i]]});
    }
}
void nextGreater(int *arr, int n) {
    stack <int> st;
    for(int i = 0; i < n; i++) {
        while(!st.empty() && arr[st.top()] < arr[i]) {
            arr[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        arr[st.top()] = -1; st.pop();
    }
}
// prints element and NGE pair for all elements of arr[] of size n
void printNGE(int arr[], int n) {
    stack <int> st; st.push(arr[0]);
    for(int i = 1; i < n; i++) {
        if(st.empty()) {
            st.push(arr[i]); continue;
        }
        while(!st.empty() && st.top() < arr[i]){
            cout << st.top() << " " << arr[i] << endl;
            st.pop();
        }
        st.push(arr[i]);
    }
    while(!st.empty()) {
        cout <<st.top() << " " << -1 << endl;
        st.pop();
    }
}
void printNGE(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int next = -1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                next = arr[j];
                break;
            }
        }
        cout << arr[i] << " " << next << endl;
    }
}
// Function to find the cross over point (the point before which elements are 
// smaller than or equal to x and after which greater than x)
int findCross(int *arr, int low, int high, int x) {
    if (arr[high] <= x) return high;
    if (arr[low] > x) return low;
    int mid = (low + high) / 2;
    if(mid < high && arr[mid] <= x && arr[mid + 1] > x) return mid;
    if(arr[mid] <= x) return findCross(arr, mid + 1, high, x);
    return findCross(arr, low, mid - 1, x);
}
void printKclosest(int *arr, int x, int k, int n) {
    int l = findCross(arr, 0, n - 1, x);
    int r = l + 1, cnt = 0;
    if (l >= 0 && arr[l] == x) l--;
    while (l >= 0 && r < n && count < k) {
        if (x - arr[l] < arr[r] - x)
            printf("%d ", arr[l--]);
        else
            printf("%d ", arr[r++]);
        count++;
    }
    while (count < k && l >= 0) {
        printf("%d ", arr[l--]);
        count++;
    }
    while (count < k && r < n) {
        printf("%d ", arr[r++]);
        count++;
    }
}
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
    for (int num : arr) {
        minH.push({abs(num - x), num});
        if (minH.size() > k) minH.pop();
    }
    vector<int> result;
    while (!minH.empty()) {
        result.push_back(minH.top().second);
        minH.pop();
    }
    sort(result.begin(), result.end());
    return result;
}
void nthlargest(int *arr, int n, int k) {
    sort(arr, arr + n, greater <int> ());
    for(int i = 0; i < k; i++) cout << arr[i] << " ";
}
int findKthLargest(int arr[], int n, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++) {
        minHeap.push(arr[i]);
        if (minHeap.size() > k) minHeap.pop();
    }
    return minHeap.top();
}
void printKLargest(int arr[], int n, int k) {
    priority_queue<int> maxHeap;
    for (int i = 0; i < n; i++) maxHeap.push(arr[i]);
    while (k-- > 0) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
// Function to find the Kth largest element in the array using binary search
int findKthLargest(int arr[], int n, int k) {
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < n; i++) {
        low = min(low, arr[i]);
        high = max(high, arr[i]);
    }
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid)  count++;
        }
        if (count >= k) low = mid + 1;
        else high = mid - 1;
    }
    return high;
}
// Function to print the K largest elements in the array
void printKLargest(int arr[], int n, int k) {
    int kthLargest = findKthLargest(arr, n, k);
    for (int i = 0; i < n; i++) {
        if (arr[i] >= kthLargest) 
            cout << arr[i] << " ";
    }
    cout << endl;
}
int partition(int arr[], int l, int r) {
    int pivot = arr[r], i = l;
    for (int j = l; j < r; j++) {
        if (arr[j] <= pivot) {
            swap(arr[i++], arr[j]);
        }
    }
    swap(arr[i], arr[r]);
    return i;
}
int KthLargest(int arr[], int l, int r, int k) {
    int pos = partition(arr, l, r);
    if (pos == l + k - 1) return arr[pos];
    
    if (pos > l + k - 1) return KthLargest(arr, l, pos - 1, k);
    else return KthLargest(arr, pos + 1, r, k - (pos - l + 1));
}
int kthlargest(int *arr, int n, int k) {
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) pq.push(arr[i]);
    while (pq.size() > n - k) pq.pop();
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;
}
void kLargest(vector<int>& vec, int n, int K) {
    priority_queue <int, vector <int>, greater <int>> pq; /*
    // Print the k largest element
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    
    for(int i = 0; i < n; i++) {
        pq.push(vec[i]);
        if(pq.size() > k) pq.pop();
    }
    while(!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl; */
    vector <int> res(n);
    for(int i = 0; i < n; i++) {
        if(pq.size() < k) pq.push(arr[i]);
        else {
            if(arr[i] < pq.top()) {
                pq.pop(); pq.push(arr[i]);
            }
        }
        if(pq.size() < k) res[i] = -1;
        else res[i] = pq.top();
    }
    return res;
}
