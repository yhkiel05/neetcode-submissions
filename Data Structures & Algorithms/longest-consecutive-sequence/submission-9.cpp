class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> seq(nums.begin(), nums.end()); // initialize a set 
        for (int n : nums) {
            if (!seq.count(n - 1)) { // no left neighbor, can start a sequence
                int length = 0;
                while (seq.count(n + length)) { // continue looping until no longer consecutive
                    length++;
                }
                res = max(length, res);
            }
        }
        return res;
    }
};
