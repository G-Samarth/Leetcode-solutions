class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size() == 0)
            return ans;

        sort(intervals.begin(), intervals.end());
        vector<int> temp = intervals[0];

        int i=1;
        while(i < intervals.size()){
            if(intervals[i][0] <= temp[1]){
                // temp[0] = min(temp[0], intervals[i][0]);
                temp[1] = max(temp[1], intervals[i][1]);
                i++;
            }else{
                ans.push_back(temp);
                temp = intervals[i];
                i++;
            }
        }
        ans.push_back(temp);

        return ans;
    }
};