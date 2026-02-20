int add(int a, int b) { return a + b; };
int prd(int a, int b) { return a * b; };
void Build(int *arr, int n, int val) {
    cout << accumulate(arr, arr + n, val) << endl;
    cout << accumulate(arr, arr + n, val, minus <int> ()) << endl;
    cout << accumulate(arr, arr + n, val, prd) << endl;
    int ray[n];
    adjacent_difference(arr, arr + n, ray); print(ray, n);
    adjacent_difference(arr, arr + n, ray, multiplies <int> ()); print(ray, n);
    adjacent_difference(arr, arr + n, ray, add); print(ray, n);
    cout << inner_product(arr, arr + n, ray, val) << endl;
    // arr[0] * ray[0] + arr[1] * ray[1]..+ val
    cout << inner_product(arr, arr + n, ray, val, add, prd) << endl;
    cout << inner_product(arr, arr + n, ray, val, minus <int> (), divides <int> ()) << endl;
    partial_sum(arr, arr + n, ray); print(ray, n);
    partial_sum(arr, arr + n, ray, prd); print(ray, n);
}
