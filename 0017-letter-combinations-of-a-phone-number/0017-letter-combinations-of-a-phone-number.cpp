class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans = {""};
        vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        for(char d : digits){
            vector<string> temp;
            for(auto s : ans){
                int num = d - '0';
                for(auto c : mapping[num])
                    temp.push_back(s + c);
            }
            ans = temp;
        }

        return ans;
    }
};