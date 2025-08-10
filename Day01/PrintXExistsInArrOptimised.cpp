#include <iostream>
using namespace std;

// f represents whether x is there or not
bool f(int *arr, int n, int i, int x) {
    // base case
    if(i == n) {
        // array is exhausted
        return false;
    }
    return (arr[i] == x) || f(arr, n, i + 1, x);
}

int main() {
    int arr[] = {5, 4, 1, 8, 6, -9, 8, 2, 3, 5};
    int n = 10;
    int x = 8;
    bool result = f(arr, n, 0, x);
    if(result) cout << "YES";
    else {
        cout << "NO";
    }
    return 0;
}
