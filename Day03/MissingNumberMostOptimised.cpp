#include <iostream>
#include <vector>
using namespace std;


int main() {
    int nums[] = {3, 0, 1};
    // Using Cycle Sort
    int n = 3;
    int i = 0;
    while(i < n) {
        int correctIdx = nums[i];
        if(correctIdx == i || nums[i] == n) i++;
        else swap(nums[i], nums[correctIdx]); 
    }
    for(int i = 0; i < n; i++) {
        if(nums[i] != i) {
            cout << i << endl;
        }
    }
    return 0;
}
