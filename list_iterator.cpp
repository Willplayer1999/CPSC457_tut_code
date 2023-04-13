// Example 1: constructors of lists and loop through a list via an iterator
// Source: https://www.cplusplus.com/reference/list/list/list/
// --------------------
// constructing lists
#include <iostream>
#include <list>

using namespace std;

int main ()
{
  // create a list from scratch (or from another list)
  // constructors used in the same order as described above:
  list<int> first;                                // empty list of ints
  list<int> second (4,100);                       // four ints with value 100
  list<int> third (second.begin(),second.end());  // iterating through second - list of iterator values of second
  list<int> fourth (third);                       // a copy of third

  // create a list from an array 
  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  cout << "The contents of fifth are: ";

  // Loop through a list using iterators 
  // creating an iterator object:
  // list<int>::iterator it = fifth.begin();
  for (list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
    cout << *it << ' ';

  // EXERCISE: use iterator to loop through lists second and third and print result to screen. 

  std::cout << '\n';

  return 0;
}
