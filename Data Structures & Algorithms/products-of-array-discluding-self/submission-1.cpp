class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix (nums.size(), 1);
        vector<int> sufix (nums.size(), 1);
        vector<int> res (nums.size(), 0);
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                prefix[i] = prefix[i] * nums[j];
            }
        }
        for (int i = nums.size() - 1; i >= 0; i--) {
            for (int j = i - 1; j >= 0; j--) {
                sufix[i] = sufix[i] * nums[j];
            }
        }
        for (int i = 0; i < nums.size(); i++) {
            res[i] = prefix[i] * sufix[i];
        }
        return res;
    }
};
