class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();

        int i=0, j=0;
        unordered_map<char, int> map;
        int ans = 0;
        while(j<n){
            map[s[j]]++;
            if(map[s[j]] == 2){
                while(map[s[j]] == 2){
                    map[s[i]]--;
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};