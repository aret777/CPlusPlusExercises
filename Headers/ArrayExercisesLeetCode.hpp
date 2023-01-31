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
        for (size_t i = 1; i < size; i++){
            // We skip to next index if we see a duplicate element
            if (nums[i - 1] != nums[i]){
                cout << "Nums  " << nums[i - 1] << "not equal to " << nums[i] << endl;
                // Storing the unique element at insertIndex index and incrementing the insertIndex by 1
                nums[insertIndex] = nums[i];
                insertIndex++;
                cout << "Insert index increased to: " << insertIndex << endl;
            }
        }
        for (size_t i = 0; i < size; i++){
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
        if (nums1.size() == 0 || nums2.size() ==0) {return ans;}
        int m = nums1.size();
        int n = nums2.size(); 

        int i = 0, j = 0;
        while(i < m && j < n){
            if (nums1[i] < nums2[j]){
                i++;
            }
            else if(nums1[i] > nums2[j]){
                j++;
            }
            else {
                ans.push_back(nums1[i]);
                i++; j++;
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
        for (vector<int>::iterator i = digits.end()-1; i != digits.begin()-1; i--){
            (*i)++;
            if (*i == 10) {
                *i=0; 
                if (i == digits.begin()){
                    digits.insert(digits.begin(),1);
                    break;
                }
            }
            else {break;}
        }

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
        for (size_t i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[lastNonZeroIndex++] = nums[i];
            }
        }

        for (size_t i = lastNonZeroIndex; i < nums.size(); i++) {
            nums[i] = 0;
        }
            
        for (vector <int>::iterator i = nums.begin(); i != nums.end(); i++){
                cout << *i << endl;
        }
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
    } */
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
            cout << *i << " ";
        }
        cout << endl << "End of starting line. Number " << target << endl;
        
        for (size_t i = 0; i < nums.size(); i++){
            for (size_t j = i+1; j < nums.size(); j++){
                if (nums[i] + nums[j] == target) {
                    cout << "Found: " << nums[i] << " and " << nums[j] << endl;
                    answer[0] = i; answer[1]=j;
                }
            }
        }
        
        for (vector<int>::iterator i = answer.begin(); i != answer.end(); i++){
            cout << *i << " ";
        }

        cout << endl << "End of final line" << endl;
        return answer;
        
    }
};

/* You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.
Merge nums1 and nums2 into a single array sorted in non-decreasing order.
The final sorted array should not be returned by the function, but instead be stored inside the array nums1.
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, 
and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

Example 1:
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

Example 2:
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
Explanation: The arrays we are merging are [1] and [].
The result of the merge is [1].
 */

class Solution8 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) {return;}
        
        /* for (size_t i = 0; i < n; i++){
            nums1[m+i] = nums2[i];
        }
        sort(nums1.begin(), nums1.end());
        for (vector<int>::iterator i = nums1.begin(); i != nums1.end(); i++){
            cout << *i << " ";
        } */
        // OR
        // {1,4,5,6,10,0,0,0,0}; and {1,2,6,9}; m=5, n=4
        vector<int> solution;
        size_t j = 0;
        size_t i = 0;
        while ((i < m)&&(j < n)){
            if (nums1[i] <= nums2[j]) {
                solution.push_back(nums1[i]); i++;
            } //[1, 1, 2, 4, 5, 6, 6, 9, ]
            else {
                solution.push_back(nums2[j]); j++;
            }
            
        }
        // Add remaining elements from nums1
        while (i < m) {
            solution.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2
        while (j < n) {
            solution.push_back(nums2[j]);
            j++;
        } 

        for (size_t i = 0; i < solution.size(); i++) {
            nums1[i] = solution[i];
        }
        for (int x : nums1){
            cout << x << " ";
        }

    }
};

/* You are a product manager and currently leading a team to develop a new product. 
Unfortunately, the latest version of your product fails the quality check. 
Since each version is developed based on the previous version, all the versions after a bad version are also bad.
Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
You are given an API bool isBadVersion(version) which returns whether version is bad. 
Implement a function to find the first bad version. You should minimize the number of calls to the API.
Example 1:
Input: n = 5, bad = 4
Output: 4
Explanation:
call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true
Then 4 is the first bad version.
 */

class Solution9 {
public:
    int firstBadVersion(int n) {
        //false == good version, it doesnt have mistakes
        
        int left = 1;
        int right = n;
        int mid;

        while(left <= right)
        {
            mid = left + (right-left)/2;
           //  isBadVersion(mid)? right = mid - 1 : left = mid + 1;
        }
        return left;
    }
};

/* Given an integer array nums, find the subarray with the largest sum, and return its sum.
Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.
Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23. */

class Solution10 {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int sum = nums[0];
        for (size_t i = 1; i < n; i++){
            if (sum < 0) {
            sum = nums[i]; //basically reloading sum to new possible array, if previous one gathered a lot of -1-2-3-4...
            }
            else {
                sum += nums[i];
            }
            maxi = max(sum, maxi);
        }
        return maxi;
    }
};

/* You are a professional robber planning to rob houses along a street. 
Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that 
adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses
were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money
you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12. */

class Solution11 {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = nums[0];

        if (n == 1) {
            return nums[0];
        }

        int prev1 = max(prev2, nums[1]);
        for(int i = 2; i < n; i++){
            int cur = max(prev1,prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};


/* Given an integer array nums, design an algorithm to randomly shuffle the array. 
All permutations of the array should be equally likely as a result of the shuffling.
Implement the Solution class:
Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array. */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */

class Solution12 {
public:
    vector<int> duplic;
    vector<int> shuffleArr;
    Solution12(vector<int>& nums) {
        duplic = nums;
        shuffleArr = nums;
    }
    
    vector<int> reset() {
        return duplic;
    }
    
    vector<int> shuffle() {
        int randomPos = rand()% shuffleArr.size();
        for (size_t i = 0; i < shuffleArr.size(); i++){
            swap(shuffleArr[i], shuffleArr[randomPos]);
        }
        return shuffleArr;
    }
};



#endif // ARRAYEXERCISES_HPP