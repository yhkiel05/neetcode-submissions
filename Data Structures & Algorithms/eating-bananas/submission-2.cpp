class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = 0;
        for (int n : piles) {
            r = max(r,n);
        }
        int res = r;
        int l = 1;
        while (l <= r) {
            int k = (l + r) / 2;
            long long totalTime = 0;
            for (int p : piles) {
                totalTime += ceil(static_cast<double>(p) / k);
            }
            if (totalTime <= h) {
                res = k;
                r = k - 1; // try a slower speed
            } else {
                l = k + 1; // needs to be faster
            } 
        }
        return res;
    }
};
