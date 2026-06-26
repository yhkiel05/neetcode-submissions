class Solution {
public:
vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> res(n, 0); // Result vector initialized to 0
    stack<int> stk; // Stack to keep indices

    for (int i = 0; i < n; ++i) {
        // While stack is not empty and current temp is higher than temp at stk.top()
        while (!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
            int idx = stk.top();
            stk.pop();
            res[idx] = i - idx; // Store the number of days waited
        }
        stk.push(i); // Push current index
    }
    return res;
}
};
