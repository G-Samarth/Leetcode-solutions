class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size()-1;
        int i=0, j=n;
        int ans = 0;

        while(i < j){
            int low = min(height[i], height[j]);
            ans = max(ans, low*(j-i));

            if(height[i] < height[j])
                i++;
            else
                j--;
        }

        return ans;
    }
};