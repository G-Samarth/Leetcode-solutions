class Solution {
    void merge(vector<int> &nums, int low, int mid, int high){
        if(low >= high)
            return;

        int l = low, r = mid+1, k=0, n = high-low+1;
        vector<int> sorted(n, 0);
        while(l <= mid && r <= high){
            sorted[k++] = nums[l] < nums[r] ? nums[l++] : nums[r++];
        }

        while(l <= mid)
            sorted[k++] = nums[l++];
        while(r <= high)
            sorted[k++] = nums[r++];

        for(int i=0;i<n;i++)
            nums[i+low] = sorted[i];
    }
    
public:
    void mergeSort(vector<int> &nums, int low, int high){
        if(low >= high)
            return;

        int mid = (high - low)/2 + low;
        mergeSort(nums,low, mid);
        mergeSort(nums, mid+1, high);

        merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int low = 0, high = nums.size()-1;
        mergeSort(nums, low, high);

        return nums;
    }
};