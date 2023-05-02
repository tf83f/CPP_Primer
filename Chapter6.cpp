#include <iostream>
#include <string>
#include <vector>

using namespace std;

void exercise_6_10(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

void exercise_6_12(int& ref1, int& ref2) {
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
    /*
    Both the pointer and reference versions of the swap function work in the same way, but using references is generally considered more convenient and safer than using pointers. 
    References are easier to read and less error-prone than pointers, as they cannot be null or uninitialized. 
    Therefore, the reference version of the swap function would be easier to use and understand than the pointer version.
    */
}

int exercise_6_13() {
    /*
    Exercise 6.13: Assuming T is the name of a type, explain the difference between a function declared as void f(T) and void f(T&).
    
    void f(T) is a function that takes its argument by value, which means a copy of the argument is passed to the function. 
    The function parameter T inside the function refers to this copy, and any changes made to this copy inside the function will not affect the original argument outside the function.

    On the other hand, void f(T&) is a function that takes its argument by reference, which means the original argument is passed to the function. 
    The function parameter T& inside the function refers to the same object as the original argument outside the function, and any changes made to this parameter inside the function will also affect the original argument outside the function.
    */
   return 0;
}

int exercise_6_16() {
    /*
    The following function, although legal, is less useful than it might be. 
    Identify and correct the limitation on this function: bool is_empty(string& s) { return s.empty(); }

    The limitation of this function is that it only works with non-const lvalue references to strings. 
    If we try to pass a const lvalue reference or an rvalue reference to a string, it will not compile. 
    To make the function more useful, we should change the parameter to a reference to const string instead:
   
    bool is_empty(const string& s) { return s.empty(); }

    This version of the function can be called with a const lvalue reference, a non-const lvalue reference, or an rvalue reference to a string.
    */
   return 0;

}

bool exercise_6_17(string &i) {
    bool e = false;
    for (char& c : i) {
            if (isupper(c)) { e = true; }
            c = tolower(c);
        }
    return  e;
}

int exercise_6_20() {
    /*
    Reference parameters should be references to const when the function doesn't modify the object referred to by the parameter. 
    This can help prevent accidental modifications to the object and also allow the function to accept const objects as arguments.

    If we make a parameter a plain reference when it could be a reference to const, the function can modify the object referred to by the parameter, even if the caller intended for it to remain unchanged. 
    This can lead to unexpected behavior and bugs in the program.
    */
   return 0;
}

int exercise_6_21(int n, const int *ptr)
{
    return (n > *ptr) ? n : *ptr;
}

void exercise_6_22(int* &ptr1, int* &ptr2) {
    int* temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

int exercise_6_24() {
    /*
    The behavior of the print function is to print the contents of an integer array of size 10 to the console. The function takes a pointer to the first element of the array as an argument.

    One potential problem with the function is that it assumes that the array passed as an argument has exactly 10 elements. 
    If an array with a different number of elements is passed to the function, it could lead to undefined behavior. 
    For example, if an array with fewer than 10 elements is passed, the function will access elements outside of the array bounds, which could cause the program to crash or produce unpredictable results.

    To fix this issue, the function signature should be changed to void print(const int* ia, size_t size) to take a pointer to the first element of the array and the size of the array as arguments. 
    The function can then use the size parameter to iterate over the array instead of assuming that it has exactly 10 elements.

    void print(const int* ia, size_t size)
    {
        for (size_t i = 0; i < size; ++i) 
        {
            cout << ia[i] << endl;
        }
    }
    */
   return 0;
}

int exercise_6_27(initializer_list<int> il)
{
    int sum = 0;
    for (auto elem : il) sum += elem;
    return sum;

}

int exercise_6_31()
{
    /*
    When is it valid to return a reference? A reference to const?

    It is valid to return a reference when the object being referred to has a lifetime that extends beyond the scope of the function. 
    This can be achieved by returning a reference to a static or global object, or to an object passed to the function as a parameter by reference.

    It is also valid to return a reference to const when the object being referred to should not be modified through that reference. 
    This can be used to provide read-only access to an object, while still allowing other parts of the program to modify it through other means.
    */
   return 0;

}

int exercise_6_36() {
    /*
    Write the declaration for a function that returns a reference to an array of ten strings, without using either a trailing return, decltype, or a type alias.

    string (&get_array_of_strings())[10];
    */
   return 0;

}

int exercise_6_37() {
    /*
    Write three additional declarations for the function in the previous exercise. 
    One should use a type alias, one should use a trailing return, and the third should use decltype. Which form do you prefer and why?

    Using a type alias:

    using arrT = string[10];
    arrT& func1();

    Using a trailing return:
    auto func2() -> string(&)[10];

    Using decltype:
    string arr[10];
    decltype(arr)& func3();
    */
   return 0;
}

int exercise_6_39() {
    /*
    Explain the effect of the second declaration in each one of the following
    sets of declarations. Indicate which, if any, are illegal.
    
    (a) 
    int calc(int, int);
    int calc(const int, const int);

    The second declaration is a legal function declaration that differs from the first only in the constness of its parameters. 
    These two declarations are overloaded functions, meaning they share the same name but differ in the types, order, or number of their parameters.
    
    (b) 
    int get(); 
    double get();
    
    The second declaration is illegal because two functions can't have the same name and parameter types but differ only in their return types. 
    This is called function overloading by return type and is not allowed in C++.
    
    (c) 
    int *reset(int *); 
    double *reset(double *);
    
    The second declaration is a legal function declaration that differs from the first only in the pointer type of its return value. 
    These two declarations are overloaded functions, meaning they share the same name but differ in the types, order, or number of their parameters.

    */
   return 0;

}

int exercise_6_40() {
    /*
    Which, if either, of the following declarations are errors? Why? 
    (a) intff(inta,intb=0,intc=0);
    (b) char *init(int ht = 24, int wd, char bckgrnd);

    The second declaration is an error because it has a default argument (ht = 24) that appears before a non-default argument (wd). This is not allowed in C++. In general, all parameters with default arguments must appear after all parameters without default arguments. 
    The correct version of the declaration would be:
    char *init(int wd, char bckgrnd, int ht = 24);
    */
   return 0;
}

int exercise_6_41() {
    /*
    Which, if any, of the following calls are illegal? Why? Which, if any, are
    legal but unlikely to match the programmer’s intent? Why?
    char *init(int ht, int wd = 80, char bckgrnd = ’ ’);
    
    (a) init(); 
    is illegal because the function init() requires at least one argument for ht, but none are provided.

    (b) init(24,10); 
    is legal and matches the function init(int, int, char) where ht is 24 and wd is 10. 
    The default value of bckgrnd is used because it was not provided in the call.

    (c) init(14, ’*’);
    is legal but unlikely to match the programmer's intent. 
    It matches the function init(int, int, char) where ht is 14 and wd is the ASCII value for '*'. 
    The default value of bckgrnd is used because it was not provided in the call.
    */
   return 0;

}

int exercise_6_49() {
    /*
    What is a candidate function? What is a viable function?

    In C++, a candidate function is a function that has the same name as the called function and is visible in the current scope at the point of the call. 
    Candidate functions can be overloaded functions or non-member functions that can be converted to the required function type.

    A viable function is a candidate function that can be called with the given arguments without generating a compilation error. 
    */
   return 0;
}

int main() {
    return 0;
}
