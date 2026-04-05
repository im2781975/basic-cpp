#include <iostream>
#include <vector>
using namespace std;
void maxMin(vector<int> vec, int n,
        int& bingo, int& nextBingo)
{
    for (int i = 1; i < n; i++)
    {
        bingo = min(bingo, vec[i]);
        nextBingo = max(nextBingo, vec[i]), 
    }
}
void bingoSort(vector<int>& vec, int n)
{
    //It repeatedly finds the minimum element (bingo) and moves it to 
    //its correct position, updating the next minimum element (nextBingo) for the next pass.
    int bingo = vec[0];
    int nextBingo = vec[0];
    maxMin(vec, n, bingo, nextBingo);
    int largest = nextBingo;
    int nxtPos = 0;
    while (bingo < nextBingo) {
        // Will keep the track of the element position to shifted to their correct position
        int startPos = nxtPos;
        for (int i = startPos; i < n; i++) {
            if (vec[i] == bingo) {
                swap(vec[i], vec[nextElePos]);
                nextElePos = nextElePos + 1;
            }
            // Here we are finding the next Bingo Element for the next pass
            else if (vec[i] < nextBingo)
                nextBingo = vec[i];
        }
        //After the inner loop, bingo is updated to the current value of nextBingo.
        //nextBingo is reset to the initial value of the largest element.
        bingo = nextBingo;
        nextBingo = largestEle;
    }
}
void printArray(vector<int> arr, int n)
{
    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr = { 5, 4, 8, 5, 4, 8, 5, 4, 4, 4 };
    bingoSort(arr, arr.size());
    printArray(arr, arr.size());
    return 0;
}
//this program works only when size of input is a power of 2
#include<bits/stdc++.h>
using namespace std;
//The parameter dir indicates the sorting direction, ASCENDING or DESCENDING; 
//if (a[i] > a[j]) agrees with the direction, then a[i] and a[j] are interchanged.
void compAndSwap(int a[], int i, int j, int dir)
{
    if (dir==(a[i]>a[j]))
        swap(a[i],a[j]);
}
//It recursively sorts a bitonic sequence in ascending order, if dir = 1, and in descending order otherwise (means dir=0).
  //The sequence to be sorted starts at index position low, the parameter cnt is the number of elements to be sorted.
