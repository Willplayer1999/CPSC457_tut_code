// Example 3: traverse a list using the std::prev() function
// source: http://www.cplusplus.com/reference/iterator/prev/
// source 2: https://www.cplusplus.com/reference/iterator/next/
// prev example
#include <iostream>     // std::cout
#include <iterator>     // std::next
#include <list>         // std::list
#include <algorithm>    // std::for_each

int main () {
  std::list<int> mylist;
  for (int i=0; i<10; i++) mylist.push_back (i*10); 
 
  // loop via iterator
  std::cout << "mylist contains:";
  // declaring iterator! can do this inside the for loop definition as well. 
  std::list<int>::iterator it;
  for (it = mylist.begin(); it != mylist.end(); it++)
    std::cout << ' ' << *it;
  std::cout << '\n';

  // prev()
  std::cout << "The last element is " << *std::prev(mylist.end()) << '\n';

  // next()
  std::cout << "mylist:";
  std::for_each (mylist.begin(), std::next(mylist.begin(),5), 
    [](int x) {std::cout << ' ' << x;} );

  std::cout << '\n';
  return 0;
}
