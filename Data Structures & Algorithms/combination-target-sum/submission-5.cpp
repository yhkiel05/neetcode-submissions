class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        combo(nums, target, cur, 0);
        return res;
    }
    void combo(vector<int>& nums, int target, vector<int>& cur, int i) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || i >= nums.size()) return;
        cur.push_back(nums[i]);
        combo(nums, target - nums[i], cur, i);
        cur.pop_back();
        combo(nums,target, cur, i+1);
        return;
    }
};
