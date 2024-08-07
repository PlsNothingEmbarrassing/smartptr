# Creating Smart Pointer Class and testing using gtest framework



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

 ![Output of task 1](Screenshots/task1_output.png)

## Task 2
- Task 2 extends upon the implementation of task 1 by implementing reference counting into the my_string class. This is relatively straightforward by adding an reference count data member and incrementing and decrementing when an object is copied or assigned.
- The default constructor remains very similar to task 1 but also initialising a nullptr for the refcount.
- The other constructor is also almost identical but with the addition of creating an integer to store the reference count.
- In the copy constructor we again make a shallow copy of the existing object. As this increases the number of pointers pointing to the existing objects address we increment the reference count.
- The overloaded assignment operator is similar to task 1 also with the check for self assertion but extends on the previous implementation by incrementing the reference count. 
- In this implementation the deconstructor is responsible for freeing the memory used by an object when it goes out of scope which is when the reference count reaches 0. If the reference count is still > 1 when an object is destroyed then the reference count is decremented.
### Member Functions:
- The member function are identical to the previous task bar the print function which now also prints the object reference count.

![Ouput of task 2](Screenshots/task_2_output.png)

## Task 3
- For task 3 we were supposed to implement a test case where the reference count was 0. I used google tests to test when the count is 0 by using the default constructor to create an object instance without any data and asserting that the count was 0.

![Output of task 3](Screenshots/task3_ouput.png)

## Task 4
- For task 4 we were essentially asked to make a smart pointer class which could be used as a template to implement automatic reference counting for a managed object.
### Reference Count class
- To begin with I created a reference count class to contain the count and perform incrementing and decrementing operations.
### Smart_ptr class
- I then created a template smart_ptr class which would be used to manage an objects memory and reference count. The code for the ptr class is quite similar to the my_string object code from previous implementations but with some key differences such as using the member functions of the reference count object to increment and decrement the count.
- I use a virtual deconstuctor in the smart_ptr class for when the reference count reaches 0 the managed object and reference count pointer data are deleted so there are no memory leaks. As the objects are "newed" and their memory is dynamically allocated, they must be explicitly deleted as dynamically allocated objects have a lifetime that extends beyond the scope that they were created in. The pointers to the managed object and the managed refcount are set to nullptr so that they are not left dangling. This is when a pointer is left pointing to deallocated memory and so dereferencing the pointer can lead to unpredictable results as the memory might have been used for a different purpose.
- I used a get() function to access the raw pointer to the managed object which was mainly used to perform operations such as getChar and setChar. The way that the managed object data can be accessed is through the member access operator overload (->) which is a convenient way which allows us to use the smart pointer similarly to how we would use a raw pointer. This is not really used however as the pointer is initialised within the my_string constructor so it is already a member and therefore we can use the "." operator instead. I left the overloaded member access operator in as I can still create smart_ptrs for other object types where I may be working with the pointer instead of the object instance so it may be handy in the future.
### my_string class
- The my_string class in this task is very similar to task 1 as the reference counting is now handled by the smart_ptr class. The difference is that the my_string object's pointer is now initialised with an instance of the smart_ptr class which manages the objects memory and reference count.
- Another difference is that the get/setChar functions access the object data through the get() method.

### Alternative smart_ptr implementation
- I also included a different implementation which removes the additional ReferenceCount class and handles the reference count value directly within the smart_ptr class

### Testing
For testing I used the google test testing framework to test my smart_ptr and my_string class.

#### Constructor Test 
- The purpose of this test is to check if the constructor of my_string is working properly. A my_string object is created with the value of "Hello World" and checks that the first letter is "H" which indicates that the data is being assigned to the object correctly. It also checks the reference count is 1 indicating there is only the single instance of the object.

#### Default Constructor Test 
- The purpose of this test is to check that the default constructor is working correctly. It initialises an instance of my_string without a value and checks that the getChar function returns a null character as it should in this scenario. It also checks that the reference count is 0 as the pointer should be initialised as a nullptr and that the print functions returns an empty string.

#### Constructor with string 
- This test makes sure that the constructor can take a C-string as an argument and ensures that the object is created correctly similarly to the first test. It also checks that the count is as expected and the print function works.

#### Copy Constructor Test 
- This test checks that the copy constructor works correctly. It creates a my_string instance and creates a copy using the copy constructor. It then verifies that the data was copied correctly by checking the character data and the reference count.

#### Assignment operator test
- This test checks that the assignment operator is working correctly. It creates 2 my_string instances and assigns the value of the first to the second and then verifies that the data is correct by checking the first character and the reference count.

#### setChar Test
- This test checks the setChar method. A my_string instance is created and we use the setChar method for index 1 to change the character value. We then check that the correct character is returned for that index using the getChar method.

#### getChar Test
- Although this function has been used in the other tests I thought it would be more thourough if I tested it on its own also. A my_string instance is assigned a value and then we retrieve the first character of the string and check that it is what we assigned it.

#### Print Test 
- To test that the print function is working correctly an empty instance of my_string is created, we then redirect stdout to a stringstream to capture the output. The print function is now called and the output is captured and stored in a new string. stdout is reset so no more outputs are captured. We then check to make sure that the print function returned an empty string as there it was not created with any data.

#### Chain operations 
- This test is similar to ones used in the previous tasks by using block scope to check the reference count as objects come in and out of scope. It creates a my_string object and then creates copies within nested scopes and verifies that the reference count behaves correctly.

As you can see in the screenshot of the output below, the task 4 implementation passed the written tests.

![Output of task 4](Screenshots/task4_ouput.png)



