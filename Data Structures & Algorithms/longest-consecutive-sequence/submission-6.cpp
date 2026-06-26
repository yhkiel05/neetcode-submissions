class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seq;
        for (int n : nums) {
            seq.insert(n);
        }
        
        int maxSeq = 0;
        for (int num : seq) {
            if (!seq.count(num - 1)) {
                int length = 1;
                while (seq.count(num + length)) {
                    length++;
                }
                maxSeq = max(maxSeq, length);
            }
        }
        return maxSeq;
    }
};
