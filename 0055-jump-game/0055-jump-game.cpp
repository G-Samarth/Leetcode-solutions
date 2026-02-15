class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<bool> jump(nums.size(), false);
        jump[0] = true;

        if(nums.size() == 1)
            return true;
        for(int i=0;i<nums.size();i++){
            if(jump[i]){
                for(int j=1;j<=nums[i];j++){
                    jump[i+j] = true;
                    if(i+j == nums.size()-1)
                        return true;
                }
            }
        }

        return false;
    }
};