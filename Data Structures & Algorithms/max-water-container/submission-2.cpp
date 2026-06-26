class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxx = 0;
        int l = 0;
        int r = heights.size() - 1;
        while (l < r) {
            int area = min(heights[r], heights[l]) * (r - l);
            maxx = max(area, maxx);
            if (heights[l] < heights[r]) {
                l++;
            } else if (heights[l] > heights[r]) {
                r--;
            } else {
                l++;
                r--;
            }
        }
        return maxx; 
    }
};
