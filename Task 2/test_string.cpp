#include "my_string.h"

int main()
{
    {
        my_string s("Hello world");
        s.print();
        s = "Hello";

        {
            my_string t = s;
            s.print(); // Ref count 2
            t.print(); // Ref count 2

            {
                my_string u = s;
                s.print(); // Ref count 3
                t.print(); // Ref count 3
                u.print(); // Ref count 3
            }

            s.print(); // Ref count 2
            t.print(); // Refcount 2
        }

        s.print(); // Ref count 1

        s.setChar(1, 'E');
        s.print();
    }
    std::cout << "End of main" << std::endl;
    return 0;
}
