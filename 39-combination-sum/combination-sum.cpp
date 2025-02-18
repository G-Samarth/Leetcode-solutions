class Solution {
    void combinationSum(vector<int> candidates, int target, int i, vector<int> temp, vector<vector<int>>& ans) {
        if(i > candidates.size())
            return;
        if(target < 0)
            return;

        if(target == 0){
            ans.push_back(temp);
            return;
        }

        for(int j=i;j<candidates.size();j++){
            temp.push_back(candidates[j]);
            combinationSum(candidates, target-candidates[j], j, temp, ans);
            temp.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;

        combinationSum(candidates, target, 0, temp, ans);
        return ans;
    }
};