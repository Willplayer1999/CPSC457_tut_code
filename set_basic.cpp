// Example 1: basic example of using std::set
// Source: https://thispointer.com/stdset-tutorial-part-1-set-usage-details-with-default-sorting-criteria/
// -------
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
 
   // Only 3 elements will be inserted
    std::cout<<"Set Size = "<<setOfNumbers.size()<<std::endl;

    // Iterate through all the elements in a set and display the value.
    for (std::set<std::string>::iterator it=setOfNumbers.begin(); it!=setOfNumbers.end(); ++it)
        std::cout << ' ' << *it;
    std::cout<<"\n";
    return 0;

    // BEFORE running the code, what do you expect to be printed?
    // AFTER running code, what is missing? why? 
}
