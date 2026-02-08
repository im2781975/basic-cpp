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
