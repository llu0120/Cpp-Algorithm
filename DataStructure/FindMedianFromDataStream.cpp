/*
Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

For example,
[2,3,4], the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
 

Example:

addNum(1)
addNum(2)
findMedian() -> 1.5
addNum(3) 
findMedian() -> 2
 

Follow up:

If all integer numbers from the stream are between 0 and 100, how would you optimize it?
If 99% of all integer numbers from the stream are between 0 and 100, how would you optimize it?
*/
//Heap Solution O(logn) --> heap insertion 
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {    
    }
    
    void addNum(int num) {
        //if num is samller than the top of max queue (biggest number in max queue) --> insert into max queue
        if (pq_max.empty() || pq_max.top() > num) {
           pq_max.push(num);
        } else {
           pq_min.push(num);
        }
        //Rebalance 
        if (pq_max.size() > (pq_min.size()+1)) {
            pq_min.push(pq_max.top());
            pq_max.pop(); 
        } else if (pq_min.size() > (pq_max.size()+1)) {
            pq_max.push(pq_min.top());
            pq_min.pop(); 
        }
    }
    
    double findMedian() {
    
        if (pq_max.size() == pq_min.size()) {
            if (pq_max.size() == 0) {
                return 0; 
            }
            return (pq_max.top() + pq_min.top()) / 2.0; 
        } 
        if (pq_max.size() > pq_min.size()) {
            return pq_max.top(); 
        } else {
            return pq_min.top(); 
        }
    }
private: 
    priority_queue<int> pq_max; //max heap
    priority_queue<int, vector<int>, greater<int>> pq_min; //min heap
};



//Brute Force --> O(nlogn) because of sort  
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(int num) {
        data.push_back(num);
    }
    
    double findMedian() {
        sort(data.begin(), data.end());
        int n = data.size(); 
        if (n%2 == 0) {
            result = (data[(n+1)/2] + data[(n+1)/2-1]) / 2.0;
            return result; 
        }
        result = data[(n)/2.0];
        return result;
    }
private: 
    vector<int> data; 
    double result;
};

