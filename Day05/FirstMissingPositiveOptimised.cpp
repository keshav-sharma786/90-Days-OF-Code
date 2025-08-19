#include <iostream>
using namespace std;

int main() {
    int arr[] = {7, 8, 9, 11, 12};
    int n = 5;
    int idx = 0;
    while(idx < n) {
        if(arr[idx] >= 1 && arr[idx] <= n) {
            int correctIdx = arr[idx] - 1;
            if(idx != correctIdx && arr[idx] != arr[correctIdx]) {
                swap(arr[idx], arr[correctIdx]);
            } else {
                idx ++;
            }
        } else {
            idx ++;
        }
    }

    for(int i = 0; i < n; i++) {
        if(arr[i] != i + 1) {
            cout << (i + 1) << endl;
        }
    }

    cout << (n + 1) << endl;
    return 0;
}