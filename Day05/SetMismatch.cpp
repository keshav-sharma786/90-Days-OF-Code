class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
         vector<int> answer;
         int n = nums.size();
         int idx = 0;
         while(idx < n) {
             int correctIdx = nums[idx] - 1;
             if(correctIdx == idx) idx ++;
             else {
                 if(nums[idx] == nums[correctIdx]) {
                     idx ++;
                 } else {
                     swap(nums[idx], nums[correctIdx]);
                 }
             }
         }
         for(int i = 0; i < n; i++) {
             if(nums[i] != i + 1) {
                 // nums[i] is the culprit
                 answer.push_back(nums[i]);
                 answer.push_back(i + 1);
                 break;
             }
         }
        return answer;
    }
};