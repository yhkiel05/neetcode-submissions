class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> ts;
        for (int i = 0; i < nums.size(); i++) {
            int diff = target - nums[i];
            if (ts.count(diff)) {
                return {ts[diff], i};
            } else {
                ts[nums[i]] = i;
            }
        }
        return {};
    }
};
