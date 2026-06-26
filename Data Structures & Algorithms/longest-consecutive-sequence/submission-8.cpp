class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet;
        for (int n : nums) {
            numSet.insert(n);
        }
        int maxSeq = 0;
        for (int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            // only start counting if new sequence
            if (!numSet.count(n - 1)) {
                int length = 1;
                while (numSet.count(n + length)) {
                    length++;
                    
                }
                maxSeq = max(maxSeq, length);
            }
        }
        return maxSeq; 
    }
};
