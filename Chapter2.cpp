#include <iostream>

using namespace std;

int exercise_2_5() {
    /*
    Determine the type of each of the following literals. Explain the differ-
    ences among the literals in each of the four examples:
    (a) ’a’,L’a’,"a",L"a"
    (b) 10,10u,10L,10uL,012,0xC (c) 3.14,3.14f,3.14L
    (d) 10,10u,10.,10e-2

    (a)

    'a' is a character literal of type char.
    L'a' is a wide character literal of type wchar_t.
    "a" is a string literal of type const char[].
    L"a" is a wide string literal of type const wchar_t[].
    The difference between 'a' and L'a' is that the former is a character literal in the default character set of the implementation, while the latter is a character literal in the wide character set. The difference between "a" and L"a" is similar, in that the former is a string literal in the default character set, while the latter is a string literal in the wide character set.

    (b)

    10 is an integer literal of type int.
    10u is an integer literal of type unsigned int.
    10L is an integer literal of type long int.
    10uL is an integer literal of type unsigned long int.
    012 is an integer literal in octal notation of value 10 and type int.
    0xC is an integer literal in hexadecimal notation of value 12 and type int.
    The difference between these literals is the way in which they are represented. The suffix u indicates that the literal is of unsigned type, the suffix L indicates that the literal is of long type, and the combination of u and L indicates that the literal is of unsigned long type. The prefix 0 indicates an integer literal in octal notation, while the prefix 0x indicates an integer literal in hexadecimal notation.

    (c)

    3.14 is a floating-point literal of type double.
    3.14f is a floating-point literal of type float.
    3.14L is a floating-point literal of type long double.
    The difference between these literals is their precision. A literal with the suffix f is of type float, which typically has less precision than a double literal. A literal with the suffix L is of type long double, which typically has greater precision than a double literal.

    (d)

    10 is an integer literal of type int.
    10u is an integer literal of type unsigned int.
    is a floating-point literal of type double.
    10e-2 is a floating-point literal of type double.
    The difference between 10 and 10u is the same as in (b). The literal 10. is a floating-point literal that represents the same value as 10 but is of type double. The literal 10e-2 represents the value 0.1 in scientific notation and is also of type double.
    */

    return 0;
}

int exercise_2_6() {
    /*
    What, if any, are the differences between the following definitions: 
    int month = 9, day = 7;
    int month = 09, day = 07;

    Yes, there is a difference between the two definitions.

    The first definition, int month = 9, day = 7;, initializes two variables month and day to the integer values 9 and 7, respectively. This is because the values are represented in decimal (base 10) notation.

    The second definition, int month = 09, day = 07;, initializes two variables month and day to the integer values 011 and 07, respectively. This is because the values are represented in octal (base 8) notation. In C++, if an integer literal starts with a leading zero, it is treated as an octal integer literal. In octal notation, the digits range from 0 to 7, so 09 is not a valid octal number. Instead, the number 9 is interpreted as a decimal number, and the leading zero is ignored.

    Therefore, the first definition initializes month to 9 and day to 7, while the second definition initializes month to 11 (since 011 in octal is 9 in decimal) and day to 7
    */
   return 0;
}

int exercise_2_9() {
    /*
    Explain the following definitions. For those that are illegal, explain what’s wrong and how to correct it.
    (a) std::cin >> int input_value; 
    (b) int i = { 3.14 }; 
    (c) double salary = wage = 9999.99; 
    (d) int i = 3.14;

    (a) std::cin >> int input_value; is not a valid definition because you cannot declare a variable inside an input statement. 
    Instead, you should declare the variable before using it in the input statement. For example:
    int input_value;
    std::cin >> input_value;   

    (b) int i = { 3.14 }; is not a valid definition because you cannot initialize an int variable with a floating-point value without casting. 
    If you want to initialize an int variable with a value of 3, you should write: 
    int i = 3;

    (c) double salary = wage = 9999.99; is not a valid definition because you cannot declare and initialize multiple variables in the same statement without explicitly defining the type of the second variable (wage in this case). 
    To correct this, you should either define and initialize wage before using it to initialize salary, or explicitly define the type of wage:
    double wage = 9999.99;
    double salary = wage;
    // or
    double salary, wage = 9999.99;
    salary = wage;

    (d) int i = 3.14; is not a valid definition because you cannot initialize an int variable with a floating-point value without casting. 
    If you want to initialize an int variable with a value of 3, you should write:
    int i = 3;
    */
   return 0;
}

