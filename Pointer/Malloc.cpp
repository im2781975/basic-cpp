#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    // Both of these allocate the same number of bytes, which is the amount of bytes that is required to store 5 int values.

    // The memory allocated by calloc will be zero-initialized, but the memory allocated with
    // malloc will be uninitialized so reading it would be undefined behavior.
    int* allocated_with_malloc = static_cast<int*>(malloc(5 * sizeof(int)));
    int* allocated_with_calloc = static_cast<int*>(calloc(5, sizeof(int));

    // As you can see, all of the values are initialized to zero.
    cout << "Values of allocated_with_calloc: ";
    for (size_t i = 0; i < 5; ++i) { 
        cout << allocated_with_calloc[i] << " ";
    }
    // This malloc requests 1 terabyte of dynamic memory,which is unavailable in this case, 
    //and so the allocation fails and returns NULL.
    int* failed_malloc = static_cast<int*>(malloc(1000000000000));
    if (failed_malloc == nullptr) {
        cout << "The allocation failed, the value of failed_malloc is: " << failed_malloc ;
    }

    // Remember to always free dynamically allocated memory.
    free(allocated_with_malloc);
    free(allocated_with_calloc);

    return 0;
}

