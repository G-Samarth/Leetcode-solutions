class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        unordered_map<char, int> map;

        for(char t:tasks){
            map[t]++;
        }
        for(auto m : map){
            pq.push(m.second);
        }

        int ans = 0;
        while(!pq.empty()){
            vector<int> temp;
            int cycle = n+1;

            while(cycle && !pq.empty()){
                int top = pq.top();
                pq.pop();
                cycle--;
                ans++;
                if(top > 1)
                    temp.push_back(--top);
            }

            for(int t : temp)
                pq.push(t);

            if(!pq.empty())
                ans += cycle;
        }
        return ans;
    }
};