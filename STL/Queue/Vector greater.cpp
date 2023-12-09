// min heap for priority queue
#include <iostream>
#include <queue>
using namespace std;
  
void showpq(
    priority_queue<int, vector<int>, greater<int> > g)
{
    while (!g.empty()) {
        cout << ' ' << g.top();
        g.pop();
    }
}
void showArray(int* arr, int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
}
int main()
{
    int arr[6]={10, 2, 4, 8, 6, 9};
    priority_queue<int, vector<int>, greater<int> > gquiz(
        arr, arr + 6);
    //int: The data type of elements in the priority q.
//vector<int>:underlying container used for the priority queue 
//greater<int>: The comparison function or functor that defines the order of elements.
    cout << "\nArray: ";
      showArray(arr, 6);
  
    cout << "\nPriority Queue : ";
    showpq(gquiz);
  
    return 0;
}
