#ifndef BINARYTREEEXERCISES_HPP
#define BINARYTREEEXERCISES_HPP

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/* Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:
Input: root = [1,null,2]
Output: 2
 */

class Solution1 {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL) {return 0;}
        
        return max(maxDepth(root->left), maxDepth(root->right)) + 1; //max() is function in STL to compare two values and return max
    }
};

/* Given the root of a binary tree, determine if it is a valid binary search tree (BST).
A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
Example 1:
Input: root = [2,1,3]
Output: true
Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4. */

class Solution2 {
public:
    bool isValidBST(TreeNode* root) {
    if (root == nullptr) return true;
    if (root->left != nullptr && root->val <= maximumValue(root->left)) return false;
    if (root->right != nullptr && root->val >= minimumValue(root->right)) return false;
    return isValidBST(root->left) && isValidBST(root->right);
}

int minimumValue(TreeNode* root) {
    while (root->left != nullptr) root = root->left;
    return root->val;
}

int maximumValue(TreeNode* root) {
    while (root->right != nullptr) root = root->right;
    return root->val;
}
};


/* Convert Sorted Array to Binary Search Tree
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
Example 1:
Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:
 */
class Solution3 {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    
    TreeNode* helper(vector<int>& nums, int left, int right){
        
        //base case
        //If the left pointer crosses right return null;
        if(left > right){
            return NULL;
        }
        
        // as middle of the array will be the root node
        int mid = (left + right) / 2;
        TreeNode* temp = new TreeNode(nums[mid]);
        
        //left part from middle will be left subtree
        temp->left = helper(nums, left, mid-1);
        
        //right part of array will be right subtree
        temp->right = helper(nums, mid+1 , right);
        
        return temp;
    }
};

#endif // BINARYTREE