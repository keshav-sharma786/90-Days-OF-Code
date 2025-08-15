#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    vector<int> temp(end - start + 1);
    int left = start, right = mid + 1, index = 0;
    while(left <= mid && right <= end)
    {
        if(arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            index ++;
            left ++;
        }
        else 
        {
            temp[index] = arr[right];
            index ++;
            right ++;
        }
    }
    // left array is not empty yet
    while(left <= mid)
    {
        temp[index] = arr[left];
        index ++;
        left ++;
    }
    // Right array is not empty yet
    while(right <= end)
    {
        temp[index] = arr[right];
        index ++;
        right ++;
    }
    index = 0;
    // put these values in the array
    while(start <= end) 
    {
        arr[start] = temp[index];
        start ++;
        index ++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    // Base Case
    if(start == end)
    {
        return;
    }
    // calculating mid
    int mid = start + (end - start) / 2;
    
    // Left side
    mergeSort(arr, start, mid);
    // right side
    mergeSort(arr, mid + 1, end);
    // now calling the merge function
    merge(arr, start, mid, end);
}

int main()
{
    int arr[] = {5, 4, 3, 2, 1};
    // calling the mergeSort function
    mergeSort(arr, 0, 4);
    // printing the finally sorted array

    /*
     time complexity = O(nlogn).
     space complecity = O(n).
    */
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
