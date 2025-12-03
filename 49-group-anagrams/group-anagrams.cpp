class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(string str : strs){
            string copy = str;
            sort(copy.begin(), copy.end());

            map[copy].push_back(str);
        }

        vector<vector<string>> ans;

        for(auto m : map){
            ans.push_back(m.second);
        }

        return ans;
    }
};