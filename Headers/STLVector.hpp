#ifndef STLVECTOR_HPP
#define STLVECTOR_HPP


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <cassert>
using namespace std;

//Exercise 1 In this example, we will fill a std::vector object with integers, and then discard specific elements from it using C++ 17.
void vector1() {

vector<int> v {1, 2, 4, 2, 5, 2, 6, 2, 4, 8};
const auto new_end (remove(begin(v), end(v), 2)); //deleting many 2
//but it still have the same size!
for (auto i : v) { //checking if all works
    cout << i << ", ";
}
cout << '\n';


v.erase(new_end, end(v)); //deleting positions starting from new_end end (last 6,2,4,8)

for (auto i : v) { //checking if all works
    cout << i << ", ";
}
cout << '\n';
/*
Now let's remove the whole class of elements, not specific values. 
To do this, we first define a predicate function that takes a number 
as a parameter and returns true if the passed number is odd.
*/
const auto odd([] (int i) { //predicat function
    return i%2 != 0;
});
/*
We use the remove_if function, passing it values using the predicate function. 
Instead of deleting elements in two steps, we now do it in one:
*/
v.erase(remove_if(begin(v), end(v), odd), end(v));
v.shrink_to_fit(); //deleting nulls

for (auto i : v) { //checking if all works
    cout << i << ", ";
}
cout << '\n';

}

//Exercise 2. Removing elements from an unsorted std::vector in O(1) time
template <typename T>
void quick_remove_at(vector<T> &v, size_t delpos){
/*
First, we simply take the value of the last element of the vector and 
write it in place of the element to be removed. Secondly, we discard the last element.
That's it, just two steps. We'll add a little security check to this code. 
If the index value is clearly out of range of the vector, we won't do anything.
Otherwise, the code will fail for an empty vector.
*/
if (delpos < v.size()){
    v[delpos] = move(v.back()); //writing over delpos the last element of vector
    v.pop_back(); //destroys last element
}
}

template <typename T>
void quick_remove_at(vector<T> &v, typename vector<T>::iterator it){ 
//Instead of taking a numeric index, it takes an iterator for a vector

if (it != end(v)){
    *it = move(v.back());
    v.pop_back();
}


}

void vector2(){
//Removing elements from an unsorted std::vector in O(1) time

vector<int> v {123, 456, 789, 100, 200};
quick_remove_at(v,2); //deleting 2nd position (789)

for (auto i : v) { //checking if all works
    cout << i << ", ";
}
cout << '\n';
//Now let's remove one more element. This will be the value 123. Suppose we don't know its index.
quick_remove_at(v, find(begin(v), end(v), 123));
for (int i : v){
    cout << i << ", ";
} 
cout << '\n';

}

//Exercise 3. Accessing std::vector instances in a fast or safe way
void vector3(){
/*
If the vector contains 100 elements, and our code is trying to access the element at index 123, then this is obviously bad.
An experienced programmer can add checks before directly accessing a vector element by index.
Such checks do not increase the readability of the code, and many developers do not know that the std::vector container is already
supports such built-in checks!
*/
const size_t container_size {1000};
vector<int> v (container_size, 123); //1000 znachenij of 123
/*
cout << "Out of range element value: " //not to be used, cause it gives garbage value to 1010 value
<< v[container_size + 10] << '\n';

cout << "Out of range element value: " //better to use cause it makes an error
<< v.at(container_size + 10) << '\n';
}
*/
try {
    cout << "Out of range element value: "
    << v.at(container_size + 10) << '\n';
} catch (const std::out_of_range &e) {
    cout << "Ooops, out of range access detected: "
    << e.what() << '\n';
}
}

//Exercise 4. Sorting class std::vector. In this example, we'll fill 
//a std::vector container with random words, sort them, and then insert additional words based on the sort.
void insert_sorted(vector<string> &v, const string &word){
    const auto insert_pos(lower_bound(begin(v), end(v), word));
    v.insert(insert_pos, word);
}

void vector4(){

vector<string> v {"some", "random", "words", "without", "order", "aaa", "yyy"};
assert(false == is_sorted(begin(v), end(v))); //pass cause v is not sorted
sort(begin(v), end(v));
assert(true == is_sorted(begin(v), end(v))); //pass cause v is now sorted
insert_sorted(v, "foobar");
insert_sorted(v, "zzz");

for (const auto &w : v) {
cout << w << " ";
}
cout << '\n';

}



#endif // STLVECTOR_HPP