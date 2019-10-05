/* O(n)
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.
Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int price_size = prices.size();
        if (price_size < 1) {
            return 0; 
        } 
        vector<int> min_price(price_size); //Maintain a minimum price till today
        vector<int> max_profit(price_size); //Maitain a maximum profit till today
        min_price[0] = prices[0];
        max_profit[0] = 0;
        for (int i = 1; i < price_size; i++) {
            min_price[i] = min(min_price[i-1], prices[i]);
            max_profit[i] = max(max_profit[i-1], prices[i] - min_price[i-1]);
        }
        return max_profit[price_size-1];
    }
};
