#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(int arr[], int n) {
    for(int i = 1; i <= n; i++) {
        // now looping onto the array
        bool flag = false;
        for(int j = 0; j < n; j++) {
            if(arr[j] == i) {
                // which means that is not our first missing positive integer
                flag = true;
                break;
            }
            // if(!flag) {
            //     // which means that is a first missing positive integer
            //     // cout << i << endl;
            //     return i;
            // }
        }
        if(!flag) {
                // which means that is a first missing positive integer
                // cout << i << endl;
                return i;
            }
    }
    return 0;
}

int main() {
    int arr[] = {3, 4, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    
    // chcck weather from 1 to n smallest positive integer is present in the arr or not

    // M1 Brute Force
    // applying nested for loop
    cout << firstMissingPositive(arr, n) << endl;
    return 0;
}