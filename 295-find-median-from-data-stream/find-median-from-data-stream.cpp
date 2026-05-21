class MedianFinder {
public:

    // max heap
    priority_queue<int> left;

    // min heap
    priority_queue<int,
                   vector<int>,
                   greater<int>> right;

    MedianFinder() {
    }

    void addNum(int num) {

        // add to left
        left.push(num);

        // move largest to right
        right.push(left.top());
        left.pop();

        // balance sizes
        if (right.size() > left.size() + 1) {

            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {

        if (left.size() == right.size()) {

            return (left.top() +
                    right.top()) / 2.0;
        }

        return right.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */