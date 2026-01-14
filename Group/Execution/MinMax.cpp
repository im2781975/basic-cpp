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
