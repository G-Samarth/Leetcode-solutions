class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0;
        int maxSum = INT_MIN;

        for(int n : nums){
            currSum = max(currSum+n, n);
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};