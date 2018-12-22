# ** READ ME **
This is a read me for Assignment 2.

Makefile was generated with CMake, as seen in CMakeLists.txt. The project structure is as follows:

---
##### Project structure
```
bin //contains executables
    ->stack //test program for stack
    ->postfix //exercise 1
    ->delimiters //exercise 2
build //contains Makefile and CMAKE stuff
    ->Makefile
    ->CMake generated files
config  //config files
    ->config.h  //to switch between array and linked
include //for header files
    ->Stack.h //specification for parent class
    ->StackArray.h  //specification for array stack
    ->StackLinked.h //specification for linked stack
src //for .cpp files
    ->StackArray.cpp  //implementation of array stack
    ->StackLinked.cpp //implementation of linked stack
test  //for the exercises
    ->delimiters.cpp  //implementation of exercise 2
    ->postfix.cpp //implementation of exercise 1
    ->test6.cpp //file for testing functionality of stack
CMakeLists.txt  //for generating Makefile
README.md //this document
```
---
##### Running the program
To run an executable, `cd bin`, then `./stack` to run the test of the stack, `./postfix` to run the postfix program, and `./delimiters` to run the delimiters program.

---
##### Switching between array and linked list implementations

To switch between implementations, change `LAB6_TEST1` in `config/config.h` to 0 to use the array implementation, or 1 to use the linked list implementations. Then, in terminal, starting from `proj`:
```
cd build
make
cd ../bin
./postfix
```
---
##### Postfix
The postfix program evaluates expressions entered in postfix notation and returns their value. If the stack is not empty/the user has an expression that cannot be evaluated, the program gives an error message.


---
##### Delimiters
The delimiters program tests for balanced delimiters. If there is an unmatched closing brace, unmatched opening brace, or closing braces out of order, it will return invalid. 

---
##### Stack
The stack program demonstrates the functions of the data type, including push, pop, and peek.

---
##### Credits
Code based off examples in Data Abstraction and Problem Solving with C++: Walls and Mirrors (6th edition).
