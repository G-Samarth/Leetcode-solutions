class Solution {
    int rob(vector<int>& nums, int start, int end){
        if(end - start == 0)
            return nums[start];
        
        vector<int> dp(nums.size(), 0);
        dp[start] = nums[start];
        dp[start+1] = max(nums[start], nums[start+1]);

        for(int i=start+2;i<=end;i++){
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]);
        }

        return dp[end];
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
            
        int a = rob(nums, 0, n-2);
        int b = rob(nums, 1, n-1);

        return max(a, b);
    }
};