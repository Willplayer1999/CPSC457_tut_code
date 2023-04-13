// Example 2: Find using set and iterators. 
// Source: https://thispointer.com/stdset-tutorial-part-1-set-usage-details-with-default-sorting-criteria/
// Note -- 
// This website gives a very good run through of set. STRONGLY RECOMMEND: go through this website's tutorial. They cover removing an element from set and verifying set insertion. 
// ---------
// The purpose of this code is that we use the find() function from the set library. 
// Why not use <algorithm> std::find instead?
// Because the internal data structure of set is a balance binary search tree. 
// The set.find() knows this, hence it takes less time to find than the algorithm class find!
#include <iostream>
#include <set>
#include <string>

int main()
{
    std::set<std::string> setOfNumbers;

    // Lets insert four elements
    setOfNumbers.insert("first");
    setOfNumbers.insert("second");
    setOfNumbers.insert("third");
    setOfNumbers.insert("first");

    // Search for element in set using find member function
    std::set<std::string>::iterator it = setOfNumbers.find("second");
    if(it != setOfNumbers.end())
        std::cout<<"'first'  found"<<std::endl;
    else
        std::cout<<"'first' not found"<<std::endl;
    // Search for element in set using find member function
    it = setOfNumbers.find("fourth");
    if(it != setOfNumbers.end())
        std::cout<<"'fourth'  found"<<std::endl;
    else
        std::cout<<"'fourth' not found"<<std::endl;
    return 0;
}
