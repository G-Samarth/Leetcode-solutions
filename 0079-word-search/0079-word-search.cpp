class Solution {
    bool exist(vector<vector<char>>& board, string word, int i, int j, int ind){
        int m = board.size();
        int n = board[0].size();

        if(i<0 || i>=m || j<0 || j>=n)
            return false;
        if(board[i][j] != word[ind])
            return false;
        if(ind == word.size()-1)
            return true;
        
        board[i][j] = '#';
        if(exist(board, word, i+1, j, ind+1))
            return true;
        if(exist(board, word, i-1, j, ind+1))
            return true;
        if(exist(board, word, i, j+1, ind+1))
            return true;
        if(exist(board, word, i, j-1, ind+1))
            return true;
        
        board[i][j] = word[ind];
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size() == 0)
            return true;

        int m = board.size();
        int n = board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    if(exist(board, word, i, j, 0))
                        return true;
                }

            }
        }

        return false;
    }
};