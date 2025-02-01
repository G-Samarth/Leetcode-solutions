class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(string s : strs){
            string temp = s;
            sort(temp.begin(), temp.end());
            map[temp].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto arr : map){
            ans.push_back(arr.second);
        }

        return ans;
    }
};