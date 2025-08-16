#include <iostream>
#include <vector>
using namespace std;

int c = 0;

int inversion(int arr[], int left, int right, int mid, int end)
{
    int count = 0;
    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            left++;
        }
        else
        {
            count += (mid - left + 1); // all remaining left-side elements are inversions
            right++;
        }
    }
    return count;
}

void merge(int arr[], int start, int mid, int end)
{
    int left = start, right = mid + 1, index = 0;
    c += inversion(arr, left, right, mid, end);
    vector<int> temp(end - start + 1);
    while (left <= mid && right <= end)
    {
        if (arr[left] < arr[right])
        {
            temp[index] = arr[left];
            index++;
            left++;
        }
        else
        {
            temp[index] = arr[right];
            index++;
            right++;
        }
    }
    // if elements in the left array are still left
    while (left <= mid)
    {
        temp[index] = arr[left];
        index++;
        left++;
    }
    // if elements in the right array are still left
    while (right <= end)
    {
        temp[index] = arr[right];
        index++;
        right++;
    }
    // writing the counting inversion logic here of 2 sorted arrays
    // we will make a separate inversion function for implementing the desired logic
    // left = start, right = mid + 1;
    

    // copying to the original array
    index = 0;

    while (start <= end)
    {
        arr[start] = temp[index];
        start++;
        index++;
    }
}

void mergeSort(int arr[], int start, int end)
{
    // base case
    if (start == end)
    {
        return;
    }
    // calculating mid
    int mid = start + (end - start) / 2;
    // merge left array
    mergeSort(arr, start, mid);

    // merge right array
    mergeSort(arr, mid + 1, end);
    // calling the merge function
    merge(arr, start, mid, end);
}

int main()
{
    int arr[] = {5, 4, 3};
    int n = 3;
    // first function call
    mergeSort(arr, 0, 2);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << c << endl;
    return 0;
}
