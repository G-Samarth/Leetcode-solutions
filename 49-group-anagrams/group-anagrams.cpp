class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(string s : strs){
            string temp = s;
            sort(s.begin(), s.end());
            map[s].push_back(temp);
        }

        vector<vector<string>> ans;
        for(auto m : map){ 
            ans.push_back(m.second);
        }

        return ans;
    }
};