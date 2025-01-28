class DetectSquares {
    map<pair<int, int>, int> map;
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        map[{point[0], point[1]}]++;
    }
    
    int count(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int ans = 0;

        for(auto it : map){
            pair<int, int> diagonal = it.first;

            if(x != diagonal.first && y != diagonal.second && abs(x-diagonal.first) == abs(y-diagonal.second)){
                int point1 = map[diagonal];
                int point2 = map[{x, diagonal.second}];
                int point3 = map[{diagonal.first, y}];

                ans += point1 * point2 * point3;
            }
        }

        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */