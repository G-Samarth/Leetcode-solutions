class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> map;

        for(int i=0;i<nums.size();i++){
            map[nums[i]] = 1;
        }

        int ans = 0;
        for(auto m : map){
            int temp = m.first;
            int count = 0;
            while(map[temp] == 1){
                map[temp++] = 0;
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};