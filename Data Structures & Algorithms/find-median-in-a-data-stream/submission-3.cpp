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
        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if (minheap.size() > maxheap.size() + 1) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if (minheap.size() == maxheap.size()) {
            return (1.0 * minheap.top() + maxheap.top()) / 2;
        } else if (maxheap.size() == minheap.size() + 1) {
            return static_cast<double>(maxheap.top());
        } else {
            return static_cast<double>(minheap.top());
        }
    }
};
