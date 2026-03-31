class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> chain;

        for(int i=0;i<nums.size();i++){
            chain.insert(nums[i]);
        }

        int ans = 0;
        for(int num : chain){
            if(chain.count(num-1) == 0){
                int count = 1;
                int curr = num+1;
                while(chain.count(curr)){
                    count++;
                    curr++;
                }

                ans = max(ans, count);
            }
        }

        return ans;
    }
};