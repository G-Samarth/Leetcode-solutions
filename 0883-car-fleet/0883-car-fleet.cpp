class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<float> count;
        vector<pair<int, int>> temp;

        for(int i=0;i<speed.size();i++)
            temp.push_back({position[i], speed[i]});

        sort(temp.begin(), temp.end());

        for(int i=temp.size()-1;i>=0;i--){
            float curr = (float)(target - temp[i].first) / temp[i].second;

            if(count.empty() || count.top() < curr)
                count.push(curr);
        }

        return count.size();
    }
};