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
#include "Headers/StringExercisesLeetCode.hpp"

#ifndef TESTING
main(){

    vector <int> v1 = {-5,2,3,9};
    vector <int> v2 = {6, 89, 23, 56, 123, 59, 12, 87, 34, 65, 4567, 2, 1, 54, 15};
    vector <int> v3 = {1,4,-6,-9};
    vector <int> v4 = {0,0,3,3,4,2,4,0,8};
    vector <char> c1 = {'H','a','n','n','a','h'};
    vector <char> c2 = {'H','e','l','l','o'};
    vector<char> c3 = {'A', ' ', 'm', 'a', 'n', ',', ' ', 'a', ' ', 'p', 'l', 'a', 'n', ',', ' ', 'a', ' ', 'c', 'a', 'n', 'a', 'l', ':', ' ', 'P', 'a', 'n', 'a', 'm', 'a'};
    int a1 = 123, a2 = 3456700, a3 = -592, a4 = 2;
    string s1 = "raceacar", s2 = "hannah", s3 = "Do geese see God?", s4 = "abcdefghijklmnop", s5 = "reerac";
    vector <string> vs1 = {"babe", "babushka", "babaika", "bababababab"};

    Solution6 myObj;
    cout << myObj.longestCommonPrefix(vs1);
    cout << endl;
    /*cout << myObj.isPalindrome(s2);
    cout << endl;
    cout << myObj.isPalindrome(s3);
    cout << endl;
    myObj.reverse(a4); */


}
#endif