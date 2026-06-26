class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure A is the smaller array for binary search efficiency
        vector<int>& A = nums1;
        vector<int>& B = nums2;
        if (A.size() > B.size()) swap(A, B);

        int m = A.size();
        int n = B.size();
        int total = m + n;
        int half = (total + 1) / 2; // number of elements in the left half

        int left = 0;
        int right = m;

        while (left <= right) {
            int midA = (left + right) / 2;   // partition index for A
            int midB = half - midA;          // partition index for B

            // Border elements around the cuts
            int A_left_max  = (midA > 0) ? A[midA - 1] : INT_MIN;
            int A_right_min = (midA < m) ? A[midA] : INT_MAX;
            int B_left_max  = (midB > 0) ? B[midB - 1] : INT_MIN;
            int B_right_min = (midB < n) ? B[midB] : INT_MAX;

            // ✅ Correct partition found
            if (A_left_max <= B_right_min && B_left_max <= A_right_min) {
                if (total % 2 == 1)
                    return max(A_left_max, B_left_max);
                else
                    return (max(A_left_max, B_left_max) + min(A_right_min, B_right_min)) / 2.0;
            }
            // Move cut left or right
            else if (A_left_max > B_right_min) {
                right = midA - 1; // too many in A's left
            } else {
                left = midA + 1;  // too few in A's left
            }
        }

        return -1; // should never reach here
    }
};
