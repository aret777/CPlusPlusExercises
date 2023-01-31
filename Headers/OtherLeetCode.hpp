#ifndef OTHEREXERCISES_HPP
#define OTHEREXERCISES_HPP

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step */

class Solution1 {
public:
    int climbStairs(int n) {
        vector<int> dp(n+10);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

/* You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
 */

class Solution2 {
public: 
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int index = 0;
        for (size_t i = 0; i < prices.size(); i++){
            if (prices[i] < prices[index]) {
                index = i; 
            } 
            if ((prices[i] - prices[index]) > profit){
                profit = prices[i] - prices[index];  
            }
        }
        return profit;
    }
};


#endif //OTHEREXERCISES_HPP