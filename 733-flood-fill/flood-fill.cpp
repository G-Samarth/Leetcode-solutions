class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(), m = image[0].size();
        int org = image[sr][sc];

        if(color == org)
            return image;
        
        queue<pair<int, int>> q;
        q.push({sr, sc});
        int x[4] = {1,-1,0,0};
        int y[4] = {0,0,1,-1};

        while(!q.empty()){
            auto top = q.front();
            q.pop();
            image[top.first][top.second] = color;

            for(int i=0;i<4;i++){
                int row = top.first + x[i];
                int col = top.second + y[i];

                if(row<0 || row>=n || col<0 || col>=m || image[row][col] != org)
                    continue;
                q.push({row, col});
            }
        }

        return image;
    }
};