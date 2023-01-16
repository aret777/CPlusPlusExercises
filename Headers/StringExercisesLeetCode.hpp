#ifndef STRINGEXERCISES_HPP
#define STRINGEXERCISES_HPP

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>

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

/* Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.
Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2 */
class Solution3 {
public:
    int firstUniqChar(string myString) {
        unordered_map<char, int> myMap;

        for (const char& c : myString) {
            myMap[c]++;
        }
        for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) {
        cout << iter->first << ": " << iter->second << " ";
        }
        for (int i = 0; i < myString.length(); i++) {
            char c = myString[i];
            if (myMap[c] == 1) {return i;}
        }
        return -1;
    }
};

/* Given two strings s and t, return true if t is an anagram of s, and false otherwise.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false */

class Solution4 {
public:
    bool isAnagram(string OrigStr, string CompStr) {
        unordered_map<char, int> myMap;

        for (int i = 0; i < OrigStr.length(); i++) {
            char c = OrigStr[i];
            myMap[c]++;
        }

        for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) { //showing on terminal
        cout << iter->first << ": " << iter->second << " " << endl;
        }
        
        for (int i = 0; i < CompStr.length(); i++) {
            auto it = myMap.find(CompStr[i]);
            if (it != myMap.end()) { 
                it->second -= 1; //found letter, removing 1 from value
                cout << "Removing letter " << CompStr[i] << endl;
                cout << it->first << ": " << it->second << " " << endl;
                if (it->second < 0) {return false;}
            } else {cout << "Didnt found letter " << CompStr[i] << endl;
                return false;}
            
        }

        for (auto iter = myMap.begin(); iter != myMap.end(); ++iter) { //last check if any letter left
            if(iter->second > 0) return false;
        }
        return true;
    }
};

/* A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters,
it reads the same forward and backward. Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
 */
class Solution5 {
public:
    bool isPalindrome(string myString) {
        
        myString.erase(remove_if(myString.begin(), myString.end(), [](char c){ return !isalnum(c); }), myString.end());
        //removing non-alphanumeric chars with remove_if(isalnum(c))
        transform(myString.begin(), myString.end(), myString.begin(), ::tolower);
        //transform big letter into small ones with ::tolower
        if (myString.empty() || all_of(myString.begin(), myString.end(), ::isspace) || myString.length() == 1) {
            return true;
        }

        cout << myString << " lenght is: " << myString.length()/2 << endl;
        for (int i = 0, k = myString.length()-1; ((i <= myString.length()/2)&&(k >= myString.length()/2)); ) {
            if (myString[i] != myString[k]) {
                cout << "Letters " << myString[i] << " and " << myString[k] << " not equal at iteration k: " << k << " and i: " << i; 
                return false;}
            else {i++; k--; }
            //cout << "Comparing i: " << myString[i] << " and k: " << myString[k] << endl;}
        }
        return true;
    }
};

/* Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings. */

class Solution6 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        string prefix = "";
        int smallestword = 200;
        for (int k = 0; k < strs.size(); k++){ //counting size of words in vector
                if (strs[k].length() < smallestword) {smallestword = strs[k].length();}
        }

        for (int i = 0; i < smallestword; i++){//iterating letters
            char currentChar = strs[0][i]; //assigning first letter of first word
            for (int k = 0; k < strs.size(); k++){ //iterating words in vector
                if (currentChar==strs[k][i]){continue;} else {return prefix;}
            }
            //if just some word have common first letter, return {}
            prefix+=currentChar;
        }
        return prefix;
    }
};
#endif //STRINGEXERCISES_HPP