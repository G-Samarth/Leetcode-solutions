class Solution {
    unordered_map<int, vector<int>> graph;
    unordered_set<int> vis;

    bool dfs(int course){
        if(vis.count(course))
            return false;
        
        vis.insert(course);
        for(auto pr : graph[course]){
            if(!dfs(pr))
                return false;
        }
        vis.erase(course);
        graph[course].clear();

        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0;i<prerequisites.size();i++){
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for(int i=0;i<numCourses;i++){
            if(!dfs(i))
                return false;
        }

        return true;
    }
};