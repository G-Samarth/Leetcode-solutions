class Solution {
public:
    int rob(vector<int>& nums) {
        if(!nums.size())
            return 0;
        // DP
        // vector<int> dp(nums.size(), 0);
        int first = nums[0], second = first;
        if(nums.size() > 1)
            second = max(nums[0],nums[1]);
        // [-,-,-,-]
        
        // For Loop
        for(int i=2;i<nums.size();i++){
            // To Rob or not to rob
            int temp = max(nums[i] + first, second);
            first = second;
            second = temp;
        }

        return second;
    }
};