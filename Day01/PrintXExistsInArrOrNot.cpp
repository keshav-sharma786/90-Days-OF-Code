#include <iostream>
using namespace std;

// Recursive function Implementation
bool f(int arr[], int idx, int n, int target) {
    // base case
    if(idx == n) {
        return false;
    }
    // Assumption
    // from (idx + 1) to n, check whether the element is being present in the array or not
    if(arr[idx] == target) {
        return true;
    } 
    return f(arr, idx + 1, n, target);
}

int main() {

    // given an array of integers and a target value x. Print whether x exists in the array or not

    // we basically have to use the recursive approach
    
    int arr[] = {4, 12, 54, 14, 3, 8, 6, 1};
    int n = 8;
    int target = 1;
    // function call
    if(f(arr, 0, n, target)) {
        cout << "yes the element is present in the array" << endl;
    } else {
        cout << "No the element is not present in the array" << endl;
    }
    return 0;
}
