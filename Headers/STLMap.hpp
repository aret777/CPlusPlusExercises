#ifndef STLMAP_HPP
#define STLMAP_HPP


#include <iostream>
#include <functional>
#include <list>
#include <map>
#include <string>
using namespace std;

// Exercise 1. Inserting elements into a std::map container efficiently and according to conditions
/*Starting with C++17, the try_emplace function appeared in the STL, which allows you to create elements 
only on the condition that we perform an insertion.
In this example, we are implementing an application that creates an associative array based on a list of billionaires. 
It displays country names and links to the richest person living in that country, 
as well as a counter indicating the number of billionaires.
*/
struct billionaire {
    string name;
    double dollars;
    string country;
};

void map1 (){
    list<billionaire> billionaires {
        {"Bill Gates", 86.0, "USA"},
        {"Warren Buffet", 75.6, "USA"},
        {"Jeff Bezos", 72.8, "USA"},
        {"Amancio Ortega", 71.3, "Spain"},
        {"Mark Zuckerberg", 56.0, "USA"},
        {"Carlos Slim", 54.5, "Mexico"},
        {"Bernard Arnault", 41.5, "France"},
        {"Liliane Bettencourt", 39.5, "France"},
        {"Wang Jianlin", 31.3, "China"},
        {"Li Ka-shing", 31.2, "Hong Kong"}
};


/*
Now let's define an associative array. In it, the string containing the country corresponds to the pair. 
The pair includes an immutable copy of the first billionaire from each country on our list. 
These people are the richest people in their country. The other variable in the pair is a 
counter that will increase for each successive billionaire in the country.
*/
map<string, pair<const billionaire, size_t>> m;
/*
Now let's go through the list and try for each country to replace the corresponding value with a new pair.
The pair includes a reference to the billionaire we are currently viewing and a counter value of 1

for (const auto &b : billionaires){
    auto [countiter, success] = m.emplace(b.country, make_pair(b, 1));
}
if (!success) {
    countiter->second.second += 1; //counting billionaires in country that was found by auto [countiter, success]
}

for (const auto &[key, value] : m) {
    const auto &[b, count] = value;
    cout << b.country << " : " << count
    << " billionaires. Richest is "
    << b.name << " with " << b.dollars
    << " B$\n";
}
*/
}

// Exercise 2. Exploring new hint semantics for inserting elements using the std::map::insert method
/*In this example, we'll insert multiple elements into a std::map container and use insertion hints 
to reduce the number of lookups. If the hint is correct, then the amortized insertion time is O(1).
Otherwise, its O(log(n)).
*/
void map2(){

    map <string, size_t> m {{"b", 1}, {"c", 2}, {"d", 3}};
    auto insert_it (end(m)); //Hint for inserting the following elements to be in correct alphabet order

    for (const auto &s : {"z", "y", "x", "w"}) {
        insert_it = m.insert(insert_it, {s, 1});
    }


    map<string, size_t>::iterator it = m.begin();
    while (it != m.end())
    {
        cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
        ++it;
    }

}

// Exercise 3. Efficiently changing std::map element keys
/*In this example, we'll implement a small application that organizes a list of drivers in a 
fictional race into a std::map structure. As the drivers pass each other during the race, 
the keys to show their current position need to be changed. We will do it in C++17 style.
*/

template <typename M>
void print(const M &m){
    cout << "Race placement: \n";
    for (const auto &[placement, driver] : m){
        cout << placement << ": " << driver << '\n';}
}

void map3(){
    map<int,string> race_placement {
        {1, "Mario"}, {2, "Luigi"}, {3, "Bowser"},
        {4, "Peach"}, {5, "Yoshi"}, {6, "Koopa"},
        {7, "Toad"}, {8, "Donkey Kong Jr."}
    };
    print(race_placement);
/*
Imagine Bowser goes to last place, but Donkey Kong goes to 3rd place.
In this case, you first need to extract the specified elements from the associative array, 
since this is the only way to manipulate their keys. The extract function is a new feature in C++17.

/*
{
    auto a (race_placement.extract(3));
    auto b (race_placement.extract(8));
    swap(a.key(), b.key());
    race_placement.insert(move(a));
    race_placement.insert(move(b));
}
print(race_placement);
*/
}


#endif // STLMAP_HPP