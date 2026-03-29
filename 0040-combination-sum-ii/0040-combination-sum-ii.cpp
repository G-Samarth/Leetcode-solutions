class Solution {
    void getAllCombos(vector<int>& candidates, int target, vector<vector<int>>& ans, int idx, vector<int>& curr){
        if(target == 0){
            ans.push_back(curr);
            return;
        }else if(target < 0){
            return;
        }

        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i] == candidates[i-1])
                continue;
            
            curr.push_back(candidates[i]);
            getAllCombos(candidates, target-candidates[i], ans, i+1, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        getAllCombos(candidates, target, ans, 0, curr);

        return ans;
    }
};