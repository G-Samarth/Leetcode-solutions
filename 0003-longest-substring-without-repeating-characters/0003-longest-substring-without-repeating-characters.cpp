class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> set;
        int i=0, j=0;
        int ans = 0;

        while(j < s.length()){
            if(set.find(s[j]) != set.end()){
                set.erase(s[i++]);
            }else{
                ans = max(ans, j-i+1);
                set.insert(s[j++]);
            }
        }

        return ans;
    }
};