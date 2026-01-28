class TrieNode {
public:
    string word;
    TrieNode* children[26];

    TrieNode(){
        word = "";
        for(int i=0;i<26;i++)
            children[i] = NULL;
    }

    void addWord(string str){
        TrieNode* root = this;
        for(int i=0;i<str.length();i++){
            char c = str[i];

            if(!root->children[c-'a']){
                root->children[c-'a'] = new TrieNode();
            }
            root = root->children[c-'a'];
        }

        root->word = str;
    }
};

class Solution {
    vector<string> ans;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string word:words)
            root->addWord(word);

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++){
                dfs(board, root, i, j);
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>>& board, TrieNode* root, int r, int c){
        int n = board.size();
        int m = board[0].size();

        if(r<0 || r>=n || c<0 || c>=m || board[r][c] == '*' || !root->children[board[r][c]-'a'])
            return;
        root = root->children[board[r][c]-'a'];
        if(!root->word.empty()){
            ans.push_back(root->word);
            root->word = "";
        }
        
        char temp = board[r][c];
        board[r][c] = '*';
        
        dfs(board, root, r+1, c);
        dfs(board, root, r-1, c);
        dfs(board, root, r, c+1);
        dfs(board, root, r, c-1);

        board[r][c] = temp;
    }
};