class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int maxHeight = 0;

        for(int i=0;i<heights.size();i++){
            while(!st.empty() && st.top().second > heights[i]){
                int topHeight = st.top().second;
                st.pop();
                int leftB;
                if(st.empty())
                    leftB = -1;
                else
                    leftB = st.top().first;

                maxHeight = max(maxHeight, (i-leftB-1)*topHeight);
            }

            st.push({i, heights[i]});
        }

        while(!st.empty()){
            int topHeight = st.top().second;
            st.pop();
            int leftB;
            if(st.empty())
                leftB = -1;
            else
                leftB = st.top().first;

            maxHeight = max(maxHeight, (int)(heights.size()-leftB-1)*topHeight);
        }

        return maxHeight;
    }
};