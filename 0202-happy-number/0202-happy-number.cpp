class Solution {
    int sumOfSq(int n){
        int sum = 0;
        while(n){
            int curr = n%10;
            n = n/10;
            sum += curr*curr;
        }

        return sum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> nums;

        while(true){
            int nextNum = sumOfSq(n);

            if(nextNum == 1)
                return true;
            else if(nums.count(nextNum) > 0)
                return false;
            
            nums.insert(nextNum);
            n = nextNum;
        }
    }
};