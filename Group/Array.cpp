using namespace std;
//return the only occurring which is odd or even
int findOdd(int arr[], int n){
    int res = 0;
    for (int i = 0; i < n; i++)
        res ^= arr[i];
    return res;
}
int main(){
    int arr[] = {12, 12, 14, 90, 14, 14, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << findOdd(arr, n);
}
using namespace std;
int main(){
    int arr[5];
    arr[0] = -1; arr[3 / 2] = 1; arr[2] = arr[0];
    int i = 0;
    while(arr[i]){
        cout << arr[i] << " ";
        i++;
    }
    char ar[5] = {'a', 'b', 'c'};
    int i = 0;
    while(ar[i]){
        cout << ar[i] << " ";
        i++;
    }
}
using namespace std;
//Given five positive integers, find the minimum and maximum values that can be calculated by summing exactly four of the five integers.print the respective minimum and maximum values
int main(){
    int n = 5;
    int arr[n], sum, tmp = -888;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    int ray[n];
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            sum += arr[j];
        }
        ray[i] = sum;
    }
    for(int i = 0; i < n; i++){
        if(ray[i] > ray[i + 1]){
            int tmp = ray[i + 1];
            ray[i + 1] = ray[i];
            ray[i] = tmp;
        }
    }
    cout << ray[n - 2] << " " << ray[n - 1];
}
//Allocation memory
using namespace std;
int main (){
    int* p = NULL;
    //you can use "new (nothrow)" when allocating memory to prevent an exception from being thrown
    // if the allocation fails for shortes memory in heap for continue the code.
    p = new(nothrow) int;
    if (!p)
        cout << "allocation of memory failed\n";
    else{
        *p = 29;
        cout << "Value of p: " << *p <<"\n";
    }
    float *r = new(nothrow) float(75.25);
    cout << "Value of r: " << *r << "\n";
    int n = 5;
    int *q = new(nothrow) int[n];
    if (!q) cout << "allocation of memory failed\n";
    else{
        for (int i = 0; i < n; i++)
            q[i] = i + 1;
        cout << "Value store in block of memory: ";
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
    }
    delete p;
    delete r;
    delete[] q;
}
using namespace std;
//Given an array of integers, calculate the ratios of its elements that are positive, negative, and zero. Print the decimal value of each fraction
int main(){
    int n; cin >> n;
    int arr[n + 2];
    int pos = 0, neg = 0, zero = 0;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    for(int i = 0; i < n; i++){
        if(arr[i] > 0) pos++;
        else if(arr[i] < 0) neg++;
        else zero++;
    }
    double plus = (double)pos / n;
    double Minus = (double)neg / n;
    double zeros = (double)zero / n;
    cout << fixed << setprecision(6) << plus << "\n" << Minus << "\n" << zeros;
}
using namespace std;
//array using pointer notation
int main(){
    int arr[2][3][2] = {{{5, 10}, {6, 11}, {7, 12}, }, {{20, 30}, {21, 31}, {22, 32}, }};
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 2; k++)
                cout << *(*(*(arr + i) + j) + k) << "\t";
            cout << "\n";
        }
    }
}
using namespace std;
int main(){
    int count = 0;
    int x[2][2][3];
    for (int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for (int k = 0; k < 3; k++){
                x[i][j][k] = count;
                count++;
                // x[i][j][k] = i + j + k;
            }
        }
    }
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 3; k++)
                    cout << "[" << i << "]" << "[" << j << "]" << "[" << k << "]" << " " << x[i][j][k] << "\n";
            }
        }
    }
}

