class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // find what row target is in
        // search that row per column
        int top = 0;
        int bottom = matrix.size() - 1;
        int midR = (top + bottom) / 2;
        int r = matrix[0].size() - 1;
        while (top <= bottom) {
            if (matrix[midR][0] == target) {
                return true;
            } else if (matrix[midR][r] == target) {
                return true;
            }
            else if (matrix[midR][0] < target && matrix[midR][r] > target) {
                break;
            } else if(matrix[midR][r] < target) {
                // in a higher row
                top = midR + 1;
            } else {
                bottom = midR - 1;
            }
            midR = (top + bottom) / 2;
        }
        // found our row;
        int l = 0;
        int midCol = (l + r) / 2;
        while (l <= r) {
            if (matrix[midR][midCol] == target) {
                return true;
            } else if (matrix[midR][midCol] < target) {
                l = midCol + 1;
            } else {
                r = midCol - 1;
            }
            midCol = (l + r) / 2;
        }
        return false; 
    }
};
