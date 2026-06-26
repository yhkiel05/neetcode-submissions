class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int top = 0;
        int bottom = matrix.size() - 1;
        int midRow = (top + bottom) / 2;
        int r =  matrix[0].size() - 1;
        int row = 0;
        while (top <= bottom) { // find row target is on 
            if (matrix[midRow][0] == target) {
                return true;
            } else if (target >= matrix[midRow][0] && target <= matrix[midRow][r]) {
                // found row
                row = midRow;
                break;
            }
             else if (matrix[midRow][0] > target) {
                bottom = midRow - 1;
            } else if (matrix[midRow][0] < target) {
                top = midRow + 1;
            }
            midRow = (top + bottom) / 2; 
        }
        // now try to find target
        int l = 0;
        int midCol = (l + r) / 2;
        while (l <= r) {
            if (matrix[row][midCol] == target) {
                return true;
            } else if (matrix[row][midCol] < target) {
                l = midCol + 1;
            } else {
                r = midCol - 1;
            }
            midCol = (l + r) / 2;
        }
        return false; 
    }
};
