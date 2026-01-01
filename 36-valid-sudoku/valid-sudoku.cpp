class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            set<int> set;
            for(int j=0;j<9;j++){
                if(board[i][j] != '.'){
                    if(set.find(board[i][j]) != set.end())
                        return false;
                    set.insert(board[i][j]);
                }
            }
        }

        for(int i=0;i<9;i++){
            set<int> set;
            for(int j=0;j<9;j++){
                if(board[j][i] != '.'){
                    if(set.find(board[j][i]) != set.end())
                        return false;
                    set.insert(board[j][i]);
                }
            }
        }

        for(int r=0;r<9;r+=3){
            for(int c=0;c<9;c+=3){
                set<int> set;
                for(int i=r;i<r+3;i++){
                    for(int j=c;j<c+3;j++){
                        if(board[i][j] != '.'){
                            if(set.find(board[i][j]) != set.end())
                                return false;
                            set.insert(board[i][j]);
                        }
                    }
                }
            }
        }

        return true;
    }
};