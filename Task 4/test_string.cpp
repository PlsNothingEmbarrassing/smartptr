#include <cstring>
#include <iostream>
#include "my_string.h"
// TODO implement unit tests
int main()
{
  my_string s("Hello world");
  s.print();
  s = "Hello";
  s.print();
  s = "Hello world";

  {
    my_string t = s;
    s.print(); // Reference count should be 2
    t.print(); // Reference count should be 2

    {
      my_string u = s;
      s.print(); // Reference count should be 3
      t.print(); // Reference count should be 3
      u.print(); // Reference count should be 3
    }

    s.print(); // Reference count should be 2
    t.print(); // Reference count should be 2
  }

  s.print(); // Reference count should be 1
  std::cout << s.getChar(1) << std::endl;

  s.setChar(1, 'E');
  s.print();

  std::cout << "End of main" << std::endl;
  return 0;
}
