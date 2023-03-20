#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

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

}; 

/* Given the head of a singly linked list, reverse the list, and return the reversed list.
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
Input: head = [1,2]
Output: [2,1]
Example 3:
Input: head = []
Output: [] */
 
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


/* You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists in a one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:
Input: list1 = [], list2 = []
Output: []
Example 3:
Input: list1 = [], list2 = [0]
Output: [0] */

class Solution4 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
         // create a dummy node as the starting point for the merged list
        ListNode dummy(0);
        ListNode* tail = &dummy;

        // iterate through both lists, comparing the values of the current nodes
        while (list1 && list2) {
            if (list1->val < list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        // if one of the lists is not exhausted, append the remaining nodes
        if (list1) {
            tail->next = list1;
        } else {
            tail->next = list2;
        }

        // return the head of the merged list
        return dummy.next;
    }
};

/* Given head, the head of a linked list, determine if the linked list has a cycle in it.
There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following 
the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. 
Note that pos is not passed as a parameter.
Return true if there is a cycle in the linked list. Otherwise, return false.
Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).
Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node. */

class Solution5 {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next; //moving 1 step
            fast = fast->next->next; //moving 2 steps
            if (slow == fast) return true; //if it cycled, somwhere our steps will get to same node.
        }
        
        return false;
    }
};


/* Given the head of a singly linked list, return the middle node of the linked list.
If there are two middle nodes, return the second middle node.
Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one. */

class Solution6 {
public:
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode *curr = head;

        while (curr != NULL) {
            size++;
            curr = curr->next;
        }
        cout << "Original size: " << size << endl;
        size = size/2;
        cout << "Half size: " << size << endl;

        curr = head;
        for (size_t i = 0; i < size; i++){
            curr = curr->next;
        }
        return curr;
        
    }
};


/* Array Challenge
Have the function ArrayChallenge(strArr) take strArr which will be an an array consisting of the following elements: N which will be the number of gas stations in a circular route and each subsequent element will be the string g:c where g is the amount of gas in gallons at that gas station and c will be the amount of gallons of gas needed to get to the following gas station.

For example strArr may be: ["4","3:1","2:2","1:2","0:1"]. Your goal is to return the index of the starting gas station that will allow you to travel around the whole route once, otherwise return the string impossible. For the example above, there are 4 gas stations, and your program should return the string 1 because starting at station 1 you receive 3 gallons of gas and spend 1 getting to the next station. Then you have 2 gallons + 2 more at the next station and you spend 2 so you have 2 gallons when you get to the 3rd station. You then have 3 but you spend 2 getting to the final station, and at the final station you receive 0 gallons and you spend your final gallon getting to your starting point. Starting at any other gas station would make getting around the route impossible, so the answer is 1. If there are multiple gas stations that are possible to start at, return the smallest index (of the gas station). N will be >= 2.
Examples
Input: {"4","1:1","2:2","1:2","0:1"}
Output: impossible
Input: {"4","0:1","2:2","1:2","3:1"}
Output: 4 */

/*
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
using namespace std;

vector <int> solutionIndexes;

struct ListNode {
    int gas;
    int distance;
    int index;
    ListNode *next;
    ListNode *prev;
    ListNode() : gas(0), distance(0), index(-1), next(nullptr), prev(nullptr) {}
    ListNode(int x, int y, int i) : gas(x), distance(y), index(i), 
    next(nullptr), prev(nullptr) {}
    ListNode(int x, int y, int i, ListNode *next, ListNode *prev) : 
    gas(x), distance(y), index(i), next(next), prev(prev) {}
};

ListNode* CreateList(vector <int> gasTank, vector <int> gasNeeded){
    //looped list creation
    ListNode* head = new ListNode(gasTank[0], gasNeeded[0], 1); 
    ListNode* current = head;

    for (size_t i = 1; i < gasTank.size(); i++) {
        current->next = new ListNode(gasTank[i], gasNeeded[i], i+1);
        current->next->prev = current; // set prev pointer
        current = current->next;
    }
    current->next = head;
    head->prev = current; // set prev pointer of head node
    return head;
}

void traverseList(ListNode* head, bool forward) {
    ListNode* current = head;
    int gasTank = 0;

    if (forward) {
      cout << "Forward traversal:" << endl;}
    if (!forward) {
      cout << "Backward traversal:" << endl;}

    do {
        if (forward) {
          cout << current->gas << " and " << current->distance << endl;
          gasTank += current->gas;
          gasTank -= current->distance;
          if (gasTank < 0){
            cout << "Fuel END" << endl; break;}
          current = current->next;}
        if (!forward) {
          cout << current->gas << " and " << current->prev->distance << endl;
          gasTank += current->gas;
          gasTank -= current->prev->distance;
          if (gasTank < 0){
            cout << "Fuel END" << endl; break;}
          current = current->prev;}
    } while (current != head);
    cout << "Final fuel = " << gasTank;
    if (gasTank >= 0) {
      solutionIndexes.push_back(head->index);
    }
    cout << endl;
}

void traverseAllWays(ListNode* head) {
    ListNode* current = head;

    do {
        traverseList(current, true);  // forward traversal
        traverseList(current->prev, false);  // backward traversal
        current = current->next;
    } while (current != head);
}

string ArrayChallenge(string strArr[], int arrLength) {

  vector<int> gasTankVec, gasNeededVec;
  int gasStations = stoi(strArr[0]); 
  cout << "Gaz stations: " << gasStations << endl;
  cout << "Arrlength: " << arrLength << endl;
  string dataString[arrLength];

  for (size_t i = 1; i < arrLength; i++){
      dataString[i-1] = strArr[i];
  }
  for (size_t i = 0; i < arrLength-1; i++) {
      int colon_pos = dataString[i].find(':');

      string take = dataString[i].substr(0, colon_pos);
      int num1 = stoi(take);
      gasTankVec.push_back(num1);

      take = dataString[i].substr(colon_pos + 1);
      int num2 = stoi(take);
      gasNeededVec.push_back(num2);
  } 

  cout << "Created list" << endl;

  ListNode* list1 = CreateList(gasTankVec, gasNeededVec);
  ListNode* current = list1;
  do {
      cout << "Gas: " << current->gas << " and distance next: " 
      << current->distance << " and node index = " << current->index << endl;
      current = current->next;
  } while (current != list1);

  cout << "Traversing list" << endl;
  traverseAllWays(list1);
  if (solutionIndexes.empty()) {
    return "impossible";}
  else {
    cout << "Possible answers: "; 
    for (size_t i = 0; i < solutionIndexes.size(); i++) {
      cout << solutionIndexes[i] << " ";
    }
    cout << "Min Element = "
    << *min_element(solutionIndexes.begin(), solutionIndexes.end()) << endl;
    return to_string(*min_element(solutionIndexes.begin(), solutionIndexes.end()));
  }
}

int main(void) { 
   
  // keep this function call here
  string A[] = coderbyteInternalStdinFunction(stdin);
  int arrLength = sizeof(A) / sizeof(*A);
  cout << ArrayChallenge(A, arrLength);
  return 0;
    
}

*/

#endif //LINKEDLIST_HPP 