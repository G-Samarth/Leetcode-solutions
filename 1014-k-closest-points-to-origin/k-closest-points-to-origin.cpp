class Solution {
    int calcEuc(vector<int> point){
        int sum = (point[0]*point[0]) + (point[1]*point[1]);
        return sum;
    }
    struct Compare{
        bool operator()(pair<int, int> a, pair<int, int> b){
            return a.first > b.first;
        }
    };
public:
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        for(int i=0;i<points.size();i++){
            int dist = calcEuc(points[i]);
            pq.push({dist, i});
        }

        vector<vector<int>> ans;
        while(k--){
            auto top = pq.top();
            pq.pop();

            ans.push_back(points[top.second]);
        }

        return ans;
    }
};