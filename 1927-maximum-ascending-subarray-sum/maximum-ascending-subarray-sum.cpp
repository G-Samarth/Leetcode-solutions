class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = 0, curr = 0;
        int prev = -1;
        for(int n : nums){
            curr = n>prev ? curr+n:n;
            ans = max(curr, ans);
            prev = n;
        }

        return ans;
    }
};