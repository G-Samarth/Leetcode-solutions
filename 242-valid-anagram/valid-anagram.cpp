class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        vector<int> map(26,0);

        for(char c:s)
            map[c-'a']++;
        for(char c:t)
            map[c-'a']--;
        
        for(int i:map)
            if(i >= 1)
                return false;

        return true;
    }
};