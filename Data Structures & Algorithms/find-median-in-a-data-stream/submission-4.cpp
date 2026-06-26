class MedianFinder {
    priority_queue<int, vector<int>, less<int>> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (maxheap.empty() || num <= maxheap.top()) {
            maxheap.push(num);
        } else {
            minheap.push(num);
        }
        if (minheap.size() + 1 < maxheap.size()) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if (minheap.size() > maxheap.size() + 1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if (maxheap.size() == minheap.size()) {
            return (minheap.top() + maxheap.top() * 1.0) / 2;
        } else if (maxheap.size() + 1 == minheap.size()) {
            return minheap.top() * 1.0;
        } else {
            return maxheap.top() * 1.0;
        }
    }
};
