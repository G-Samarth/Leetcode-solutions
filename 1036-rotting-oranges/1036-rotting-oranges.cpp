class Solution {
    bool check(int i, int j, int n, int m, vector<vector<int>>& grid){
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1){
            return false;
        }

        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int timer = 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q; 

        int x[4] = {1, -1, 0, 0};
        int y[4] = {0, 0, 1, -1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2)
                    q.push({i,j});
            }
        }

        while(!q.empty()){
            int size = q.size();

            while(size--){
                pair<int, int> fr = q.front();
                q.pop();

                int row = fr.first;
                int col = fr.second;

                for(int i=0;i<4;i++){
                    if(check(row+x[i], col+y[i], n, m, grid)){
                        grid[row + x[i]][col + y[i]] = 2;
                        q.push({row+x[i], col+y[i]});
                    }
                }
            }

            if(!q.empty())
                timer++;
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }

        return timer;
    }
};