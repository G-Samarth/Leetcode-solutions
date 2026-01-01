class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
       unordered_set<int> set;
        int ans = 1;
       for(int n:nums)
            set.insert(n); 

        for(int n:nums){
            if(set.find(n-1) == set.end()){
                int len = 0;
                int curr = n;
                while(set.find(curr) != set.end()){
                    set.erase(curr);
                    curr++;
                    len++;
                }

                ans = max(ans, len);
            }
        }

        return ans;
    }
};