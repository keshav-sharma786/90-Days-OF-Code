#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[] = {3, 3, 3, 3, 3};
    int n = 5;
    vector<int> temp(n - 1, 0);
    for(int i = 0; i < n; i++) {
        int element = arr[i];
        temp[element - 1] ++;
    }
    for(int i = 0; i < temp.size(); i++) {
        if(temp[i] > 1) {
            cout << (i + 1) << endl;
        }
    }
    return 0;
}