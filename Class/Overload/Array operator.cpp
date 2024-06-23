#include <iostream>
using namespace std;
class base{
    int arr[3];
    public:
    base(int i, int j, int k){
        arr[0] = i; arr[1] = j; arr[2] = k;
    }
    int operator[](int i){
        return arr[i];
    }
};
int main(){
    base b(5, 7, 9);
    cout << b[1];
}