int exercise_2_10() {
    /*
    What are the initial values, if any, of each of the following variables? 
    std::string global_str;
    int global_int;
    int main() {
        int local_int;
        std::string local_str;
    }
    For global variables (i.e., those defined outside of any function), the initial value is set to a default value, which for most built-in types is 0 or an empty string. Specifically:

    The initial value of global_str (which is a std::string) is an empty string (i.e., "").
    The initial value of global_int (which is an int) is 0.
    For local variables (i.e., those defined inside a function), the initial value is undefined, meaning that the value could be anything. Specifically:

    The initial value of local_int (which is an int) is undefined.
    The initial value of local_str (which is a std::string) is an empty string (i.e., "") because it is default-initialized.
    */
   return 0;
}

int exercice_2_18() {
    /*
    Write code to change the value of a pointer. 

    int* ptr = nullptr;  // initialize the pointer to a null value
    int value = 10;
    ptr = &value;  // change the value of the pointer to the address of 'value'

    Write code to change the value to which the pointer points.

    int* ptr = nullptr;
    int value = 10;
    ptr = &value;
    *ptr = 20;  // change the value of 'value' through the pointer
    */
   return 0;
}

int exercice_2_19() {
    /*
    Explain the key differences between pointers and references.
    
    Syntax: Pointers are declared using the * operator, while references are declared using the & operator. For example, a pointer to an int would be declared as int* ptr, while a reference to an int would be declared as int& ref.
    Nullability: Pointers can be null (i.e., they can have a value of nullptr), while references cannot. If you declare a reference variable without initializing it to refer to an existing object, you'll get a compile-time error.
    Reassignment: Pointers can be reassigned to point to different objects, while references cannot. Once a reference is initialized to refer to an object, it cannot be made to refer to a different object. This makes references safer to use than pointers, since it eliminates the possibility of accidentally dereferencing a null pointer or a pointer to an object that has been deleted.
    Indirection: Pointers are used to indirectly access the object they point to by dereferencing them with the * operator. References, on the other hand, are automatically dereferenced when used, so you don't need to use the * operator. This makes references more convenient to use than pointers in many cases.
    Address: Pointers can store the address of any object, while references can only refer to objects that are already in memory. This means that you can use pointers to point to dynamically allocated memory, but you cannot use references to refer to memory that is allocated dynamically.

    */
   return 0;

}

int exercice_2_21() {
    /*
    Explain each of the following definitions. Indicate whether any are il- legal and, if so, why.
    int i = 0;
    (a) double*dp=&i; 

    This definition is illegal. 
    It creates a pointer to a double and initializes it with the address of an int variable. 
    This is not allowed because the types are different and the sizes of int and double may differ, so the pointer would not point to the correct memory location for the type of data it is supposed to be pointing to.

    int*dp=&i;

    (b) int*ip=i; 

    This definition is also illegal. 
    It creates an integer pointer ip and initializes it with the value of i, which is an integer. 
    This is not allowed because ip should be initialized with the address of i, not its value.
    
    int*ip=&i; 

    (c) int*p=&i;

    This definition is legal. 

    */
   return 0;

}

