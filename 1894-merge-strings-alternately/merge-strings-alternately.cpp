class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i=0,j=0;
        string ans;
        while(i < word1.length() && j < word2.length()){
            ans += word1[i++];
            ans += word2[j++];
        }

        // while(i < word1.length())
        //     ans += word1[i++];

        // while(i < word1.length())
        //     ans += word1[i++];

        ans += word1.substr(i, word1.length());
        ans += word2.substr(j, word2.length());

        return ans;
    }
};