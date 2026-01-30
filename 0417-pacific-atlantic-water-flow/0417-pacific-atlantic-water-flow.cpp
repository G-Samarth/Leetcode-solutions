class Solution {
public:
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& ocean, int r, int c, int prev){
        int n = heights.size();
        int m = heights[0].size();

        if(r<0 || r>=n || c<0 || c>=m || ocean[r][c] || heights[r][c] < prev)
            return;

        ocean[r][c] = true;
        dfs(heights, ocean, r+1, c, heights[r][c]);
        dfs(heights, ocean, r-1, c, heights[r][c]);
        dfs(heights, ocean, r, c+1, heights[r][c]);
        dfs(heights, ocean, r, c-1, heights[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false)), atl(n, vector<bool>(m, false));

        for(int i=0;i<n;i++){
            dfs(heights, pac, i, 0, heights[i][0]);
            dfs(heights, atl, i, m-1, heights[i][m-1]);
        }
        for(int i=0;i<m;i++){
            dfs(heights, pac, 0, i, heights[0][i]);
            dfs(heights, atl, n-1, i, heights[n-1][i]);
        }

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(atl[i][j] && pac[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};