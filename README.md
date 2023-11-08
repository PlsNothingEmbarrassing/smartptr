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

 ![Output of task 1](asp-worksheet-1/Screenshots/task1_output.png)

## Task 2

