class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());

        int res = 0;
        for (int n : nums) {
            if (!set.count(n - 1)) { // found start of sequence
                int length = 0;
                while (set.count(n + length)) { // sequence continues
                    length++;
                }
                res = max(res, length);
            }
        }
        return res;
    }
};
