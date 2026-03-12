class Solution {
    bool check(vector<int>& piles, int h, int mid){
        long long total = 0;

        for(int p:piles){
            total += (p+mid-1)/mid;
        }

        return total <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int end = 1;
        int ans = 1;

        for(int p : piles){
            end = max(end, p);
            ans = max(ans, p);
        }

        while(start <= end){
            int mid = start + (end-start)/2;

            if(check(piles, h, mid)){
                ans = min(ans, mid);
                end = mid-1;
            }else{
                start = mid+1;
            }
        }

        return ans;
    }
};