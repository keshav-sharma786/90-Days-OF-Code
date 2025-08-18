class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> temp(n, false);
        vector<int> answer;
        for(int i = 0; i < n; i++) {
            int element = nums[i];
            temp[element - 1] = true;
        }

        for(int i = 0; i < n; i++) {
            if(temp[i] == false) {
                answer.push_back(i + 1);
            }
        }

        return answer;
    }
};