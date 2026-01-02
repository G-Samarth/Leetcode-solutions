class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        set<int> set;

        for(int n:nums){
            if(set.find(n) != set.end())
                return n;
            set.insert(n);
        }

        return -1;
    }
};