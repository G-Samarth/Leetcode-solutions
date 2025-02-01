class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j=0;
        int n = nums.size();
        int count = 0;

        while(j<n && nums[j] == val)
            j++;

        for(int i=0;i<n;i++){
            if(j<n){
                swap(nums[i], nums[j]);
                count++;
                j++;
            } else {
                break;
            }
            while(j<n && nums[j] == val)
                j++;
        }
        
        return count;
    }
};