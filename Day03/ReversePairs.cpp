class Solution {
public:

    int count = 0;

    int reversePairs(vector<int> &nums, int start, int mid, int end) {
    int left = start, right = mid + 1;
    int cnt = 0;
    while(left <= mid && right <= end) {
        if ((long long)nums[left] > 2LL * nums[right]) {
            cnt += mid - left + 1;
            right++;
        } else {
            left++;
        }
    }
    return cnt;
}


    void merge(vector<int> &nums, int start, int mid, int end) {
        int left = start, right = mid + 1, index = 0;
        vector<int> temp(end - start + 1);
        while(left <= mid && right <= end) {
            if(nums[left] <= nums[right]) {
                temp[index] = nums[left];
                left ++;
                index ++;
            } else {
                temp[index] = nums[right];
                right ++;
                index ++;
            }
        }
        while(left <= mid) {
            temp[index] = nums[left];
            left ++;
            index ++;
        }

        while(right <= end) {
            temp[index] = nums[right];
            right ++;
            index ++;
        }
        index = 0;
        while(start <= end) {
            nums[start] = temp[index];
            start ++;
            index ++;
        }
    }

    void mergeSort(vector<int>& nums, int start, int end) {
        if(start == end) {
            return;
        }
        int mid = start + (end - start) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        count += reversePairs(nums, start, mid, end);
        merge(nums, start, mid, end);
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int start = 0;
        int end = (n - 1);
        mergeSort(nums, start, end);
        return count;
    }
};