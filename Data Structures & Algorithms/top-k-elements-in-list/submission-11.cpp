class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freqs(nums.size() + 1);
        unordered_map<int,int> count;
        for (int n : nums) {
            count[n]++;
        }
        for (auto pair : count) {
            freqs[pair.second].push_back(pair.first);
        }
        vector<int> res;

        for (int i = freqs.size() - 1; i >= 1; i--) {
            for (int n : freqs[i]) {
                res.push_back(n);
            }
            if (res.size() == k) {
                return res;
            }
        }
        return res;       
    }
};
