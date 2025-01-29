class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while(n){
            if(n%2 == 1)
                ans++;
            n = n>>1;
        }

        return ans;
    }
};