// 295. Find Median from Data Stream
// Leetcode - https://leetcode.com/problems/find-median-from-data-stream/

// Very Good Editorial at LeetCode


class MedianFinder {
public:
    priority_queue<double> lo;
    priority_queue<double, vector<double>, greater<double> > hi;
    void addNum(int num) {
        lo.push(num); // asuming that the new number is less than lo.top();
        hi.push(lo.top());
        lo.pop(); // size balancing - asuming that both are now of same size
        
        if(lo.size() != hi.size()){ // if our asumption was wrong
            lo.push(hi.top());
            hi.pop();
        }
    }    
    double findMedian() {
        if(lo.size() > hi.size())
            return lo.top();
        return (lo.top() + hi.top())/2.0;
    }
};