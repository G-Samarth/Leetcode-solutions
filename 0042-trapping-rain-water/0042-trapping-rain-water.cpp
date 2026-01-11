class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int lMax = INT_MIN, rMax = INT_MIN;
        int i=0, j=n-1;
        int ans = 0;

        while(i < j){
            if(height[i] < height[j]){
                if(lMax < height[i])
                    lMax = height[i];
                else
                    ans += lMax - height[i];

                i++;
            }else{
                if(rMax < height[j])
                    rMax = height[j];
                else
                    ans += rMax - height[j];

                j--;
            }
        }

        return ans;
    }
};