class MedianFinder {
public:
    // max_heap (contains first half of elements, max element is middle element)
    priority_queue<int> lo;
    // min heap (contains first second of elements, min element is middle
    // element)
    priority_queue<int, vector<int>, greater<int>> hi;

    void addNum(int num) {
        // pushing num to max heap
        lo.push(num);
        // if element is max of first half, taking this max elemnt into second
        // half.
        hi.push(lo.top());
        // pop max element after moving to min heap.
        lo.pop();

        // if odd, lo should contain modd element else even one element from min
        // & one from max heap *0.5
        if (lo.size() < hi.size()) {
            lo.push(hi.top());
            hi.pop();
        }
    }

    double findMedian() {
        return lo.size() > hi.size() ? lo.top()
                                     : ((double)lo.top() + hi.top()) * 0.5;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */