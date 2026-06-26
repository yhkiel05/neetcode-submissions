class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }
        for (auto pairs : freq) {
            buckets[pairs.second].push_back(pairs.first);
        }
        // buckets are created
        vector<int> res;
        for (int i = buckets.size() - 1; i >= 0; --i) {

            for (int n : buckets[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }

        }
        return res;
    }
};