int exercice_2_25() {
    /*
    Determine the types and values of each of the following variables.

    (a) int *ip, i, &r = i; 

    The type of ip is int*, which is a pointer to an integer. 
    The type of i is int, which is an integer. The type of r is int&, which is a reference to an integer. 
    All three variables have the initial value of uninitialized.
    
    (b) int i, *ip = 0; 

    The type of i is int, which is an integer. 
    The type of ip is int*, which is a pointer to an integer. 
    The initial value of i is uninitialized, and the initial value of ip is a null pointer.

    (c) int *ip, ip2;

    The type of ip is int*, which is a pointer to an integer. 
    The type of ip2 is int, which is an integer. 
    The initial value of ip is uninitialized, and the initial value of ip2 is also uninitialized.
    */
   return 0;

}

int exercice_2_26() {
    /*
    Which of the following are legal? For those that are illegal, explain why.
    (a) const int buf; 
    
    const int buf; is illegal because a const object must be initialized when it is defined, otherwise its value is undefined. 
    Therefore, this declaration should be changed to const int buf = 0; or another appropriate value.
    
    (b) int cnt = 0; 
    
    int cnt = 0; is legal. It initializes an integer variable named cnt to the value 0.

    (c) const int sz = cnt; 

    const int sz = cnt; is legal, but it initializes sz with the value of cnt at the time of initialization. 
    If cnt changes later, sz will not reflect that change.
    
    (d) ++cnt; ++sz;

    ++cnt; ++sz; is illegal because sz is a const object and cannot be modified after it has been initialized. 
    Therefore, attempting to modify sz will result in a compiler error.
    */
   return 0;

}

int exercice_2_27() {
    /*
    Which of the following initializations are legal? Explain why.
    
    (a) int i = -1, &r = 0; 
    This initialization is illegal because the variable r is a reference to a non-const integer and is being initialized to a constant integer value of 0.

    (b) int *const p2 = &i2;
    This initialization is legal. It declares a constant pointer p2 that points to an integer i2.

    (c) const int i = -1, &r = 0; 
    This initialization is illegal. 
    The variable r is a reference to a non-const integer and is being initialized to a constant integer value of 0.
    
    (d) const int *const p3 = &i2; 
    This initialization is legal. 
    It declares a constant pointer p3 that points to a constant integer i2.

    (e) const int *p1 = &i2; 
    This initialization is legal. It declares a pointer p1 that points to a constant integer i2.
    
    (f) const int &const r2;
    This initialization is illegal because it declares a constant reference r2 but does not initialize it with any value.
    
    (g) const int i2 = i, &r = i;
    This initialization is legal. 
    It declares a constant integer i2 and a constant reference r that refers to i. Both are initialized with the value of i. 
    However, note that the use of const in this case is redundant, since references are always constant and cannot be re-assigned to refer to a different object.

    */
   return 0;

}

int exercice_2_28() {
    /*
    Explain the following definitions. Identify any that are illegal.
    
    (a) int i, *const cp; 
    This defines an integer i and a constant pointer cp to an integer. This is a legal definition.
    
    (b) int *p1, *const p2; 
    This defines two pointers to an integer: p1 and a constant pointer p2. 
    This is also a legal definition.

    (c) const int ic, &r = ic; 
    This defines a constant integer ic and a reference r that is initialized to refer to ic. 
    However, this is an illegal definition because ic is uninitialized and cannot be const.

    (d) const int *const p3; 
    This defines a constant pointer p3 to a constant integer, but the pointer is uninitialized. 
    This is an illegal definition because it doesn't provide a valid address for p3.
    
    (e) const int *p;
    This defines a pointer p to a constant integer. This is a legal definition.

    */
   return 0;

}

int exercice_2_30() {
    /*
    For each of the following declarations indicate whether the object being declared has top-level or low-level const.
    
    const int v2 = 0; declares a constant integer v2. This has top-level const.

    int v1 = v2; declares an integer v1 that is initialized with the value of v2. This has no const qualifiers.

    int *p1 = &v1, &r1 = v1; declares a pointer p1 that points to an integer v1 and a reference r1 that refers to v1. These have no const qualifiers.

    const int *p2 = &v2; declares a pointer p2 that points to a constant integer v2. This has low-level const.

    const int *const p3 = &i; declares a constant pointer p3 that points to a constant integer i. This has both top-level and low-level const.

    const int &r2 = v2; declares a constant reference r2 that refers to v2. This has low-level const.

    */
   return 0;

}

