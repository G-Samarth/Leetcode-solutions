class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int i=0, j=0;
        int maxfreq = 0;
        unordered_map<int,int> map;
        int ans = 0;

        while(j < n){
            map[s[j]]++;
            maxfreq = max(maxfreq, map[s[j]]);

            if((j-i+1) - maxfreq <= k){
                ans = max(ans, j-i+1);
            }else{
                map[s[i]]--;
                i++;
            }
            j++;
        }

        return ans;
    }
};