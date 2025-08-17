#include <iostream>
#include <vector>
using namespace std;

// let us make a global vector answer
vector<int> answer;

void countSmallerNumbersAfterSelf(int arr[], int start, int mid, int end) {
    
    // inside this function logic we are basically going to count the total number of the inversions
    int left = start, right = mid + 1;
    while(right <= end) {
        if(arr[left] > arr[right]) {
            // push back that smaller value to the answer vector
            answer.push_back(arr[right]);
            right ++;
        } else {
            answer.push_back(0);
            right ++;
        }
    }

}

void merge(int arr[], int start, int mid, int end) {
    int left = start, right = mid + 1, index = 0;
    vector<int> temp(end - start + 1);
    while(left <= mid && right <= end) {
        if(arr[left] >= arr[right]) {
            temp[index] = arr[left];
            index ++;
            left ++;
        } else {
            temp[index] = arr[right];
            index ++;
            right ++;
        }
    }
    // what if some elements are left in the left array
    while(left <= mid){
        temp[index] = arr[left];
        left ++;
        index ++;
    }
    // what if some elements are left in the right array
    while(right <= end){
        temp[index] = arr[right];
        right ++;
        index ++;
    }
    index = 0;
    while(start <= end) {
        arr[start] = temp[index];
        start ++;
        index ++;
    }
}

void mergeSort(int arr[], int start, int end) {
    // base case
    if(start == end) {
        return;
    }
    // calculate mid
    int mid = start + (end - start) / 2;

    // dividing the left array
    mergeSort(arr, start, mid);

    // dividing the right array
    mergeSort(arr, mid + 1, end);

    // at this particular step only, We basically have to count the inversions
    // calling the countSmallerNumbersAfterSelf() function here
    countSmallerNumbersAfterSelf(arr, start, mid, end);
    
    // finally merging the 2 arrays
    merge(arr, start, mid, end);
}

int main() {

    int arr[] = {5, 2, 6, 1};
    int n = 4;
    // first function call
    mergeSort(arr, 0, 3);
    // printing the finally sorted array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    // printing the final answer vector
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}