int exercice_2_31() {
    /*
    Given the declarations in the previous exercise determine whether the following assignments are legal. Explain how the top-level or low-level const applies in each case.

    r1 = v2; is legal. This assigns the value of the constant integer v2 to the non-constant integer r1. 
    This is allowed because r1 is not declared as a constant.

    p1 = p2; is illegal. This tries to assign a pointer to a constant integer (p2) to a non-constant pointer to an integer (p1). 
    This is not allowed because it would allow modifying the value of the constant integer through the non-constant pointer.

    p2 = p1; is legal. This assigns a non-constant pointer to an integer (p1) to a pointer to a constant integer (p2). 
    This is allowed because the non-constant pointer can be used to access a constant integer.

    p1 = p3; is illegal. This tries to assign a constant pointer to a constant integer (p3) to a non-constant pointer to an integer (p1). 
    This is not allowed because it would allow modifying the value of the constant integer through the non-constant pointer.

    p2 = p3; is legal. This assigns a constant pointer to a constant integer (p3) to a pointer to a constant integer (p2). 
    This is allowed because both pointers have the same level of constness, and therefore the pointer to the constant integer can be used to access the constant integer.
    */
   return 0;
}

int exercice_2_32() {
    /*
    Is the following code legal or not? If not, how might you make it legal? int null = 0, *p = null;

    The code is not legal. null is an integer with value 0, but it is not a valid memory address that can be used to initialize a pointer. 
    Therefore, trying to initialize a pointer p with null results in undefined behavior.

    To make this code legal, we should initialize p with a null pointer instead. 
    int *p = nullptr;
    
    */
   return 0;
}

int exercice_2_35() {
    /*
    Determine the types deduced in each of the following definitions. Once you’ve figured out the types, write a program to see whether you were correct.
    const int i = 42;: i is a const int.
    auto j = i;: j is an int.
    const auto &k = i;: k is a const int&.
    auto *p = &i;: p is a pointer to a const int.
    const auto j2 = i, &k2 = i;: j2 is a const int and k2 is a const int&.
    
    */
   return 0;

}

int exercice_2_38() {
    /*
    Describe the differences in type deduction between decltype and auto. 
    Give an example of an expression where auto and decltype will deduce the same type and an example where they will deduce differing types.
    
    decltype and auto are both used for type deduction in C++, but they differ in how they deduce the types.

    decltype deduces the type of an expression and yields the exact type of that expression, including top-level const and references. 
    It's often used to declare a variable with the same type as an existing variable or expression. 
    For example:

    int x = 42;
    decltype(x) y = x; // y is an int, same as x

    auto, on the other hand, deduces the type of a variable from its initializer. 
    It doesn't include top-level const or references in the deduced type. 
    For example:

    int x = 42;
    auto y = x; // y is an int, same as x

    An expression where auto and decltype will deduce the same type is when the initializer is a simple expression with no top-level const or reference qualifiers. 
    For example:

    int x = 42;
    const int y = x;
    auto z = x + y; // z is an int, same as x+y
    decltype(x + y) w = x + y; // w is an int, same as z

    An example where auto and decltype will deduce differing types is when the initializer is a reference. 
    For example:

    int x = 42;
    int& y = x;
    auto z = y; // z is an int, not a reference
    decltype(y) w = y; // w is an int&, a reference to x

    In this case, auto deduces the type of y as int, ignoring the fact that it's a reference. decltype(y), however, yields the type of y, which is an int&, a reference to x.

    */
   return 0;

}

int main() {
    return 0;
}
