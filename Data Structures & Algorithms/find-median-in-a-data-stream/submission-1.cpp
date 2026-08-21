class MedianFinder {
public:

    priority_queue<int> maxHeap;
    priority_queue<int,vector<int>,greater<int>> minHeap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty()){
            maxHeap.push(num);
            return;
        }


        if(num<=maxHeap.top()){
            maxHeap.push(num);
        }else{
            minHeap.push(num);
        }

        if(maxHeap.size()>minHeap.size()+1){
            int top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }else if(minHeap.size()>maxHeap.size()){
            int top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }


    }
    
    double findMedian() {
        if(maxHeap.size()>minHeap.size()){
            return (double) maxHeap.top();
        }else{
            return (double)(maxHeap.top() + minHeap.top())/2;
        }
    }
};
