class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freq(nums.size()+1, vector<int>(0));
        unordered_map<int, int> map;

        for(auto n : nums)
            map[n]++;

        for(auto m : map)
            freq[m.second].push_back(m.first);

        vector<int> ans;
        for(int i=nums.size();i>=0;i--){
            for(auto n:freq[i]){
                ans.push_back(n);

                if(ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};