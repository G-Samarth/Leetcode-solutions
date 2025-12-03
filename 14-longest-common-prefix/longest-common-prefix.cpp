class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string common = "";
        string first = strs[0], last = strs[strs.size()-1];

        int size = min(first.length(), last.length());
        for(int i=0;i<size;i++){
            if(first[i] == last[i])
                common += first[i];
            else
                return common;
        }

        return common;
    }
};