class Solution {
    bool checkOutOfBound(int x, int y, vector<vector<char>>& grid){
        int row = grid.size(), col = grid[0].size();
        if(x<0 || y<0 || x>=row || y>=col || grid[x][y] != '1')
            return false;
        return true;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // empty array case
        int n = grid.size(), m = grid[0].size();
        if(n == 0 && m == 0)
            return 0;

        // intitalize queue
        queue<pair<int,int>> islands;
        int ans = 0;

        // for loop
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //while loop
                if(grid[i][j] == '1'){
                    islands.push({i, j});
                    grid[i][j] = '0';
                    ans++;

                    while(!islands.empty()){
                        auto island = islands.front();
                        int x = island.first;
                        int y = island.second;
                        islands.pop();

                        if(checkOutOfBound(x-1, y, grid)){
                            islands.push({x-1, y});
                            grid[x-1][y] = '0';
                        }
                        if(checkOutOfBound(x, y-1, grid)){
                            islands.push({x, y-1});
                            grid[x][y-1] = '0';
                        }
                        if(checkOutOfBound(x+1, y, grid)){
                            islands.push({x+1, y});
                            grid[x+1][y] = '0';
                        }
                        if(checkOutOfBound(x, y+1, grid)){
                            islands.push({x, y+1});
                            grid[x][y+1] = '0';
                        }
                    }
                }
            }
        }

        return ans;
    }
};