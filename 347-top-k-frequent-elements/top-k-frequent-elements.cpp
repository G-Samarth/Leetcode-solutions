class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int n : nums)
            map[n]++;

        vector<vector<int>> bucket(nums.size()+1, vector<int>({}));

        for(auto m : map)
            bucket[m.second].push_back(m.first);

        vector<int> ans;
        for(int i=nums.size();i>=0;i--){
            for(int b : bucket[i]){
                ans.push_back(b);
                if(ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};