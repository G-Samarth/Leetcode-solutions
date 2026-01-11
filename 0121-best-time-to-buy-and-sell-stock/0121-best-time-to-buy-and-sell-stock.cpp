class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minimum = INT_MAX;
        for(int i=0;i<prices.size();i++){
            ans = max(ans, prices[i] - minimum);
            minimum = min(minimum, prices[i]);
        }

        return ans;
    }
};