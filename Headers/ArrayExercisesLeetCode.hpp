// or #pragma once? Anyway...
#ifndef ARRAYEXERCISES_HPP
#define ARRAYEXERCISES_HPP

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such
that each unique element appears only once. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result
be placed in the first part of the array nums. More formally, if there are k elements after removing the
duplicates, then the first k elements of nums should hold the final result. It does not matter what you
leave beyond the first k elements.

Return k after placing the final result in the first k slots of nums.

Do not allocate extra space for another array. You must do this by modifying the input array in-place
with O(1) extra memory.*/

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int insertIndex = 1;
        int size = nums.size();
        for (int i = 1; i < size; i++)
        {
            // We skip to next index if we see a duplicate element
            if (nums[i - 1] != nums[i])
            {
                cout << "Nums  " << nums[i - 1] << "not equal to " << nums[i] << endl;
                // Storing the unique element at insertIndex index and incrementing the insertIndex by 1
                nums[insertIndex] = nums[i];
                insertIndex++;
                cout << "Insert index increased to: " << insertIndex << endl;
            }
        }
        for (int i = 0; i < size; i++)
        {
            cout << "Final Arrays: " << nums[i] << endl;
        }
        return insertIndex;
    }
};

// Given an integer array nums, return true if any value appears at least twice in the array, 
// and return false if every element is distinct.

class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        auto it = adjacent_find(nums.begin(), nums.end());
        if (it != nums.end()) {
            cout << "First pair of duplicates: " << *it << " " << *(it+1) << endl;
            return true;
        } else {
            cout << "No duplicates found" << endl;
            return false;
        }
    }
};

/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.
*/
class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
         
        int ans=0;
        for(auto x : nums){
            ans = ans^x; cout << ans << "Ans XOR " << x << endl;}
        return ans;
        /*
        sort(nums.begin(), nums.end());
        for (int i = 1; i<=nums.size(); i+=2) {
            if (nums.size()==1) {return nums[0];}
            if (nums[i] != nums[i-1]) {
                cout << "Found " << nums[i-1] << " at " << i-1 << endl;
                return nums[i-1];
                }
         else {cout << "Number " << nums[i] << " at positions " << i << " and " << i-1 << endl;}
        }*/
    }
};

/*
Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
*/
class Solution4 {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int> ans;
        if(nums1.size()==0 || nums2.size()==0) return ans;
        int m = nums1.size();
        int n = nums2.size(); 

        int i=0,j=0;
        while(i<m && j<n){
        if(nums1[i]<nums2[j]){
            i++;
        }
        else if(nums1[i]>nums2[j]){
            j++;
        }
        else{
            ans.push_back(nums1[i]);
            i++;j++;
        }
    }   

        return ans;
    }
};

/*
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. 
The digits are ordered from most significant to least significant in left-to-right order. 
The large integer does not contain any leading 0's.
Increment the large integer by one and return the resulting array of digits.
Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/
class Solution5 {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int>::iterator i;
        for (i = digits.end()-1; i != digits.begin()-1; i--){
            (*i)++;
            if (*i == 10) {
            *i=0; 
            if (i == digits.begin()){
                digits.insert(digits.begin(),1);
                break;}}
            else {break;}
        }
        for (i = digits.end()-1; i != digits.begin()-1; i--){
            cout << *i << endl;}
    return digits;
    }
};

/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.
Example 1:

Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:

Input: nums = [0]
Output: [0]

*/

class Solution6 {
public:
    void moveZeroes(vector<int>& nums) {
        int lastNonZeroIndex = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroIndex++] = nums[i];
            }
        }
        for (int i = lastNonZeroIndex; i < nums.size(); i++) {
            nums[i] = 0;
        }
            
    vector <int>::iterator i;
    for (i = nums.begin(); i != nums.end(); i++){
            cout << *i << endl;}
    }
/*         vector<int>::iterator i;
        for (i = nums.begin(); i != nums.end(); i++){
            if ((*i)==0) {
                vector<int>::iterator j = i;
                while (j != nums.end() && *(j+1) == 0) {  //So if equal zero, we go forward to find non-zero element to swap with it
                    j++; //incrementing iterator. If we reached end and all we found iz 0 - our zero is in the end
                }
                swap(*i, *j);
            }
    } 
    for (i = nums.begin(); i != nums.end(); i++){
            cout << *i << endl;}
    }*/
};

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]
*/
class Solution7 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>::iterator it;
        vector<int> answer = {0, 0};
        
        for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
            cout << *i << " ";}
        cout << endl << "End of starting line. Number " << target << endl;

/*         for (it = nums.begin(); it != nums.end() ; ){
            if (*it>target){
                it = nums.erase(it);}
            else {it++;}} */
        
        for (int i = 0; i<nums.size(); i++){
            for (int j = i+1; j<nums.size(); j++){
                if (nums[i] + nums[j] == target) {cout << "Found: " << nums[i] << " and " << nums[j] << endl;
                answer[0] = i; answer[1]=j;}
        }}
        
        for (vector<int>::iterator i = answer.begin(); i != answer.end(); i++){
            cout << *i << " ";}
        cout << endl << "End of final line" << endl;
        return answer;
        
    }
};








#endif // ARRAYEXERCISES_HPP