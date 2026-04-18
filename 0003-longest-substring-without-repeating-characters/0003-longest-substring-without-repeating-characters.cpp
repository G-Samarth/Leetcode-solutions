class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = s.length();
        unordered_map<char, int> map;
        int i=0, j=0;
        int ans = 0;
        
        while(i < l){
            map[s[i]]++;
            if(map.count(s[i]) && map[s[i]] > 1){
                while(map[s[i]] != 1)
                    map[s[j++]]--;
            }

            ans = max(ans, i-j+1);
            i++;
        }

        return ans;
    }
};