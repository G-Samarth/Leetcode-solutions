class Solution {
    bool dfs(unordered_map<int, vector<int>>& prereq, vector<int>& state, int curr){

        state[curr] = 1;
        for(int i : prereq[curr]){
            if(state[i] == 1)
                return false;
            else if(state[i] == 0)
                if(!dfs(prereq, state, i))
                    return false;
        }
        state[curr] = 2;

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> prereq;
        for(auto p : prerequisites){
            prereq[p[0]].push_back(p[1]);
        }

        vector<int> state(numCourses, 0);
        for(int i=0;i<numCourses;i++){
            if(state[i] == 0){
                if(!dfs(prereq, state, i))
                    return false;
            }
        }

        return true;
    }
};