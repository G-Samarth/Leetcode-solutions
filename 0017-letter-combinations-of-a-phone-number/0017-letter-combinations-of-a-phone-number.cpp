class Solution {
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl",
                          "mno", "pqrs", "tuv", "wxyz"};
public:
    void getAllCombos(string digits, string curr, vector<string>& ans, int index){
        if(index == digits.size()){
            ans.push_back(curr);
            return;
        }

        for(auto m : mapping[digits[index] - '0']){
            curr.push_back(m);
            getAllCombos(digits, curr, ans, index+1);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(!digits.size())
            return {};
        
        string curr = "";
        vector<string> ans;
        getAllCombos(digits, curr, ans, 0);
        return ans;
    }
};