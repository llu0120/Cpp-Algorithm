//Data Structure
/*
* Implement a stack by two queues. The queue is first in first out (FIFO). That means you can not directly pop the last element in a queue.
* Example
* Example 1:
* Input:
* push(1)
* pop()
* push(2)
* isEmpty() // return false
* top() // return 2
* pop()
* isEmpty() // return true
* Example 2:
* Input:
* isEmpty()
*/

class Stack {
public:
    /*
     * @param x: An integer
     * @return: nothing
     */
    void push(int x) {
        // write your code here
        if (queue1.empty()){
            queue1.push(x);
            while (!queue2.empty()){
                int temp = queue2.front();
                queue2.pop();
                queue1.push(temp);
            }
        }
        else{                           // (queue2.empty())
            queue2.push(x);
            while (!queue1.empty()){
                int temp = queue1.front();  // store the first, seconde... element in the queue in temp 
                queue1.pop();               // remove the element from the queue
                queue2.push(temp);          // insert the element after x, then when doing top and pop operation will pop the last in element (LIFO)
            }
        }
        
    }

    /*
     * @return: nothing
     */
    void pop() {
        // write your code here
        if (!queue1.empty()) return queue1.pop();
        if (!queue2.empty()) return queue2.pop();
        
    }

    /*
     * @return: An integer
     */
    int top() {
        // write your code here
        if (!queue1.empty()) return queue1.front();
        if (!queue2.empty()) return queue2.front();
    }

    /*
     * @return: True if the stack is empty
     */
    bool isEmpty() {
        // write your code here
        return queue1.empty() && queue2.empty();
    }
private:
    queue<int> queue1;
    queue<int> queue2;
};
