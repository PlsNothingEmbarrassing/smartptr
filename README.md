# ASP worksheet 1



## Task 1
 - In task 1 there is a basic implementation of the custom string class "my_string" which can perform basic operations such as getChar and setChar and print.
 - The my_string class contains a default constructor which initialises the my_string object.
 - Also includes an additional constructor which takes a traditional c style string char array as an arguement and creates a "my_string" object with the data from the passed string.
 - It also contains a copy constructor which creates a shallow copy of an existing my_string object by copying the pointer to the object data.
 - There is also the overloaded assignment operator which allows for assignment of one my_string object to another. It is similar to the copy constructor but first checks for self-assignment before copying over the object data.
 - In this task the deconstructor is left blank as specified in the assignment brief but is usually used to clean up resources when an the object goes out of scope.
 ###The member functions are:
 - getChar which retrieves a character from the my_string character data and takes an integer as arguement.
 - setChar which sets a character to a specified value and takes a char as argument.
 - print which prints the character data that has been assigned to the object.

 ![Output of task 1](https://gitlab.uwe.ac.uk/j5-hutton/asp-worksheet-1/-/blob/main/Screenshots/task1_output.png)

## Task 2
- Task 2 extends upon the implementation of task 1 by implementing reference counting into the my_string class. This is relatively straightforward by adding an reference count data member and incrementing and decrementing when an object is copied or assigned.
- The default constructor remains very similar to task 1 but also initialising a nullptr for the refcount.
- The other constructor is also almost identical but with the addition of creating an integer to store the reference count.
- In the copy constructor we again make a shallow copy of the existing object. As this increases the number of pointers pointing to the existing objects address we increment the reference count.
- The overloaded assignment operator is similar to task 1 also with the check for self assertion but extends on the previous implementation by incrementing the reference count. 
- In this implementation the deconstructor is responsible for freeing the memory used by an object when it goes out of scope which is when the reference count reaches 0. If the reference count is still > 1 when an object is destroyed then the reference count is decremented.
### Member Functions:
- The member function are identical to the previous task bar the print function which now also prints the object reference count.

![Ouput of task 2](https://gitlab.uwe.ac.uk/j5-hutton/asp-worksheet-1/-/blob/main/Screenshots/task_2_output.png)
## Task 3
- For task 3 we were supposed to implement a test case where the reference count was 0. I used google tests to test when the count is 0 by using the default constructor to create an object instance without any data and asserting that the count was 0.
![Output of task 3](https://gitlab.uwe.ac.uk/j5-hutton/asp-worksheet-1/-/blob/main/Screenshots/task3_ouput.png)

## Task 4
- For task 4 we were essentially asked to make a smart pointer class which could be used as a template to implement automatic reference counting for a managed object.
- To begin with I created a reference count class to contain the count and perform incrementing and decrementing operations.
- I then created a template smart_ptr class which would be used to manage an objects memory and reference count. The code for the ptr class is quite similar to the my_string object code from previous implementations but with some key differences such as using the member functions of the reference count object to increment and decrement the count.
- I use a virtual deconstuctor in the smart_ptr class for when the reference count reaches 0 the managed object and reference count object data are deleted so there are no memory leaks.
- Another key difference in this task is how the my_string class accesses its object data as the pointer is now the smart_ptr class so member access is a template get() function to return the pointer to the object data.

![Output of task 4](https://gitlab.uwe.ac.uk/j5-hutton/asp-worksheet-1/-/blob/main/Screenshots/task4_ouput.png)



