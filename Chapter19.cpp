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
#include <typeinfo>

using namespace std;

void exercise_19_1() {
    /*
void* operator new(size_t size) {
    std::cout << "Custom operator new called: allocating " << size << " bytes" << std::endl;
    void* ptr = malloc(size);
    if (ptr == nullptr) {
        throw std::bad_alloc(); // throw exception if allocation fails
    }
    return ptr;
}

void operator delete(void* ptr) noexcept {
    std::cout << "Custom operator delete called" << std::endl;
    free(ptr);
}

int main() {
    int* num = new int(42); // Custom operator new called
    delete num;             // Custom operator delete called
    return 0;
}
    */
}

void exercise_19_2() {
    /*
(a) A *pa = new C;
B pb = dynamic_cast< B >(pa);

In this case, the dynamic_cast from A* to B* will succeed because C is derived from B. The cast will return a valid pointer to B, so it does not fail.

(b) B *pb = new B;
C pc = dynamic_cast< C >(pb);

Here, the dynamic_cast from B* to C* will fail because B is not derived from C. The cast will return a null pointer, indicating the failure of the cast.

(c) A *pa = new D;
B pb = dynamic_cast< B >(pa);

In this case, the dynamic_cast from A* to B* will fail because D is derived from both A and B, but there is ambiguity due to the presence of multiple inheritance. The cast will return a null pointer, indicating the failure of the cast.
*/
}

void exercise_19_3() {
    /*
if (C *pc = dynamic_cast<C*>(pa)) {
    C& cRef = *pc;
    // use C's members with cRef
} else {
    A& aRef = *pa;
    // use A's members with aRef
}
    */
}

void exercise_19_9() {
    /*
std::string translateTypeName(const std::string& typeName) {
    if (typeName == "i") {
        return "int";
    } else if (typeName == "c") {
        return "char";
    } else if (typeName == "f") {
        return "float";
    } else if (typeName == "d") {
        return "double";
    } else if (typeName == "b") {
        return "bool";
    } else if (typeName == "v") {
        return "void";
    } else {
        return typeName; 
    }
}

int main() {
    std::cout << "Common type names used by the compiler:" << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    // Print the type names
    std::cout << "int: " << typeid(int).name() << " -> " << translateTypeName(typeid(int).name()) << std::endl;
    std::cout << "char: " << typeid(char).name() << " -> " << translateTypeName(typeid(char).name()) << std::endl;
    std::cout << "float: " << typeid(float).name() << " -> " << translateTypeName(typeid(float).name()) << std::endl;
    std::cout << "double: " << typeid(double).name() << " -> " << translateTypeName(typeid(double).name()) << std::endl;
    std::cout << "bool: " << typeid(bool).name() << " -> " << translateTypeName(typeid(bool).name()) << std::endl;
    std::cout << "void: " << typeid(void).name() << " -> " << translateTypeName(typeid(void).name()) << std::endl;

    return 0;
}
*/
}

void exercise_19_11() {
    /*
An ordinary data pointer is a pointer that can store the memory address of a data object. It allows you to access and manipulate the value of the data object through the pointer. It is commonly used to dynamically allocate memory for objects, create arrays, and perform pointer arithmetic.

On the other hand, a pointer to a data member is a special kind of pointer that can store the offset or address of a data member within a class or structure. It does not store the memory address of the actual data object itself, but rather the information needed to access a specific data member within an object.

The main difference between an ordinary data pointer and a pointer to a data member lies in their purpose and usage:

Accessing data: An ordinary data pointer allows direct access to the value of the data object it points to. You can dereference the pointer using the indirection operator * to read or modify the data.
Accessing data members: A pointer to a data member does not provide direct access to the value of the data member. Instead, it provides the ability to access the data member through an object using the .* or ->* operators.
Dynamic binding: Ordinary data pointers are typically used for dynamic polymorphism when dealing with inheritance hierarchies. They can be used to create base class pointers pointing to derived class objects and enable late binding based on the dynamic type of the object.
Static binding: Pointers to data members, on the other hand, are used for static polymorphism when dealing with data members of a class or structure. They allow you to access specific data members based on their names at compile-time, without relying on the dynamic type of an object.
    */
}

void exercise_19_12() {
    /*
class Screen {
public:
    int cursor;
};

int main() {
    
    int Screen::*pCursor = &Screen::cursor;

    Screen screen;
    screen.cursor = 42;

    int cursorValue = screen.*pCursor;

    std::cout << "Cursor value: " << cursorValue << std::endl;

    return 0;
}
*/
}

void exercise_19_15() {/*

The difference between an ordinary function pointer and a pointer to a member function lies in their usage, syntax, and the context in which they can be used:

Syntax: An ordinary function pointer is declared using the function's return type, followed by the pointer declarator (*), and the function's parameter types in parentheses. For example, int (*funcPtr)(int) declares a function pointer funcPtr that can point to a function returning an integer and taking an integer parameter.
On the other hand, a pointer to a member function is declared using the class type, followed by the scope resolution operator (::), the function's return type, and the pointer declarator (*). Additionally, the class type must be specified, as the member function is associated with a particular class. For example, int (MyClass::*memFuncPtr)(int) declares a member function pointer memFuncPtr that can point to a member function of MyClass returning an integer and taking an integer parameter.
Usage: An ordinary function pointer can be used to point to any standalone or static function that matches the signature (return type and parameter types) specified during its declaration. It can invoke the function directly using the function call syntax, such as (*funcPtr)(5).
On the other hand, a pointer to a member function can only point to member functions of a specific class. It is associated with the class and can access the class's members and functions through the object or pointer to the object. To invoke the member function through the pointer, you need to use the pointer-to-member function syntax, such as (object.*memFuncPtr)(5) or (ptrToObject->*memFuncPtr)(5).
Context: Ordinary function pointers are typically used for generic callbacks, function dispatching, or implementing function pointers tables.
Pointers to member functions are commonly used in object-oriented programming and scenarios where you need to dynamically select and invoke a member function based on the specific object or context. They enable runtime polymorphism and virtual function calls in C++.
*/
}


int main() {

    return 0;
}
