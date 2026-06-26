class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> dups;
        for (int i = 0; i < nums.size(); i++) {
            if (dups.count(nums[i])) {
                return true;
            } else {
                dups.insert(nums[i]);
            }
        }
        return false; 
    }
};
