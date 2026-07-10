class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int rowH = 0;
        int rowL = rows - 1;
        int colL = 0;
        int colR = cols - 1;

        while (rowH <= rowL) {
            int rowM = rowH + (rowL - rowH) / 2;
            if (matrix[rowM][0] <= target && 
                matrix[rowM][cols - 1] >= target) {
                colL = 0;
                colR = cols - 1;
                while (colL <= colR) { // cols
                    int colM = colL + (colR - colL) / 2;
                    if (matrix[rowM][colM] == target) {
                        return true;
                    }
                    else if (matrix[rowM][colM] > target) {
                        // element bigger than target
                        // search left <-> shift right border
                        colR = colM - 1;
                    }
                    else {
                        colL = colM + 1;
                    }
                }
                return false;
            }
            else if (matrix[rowM][cols - 1] < target) {
                // last element of the row less than target
                // => search lower -> shift high row
                rowH = rowM + 1;
            }
            else if (matrix[rowM][0] > target) {
                rowL = rowM - 1;
            }
        }
        return false;
    }
};
