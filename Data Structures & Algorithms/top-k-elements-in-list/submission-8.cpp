class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> freq(nums.size() + 1);
        for (int i = 0; i < nums.size(); i++) {
            count[nums[i]]++;
        }

        for (auto entry : count) {
            freq[entry.second].push_back(entry.first); // elements with highest freqs will be at back of array

        }
        vector<int> res;
        for (int i = freq.size() - 1; i > 0; i--) {
            for (int n : freq[i]) {
                res.push_back(n);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        return res;

    }
};
