#include <iostream>
#include <vector>
using namespace std;

int c = 0;

int countInversions(int arr[], int start, int mid, int end) {
    
    // inside this function logic we are basically going to count the total number of the inversions
    int left = start, right = mid + 1;
    int count = 0;
    while(left <= mid && right <= end) {
        if(arr[left] > arr[right]) {
            // it is an inversion
            count += mid - left + 1;
            // rest left array elements are also going to be the inversions, because left array will be sorted
            right ++;
        } else {
            left ++;
        }
    }
    return count;
}

void merge(int arr[], int start, int mid, int end) {
    int left = start, right = mid + 1, index = 0;
    vector<int> temp(end - start + 1);
    while(left <= mid && right <= end) {
        if(arr[left] <= arr[right]) {
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
    c += countInversions(arr, start, mid, end);
    
    // finally merging the 2 arrays
    merge(arr, start, mid, end);
}

int main() {

    int arr[] = {3, 2, 1};
    int n = 3;
    // first function call
    mergeSort(arr, 0, 2);
    // printing the finally sorted array
    for(int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << c << endl;
    
    return 0;
}
