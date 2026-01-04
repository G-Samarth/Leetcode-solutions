class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cand1 = -1, count1 = 0;
        int cand2 = -1, count2 = 0;

        for(int n : nums){
            if(cand1 == n){
                count1++;
            }else if(cand2 == n){
                count2++;
            }else if(count1 == 0){
                count1 = 1;
                cand1 = n;
            }else if(count2 == 0){
                count2 = 1;
                cand2 = n;
            }else{
                count1--;
                count2--;
            }
        }

        count1=0, count2=0;
        for(int n : nums){
            if(n == cand1)
                count1++;
            else if(n == cand2)
                count2++;
        }

        cout<<cand1<<cand2<<endl;

        int thrsh = nums.size()/3;
        vector<int> ans;
        if(count1 > thrsh)
            ans.push_back(cand1);
        if(count2 > thrsh)
            ans.push_back(cand2);

        return ans;
    }
};