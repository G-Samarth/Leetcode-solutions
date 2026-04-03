class Solution {
    int dfs(vector<vector<int>>& grid, int row, int col){
        int n = grid.size();
        int m = grid[0].size();

        if(row < 0 || row >= n || col < 0 || col >= m || !grid[row][col])
            return 0;

        int count = 1;
        grid[row][col] = 0;

        count += dfs(grid, row+1, col);
        count += dfs(grid, row-1, col);
        count += dfs(grid, row, col+1);
        count += dfs(grid, row, col-1);

        return count;
    } 
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                   int cnt = dfs(grid, i, j);
                   ans = max(ans, cnt);
                }
            }
        }

        return ans;
    }
};