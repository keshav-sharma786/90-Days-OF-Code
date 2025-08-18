#include <iostream>
#include <vector>
using namespace std;

int main() {
    int arr[] = {4, 3, 2, 7, 8, 2, 3, 1};
    // M-2 let us solve this problem using Cyclic Sort
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> answer;
    int idx = 0;
    while(idx < n) {
        int correctIdx = arr[idx] - 1;
        if(idx == correctIdx || arr[idx] == arr[correctIdx]) idx ++;
        else {
            swap(arr[idx], arr[correctIdx]);
        }
    }
    // applying cyclic sort second time
    idx = 0;
    while(idx < n) {
        int correctIdx = arr[idx] - 1;
        if(idx != correctIdx) {
            // which at that idx culprit is present
            answer.push_back(idx + 1);
        }
        idx ++;
    }
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}