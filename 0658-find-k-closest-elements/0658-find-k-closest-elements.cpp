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

        ans.push_back(arr[middle]);
        int i = middle-1, j = middle+1;

        while(ans.size() != k){
            if(i >= 0 && j < arr.size()){
                if(abs(x-arr[i]) > abs(x-arr[j])){
                    ans.push_back(arr[j]);
                    j++;
                }else{
                    ans.push_back(arr[i]);
                    i--;
                }
            }else if(i >= 0){
                ans.push_back(arr[i--]);
            }else{
                ans.push_back(arr[j++]);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};