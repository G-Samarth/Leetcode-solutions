class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n,0));

        int start=0, len=1;

        for(int i=0;i<n;i++){
            dp[i][i] = 1;
        }

        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;

                start = i;
                len = 2;
            }
        }

        for(int g=2;g<=n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(s[i] == s[j]){
                    if(dp[i+1][j-1]){
                        dp[i][j] = 1;

                        if(g+1 > len){
                            start = i;
                            len = g+1;
                        }
                    }
                }
            }
        }


        return s.substr(start, len);
    }
};