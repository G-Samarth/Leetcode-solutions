class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int curr = 0;

        for(int n : nums){
            curr += n;
            curr = max(curr, n);
            ans = max(ans, curr);
        }

        return ans;
    }
};