class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            if(c == '(' || c == '{' || c == '['){
                st.push(c);
            }else{
                if(!st.empty() && ((int)st.top()+1 == (int)c || (int)st.top()+2 == (int)c)){
                    // cout<<st.top()<<endl;
                    st.pop();
                }else{
                    st.push(c);
                }
            }
        }

        if(!st.empty())
            return false;
        return true;
    }
};