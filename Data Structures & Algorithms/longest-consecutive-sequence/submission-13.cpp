class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (int n : nums) {
            set.insert(n);
        }
        int res = 0;
        for (int n : nums) {
            if (!set.count(n - 1)) {
                int len = 0;
                while (set.count(n + len)) len++;
                res = max(len, res); 
            }
            
        }
        return res;
    }
};
