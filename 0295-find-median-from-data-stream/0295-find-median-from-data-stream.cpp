class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(minHeap.empty() || num > minHeap.top())
            minHeap.push(num);
        else
            maxHeap.push(num);

        if(minHeap.size() > maxHeap.size()+1){
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }else if(minHeap.size()+1 < maxHeap.size()){
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
    }
    
    double findMedian() {
        if(minHeap.empty() && maxHeap.empty())
            return 0;
        else if(minHeap.empty())
            return maxHeap.top();
        else if(maxHeap.empty())
            return minHeap.top();
        
        if(minHeap.size() == maxHeap.size())
            return (maxHeap.top() + minHeap.top())/2.0;
        else if(minHeap.size() > maxHeap.size())
            return minHeap.top();
        else
            return maxHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */