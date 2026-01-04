class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans = 0;

        for(int n : nums){
            int sum = 1+n;
            int count = 2;

            int range = sqrt(n);
            for(int i=2;i<range+1;i++){
                if(n%i == 0){
                    int rem = n/i;

                    if(rem == i){
                        count++;
                        sum += i;
                    }else{
                        count += 2;
                        sum = sum + i + rem;
                    }
                }

                if(count > 4)
                    continue;
            }

            if(count == 4)
                ans += sum;
        }

        return ans;
    }
};