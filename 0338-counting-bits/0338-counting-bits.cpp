class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i=0;i<=n;i++){
            int count = 0;
            int curr = i;
            while(curr){
                if(curr & 1)
                    count++;
                curr = curr >> 1;
            }

            ans.push_back(count);
        }

        return ans;
    }
};