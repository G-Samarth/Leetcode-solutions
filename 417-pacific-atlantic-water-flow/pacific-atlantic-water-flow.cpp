class Solution {
    void dfs(int row, int col, vector<vector<int>>& ocean, int prevHeight, vector<vector<int>>& heights){
        int n = heights.size(), m = heights[0].size();
        if(row<0 || row==n || col<0 || col==m || heights[row][col] < prevHeight || ocean[row][col])
            return;

        ocean[row][col] = 1;
        dfs(row+1, col, ocean, heights[row][col], heights);
        dfs(row-1, col, ocean, heights[row][col], heights);
        dfs(row, col+1, ocean, heights[row][col], heights);
        dfs(row, col-1, ocean, heights[row][col], heights);
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> pacific(n, vector<int> (m, 0));
        vector<vector<int>> atlantic(n, vector<int> (m, 0));
        

        for(int i=0;i<n;i++){
            dfs(i, 0, pacific, heights[i][0], heights);
            dfs(i, m-1, atlantic, heights[i][m-1], heights);
        }

        for(int i=0;i<m;i++){
            dfs(0, i, pacific, heights[0][i], heights);
            dfs(n-1, i, atlantic, heights[n-1][i], heights);
        }

        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i,j});
            }
        }

        return ans;
    }
};