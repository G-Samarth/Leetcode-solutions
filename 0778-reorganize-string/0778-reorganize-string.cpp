class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        for(char c:s)
            freq[c-'a']++;
        
        priority_queue<pair<int, char>> pq;

        for(int i=0;i<freq.size();i++){
            if(freq[i] != 0)
                pq.push({freq[i], (char)(i+'a')});
        }


        string ans = "";
        pair<int, char> prev = {-1, ' '};

        while(!pq.empty()){
            pair<int, char> top = pq.top();
            pq.pop();

            ans += top.second;
            if(prev.first != -1)
                pq.push(prev);

            if(top.first == 1){
                prev = {-1, ' '};
            }else
                prev = {top.first-1, top.second};
        }

        if(ans.length() == s.length())
            return ans;
        else
            return "";
    }
};