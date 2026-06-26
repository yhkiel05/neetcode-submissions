class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> ns;
        for (int n : nums) {
            if (ns.count(n)) return true;
            ns.insert(n);
        }
        return false;
    }
};