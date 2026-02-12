class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> set;

        for(string word : wordDict)
            set.insert(word);

        vector<int> possible(s.length()+1, 0);
        possible[0] = 1;

        for(int i=0;i<=s.length();i++){
            for(int j=0;j<i;j++){
                if(possible[j] && set.count(s.substr(j, i-j))){
                    possible[i] = 1;
                    break;
                }
            }
        }

        return possible[s.length()];
    }
};