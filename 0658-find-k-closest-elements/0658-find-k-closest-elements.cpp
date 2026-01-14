class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(k == 0)
            return {};

        vector<int> ans;
        int middle, lowest = INT_MAX;

        for(int i=0;i<arr.size();i++){
            if(abs(x - arr[i]) < lowest){
                lowest = abs(x-arr[i]);
                middle = i;
            }
        }

        int i = middle;
        int j = middle;

        while(j-i+1 < k){
            if(i>0 && j<arr.size()-1){
                if(abs(x-arr[i-1]) > abs(x-arr[j+1]))
                    j++;
                else
                    i--;
            }else if(i>0){
                i--;
            }else if(j<arr.size()-1){
                j++;
            }
        }

        while(i <= j){
            ans.push_back(arr[i++]);
        }
        return ans;
    }
};