void bitonicMerge(int a[], int low, int cnt, int dir)
{
    if (cnt>1)
    {
        int k = cnt/2;
        for (int i=low; i<low+k; i++)
            compAndSwap(a, i, i+k, dir);
        bitonicMerge(a, low, k, dir);
        bitonicMerge(a, low+k, k, dir);
    }
}
void bitonicSort(int a[],int low, int cnt, int dir)
{
    if (cnt>1)
    {
        int k = cnt/2;
        // sort in ascending order since dir here is 1
        bitonicSort(a, low, k, 1);
        // sort in descending order since dir here is 0
        bitonicSort(a, low+k, k, 0);
        // Will merge whole sequence in ascending order since dir=1.
        bitonicMerge(a,low, cnt, dir);
    }
}
void sort(int a[], int N, int up)
{
    bitonicSort(a,0, N, up);
}
int main()
{
    int a[]= {3, 7, 4, 8, 6, 2, 1, 5};
    int N = sizeof(a)/sizeof(a[0]);
 
    int up = 1;   
    // means sort in ascending order
    sort(a, N, up);
    cout<<"\nSorted array is: ";
    for (int i=0; i<N; i++)
        printf("%d ", a[i]);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
bool isSorted(int a[], int n)
{
    while (--n > 0)
        if (a[n] < a[n - 1])
            return false;
    return true;
}
void bogosort(int a[], int n)
{
    while (!isSorted(a, n))
    {
        for (int i = 0; i < n; i++)
            swap(a[i], a[rand() % n]);
    }
}
void BrickSort(int arr[], int n)
{
    bool isSorted = false;
    while (!isSorted)
    {
        isSorted = true;
        for (int i = 1; i<= n -2; i+= 2)
        {
            if (arr[i] > arr[i+1])
             {
                swap(arr[i], arr[i+1]);
                isSorted = false;
              }
        }
        for (int i = 0; i<= n-2; i+= 2)
        {
            if (arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
    }
    return;
}
void printArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    int a[] = { 3, 2, 5, 1, 0, 4 };
    int n = sizeof a / sizeof a[0];
    bogosort(a, n);
    cout<<"\nBogo sort: ";
    printArray(a, n);
    BrickSort(a, n);
    printArray(a, n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, temp;
    cin >> n;
    int arr[n+5];
    for(int i = 1; i<= n; i++)
        cin >> arr[i];
    for(int i = 1; i < n; i++){
        for(int j = i+1; j<= n; j++){
            if(arr[i] < arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for(int i = 1; i<= n; i++)
        cout <<  arr[i] << " ";
    return 0;
}
// Bubble sort
#include<bits/stdc++.h>
using namespace std;
void Bubble_sort(int arr[], int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
                swap(arr[i], arr[j]);
        }
    }
}
void BubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        // If no two elements were swapped
        // by inner loop, then break
        if (swapped == false)
            break;
    }
}
void print(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = {7, 2, 13, 2, 11, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"\nImposed Bubble sort optimized: ";
    BubbleSort(arr,n);
    print(arr,n);
    
    cout<<"\nImposed Bubble sort: ";
    Bubble_sort(arr, n);
    print(arr, n);
    vector<int> a(arr, arr+n);
    for (int pass = 0; pass < n; pass++) {
        int last = n - 1 - pass;
        bool sorted = true;

        for (int j = 0; j <= last - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                sorted = false;
            }
        }
        if (sorted)
            break;
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
void bucketSort(float arr[], int n)
{
    vector<float> b[n];
 
    //Put array elements in different buckets
    for (int i = 0; i < n; i++) {
        // Index in bucket
        int bi = n * arr[i];
        b[bi].push_back(arr[i]);
    }
    //Sort individual buckets
    for (int i = 0; i < n; i++)
        sort(b[i].begin(), b[i].end());
    //Concatenate all buckets into arr[]
    int index = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < b[i].size(); j++)
            arr[index++] = b[i][j];
}
int main()
{
    float arr[]
        = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
 
    cout << "Sorted array is \n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

struct Element {
    int value;
    int originalIndex;
};

bool compareElements(const Element& a, const Element& b) {
    return a.value < b.value;
}

int main() {
    int n;
    std::cin >> n;

    std::vector<Element> elements(n);

    for (int i = 0; i < n; ++i) {
        std::cin >> elements[i].value;
        elements[i].originalIndex = i;
    }

    std::sort(elements.begin(), elements.end(), compareElements);

    std::cout << "Value " << elements[0].value << ", Previous Index " << elements[0].originalIndex << std::endl;
    for (int i = 1; i < n; ++i) {
        if (elements[i].value == elements[i - 1].value) {
            std::cout << "Value " << elements[i].value << ", Previous Index " << elements[i - 1].originalIndex << std::endl;
        } else {
            std::cout << "Value " << elements[i].value << ", Previous Index " << elements[i].originalIndex << std::endl;
        }
    }

    return 0;
}

// C++ program to sort an array of dates 
#include<bits/stdc++.h> 
using namespace std; 
  
// Structure for date 
struct Date 
{ 
    int day, month, year; 
}; 
  
// This is the compare function used by the in-built sort 
// function to sort the array of dates. 
// It takes two Dates as parameters (const is 
// given to tell the compiler that the value won't be 
// changed during the compare - this is for optimization..) 
  
// Returns true if dates have to be swapped and returns 
// false if not. Since we want ascending order, we return 
// true if the first Date is less than the second date 
bool compare(const Date &d1, const Date &d2) 
{ 
    // All cases when true should be returned 
    if (d1.year < d2.year) 
        return true; 
    if (d1.year == d2.year && d1.month < d2.month) 
        return true; 
    if (d1.year == d2.year && d1.month == d2.month && 
                              d1.day < d2.day) 
        return true; 
  
    // If none of the above cases satisfy, return false 
    return false; 
} 
  
// Function to sort array arr[0..n-1] of dates 
void sortDates(Date arr[], int n) 
{ 
    // Calling in-built sort function. 
    // First parameter array beginning, 
    // Second parameter - array ending, 
    // Third is the custom compare function 
    sort(arr, arr+n, compare); 
} 
  
// Driver Program 
int main() 
{ 
    Date arr[] = {{20,  1, 2014}, 
                  {25,  3, 2010}, 
                  { 3, 12, 1676}, 
                  {18, 11, 1982}, 
                  {19,  4, 2015}, 
                  { 9,  7, 2015}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    sortDates(arr, n); 
  
    cout << "Sorted dates are\n"; 
    for (int i=0; i<n; i++) 
    { 
        cout << arr[i].day << " " << arr[i].month 
             << " " << arr[i].year; 
        cout << endl; 
    } 
} 
#include <bits/stdc++.h>
using namespace std;
 
struct ele {
    int val, count;
};
 
void swap(struct ele* a, struct ele* b)
{
    struct ele temp = *a;
    *a = *b;
    *b = temp;
}
 
int partition(struct ele arr[], int low, int high)
{
    struct ele pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++) {
        if (arr[j].count < pivot.count || (arr[j].count == pivot.count && arr[j].val > pivot.val)) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
 
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 
void quicksort(struct ele arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
 
void sortByFrequency(int arr[], int n)
{
    struct ele element[n];
    for (int i = 0; i < n; i++) {
        element[i].val = arr[i];
        element[i].count = 0;
    }
 
    for (int i = 0; i < n; i++) {
        int j;
        for (j = 0; j < i; j++)
            if (arr[i] == arr[j])
                break;
 
        if (i == j)
            element[i].count++;
        else
            element[j].count++;
    }
 
    quicksort(element, 0, n - 1);
 
    for (int i = n - 1, index = 0; i >= 0; i--) {
        for (int j = 0; j < element[i].count; j++)
            arr[index++] = element[i].val;
    }
}
 
int main()
{
    int arr[] = { 2, 5, 2, 8, 5, 6, 8, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
 
    sortByFrequency(arr, n);
 
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
#include <bits/stdc++.h> 
using namespace std; 
// Number of elements to be sorted 
#define N 1000000 
  
// A comparator function used by qsort 
int compare(const void * a, const void * b) 
{ 
    return ( *(int*)a - *(int*)b ); 
} 
int main() 
{ 
    int arr[N], dupArr[N]; 
  
    // seed for random input 
    srand(time(NULL)); 
  
    // to measure time taken by qsort and sort 
    clock_t begin, end; 
    double time_spent; 
  
    // generate random input 
    for (int i = 0; i < N; i++) 
        dupArr[i] = arr[i] = rand()%100000; 
  
    begin = clock(); 
    qsort(arr, N, sizeof(int), compare); 
    end = clock(); 
  
    // calculate time taken by C qsort function 
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC; 
  
    cout << "Time taken by C qsort() - "
         << time_spent << endl; 
  
    time_spent = 0.0; 
  
    begin = clock(); 
    sort(dupArr, dupArr + N); 
    end = clock(); 
  
    // calculate time taken by C++ sort 
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC; 
  
    cout << "Time taken by C++ sort() - "
         << time_spent << endl; 
  
    return 0; 
} 
#include<bits/stdc++.h>
using namespace std;
int getNextGap(int gap)
{
    gap = (gap*10)/13;
    if (gap < 1)
        return 1;
    return gap;
}
void combSort(int a[], int n)
{
    int gap = n;
    bool swapped = true;
    // Keep running while gap is more than 1 and last iteration caused a swap
    while (gap != 1 || swapped == true)
    {
        gap = getNextGap(gap);
        // Initialize swapped as false so that we can check if swap happened or not
        swapped = false;
        for(int i = 0; i < n - gap; i++)
        {
            if (a[i] > a[i + gap])
            {
                swap(a[i], a[i + gap]);
                swapped = true;
            }
        }
    }
}
void CocktailSort(int a[], int n)
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;
    while (swapped) {
        // reset the swapped flag on entering the loop, because it might be true from a previous iteration.
        swapped = false;
        for (int i = start; i < end; ++i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
        // otherwise, reset the swapped flag so that it can be used in the next stage
        swapped = false;
        // move the end point back by one, because item at the end is in its rightful spot
        --end;
        // from right to left, doing the same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        // increase the starting point, because the last stage would
        //have moved the next smallest number to its rightful spot.
        ++start;
    }
}
int main()
{
    int arr[] = {8, 4, 1, 56, 3, -44, 23, -6, 28, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    combSort(arr, n);
    CocktailSort(arr, n);
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
vector<int> countSort(vector<int>& input)
{
    int N = input.size();
    int M = 0;
    for (int i = 0; i < N; i++)
        M = max(M, input[i]);
 
    vector<int> count(M + 1, 0);
    // Mapping each element of inputArray[] as an index of countArray[] array
    for (int i = 0; i < N; i++)
        count[input[i]]++;
    for (int i = 1; i <= M; i++)
        count[i] += count[i - 1];
 
    // Creating outputArray[] from countArray[] array
    vector<int> out(N);
    for (int i = N - 1; i >= 0; i--)
    {
        out[count[input[i]] - 1]
            = input[i];
        count[input[i]]--;
    }
    return out;
}
void countingSort(vector<int>& arr, int n) {
    // Create a counting array to track the frequency of each number
    vector<int> count(n, 0);
    // Count the frequency of each number in the input array
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }
    // Output the sorted numbers based on the counting array
    int index = 0;
    for (int i = 0; i < n; i++) {
        while (count[i] > 0) {
            arr[index] = i;
            index++;
            count[i]--;
        }
    }
}
void print(vector <int> vec, int n)
{
    for(int i = 0; i < n; i++)
        cout << vec[i] << " ";
    cout << "\n";
}
int main()
{
    vector<int> input = { 4, 3, 12, 1, 5, 5, 3, 9 };
    vector<int> output = countSort(input);
    output.resize(input.size());
    print(output, output.size());
    countingSort(input, input.size());
    print(input, input.size());
    return 0;
}
#include <iostream>
using namespace std;
void cyclicSort(int arr[], int n){
    int i = 0; 
    while(i < n)
    {
    int correct = arr[i] - 1 ;
    if(arr[i] != arr[correct]){
      // if array element should be lesser than size and array element should not be at
      // its correct position then only swap with its correct position or index value
      swap(arr[i], arr[correct]) ;
    }else{
      // if element is at its correct position just increment i and check for remaining array elements
      i++ ;
    }
  }
}
void cycleSort(int arr[], int n)
{
    // count number of memory writes
    int writes = 0;
    // traverse array elements and put it to on the right place
    //i=cycle start.
    for (int i = 0; i <= n - 2; i++) {
        // initialize item as starting point
        int item = arr[i];
 
        // Find position where we put the item. We basically count all smaller elements on right side of item.
        int pos = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < item)
                pos++;
 
        // If item is already in correct position
        if (pos == i)
            continue;
 
        // ignore all duplicate  elements
        while (item == arr[pos])
            pos += 1;
 
        // put the item to it's right position
        if (pos != i) {
            swap(item, arr[pos]);
            writes++;
        }
        // Rotate rest of the cycle
        while (pos != i) {
            pos = i;
 
            // Find position where we put the element
            for (int j = i + 1; j < n; j++)
                if (arr[j] < item)
                    pos += 1;
 
            // ignore all duplicate  elements
            while (item == arr[pos])
                pos += 1;
 
            // put the item to it's right position
            if (item != arr[pos]) {
                swap(item, arr[pos]);
                writes++;
            }
        }
    }
    // cout << writes << endl ;
}
int main()
{
    int arr[] = { 1, 8, 3, 9, 10, 10, 2, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cycleSort(arr, n);
    cyclicSort(arr, n);
    cout << "\nAfter sort : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
#include <iostream> 
using namespace std; 
void gnomeSort(int arr[], int n) 
{ 
    int index = 0; 
    while (index < n) { 
        if (index == 0) 
            index++; 
        if (arr[index] >= arr[index - 1]) 
            index++; 
        else { 
            swap(arr[index], arr[index - 1]); 
            index--; 
        } 
    } 
    return; 
} 
int shellSort(int arr[], int n) 
{ 
    for (int gap = n/2; gap > 0; gap /= 2) 
    { 
        for (int i = gap; i < n; i += 1) 
        { 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i]; 
            // shift earlier gap-sorted elements up until the correct  location for a[i] is found 
            int j;             
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                arr[j] = arr[j - gap]; 
            //  put temp (the original a[i]) in its correct location 
            arr[j] = temp; 
        } 
    } 
    return 0; 
} 
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}
void printArray(int arr[], int n) 
{ 
    cout << "Sorted sequence after Gnome sort: "; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
} 
int main() 
{ 
    int arr[] = { 34, 2, 10, -9 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    shellSort(arr, n); 
    gnomeSort(arr, n);
    selectionSort(arr, n);
    printArray(arr, n); 
    return (0); 
} 
#include<bits/stdc++.h>
using namespace std;
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
}
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    if (l < n && arr[l] > arr[largest])
        largest = l;
    
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        swap(arr[i], arr[largest]);
        
        cout<<"\n";
        printArray(arr,n);
        heapify(arr, n, largest);
    }
} 
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
int main()
{
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = 10;
    heapSort(arr, n);
    cout << "\narray after using heap sort: ";
    printArray(arr, n);
}
