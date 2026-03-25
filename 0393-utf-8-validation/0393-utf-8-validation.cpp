class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int rem = 0;

        for(int i=0;i<data.size();i++){
            if(rem){
                if((data[i] & 0xC0) != 0x80)
                    return false;
                rem--;
            }else{
                if((data[i] & 0x80) == 0x00)
                    rem = 0;
                else if((data[i] & 0xE0) == 0xC0)
                    rem = 1;
                else if((data[i] & 0xF0) == 0xE0)
                    rem = 2;
                else if((data[i] & 0xF8) == 0xF0)
                    rem = 3;
                else
                    return false;
            }
        }

        return rem == 0;
    }
};