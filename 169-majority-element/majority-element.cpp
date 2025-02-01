class Solution {
public:
    int majorityElement(vector<int>& nums) {
        pair<int, int> winner;
        winner = {nums[0], 1};

        for(int i=1;i<nums.size();i++){
            if(nums[i] == winner.first)
                winner.second++;
            else{
                winner.second--;
                if(winner.second == 0)
                    winner = {nums[i], 1};
            }
        }

        return winner.first;
    }
};