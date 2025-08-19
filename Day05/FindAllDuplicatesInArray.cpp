class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer;
        int idx = 0;
        while(idx < n) {
            int correctIdx = nums[idx] - 1;
            if(correctIdx == idx) idx ++;
            else {
                if(nums[idx] == nums[correctIdx]) {
                    // they are duplicates
                    // answer.push_back(nums[correctIdx]);
                    idx ++;
                } else {
                    swap(nums[idx], nums[correctIdx]);
                }
            }
        }
        for(int i = 0; i < n; i++) {
            if(nums[i] != i + 1) {
                answer.push_back(nums[i]);
            }
        }
        return answer;
    }
};