class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> dp(prices.size(), 0);
        
        for(int i=1;i<prices.size();i++){
            for(int j=0;j<i;j++){
                if(prices[j] < prices[i]){
                    dp[i] = max((prices[i] - prices[j]) + dp[j], dp[i]);
                }else{
                    dp[i] = max(dp[i], dp[j]);
                }
            }
        }

        //0,0,4,2,0,0

        int ans = 0;
        for(int i=0;i<prices.size();i++){
            ans = max(ans, dp[i]);
        }

        return ans;
    }
};