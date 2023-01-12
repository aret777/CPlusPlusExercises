#ifndef STRINGEXERCISES_HPP
#define STRINGEXERCISES_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/* 
Write a function that reverses a string. The input string is given as an array of characters s.
You must do this by modifying the input array in-place with O(1) extra memory.
Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"] */

class Solution {
public:
    void reverseString(vector<char>& str) {
        int size = str.size();
        for (int i = 0, j = size-1; i < size/2 && j >= size/2; i++, j--){
            swap(str[i], str[j]);
        }

        for (vector<char>::iterator i = str.begin(); i != str.end(); i++){
            cout << *i << " ";}
        cout << endl << "End of final line" << endl;   
    }
};

/* Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21 */

class Solution2 {
public:
    int reverse(int x) {
  
        string str = to_string(x);
        bool isNegative = (str[0] == '-');
        if(isNegative) {str.erase(0,1);}
        
        for (int i=0; i<str.size(); i++){
            cout << str[i] << " ";
        }
        std::reverse(str.begin(), str.end());
        long long int result = stoll(str); //stoll converts a string to a long long int
        if (result > 2147483647 || result < -2147483648) {return 0;}
        cout << "Result: " << result;

        if (isNegative) {return -result;}
        else {return result;}

    }
};

#endif //STRINGEXERCISES_HPP