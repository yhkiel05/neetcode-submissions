class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> postfix(size, 1);
        vector<int> prefix(size, 1);
        vector<int> res(nums.size());
        for (int i = 1; i < nums.size(); i++) {
            postfix[i] = nums[i - 1] * postfix[i - 1]; 
        }
        for (int i = size - 2; i >= 0; i--) {
            prefix[i] = nums[i + 1] * prefix[i + 1];
        }
        for (int i = 0; i < size; i++) {
            res[i] = postfix[i] * prefix[i];
        }
        return res;

    }
};
