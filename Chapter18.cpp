#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <sstream>
#include <memory>
#include <cstring>
#include <functional>
#include <cstring>
#include <sstream>
#include<tuple>
#include<bitset>
#include<array>
#include<regex>
#include<random>
#include<ctime>
#include <iomanip>

using namespace std;

void exercise_18_1() {
    /*
(a) range_error r("error"); throw r;

The type of the exception object being thrown is range_error. r is an object of type range_error initialized with the message "error". When throw r is executed, it throws an exception of type range_error and the exception handling mechanism will look for an appropriate catch block to handle this type of exception.

(b) exception *p = &r; throw *p;

The type of the exception object being thrown is exception. Here, p is a pointer of type exception* that points to the range_error object r. When throw *p is executed, it throws an exception of type exception (the base type of range_error). However, the exception handling mechanism will still try to match this exception with catch blocks that can handle exception or its derived types.

If the throw in (b) were written as throw p, it would not be a valid syntax. The throw statement expects an exception object, not a pointer. So, it would result in a compilation error.
    */
}

void exercise_18_2() {
    /*
The exception would interrupt the normal flow of the program.
Stack unwinding would occur, meaning that the program would unwind the function call stack and look for an appropriate exception handler.
Since there is no explicit exception handling mechanism (try-catch block) in the provided code, the exception would propagate to the caller of the exercise() function.
If the exception remains unhandled in the caller, it will continue to propagate up the call stack until an appropriate exception handler is found or until it reaches the top level of the program.
If the exception is not caught and handled anywhere in the program, it will result in the termination of the program.
    */
}

void exercise_18_3() {
    /*
1. Using a try-catch block:
We can wrap the code inside a try block and catch any potential exceptions that might occur. This allows us to handle the exception gracefully and perform any necessary cleanup operations.

void exercise(int* b, int* e) {
    try {
        vector<int> v(b, e);
        int* p = new int[v.size()];
        ifstream in("ints");
        // Code that may throw an exception
    } catch (const std::exception& e) {
        // Exception handling code
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        // Perform any necessary cleanup operations
        // ...
    }
}

By using a try-catch block, we catch the exception and handle it appropriately. We can print an error message or perform any necessary cleanup operations before the exception propagates further.

2. Using RAII (Resource Acquisition Is Initialization):
In this approach, we rely on the automatic resource management capabilities of C++ to handle the cleanup when an exception occurs. We can achieve this by using objects with automatic destructors or using smart pointers to manage dynamically allocated memory. 

void exercise(int* b, int* e) {
    std::unique_ptr<int[]> p;
    try {
        vector<int> v(b, e);
        p = std::make_unique<int[]>(v.size());
        ifstream in("ints");
        // Code that may throw an exception
    } catch (const std::exception& e) {
        // Exception handling code
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        // No need to explicitly clean up resources
    }
}

Here, we use std::unique_ptr to manage the dynamically allocated memory pointed to by p. If an exception occurs, the destructor of std::unique_ptr will automatically deallocate the memory, ensuring proper cleanup.

    */
}

void exercise_18_4() {
    /*
The problem with the given try block is that it catches the base class exception by value instead of by reference. This can lead to object slicing, where only the base class portion of the exception object is captured, losing the derived class-specific information.

To correct the try block, we should catch the exceptions by reference to preserve their original types and prevent object slicing. 

try {
    // use of the C++ standard library
} catch (const std::exception& e) {
    // Handle exceptions of type std::exception or its derived classes
} catch (const std::runtime_error& re) {
    // Handle exceptions of type std::runtime_error or its derived classes
} catch (const std::overflow_error& oe) {
    // Handle exceptions of type std::overflow_error or its derived classes
}
    */
}

void exercise_18_5() {
    /*
int main() {
    try {

    } catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
        std::abort();
    }


    return 0;
}
*/
}

void exercise_18_6() {
    /*
(a) class exceptionType { }; catch(exceptionType *pet) { }

To create an exception object that can be caught by this catch clause, you can throw a pointer to an object of type exceptionType.

exceptionType ex;
throw &ex;

(b) catch(...) { }

The ellipsis catch clause is used to catch any type of exception. You can throw any exception object, and it will be caught by this catch clause. 

throw std::exception();

(c) typedef int EXCPTYPE; catch(EXCPTYPE) { }

To create an exception object that can be caught by this catch clause, you can throw a value of type int.

throw 42;
*/
}

