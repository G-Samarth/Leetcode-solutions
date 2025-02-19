class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size())
            return 0;
        // DP
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        if(nums.size() > 1)
            dp[1] = max(nums[0],nums[1]);
        // [-,-,-,-]
        
        // For Loop
        for(int i=2;i<nums.size();i++){
            // To Rob or not to rob
            dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
        }

        return dp[nums.size()-1];
    }
};