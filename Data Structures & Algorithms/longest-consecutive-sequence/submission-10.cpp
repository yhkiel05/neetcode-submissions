class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> conseq(nums.begin(), nums.end());
        int res = 0;
        for (int n : nums) {
            if (!conseq.count(n-1)) {
                int len = 0;
                while (conseq.count(n + len)) {
                    len++;
                }
                res = max(len, res);
            }
        }
        return res;
    }
};
