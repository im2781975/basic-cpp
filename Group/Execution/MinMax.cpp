//find the minimum and maximum values that can be calculated by summing exactly 
// four of the five integers. print the respective minimum and maximum values
using namespace std;
int main(){
    int n; cin >> n;
    int arr[n], sum;
    for(int i = 0; i < n; i++) cin >> arr[i];
    int tmp[n];
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            sum += arr[j];
        }
        tmp[i] = sum;
    }
    int duo = tmp[0];
    for(int i = 1; i < n; i++){
        if(duo < tmp[i]) duo = tmp[i];
    } 
    cout << tmp[0] << " " << tmp[n - 1] << endl;
}
using namespace std;
int poslt(int *arr, int lt, int rt, int key){
    while(rt - lt > 1){
        int mid = lt + (rt - lt) / 2;
        if(arr[mid] >= key)  rt = mid;
        else    lt = mid;
    }
    return rt;
}
int posrt(int *arr, int lt, int rt, int key){
    while(rt - lt > 1){
        int mid = lt + (rt - lt) / 2;
        if(arr[mid] <= key)  lt = mid;
        else    rt = mid;
    }
    return lt;
}
int cntfreq(int *arr, int n, int key){
    int lt = poslt(arr, -1, n - 1, key);
    int rt = posrt(arr, 0, n - 1, key);
    return (arr[lt] == key && key == arr[rt]) ? (rt - lt + 1) : 0;
}
int main(){
    int arr[]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    cout << cntfreq(arr, n, key) << endl;
}
