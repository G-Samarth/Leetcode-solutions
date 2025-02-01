class Solution {

    string countSort(string s){
        vector<int> freq(26, 0);

        for(char ch:s)
            freq[ch-'a']++;

        string ret;
        for(int i=0;i<26;i++)
            ret += string(freq[i], i+'a');

        return ret;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for(string s: strs){
            map[countSort(s)].push_back(s);
        }

        vector<vector<string>> ans;
        for(auto sec:map){
            ans.push_back(sec.second);
        }

        return ans;
    }
};