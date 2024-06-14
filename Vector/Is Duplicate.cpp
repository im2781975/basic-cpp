#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        string ans = "No";  
        for (int j = 0; j < n; j++)
        {
            if (i != j && arr[i] == arr[j])
            {
                ans = "Yes";
                break;
            }
        }
        cout << i << " " << ans << "\n";
    }
    return 0;
}
