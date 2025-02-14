class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<vector<int>> ans;
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int j=i+1, k=n-1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    // k--;
                    while(j<k && nums[j-1] == nums[j])
                        j++;
                    // while(j<k && nums[k+1] == nums[k])
                    //     k--;
                }
                else if(nums[i] + nums[j] + nums[k] < 0)
                    j++;
                else
                    k--;
            }
        }

        return ans;
    }
};