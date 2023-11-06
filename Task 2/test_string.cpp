#include "my_string.h"

int main()
{
    {
        my_string s("Hello world");
        s.print();
        s = "Hello";

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

        s.setChar(1, 'E');
        s.print();
    }
    std::cout << "End of main" << std::endl;
    return 0;
}
