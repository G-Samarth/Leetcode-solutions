class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,0));

        int start = 0, len = 1;

        for(int i=0;i<s.length();i++)
            dp[i][i] = 1;
        
        for(int i=0;i<s.length()-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                start = i;
                len = 2;
            }
        }

        for(int g=2;g<s.length();g++){
            for(int i=0, j=g;j<s.length();i++,j++){
                if(s[i] == s[j]){
                    if(dp[i+1][j-1]){
                        start = i;
                        len = g+1;
                        dp[i][j] = 1;
                    }
                }
            }
        }

        return s.substr(start, len);
    }
};