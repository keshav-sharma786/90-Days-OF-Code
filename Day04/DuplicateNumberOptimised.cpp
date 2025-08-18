#include <iostream>
using namespace std;

int main() {
    // now we'll solve the same question with the help of cyclic sort
    int arr[] = {1, 3, 4, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int idx = 0;
    while(idx < n) {
        int correctIdx = arr[idx] - 1;
        if(idx == correctIdx) {
            idx++;
        } else {
            swap(arr[idx], arr[correctIdx]);
            if(arr[idx] == arr[correctIdx]) {
                // means they are the duplicate elements
                cout << arr[idx] << endl;
                break;
            }
        }
    }
    
    return 0;
}
