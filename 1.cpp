#include<bits/stdc++.h>
using namespace std;

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
int main()
{
        string s1, s2;
        cin >> s1 >> s2;
        cout<< editDis(s1,s2,s1.length(),s2.length())<<endl;
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
#include<bits/stdc++.h>
#include<stdio.h>
#include<math.h>
#include<time.h>

const int inf=(1<<28);
struct node{
    int value;
    int index;
    int last;
}tmp , BLOCK[400];
int INDEX[400],arr[100005],Output[100005];

void initialize(int N, int blockSZ ,int blockln)
{
    int tp;
    for(int i = 1; i <= blockSZ ; i++){
        int idx = (i-1)*blockln;
        for(int j = 1 ; j <= blockln; j++){
                for(int k = idx+1 ; k < idx+blockln; k++){
                    if(k >= N) break;
                    if(arr[k] > arr[k+1]){
                        tp = arr[k] ;
                        arr[k] =  arr[k+1];
                        arr[k+1] = tp;
                    }
                }
        }
        BLOCK[i].value = arr[idx+1];
        BLOCK[i].index = idx+1;
        if(idx+blockln <= N)
            BLOCK[i].last = idx+blockln;
        else
            BLOCK[i].last = N;
    }

}

void Sort(int N , int blockSZ , int blockln)
{
    for(int i = 1; i <= blockSZ; i++){
        for(int j = 1; j < blockSZ; j++){
            if(BLOCK[j].value > BLOCK[j+1].value){
                tmp = BLOCK[j];
            BLOCK[j] = BLOCK[j+1];
               BLOCK[j+1] = tmp;
            }
        }
    }
}
int main()
{
        double total_time;
    	clock_t start, end;
    	start = clock();
    	//time count starts
    	srand(time(NULL));



    freopen("set1.txt","r",stdin);
    int N;
    scanf("%d",&N);

    for(int i = 1; i <= N; i++)
        scanf("%d",&arr[i]);

    int blockSZ = sqrt(N);
    int blockln = N/blockSZ;

    if(blockln * blockSZ != N)
        blockln += 1;

    initialize(N , blockSZ , blockln);
    Sort(N , blockSZ , blockln);

    for(int i = 1; i <= N; i++){
        Output[i] = BLOCK[1].value;
        int inx = BLOCK[1].index + 1 , Crnt, pos , R;
        if(inx <= BLOCK[1].last){
            Crnt = arr[inx];
            pos = inx;
            R = BLOCK[1].last;
        }
        else{
            Crnt = inf;
            pos = N + 1;
            R = 0;
        }

        int j = 2;
        while(Crnt > BLOCK[j].value && j <= blockSZ){
            BLOCK[j-1] = BLOCK[j];
            j++;
        }
        BLOCK[j-1].value = Crnt;
        BLOCK[j-1].index = pos;
        BLOCK[j-1].last = R;
    }

    end = clock();
    	//time count stops
    	total_time = ((double) (end - start)) / CLK_TCK;
    	//calulate total time
    	printf("\nTime taken ---> : %f", total_time);
    	return 0;
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
/**/
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
/***/
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
void Hanoi(int n, int a, int b, int c){
    if(n == 1)
        cout << a << " " << c << "\n";
    else{
        Hanoi(n - 1, a, b, c);
        cout << a << " " << c << "\n";
        Hanoi(n - 1, b, c, a);
    }
}
