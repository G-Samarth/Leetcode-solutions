class Solution {
    string expand(string s, int start, int end){
        while(start >= 0 && end < s.length()){
            if(s[start] != s[end])
                break;
            start--;
            end++;
        }

        return s.substr(start+1, end-start-1);
    }
public:
    string longestPalindrome(string s) {
        //Edge cases
        if(s.length() <= 1)
            return s;

        string ans = "";
        //For loop
        for(int i=0;i<s.length();i++){
            // consider index as middle char - even & odd
            string odd = expand(s, i, i);
            string even = expand(s, i, i+1);

            if(odd.length() > ans.length())
                ans = odd;
            if(even.length() > ans.length())
                ans = even;
        }

        return ans;
    }
};