void exercise_18_9() {
    /*
// Exception class for invalid ISBNs
class InvalidISBNException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid ISBN";
    }
};

// Exception class for invalid Sales_data objects
class InvalidSalesDataException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid Sales_data";
    }
};

class Sales_data {
public:
    // Compound assignment operator with exception
    Sales_data& operator+=(const Sales_data& rhs) {
        if (bookNo != rhs.bookNo)
            throw InvalidSalesDataException(); // Throw an exception for invalid Sales_data objects

        // Perform the compound assignment
        units_sold += rhs.units_sold;
        revenue += rhs.revenue;

        return *this;
    }

private:
    std::string bookNo;
    int units_sold;
    double revenue;
};

int main() {
    try {
        Sales_data data1;
        Sales_data data2;

        // Assume some operations on data1 and data2...

        data1 += data2; // Compound assignment with exception check
    }
    catch (const InvalidSalesDataException& e) {
        // Handle the exception for invalid Sales_data
        // Print an error message or take appropriate actions
    }
    catch (const std::exception& e) {
        // Handle any other exceptions
    }

    return 0;
} 
    */
}

void exercise_18_10() {
/*
class Sales_data {
public:
    Sales_data() = default;
    Sales_data(const std::string& isbn, int units, double price)
        : bookNo(isbn), units_sold(units), revenue(units * price) {}

    Sales_data& operator+=(const Sales_data& rhs) {
        if (bookNo != rhs.bookNo)
            throw std::invalid_argument("ISBN mismatch");

        units_sold += rhs.units_sold;
        revenue += rhs.revenue;

        return *this;
    }

    string isbn() { return bookNo;}
    int unitsSold() { return units_sold;}

    std::string bookNo;
    int units_sold = 0;
    double revenue = 0.0;
};

int main() {
    
    try {
        // Version 1: Handling the exception
        Sales_data data1("123", 2, 10.0);
        Sales_data data2("456", 3, 15.0);

        data1 += data2;

        std::cout << "Combined data: ISBN = " << data1.isbn()
                  << ", Units sold = " << data1.unitsSold()
                  << ", Revenue = " << data1.revenue << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

    // Version 2: No exception handling
    Sales_data data3("123", 2, 10.0);
    Sales_data data4("456", 3, 15.0);

    data3 += data4;

    std::cout << "Combined data: ISBN = " << data3.isbn()
              << ", Units sold = " << data3.unitsSold()
              << ", Revenue = " << data3.revenue << std::endl;


    return 0;
}

*/
}

void exercise_18_11() {
    /*
It is important that the what() function of an exception class doesn't throw any exceptions itself. The reason for this is to ensure that when an exception is thrown, the system can reliably retrieve and handle the exception message without the risk of further exceptions being thrown and potentially causing program termination or undefined behavior.

When an exception is thrown, the exception handling mechanism searches for an appropriate catch block to handle the exception based on the type of the thrown exception. To provide additional information about the exception, the what() function of the exception class is often called to retrieve a description or error message associated with the exception.

If the what() function were allowed to throw exceptions itself, it would introduce the possibility of cascading exceptions, where an exception is thrown while trying to retrieve the description of another exception. This could lead to a chain of exceptions being thrown and potentially make the exception handling mechanism ineffective or unreliable.

By design, the what() function is typically implemented to be noexcept, indicating that it doesn't throw any exceptions. This ensures that when an exception is caught and the what() function is called, it can provide a reliable and consistent error message without the risk of further exceptions being thrown.
    */
}

void exercise_18_15() {
    /*
Using Declarations:

A using declaration introduces a specific symbol from a namespace into the current scope.
It allows you to use a specific symbol without having to qualify it with the namespace name.
Using declarations are typically used at the function or block level.
Example: using std::cout; allows you to use cout directly instead of std::cout.
Using Directives:

A using directive brings all the symbols from a namespace into the current scope.
It allows you to use all the symbols from a namespace without having to qualify them with the namespace name.
Using directives are typically used at the global or namespace level.
Example: using namespace std; allows you to use all symbols from the std namespace directly, such as cout, cin, etc.
The main differences can be summarized as follows:

Using declarations bring a specific symbol into scope, while using directives bring all symbols from a namespace into scope.
Using declarations are more selective and precise, as you can choose which specific symbols you want to bring into scope.
Using directives have a broader impact, potentially introducing a large number of symbols into scope, which can increase the risk of naming conflicts.
Using declarations are usually preferred over using directives to avoid polluting the global or namespace scope with too many symbols.
*/
}

void exercise_18_17() {
    /*
namespace Exercise {
    int ivar = 0;

}

int ivar = 0;

void manip() {

    using Exercise::ivar;
    using Exercise::limit;

    ++ivar;
    ++ivar;
    ++::ivar;
}

int main() {
    manip();

    std::cout << "Exercise::ivar: " << Exercise::ivar << std::endl;
    std::cout << "Global ivar: " << ivar << std::endl;

    return 0;
}
*/
}

