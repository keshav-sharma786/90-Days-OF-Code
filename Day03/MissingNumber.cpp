#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[] = {3, 0, 1};
    // so basically the numbers are present in the range [0, n]
    int n = 3;
    vector<bool> check(n + 1, false);
    for(int i = 0; i < n; i++) {
        int ele = arr[i];
        check[ele] = true;
    }
    for(int i = 0; i <= n; i++) {
        if(check[i] == false) {
            cout << i << endl;
        }
    }
    return 0;
}
