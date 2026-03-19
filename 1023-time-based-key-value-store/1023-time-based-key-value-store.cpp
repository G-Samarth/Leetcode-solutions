class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> map;
    
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto& values = map[key];
        int left = 0, right = values.size()-1;
        string ans = "";

        while(left <= right){
            int mid = left + (right - left)/2;

            if(values[mid].first <= timestamp){
                ans = values[mid].second;
                left = mid+1;
            }else{
                right = mid-1;
            }
        }

        return ans;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */