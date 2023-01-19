#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <algorithm>
#include <vector>

/* There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
 };
 

class Solution1 {
public:
    void deleteNode(ListNode* node) {
        // just copy the next node value to the current node to be deleted
        node->val = node->next->val;
        // make the current pointer point to the next of next to delete the node 
        node->next = node->next->next;
    }
};
*/

//Given the head of a linked list, remove the nth node from the end of the list and return its head.
/* Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1] */
/* 
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution2 {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL) {
            return NULL;
        }

        int countNodes = 0;
        ListNode* current = head;
        while (current != NULL) { //counting how many nodes in list
            countNodes++;
            current = current->next;
        }
        cout << "COunted: " << countNodes << endl;

        if (countNodes == n) { //returning 2nd node head cause it asked us to delete head node
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        current = head;
        for (size_t i = 0; i < countNodes-n-1; i++) {
            current = current->next;
        }
        ListNode* temp = current->next;
        current->next = current->next->next;
        delete temp;
        return head;
    }

}; */

/* Given the head of a singly linked list, reverse the list, and return the reversed list.
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Input: head = [1,2]
Output: [2,1]
Example 3:
Input: head = []
Output: [] */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution3 {
public:
    ListNode* reverseList(ListNode* head) {
        //head -> 1 -> 2 -> 3 -> 4 -> nullptr
        ListNode* prev = nullptr;
        ListNode* current = head; //points to node with value 1
        while (current != nullptr) {
            ListNode* next = current->next; //points to node with value 2 , 3 , 4, null
            current->next = prev; //current node (1,2,3, 4) pointer now points to nullptr,1,2, 3
            prev = current; // prev now points to node with value 1,2,3,4
            current = next; // current now points to node with value 2,3,4, null
        }
        current = prev; //equal at final to 4, new reversed head
        while (current != nullptr) { //printing final list
            cout << current->val << " ";
            current = current->next;
        }
        return prev;
        
    }
};
#endif //LINKEDLIST_HPP 