void exercise_18_21() {
    /*
(a) class CADVehicle : public CAD, Vehicle { ... };

This declaration is attempting to define a class named CADVehicle that inherits from two base classes: CAD and Vehicle. 
However, there is a missing public keyword before the base class Vehicle.

class CADVehicle : public CAD, public Vehicle { ... };

(b) class DblList: public List, public List { ... };

This declaration is defining a class named DblList that is supposed to inherit from two base classes named List. 
However, the same base class List is listed twice, which is not allowed. 
Each base class can only appear once in the list of base classes.
 
class DblList: public List, public List2 { ... };

(c) class iostream: public istream, public ostream { ... };

This declaration is attempting to define a class named iostream that inherits from two base classes: istream and ostream. 
However, using iostream as the name for this class is incorrect because iostream is already the name of the standard library class.
 
class MyIOStream : public istream, public ostream { ... };
    */
}

void exercise_18_22() {
    /*
The default constructor of class A is executed.
The default constructor of class B is executed, which implicitly calls the default constructor of class A as it is the base class.
The default constructor of class C is executed, which implicitly calls the default constructor of class B and the default constructor of class A.
The default constructor of class X is executed.
The default constructor of class Y is executed.
The default constructor of class Z is executed, which implicitly calls the default constructors of class X and Y.
Finally, the default constructor of class MI is executed, which implicitly calls the default constructor of class C and the default constructor of class Z.

    */
}

void exercise_18_28() {
    /*
Members bar(int), foo(char), and foo(int) can be accessed without qualification.
Members ival and cval require qualification when accessing them.

    */
}

void exercise_18_29() {
    /*
(a) The order of constructors and destructors run on a Final object is as follows:

Constructors:
Class constructor
Base constructor
D1 constructor
D2 constructor
MI constructor
Final constructor
Destructors:
Final destructor
MI destructor
D2 destructor
D1 destructor
Base destructor
Class destructor
The constructors are called in the order of the inheritance hierarchy, from the base classes to the derived classes. 
The destructors are called in the reverse order, from the most derived class to the base classes.

(b) A Final object has one Base part and one Class part. 
The Base part is inherited through the MI class, which virtually inherits Base from D1 and D2. 
The Class part is inherited directly from the Class class.

*/
}

void exercise_18_30() {
    /*
class Base {
public:
    // Default constructor
    Base() {
        std::cout << "Base default constructor" << std::endl;
    }

    // Copy constructor
    Base(const Base& other) {
        std::cout << "Base copy constructor" << std::endl;
    }

    // Constructor with int parameter
    Base(int value) {
        std::cout << "Base constructor with int parameter: " << value << std::endl;
    }
};

class Derived1 : public Base {
public:
    // Default constructor
    Derived1() {
        std::cout << "Derived1 default constructor" << std::endl;
    }

    // Copy constructor
    Derived1(const Derived1& other) : Base(other) {
        std::cout << "Derived1 copy constructor" << std::endl;
    }

    // Constructor with int parameter
    Derived1(int value) : Base(value) {
        std::cout << "Derived1 constructor with int parameter: " << value << std::endl;
    }
};

class Derived2 : public Base {
public:
    // Default constructor
    Derived2() {
        std::cout << "Derived2 default constructor" << std::endl;
    }

    // Copy constructor
    Derived2(const Derived2& other) : Base(other) {
        std::cout << "Derived2 copy constructor" << std::endl;
    }

    // Constructor with int parameter
    Derived2(int value) : Base(value) {
        std::cout << "Derived2 constructor with int parameter: " << value << std::endl;
    }
};

int main() {
    Base baseDefault;            // Base default constructor
    Base baseCopy(baseDefault);  // Base copy constructor
    Base baseParam(42);          // Base constructor with int parameter

    Derived1 derived1Default;            // Derived1 default constructor, Base default constructor
    Derived1 derived1Copy(derived1Default);  // Derived1 copy constructor, Base copy constructor
    Derived1 derived1Param(123);          // Derived1 constructor with int parameter, Base constructor with int parameter

    Derived2 derived2Default;            // Derived2 default constructor, Base default constructor
    Derived2 derived2Copy(derived2Default);  // Derived2 copy constructor, Base copy constructor
    Derived2 derived2Param(456);          // Derived2 constructor with int parameter, Base constructor with int parameter

    return 0;
}

*/
}
int main() { return 0; }
