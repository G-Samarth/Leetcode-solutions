class Solution {
public:
    bool windowCheck(vector<int>& freq1, vector<int>& freq2){
        for(int i=0;i<26;i++){
            if(freq1[i] != freq2[i])
                return false;
        }

        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);

        for(int i=0;i<s1.length();i++)
            freq[s1[i]-'a']++;

        vector<int> temp(26, 0);
        int i=0;
        for(int j=0;j<s2.length();j++){
            if(j-i < s1.length()){
                temp[s2[j]-'a']++;
            }else{
                temp[s2[j]-'a']++;
                temp[s2[i]-'a']--;
                i++;
            }

            if(windowCheck(freq, temp))
                return true;
        }

        return false;
    }
};