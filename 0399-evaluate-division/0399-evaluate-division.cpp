class Solution {
    double dfs(string curr, string end, unordered_map<string, vector<pair<string, double>>>& map, double product, unordered_set<string>& visited){
        if(curr == end){
            return product;
        }

        visited.insert(curr);
        for(auto i : map[curr]){
            string nxt = i.first;
            double wt = i.second;
            if(visited.count(nxt))
                continue;
            double res = dfs(nxt, end, map, product*wt, visited);

            if(res != -1.0)
                return res;
        }

        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> map;

        for(int i=0;i<values.size();i++){
            map[equations[i][0]].push_back({equations[i][1], values[i]});
            map[equations[i][1]].push_back({equations[i][0], 1/values[i]});
        }

        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            if(!map.count(queries[i][0]) || !map.count(queries[i][1])){
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            double res = dfs(queries[i][0], queries[i][1], map, 1.0, visited);

            ans.push_back(res);
        }

        return ans;
    }
};