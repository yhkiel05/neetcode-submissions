class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = 0;
        for (int n : piles) {
            r = max(r, n);
        }
        int l = 1;
        int res = r;
        while (l <= r) {
            int k = (l + r) / 2;
            long long totalTime = 0;
            for (int p : piles) {
                totalTime += ceil(static_cast<double>(p) / k);
            }
            if (totalTime <= h) {
                res = k;
                r = k - 1; // try for a slower speed
            } else {
                l = k + 1; // needs a faster eating speed
            } 
        }
        return res; 
    }
};
