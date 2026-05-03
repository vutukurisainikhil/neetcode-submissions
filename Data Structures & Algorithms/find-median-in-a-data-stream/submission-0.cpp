class MedianFinder {
public:
    priority_queue<int> lo;                              //max_heap (contains first half of elements, max element is middle element)
    priority_queue<int, vector<int>, greater<int>> hi;  //min heap (contains first second of elements, min element is middle element)

    
    void addNum(int num) {
        lo.push(num);       // pushing num to max heap
        
        hi.push(lo.top());  // if element is max of first half, taking this max elemnt into second half.
        lo.pop(); // pop max element after moving to min heap.
        
        if(lo.size() < hi.size()){  // if odd, lo should contain modd element else even one element from min & one from max heap *0.5
            lo.push(hi.top());
            hi.pop();
        }
        
    }
    
    double findMedian() {
        return lo.size() > hi.size() ? lo.top() : ((double) lo.top() + hi.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */