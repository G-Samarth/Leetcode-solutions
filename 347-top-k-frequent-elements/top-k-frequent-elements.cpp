class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        vector<vector<int>> bucket(nums.size()+1, vector<int>({}));

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        for(auto f : freq){
            bucket[f.second].push_back(f.first);
        }

        vector<int> ans;
        for(int i=nums.size();i>=0;i--){
            for(int j=0;j<bucket[i].size();j++){
                ans.push_back(bucket[i][j]);
                if(ans.size() == k)
                    return ans;
            }
        }

        return ans;
    }
};