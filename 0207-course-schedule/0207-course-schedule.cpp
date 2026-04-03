class Solution {
    unordered_map<int, vector<int>> graph;
    unordered_set<int> done;

    bool dfs(int index){
        if(done.count(index))
            return false;
        
        done.insert(index);
        for(auto i : graph[index]){
            if(!dfs(i))
                return false;
        }
        done.erase(index);
        graph.erase(index);

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        if(n == 0)
            return true;

        for(int i=0;i<n;i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses;i++){
            if(!dfs(i))
                return false;
        }

        return true;
    }
};