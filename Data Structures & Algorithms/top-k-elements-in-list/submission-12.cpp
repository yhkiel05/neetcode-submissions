class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1); // 1 index
        unordered_map<int, int> count;
        for (int n : nums) {
            count[n]++;
        }
        for (auto pair : count) {
            buckets[pair.second].push_back(pair.first);
        }
        vector<int> res;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int n : buckets[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
            if (res.size() == k) {
                return res;
            }
        }
        return res;
    }
};
