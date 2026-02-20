class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        
        int rowStart = 0, rowEnd = matrix.size() - 1;
        int colStart = 0, colEnd = matrix[0].size() - 1;
        vector<int> ans;

        while (rowStart <= rowEnd && colStart <= colEnd) {
            // 1. Move Right
            for (int i = colStart; i <= colEnd; i++) {
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;

            // 2. Move Down
            for (int i = rowStart; i <= rowEnd; i++) {
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;

            // 3. Move Left (Check if row still exists)
            if (rowStart <= rowEnd) {
                for (int i = colEnd; i >= colStart; i--) {
                    ans.push_back(matrix[rowEnd][i]);
                }
                rowEnd--;
            }

            // 4. Move Up (Check if column still exists)
            if (colStart <= colEnd) {
                for (int i = rowEnd; i >= rowStart; i--) {
                    ans.push_back(matrix[i][colStart]);
                }
                colStart++;
            }
        }
        return ans;
    }
};