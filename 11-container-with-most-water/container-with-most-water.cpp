class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i=0, j=n-1;

        int ans = 0;
        while(i < j){
            int mi = min(height[i], height[j]);
            ans = max(ans, mi*(j-i));
            
            if(height[i] < height[j])
                i++;
            else
                j--;
        }

        return ans;
    }
};