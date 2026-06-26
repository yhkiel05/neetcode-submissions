#include <queue>
#include <vector>
#include <functional>

class MedianFinder {
    // lower half: max-heap
    std::priority_queue<int, std::vector<int>, std::less<int>> maxheap;
    // upper half: min-heap
    std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: put num into the correct half
        if (maxheap.empty() || num <= maxheap.top()) {
            maxheap.push(num);
        } else {
            minheap.push(num);
        }

        // Step 2: rebalance so that maxheap has either the same size as minheap
        // or exactly one more element than minheap
        if (maxheap.size() > minheap.size() + 1) {
            minheap.push(maxheap.top());
            maxheap.pop();
        } else if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian() {
        if (maxheap.size() == minheap.size()) {
            return (maxheap.top() + minheap.top()) / 2.0;
        } else if (minheap.size() + 1 == maxheap.size()) {
            // maxheap has the extra element
            return static_cast<double>(maxheap.top());
        } else {
            return static_cast<double>(minheap.top());
        }
    }
};
