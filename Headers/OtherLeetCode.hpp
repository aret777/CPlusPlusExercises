#ifndef OTHEREXERCISES_HPP
#define OTHEREXERCISES_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <string>
#include <stack>
#include <unordered_set>

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

/* Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example 1:
Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

Example 2:
Input: n = 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

Example 3:
Input: n = 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits. */

class Solution3 {
public:
    int hammingWeight(uint32_t n) {
        string stringy = bitset<32>(n).to_string();
        cout << stringy << endl;
        int numberOnes = 0;
        for (char c : stringy) {
            if (c == '1') {
                numberOnes++;
            }
        }
        cout << "Found 1 = " << numberOnes << endl;
        return numberOnes;
    }
};

/* Reverse bits of a given 32 bits unsigned integer.
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, 
so return 964176192 which its binary representation is 00111001011110000010100101000000. */

class Solution4 {
public:
    uint32_t reverseBits(uint32_t n) {
        string stringy = bitset<32>(n).to_string();
        while (stringy.length() < 32) { //in case if transformationt akes away 0, so it shorter than 32 bits
            stringy = "0" + stringy;
        }
        reverse(stringy.begin(), stringy.end());
        cout << stringy << endl;
        uint32_t answer = bitset<32>(stringy).to_ulong(); //transforms string back to uint32_t 
        cout << answer << endl;
        return answer;
    }
};

/* Given an integer numRows, return the first numRows of Pascal's triangle.
Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:
Input: numRows = 1
Output: [[1]] */

class Solution5 {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> finalAnswer(numRows); //cause it always will have numRows arrays in it

        for (size_t i = 0; i < numRows; i++){
            finalAnswer[i].resize(i+1); //resize every row for example 0th row with size 1, 1st = 2, 2nd = 3...
            finalAnswer[i][0] = finalAnswer[i][i] = 1; //fix value of first and last element of every row as 1.
              for (size_t j = 1; j < i; j++){
                  finalAnswer[i][j] = finalAnswer[i-1][j-1] + finalAnswer[i-1][j]; //finding value by adding above 2 elements.
              }
        } 

        for (size_t i = 0; i < numRows; i++) { //printing
            for (size_t j = 0; j < i+1; j++) {
                cout << finalAnswer[i][j] << " ";
            }
            cout << endl;
        }
        return finalAnswer;
    }
};

/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 
Example 1:
Input: s = "()"
Output: true
Example 2:
Input: s = "()[]{}"
Output: true
Example 3:
Input: s = "(]"
Output: false */

class Solution6 {
public:
    bool isValid(string s) {
        stack<char> myStack; 
        for (size_t i = 0; i < s.size(); i++){
            cout << "Checking symbol " << s[i] << endl;
            if ((s[i] == '(')||(s[i] == '{')||(s[i] == '[')){
                myStack.push(s[i]); cout << "Pushed" << endl;
            }
            else {
                if (myStack.empty()) {cout << "false empty )]}"; return false;} 
                else if ((myStack.top() == '(')&&(s[i] != ')')) {cout << "false not )"; return false;} 
                else if ((myStack.top() == '{')&&(s[i] != '}')) {cout << "false not }"; return false;}  
                else if ((myStack.top() == '[')&&(s[i] != ']')) {cout << "false not ]"; return false;}
                myStack.pop(); cout << "Popped" << endl;
            }
        }
        if (myStack.empty()){
            cout << "True" << endl;
            return true;
        } else {
            cout << "False" << endl;
            return false;
        } 
    }
    
};

/* Given an array nums containing n distinct numbers in the range [0, n], 
return the only number in the range that is missing from the array.
Input: nums = [3,0,1]
Output: 2
Explanation: n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number */

class Solution7 {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
    
        for (size_t i = 0; i <= nums.size() + 1; i++) {
            if (seen.find(i) == seen.end()) {
                return i;
            }
        }
    return -1; // If no missing number is found
    }
};
#endif //OTHEREXERCISES_HPP