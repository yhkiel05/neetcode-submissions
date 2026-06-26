class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> dups;
        for (int n : nums) {
            if (dups.count(n)) {
                return true;
            }
            dups.insert(n); 
        }
        return false;
    }
};
