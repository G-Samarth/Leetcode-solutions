class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int l=0, r=n-1;
        int ans = INT_MAX;

        while(l <= r){
            ans = min(ans, nums[l]);
            if(nums[l] <= nums[r])
                break;

            int mid = (l+r)/2;
            if(nums[l] <= nums[mid])
                l = mid+1;
            else
                r = mid;
        }

        return ans;
    }
};