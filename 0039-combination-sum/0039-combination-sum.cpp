class Solution {
    void combinationSum(vector<int> &cand, int target, int index, vector<int>& temp, vector<vector<int>>& ans){
        if(index == cand.size() || target < 0)
            return;
        if(target == 0){
            ans.push_back(temp);
            return;
        }

        temp.push_back(cand[index]);
        combinationSum(cand, target-cand[index], index, temp, ans);
        temp.pop_back();
        combinationSum(cand, target, index+1, temp, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        combinationSum(candidates, target, 0, temp, ans);

        return ans;
    }
};