using namespace std;
void Unsized_array(int *arr){
    cout << "\nsize of Unsized []: ";
    cout << sizeof(arr) ;
}
void Referenced_array(int (&arr)[10]){
    cout << "\nsize of Referenced[]: ";
    cout << sizeof(arr) ;
}
void Sized_array(int arr[], int n){
    cout << "\nsizeof(int) * n : ";
    cout << sizeof(int) * n ;
}
void aDecay(int *p){
    // prints the size of a pointer
    cout << "\nsize of array is by passing by value: ";
    cout << sizeof(p) ;
}
void pDecay(int (*p)[10]){
    // prints the size of the array
    cout << "\nModified size of array by passing by pointer: ";
    cout << sizeof(*p) ;
}
void mDecay(int *p){
    // prints the size of the array
    cout << "\nModified size of array by passing by pointer: ";
    cout << sizeof(*p) ;
}
void print_array(int arr[20], int n){
    cout << "\nAfter operation array is : ";
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " ";
}
void array_unsized(int arr[],int n){
    cout << "\nArray as Unsized Argument: ";
    for (int i = 0; i < n; i++) 
        cout << *(arr + i) << " ";
}
void array_pointer(int* ptr, int n){
    cout << "\nArray as Pointer Argument: ";
    for (int i = 0; i < n; i++) 
        cout << ptr[i] << " ";
}
void condition(){
    cout<<"\nConditional [] : ";
    for (int i = 0, j = 10, k = 20; (i+j+k) <100; j++, k--, i += k){
        cout << "\ni=" << i << " " << " j="<< j << " " << "k=" << k << " ";
    }
}
void display(){
    int arr[5];
    for (int i = 0; i < 7; i++) 
        arr[i] = i * i - 2 * i + 1;
}
int main(){
    int a[] = {1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(a)/ sizeof(a[0]);
    print_array (a, n);
    array_unsized (a, n);
    array_pointer (a, n);
    sort(a, a+ n);
    print_array (a, n);
    condition();
    display();
    Unsized_array(a);
    Referenced_array(a);
    Sized_array(a,n);
    aDecay(a);
    pDecay(&a);
    mDecay(a);
    if (binary_search(a, a + n, 6))
        cout << "\nElement found in the array";
    else
        cout << "\nElement doesn't exist";
    cout << "\nAddress of a: "<< a ;
    cout << "\nAddress of (a+1): "<<(a+1) ;
    cout << "\nValue of a[4] is: "<< a[4] ;
    cout << "\nValue of a[4]+1 is: "<< a[4]+1 ;
    //out of bound
    cout << "\nValue of a[5] is: "<< a[5] ;
    cout << "\nValue of a[5]+1 is: "<< a[5]+ 1 ;
}
//at(), get(), front(), back(), size(), max_size(), empty(), fill(), swap() 
using namespace std;
void print(array <int, 6> ar){
    for(int i = 0; i < 6; i++)
        cout << ar.at(i) << " ";
        //cout << ar[i] << " ";
}
int main(){
    array <int, 6> a;
    array <int, 0> ar1;
    ar1.empty()? cout << "\nArray empty":cout << "\nArray not empty";
    a.fill(0);
    cout << "\nArray after filling operation is : ";
    print(a);
    array <int, 6> ar = {1, 2, 3, 4, 5, 6};
    int n = sizeof (ar) /sizeof (ar[0]) ;
    cout << "\nArray elements are (using at()) : ";
    print(a);
    cout << "\nArray elements are (using get()) : ";
    cout << get <0> (ar) << " " << get <1> (ar) << " " << get <2> (ar) << " " << get <3> (ar) << " " << get <4> (ar) << " " << get <5> (ar) << " ";
    cout << "\nArray size is  : ";
    cout << ar.size();
    cout << "\nMaximum elements array can hold is : " << ar.max_size() ;
    cout << "\nArray elements are (using operator[]) : ";
    print(ar);
    cout << "\nFirst element of array is : ";
    int &arr = ar.front();
    cout << arr ;
    cout << "\nLast element of array is : ";
    int &b = ar.back();
    cout << b ;
    arr = 10; b = 60; 
    cout << "\nArray after updating first and last element :";
    print(ar);
    a.swap(ar);
    cout << "\nArray 'a' after swap: ";
    print(a);
    cout << "\nArray 'ar' after swap: ";
    print(ar);
}
