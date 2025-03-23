class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> map;

        for(int n : nums){
            map[n] = -1;
        }

        int ans = 0;
        for(auto n : nums){
            if(map[n] == -1){
                int curr = n;
                int longest = 0;

                while(map.find(curr) != map.end()){
                    if(map[curr] != -1){
                        longest += map[curr];
                        break;
                    }else{
                        map[curr] = 0;
                        longest++;
                    }
                    curr++;
                }

                ans = max(longest, ans);
                map[n] = longest;
            }
        }

        return ans;
    }
};