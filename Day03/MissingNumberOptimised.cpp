#include <iostream>
using namespace std;

int main() {
    int sum1 = 0;
    int sum2 = 0;
    int arr[] = {3, 0, 1};
    // M - 2 Using Mathematics formula
    int n = 3;
    // calculating the sum from 0 to n
    for(int i = 0; i <= n; i++) {
        sum1 += i;
    }
    // calculating the sum in the original array
    for(int i = 0; i < n; i++) {
        sum2 += arr[i];
    }
    int missingNumber = (sum1 - sum2);
    cout << missingNumber << endl;
    return 0;
}

