//#define TESTING

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <list>
#include <map>
#include <string>
using namespace std;

//#include "Headers/main.hpp"
//#include "Headers/ArrayExercisesLeetCode.hpp"
//#include "Headers/STLVector.hpp"
//#include "Headers/STLMap.hpp"
//#include "Headers/StringExercisesLeetCode.hpp"
//#include "Headers/LinkedListExercisesLeetCode.hpp"
//#include "Headers/BinaryTreeExercisesLeetCode.hpp"
#include "Headers/OtherLeetCode.hpp"

/* 
ListNode* CreateList(){
    //list creation
    ListNode* head = new ListNode(1);
    ListNode* current = head;

    for (size_t i = 2; i <= 5; i++) {
        current->next = new ListNode(i);
        current = current->next;
    }
    current->next = nullptr;
    //another list creation
    //ListNode* head = new ListNode({9, new ListNode(8, new ListNode(7, new ListNode(6, new ListNode(5))))});
    return head;
} 

TreeNode* CreateBinaryTree1(){ //just exemplar
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);
    return root;
}

TreeNode* CreateBinaryTree2(){ //good binary
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    root->right->right->right = new TreeNode(17);
    return root;
}
*/

#ifndef TESTING
main(){

    vector <int> v1 = {1,2,6,10};
    vector <int> v2 = {6, 89, 23, 56, 123, 59, 12, 87, 34, 65, 4567, 2, 1, 54, 15};
    vector <int> v3 = {1,4,-6,-9};
    vector <int> v4 = {0,0,3,3,4,2,4,0,8};
    vector <int> v5 = {1,4,5,6,10,0,0,0,0};
    vector <int> v6 = {0};
    vector <int> v7 = {};
    vector <int> v8 = {1};
    vector <char> c1 = {'H','a','n','n','a','h'};
    vector <char> c2 = {'H','e','l','l','o'};
    vector<char> c3 = {'A', ' ', 'm', 'a', 'n', ',', ' ', 'a', ' ', 'p', 'l', 'a', 'n', ',', ' ', 'a', ' ', 'c', 'a', 'n', 'a', 'l', ':', ' ', 'P', 'a', 'n', 'a', 'm', 'a'};
    int a1 = 123, a2 = 3456700, a3 = -592, a4 = 2;
    string s1 = "raceacar", s2 = "hannah", s3 = "Do geese see God?", s4 = "abcdefghijklmnop", s5 = "reerac", s6 = "race";
    vector <string> vs1 = {"babe", "babushka", "babaika", "bababababab"};
    uint32_t abc = 00000000000000000000000000001011;
    //uint32_t abd = 00000010100101000001111010011100;

    Solution6 myObj;
    myObj.isValid("(]");
    cout << endl << "End" << endl;
    myObj.isValid("([)]");
    /*cout << endl;
    cout << myObj.isPalindrome(s3);
    cout << endl;
    myObj.reverse(a4); */


    /* 
    ListNode* current = CreateList();
    while(current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    } */
}
#endif