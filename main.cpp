//#define TESTING

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <list>
#include <map>
#include <string>
using namespace std;

//#include "Headers/DesignPatterns.hpp"
//#include "Headers/ArrayExercisesLeetCode.hpp"
#include "Headers/STLVector.hpp"
//#include "Headers/STLMap.hpp"
//#include "Headers/StringExercisesLeetCode.hpp"
//#include "Headers/LinkedListExercisesLeetCode.hpp"
//#include "Headers/BinaryTreeExercisesLeetCode.hpp"
//#include "Headers/OtherLeetCode.hpp"

/*
ListNode* CreateList(){
    //list creation
    ListNode* head = new ListNode(1); //creating first head node with value 1
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

    vector <int> v1 = {1,2,3,4};
    vector <int> v2 = {6, 89, 23, 56, 123, 59, 12, 87, 34, 65, 4567, 2, 1, 54, 15};
    vector <int> v3 = {1,4,-6,-9};
    vector <int> v4 = {0,0,3,3,4,2,4,0,8};
    vector <int> v5 = {1,4,5,6,10,20,30,40,50};
    vector <int> v6 = {0};
    vector <int> v7 = {};
    vector <int> v8 = {1,7,3,6,5,6};
    vector <char> c1 = {'H','a','n','n','a','h'};
    vector <char> c2 = {'H','e','l','l','o'};
    vector<char> c3 = {'A', ' ', 'm', 'a', 'n', ',', ' ', 'a', ' ', 'p', 'l', 'a', 'n', ',', ' ', 'a', ' ', 'c', 'a', 'n', 'a', 'l', ':', ' ', 'P', 'a', 'n', 'a', 'm', 'a'};
    int a1 = 123, a2 = 3456700, a3 = -592, a4 = 2;
    string s1 = "raceacar", s2 = "hannah", s3 = "Do geese see God?", s4 = "abcdefghijklmnop", s5 = "reerac", s6 = "aaaabbccd";
    vector <string> vs1 = {"babe", "babushka", "babaika", "bababababab"};
    uint32_t abc = 00000000000000000000000000001011;
    //uint32_t abd = 00000010100101000001111010011100;
    //ListNode* list1 = CreateList();
    //ListNode* list2 = CreateList();

    
    Solution1 myObj;
    cout << myObj.search(v1, 5) << endl;
    cout << endl << "Next" << endl;
    cout << myObj.search(v5, 50) << endl;
    /*cout << endl;
    cout << myObj.isPalindrome(s3);
    cout << endl;
    myObj.reverse(a4); */

    /*
    ListNode* mergedList = myObj.middleNode(list1);
    cout << "Merged list: ";
    while (mergedList != nullptr) {
        cout << mergedList->val << " ";
        mergedList = mergedList->next;
    }
    cout << endl;

     
    ListNode* current = CreateList();
    while(current != nullptr) {
        ListNode* next = current->next;
        delete current;
        current = next;
    } */

    //ChainOfResponsibility();
    /* //Observer pattern
    ChatUser *user1 = new ChatUser("Jim");
    ChatUser *user2 = new ChatUser("Barb");
    ChatUser *user3 = new ChatUser("Hannah");
    
    ChatGroup *group1 = new ChatGroup("Gardening group");
    ChatGroup *group2 = new ChatGroup("Dog-lovers group");
    
    group1->subscribe(user1);
    group1->subscribe(user2);
    
    group2->subscribe(user2);
    group2->subscribe(user3);
    
    group1->publish("Special sale on gardening supplies!");
    group2->publish("It's national dog day everyone!");
    
    delete user1;
    delete user2;
    delete user3;
    delete group1;
    delete group2;
    */
    /* //Interpreter pattern
    NumberExpression *five = new NumberExpression("5");
    NumberExpression *seven = new NumberExpression("7");
    OperationExpression *fivePlusSeven = new OperationExpression("plus", five, seven);
    
    NumberExpression *thirteen = new NumberExpression("13");
    OperationExpression *complexOp = new OperationExpression("minus", thirteen, fivePlusSeven);
    
    std::cout << "Five plus seven is: " << fivePlusSeven->evaluate() << "\n";
    
    std::cout << "13 - (5 + 7) = " << complexOp->evaluate() << "\n";
    
    delete five;
    delete seven;
    delete fivePlusSeven;
    */
    /* //State pattern
    DeliveredState *deliveredState = new DeliveredState(nullptr);
    InTransitState *inTransitState = new InTransitState(deliveredState);
    PurchasedState *purchasedState = new PurchasedState(inTransitState);
    
    Purchase *purchase = new Purchase("Shoes", purchasedState);
    
    std::cout << purchase->getDescription() << "\n";
    
    purchase->goToNextState();
    std::cout << purchase->getDescription() << "\n";
    
    purchase->goToNextState();
    std::cout << purchase->getDescription() << "\n";
    
    delete deliveredState;
    delete inTransitState;
    delete purchasedState;
    delete purchase;
    */
    /* //Template method pattern
    GreetingCardTemplate gct;
    BirthdayCardTemplate bct;
    NewYearsCardTemplate nyct;
    
    std::cout << "Here's a regular greeting card:\n\n" << gct.generate("Bob", "Jane") << "\n";
    std::cout << "Here's a birthday card:\n\n" << bct.generate("Bob", "Jane") << "\n";
    std::cout << "Here's a new year's card:\n\n" << nyct.generate("Bob", "Jane") << "\n";
    */
    /* //Memento pattern (to undo things)
    Canvas *canvas = new Canvas;
    
    canvas->addShape("rhombus");
    canvas->addShape("triangle");
    canvas->addShape("square");
    canvas->addShape("circle");
    
    for (auto shape : canvas->getShapes()) {
        std::cout << shape << ", ";
    };
    
    std::cout << "\n";
    
    canvas->undo();
    
    for (auto shape : canvas->getShapes()) {
        std::cout << shape << ", ";
    };
    
    std::cout << "\n";
    
    canvas->addShape("rhombus");
    canvas->addShape("triangle");
    canvas->addShape("square");
    canvas->addShape("circle");
    canvas->undo();
    
    for (auto shape : canvas->getShapes()) {
        std::cout << shape << ", ";
    };
    
    std::cout << "\n";
 
    delete canvas;
    */
    /* //Singleton
    Leader::getInstance()->giveSpeech();
	Leader *elected = elected->getInstance();
	elected->giveSpeech();
    */




}
#endif