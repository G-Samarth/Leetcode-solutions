class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0;
        while(i<nums.size()){
            for(int j=i+1;j<=i+k;j++){
                if(j >= nums.size())
                    break;
                if(nums[i] == nums[j])
                    return true;
            }
            i++;
        }

        return false;
    }
};