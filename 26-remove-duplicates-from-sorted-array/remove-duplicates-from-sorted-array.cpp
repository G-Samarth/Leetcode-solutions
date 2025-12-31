class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=0;
        int last = -101;
        while(j<nums.size()){
            if(nums[j] == last){
                j++;
            }else{
                last = nums[j];
                nums[i] = nums[j];
                i++;
                j++;
            }
        }

        return i;
    }
};