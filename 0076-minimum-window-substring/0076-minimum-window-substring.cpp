class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length())
            return "";

        unordered_map<char, long> map;
        for(char c : t){
            map[c]++;
        }

        int count = 0;
        int j=0;
        int ans = INT_MAX;
        string str = "";
        for(int i=0;i<s.length();i++){
            map[s[i]]--;
            if(map[s[i]] >= 0){
                count++;
            }

            if(count == t.length()){
                while(map[s[j]] < 0){
                    map[s[j]]++;
                    j++;
                }
                if(i-j+1 < ans){
                    ans = i-j+1;
                    str = s.substr(j, i-j+1);
                }
            }
        }

        return str;
    }
};