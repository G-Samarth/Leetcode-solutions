class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i=0, j=1, k=n-1;

        vector<vector<int>> ans;
        while(i < n){
            if(nums[i] > 0)
                break;
            j = i+1, k=n-1;
            while(j < k){
                if(nums[i]+nums[j]+nums[k] == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(j<k && nums[j] == nums[j-1])
                        j++;
                    while(k>j && nums[k-1] == nums[k])
                        k--;
                    k--;
                }else if(nums[i]+nums[j]+nums[k] < 0)
                    j++;
                else
                    k--;
            }

            while(i < n-1 && nums[i] == nums[i+1])
                i++;
            i++;
        }

        return ans;
    }
};