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

using namespace std;

void exercise_16_1() {
    /*In programming, instantiation refers to the process of creating an instance or object of a class, known as instantiating a class. The class serves as a blueprint or template, defining the structure and behavior of objects of that type.

When a class is instantiated, memory is allocated to store the object's data, and any necessary initialization code defined in the class's constructor is executed. The resulting instance, or object, can then be used to access the member variables and member functions defined within the class.

The process of instantiation involves two main steps:

Memory Allocation: When an object is instantiated, memory is allocated to store its data. This memory allocation typically includes space for the object's member variables, as well as any additional overhead required by the underlying system.
Initialization: After memory allocation, the object's constructor is called to initialize its member variables and perform any necessary setup. The constructor is a special member function defined in the class, and it is responsible for setting the initial state of the object. Initialization may involve assigning default values to member variables, acquiring necessary resources, or performing other initialization tasks specific to the class.
Instantiation is an essential part of object-oriented programming, as it allows multiple instances of a class to be created, each with its own distinct state and behavior. Through instantiation, objects can be created and manipulated to fulfill specific requirements and perform desired actions within a program.
*/
}

void exercise_16_2() {
    /*
template<typename T>
int compare(const T& a, const T& b) {
    if (a < b) {
        return -1;
    } else if (a > b) {
        return 1;
    }
    return 0; // a and b are equal
}

int main() {
    int x = 5;
    int y = 10;

    int result = compare(x, y);
    if (result == -1) {
        std::cout << x << " is less than " << y << std::endl;
    } else if (result == 1) {
        std::cout << x << " is greater than " << y << std::endl;
    } else {
        std::cout << x << " is equal to " << y << std::endl;
    }

    std::string s1 = "hello";
    std::string s2 = "world";

    result = compare(s1, s2);
    if (result == -1) {
        std::cout << s1 << " comes before " << s2 << std::endl;
    } else if (result == 1) {
        std::cout << s1 << " comes after " << s2 << std::endl;
    } else {
        std::cout << s1 << " is equal to " << s2 << std::endl;
    }

    return 0;
}
*/
}

void exercise_16_4() {
    /*
template <typename Iterator, typename T>
Iterator myFind(Iterator first, Iterator last, const T& value) {
    for (; first != last; ++first) {
        if (*first == value) {
            return first;
        }
    }
    return last;
}

int main() {
    std::vector<int> intVector{1, 2, 3, 4, 5};
    std::list<std::string> stringList{"apple", "banana", "orange", "grape"};

    // Find a value in a vector<int>
    int targetInt = 3;
    auto intResult = myFind(intVector.begin(), intVector.end(), targetInt);
    if (intResult != intVector.end()) {
        std::cout << "Found " << targetInt << " in the vector." << std::endl;
    } else {
        std::cout << "Could not find " << targetInt << " in the vector." << std::endl;
    }

    // Find a value in a list<string>
    std::string targetString = "orange";
    auto stringResult = myFind(stringList.begin(), stringList.end(), targetString);
    if (stringResult != stringList.end()) {
        std::cout << "Found \"" << targetString << "\" in the list." << std::endl;
    } else {
        std::cout << "Could not find \"" << targetString << "\" in the list." << std::endl;
    }

    return 0;
}
*/
}

void exercise_16_5() {
    /*
}
template <typename T, size_t N>
void print(const T (&arr)[N]) {
    for (size_t i = 0; i < N; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    print(intArray);      // Print int array
    print(doubleArray);   // Print double array
    print(charArray);     // Print char array

    return 0;
}
*/
}

void exercise_16_6() {
    /*

template <typename T, size_t N>
T* myBegin(T (&arr)[N]) {
    return arr;  // Return a pointer to the first element of the array
}

template <typename T, size_t N>
T* myEnd(T (&arr)[N]) {
    return arr + N;  // Return a pointer to one past the last element of the array
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};

    // Iterate over the array using myBegin and myEnd
    for (int* it = myBegin(intArray); it != myEnd(intArray); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

*/
}

void exercise_16_7() {
    /*
template <typename T, size_t N>
constexpr size_t arraySize(const T (&arr)[N]) {
    return N;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'a', 'b', 'c', 'd', 'e'};

    constexpr size_t intSize = arraySize(intArray);
    constexpr size_t charSize = arraySize(charArray);

    std::cout << "Size of intArray: " << intSize << std::endl;
    std::cout << "Size of charArray: " << charSize << std::endl;

    return 0;
}
*/
}

void exercise_16_9() {
    /*
In C++, function templates and class templates are features that allow you to define generic functions and classes, respectively. 
They provide a way to write code that can be reused for multiple data types without having to duplicate the implementation.

A function template is a blueprint for creating a family of functions that perform similar operations on different types of data. 
It allows you to define a generic function that can work with different data types, and the actual type is determined when the function is called. 
The function template is defined using the template keyword followed by a parameter list enclosed in angle brackets (<>). 
Inside the function template, you can use the template parameter as a placeholder for the type.

Similarly, a class template is a blueprint for creating a family of classes that can work with different types. 
It allows you to define a generic class where the type is specified as a template parameter. 
You can use the template parameter within the class to define member variables, member functions, and so on. 
Class templates are defined in a similar way to function templates but applied to classes.
    */
}

void exercise_16_10()  {
    /*
When a class template is instantiated in C++, the compiler generates a specific class based on the template definition for the provided template arguments. 
This process is called template instantiation.

During template instantiation, the compiler replaces the template parameters in the class template with the actual template arguments specified by the user. 
It then creates a concrete class based on the substituted template parameters. 
This instantiated class is essentially a specialized version of the class template, tailored to the specific types used during instantiation.
    */
}

void exercise_16_11() {
    /*
template <typename elemType>
class ListItem; // Forward declaration of ListItem

template <typename elemType>
class List {
public:
    List();
    List(const List& other);
    List& operator=(const List& other);
    ~List();

    void insert(ListItem<elemType>* ptr, elemType value);

private:
    ListItem<elemType>* front; // Pointer to the front of the list
    ListItem<elemType>* end; // Pointer to the end of the list
};

template <typename elemType>
class ListItem {
    // Define the ListItem class here
    // ...
};

template <typename elemType>
List<elemType>::List() : front(nullptr), end(nullptr) {
    // Initialize the List constructor
}

template <typename elemType>
List<elemType>::List(const List& other) : front(nullptr), end(nullptr) {
    // Implement the List copy constructor
    // ...
}

template <typename elemType>
List<elemType>& List<elemType>::operator=(const List& other) {
    // Implement the List assignment operator
    // ...
}

template <typename elemType>
List<elemType>::~List() {
    // Implement the List destructor
    // ...
}

template <typename elemType>
void List<elemType>::insert(ListItem<elemType>* ptr, elemType value) {
    // Implement the insert function
    // ...
}
*/
}

void exercise_16_15() {
    /*
template <std::size_t Height, std::size_t Width>
class Screen {
public:
    Screen() : contents(Height * Width, ' ') {}

    // Member functions
    std::size_t height() const { return Height; }
    std::size_t width() const { return Width; }

    void clear() { contents.assign(Height * Width, ' '); }
    void display() const {
        for (std::size_t i = 0; i < Height; ++i) {
            for (std::size_t j = 0; j < Width; ++j) {
                std::cout << contents[i * Width + j];
            }
            std::cout << '\n';
        }
    }

    // Modify a specific position on the screen
    void set(std::size_t row, std::size_t col, char ch) {
        contents[row * Width + col] = ch;
    }

private:
    std::string contents;
};

int main() {
    Screen<10, 20> screen;

    screen.set(3, 5, 'X');
    screen.set(7, 15, 'O');
    screen.display();

    return 0;
}

*/
}

void exercise_16_17() {
    /*
In C++, the keywords "typename" and "class" are used interchangeably when declaring type parameters in template code. 
There is no functional difference between using "typename" or "class" in most cases.

Both "typename" and "class" can be used to declare type parameters in template code, and they serve the same purpose: to indicate that the following identifier represents a type parameter.
    */
}

void exercise_16_18() {
    /*
Let's go through each function template declaration and identify any errors:

(a) template <typename T, U, typename V> void f1(T, U, V);
In this declaration, the template parameter "U" is missing its type specifier. 
It should be corrected by specifying the type for "U".

(b) template <typename T> T f2(int &T);
In this declaration, there is an issue with the template parameter and function parameter declaration. 
The template parameter "T" should not be part of the function parameter list. 
It should be corrected by separating the template parameter declaration and the function parameter declaration. 

(c) inline template <typename T> T foo(T, unsigned int*);
In this declaration, the "inline" keyword is placed incorrectly. 
The "inline" keyword should come before the template keyword. 
It should be corrected by moving the "inline" keyword before "template". 

(d) template <typename T> f4(T, T);
In this declaration, the return type is missing for the function. 
The return type should be specified.

(e) typedef char Ctype;
template <typename Ctype> Ctype f5(Ctype a);
In this declaration, there is no error. However, it's important to note that the template parameter "Ctype" in the function template declaration shadows the typedef "Ctype" outside the template. 
It means that the function template declaration creates a new template parameter that hides the typedef. 
If you want to use the typedef inside the function template, you should choose a different name for the template parameter.
    */
}

void exercise_16_19() {
    /*
template<typename Container>
void PrintContainer(const Container& container) {
    typename Container::size_type size = container.size();
    for (typename Container::size_type i = 0; i < size; ++i) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    PrintContainer(numbers);
    
    return 0;
}
    */
}

void exercise_16_20() {
    /*
template<typename Container>
void PrintContainer(const Container& container) {
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    PrintContainer(numbers);

    return 0;
}
    */
}

void exercise_16_21() {
    /*

class DebugDelete {
public:
    template <typename T>
    void operator()(T* ptr) const {
        std::cout << "Deleting pointer: " << reinterpret_cast<void*>(ptr) << std::endl;
        delete ptr;
    }
};

int main() {
    int* ptr = new int(42);
    std::unique_ptr<int, DebugDelete> uniquePtr(ptr, DebugDelete());

    // The uniquePtr will automatically call the DebugDelete operator() to delete the pointer.
    // It will also print the debug message before deleting.

    return 0;
}
    */

}

void exercise_16_22() {
    /*
class DebugDelete {
public:
    template <typename T>
    void operator()(T* ptr) const {
        std::cout << "Deleting pointer: " << reinterpret_cast<void*>(ptr) << std::endl;
        delete ptr;
    }
};

class QueryResult {
public:
    using line_no = std::vector<std::string>::size_type;

    QueryResult(std::string word, std::shared_ptr<std::set<line_no>> lines,
                std::shared_ptr<std::vector<std::string>> file)
        : word_(word), lines_(lines), file_(file) {}

    void print() const {
        std::cout << "Word: " << word_ << " occurs " << lines_->size() << " times." << std::endl;
        for (auto line : *lines_)
            std::cout << "(Line " << line + 1 << ") " << (*file_)[line] << std::endl;
    }

private:
    std::string word_;
    std::shared_ptr<std::set<line_no>> lines_;
    std::shared_ptr<std::vector<std::string>> file_;
};

class TextQuery {
public:
    using line_no = std::vector<std::string>::size_type;

    TextQuery(std::ifstream& infile) : file_(new std::vector<std::string>, DebugDelete()) {
        std::string line;
        while (std::getline(infile, line)) {
            file_->push_back(line);
            line_no n = file_->size() - 1;
            std::istringstream iss(line);
            std::string word;
            while (iss >> word) {
                auto& lines = wm_[word];
                if (!lines)
                    lines.reset(new std::set<line_no>, DebugDelete());
                lines->insert(n);
            }
        }
    }

    QueryResult query(const std::string& word) const {
        static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>, DebugDelete());
        auto iter = wm_.find(word);
        if (iter != wm_.end())
            return QueryResult(word, iter->second, file_);
        else
            return QueryResult(word, nodata, file_);
    }

private:
    std::shared_ptr<std::vector<std::string>> file_;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm_;
};

void runQueries(std::ifstream& infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "Enter a word to look for, or q to quit: ";
        std::string word;
        if (!(std::cin >> word) || word == "q")
            break;
        QueryResult qr = tq.query(word);
        qr.print();
    }
}

int main() {
    std::ifstream infile("test.txt");
    runQueries(infile);
    return 0;
}

*/
}

void exercise_16_25()
{
    /*
extern template class vector<string>;

This declaration indicates that the explicit instantiation of the vector<string> template class is declared elsewhere, but it should not be instantiated in the current translation unit.
It tells the compiler that the explicit instantiation for vector<string> will be provided externally, possibly in another translation unit, and the compiler should not generate the code for instantiation in the current translation unit.
This declaration is typically used to prevent redundant template instantiations when a template class is used in multiple translation units to reduce compile time and avoid duplicate symbol errors during linking.

template class vector<Sales_data>;

This declaration explicitly instantiates the vector<Sales_data> template class for the type Sales_data in the current translation unit.
It instructs the compiler to generate the code for all member functions and static data members of the vector<Sales_data> template class with Sales_data as the template argument.
This explicit instantiation ensures that the code for the template class is generated in the current translation unit, regardless of whether it is used or instantiated elsewhere.
It can be useful when you want to force the instantiation of a specific template with specific template arguments, even if it's not directly used in the code, to catch potential compilation errors or ensure certain code paths are generated.
    */
}

void exercise_16_26() {
    /*
No, we cannot explicitly instantiate vector<NoDefault> if NoDefault does not have a default constructor.

The reason is that the vector container requires its element type to be default-constructible. When instantiating vector<T>, the container needs to be able to create objects of type T using the default constructor. This is because vector needs to dynamically allocate and manage its elements, and it relies on default construction during element insertion and resizing operations.

If the NoDefault class does not have a default constructor, it means that objects of type NoDefault cannot be created without explicitly providing constructor arguments. Therefore, the instantiation of vector<NoDefault> would result in a compilation error because the default constructor requirement of vector cannot be satisfied.

To work around this limitation, you have a few options:

Modify the NoDefault class to provide a default constructor if it makes sense in the context of your application.
Use vector<std::unique_ptr<NoDefault>> instead, where NoDefault objects are managed via smart pointers. This way, you can have non-default constructible objects within the vector by dynamically allocating them using new.
Use vector<NoDefault*> and manually manage the memory by allocating and releasing objects of NoDefault using dynamic memory allocation (new and delete).
    */
}

void exercise_16_28() {
    /*
template<typename T>
class MySharedPtr {
public:
    explicit MySharedPtr(T* ptr = nullptr) : ptr_(ptr), ref_count_(new size_t(1)) {}

    MySharedPtr(const MySharedPtr& other) : ptr_(other.ptr_), ref_count_(other.ref_count_) {
        ++(*ref_count_);
    }

    MySharedPtr& operator=(const MySharedPtr& other) {
        if (this != &other) {
            decreaseRefCount();
            ptr_ = other.ptr_;
            ref_count_ = other.ref_count_;
            ++(*ref_count_);
        }
        return *this;
    }

    ~MySharedPtr() {
        decreaseRefCount();
    }

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

private:
    void decreaseRefCount() {
        if (--(*ref_count_) == 0) {
            delete ptr_;
            delete ref_count_;
        }
    }

    T* ptr_;
    size_t* ref_count_;
};

template<typename T>
class MyUniquePtr {
public:
    explicit MyUniquePtr(T* ptr = nullptr) : ptr_(ptr) {}

    ~MyUniquePtr() {
        delete ptr_;
    }

    T& operator*() const {
        return *ptr_;
    }

    T* operator->() const {
        return ptr_;
    }

    T* release() {
        T* releasedPtr = ptr_;
        ptr_ = nullptr;
        return releasedPtr;
    }

    void reset(T* newPtr = nullptr) {
        delete ptr_;
        ptr_ = newPtr;
    }

private:
    T* ptr_;
};
    */
}

void exercise_16_33() {
    /*
In template argument deduction, there are two type conversions allowed on function arguments:

Exact match conversion: If the type of the function argument exactly matches the type of the template parameter, no conversion is necessary. 
The argument can be used as is for template argument deduction.

Deduction conversion: Deduction conversions are performed when the type of the function argument does not exactly match the type of the template parameter but can be deduced to match through a series of standard conversions.
Deduction conversions include:

Lvalue-to-rvalue conversion
Array-to-pointer conversion
Function-to-pointer conversion
Qualification conversions (const, volatile, and const volatile)
    */
}

void exercise_16_34() {
    /*
(a) compare("hi", "world"):
In this call, the function compare is invoked with two string literals as arguments. String literals are arrays of characters, and in this case, they are treated as const char[3] and const char[6] respectively. The template function compare expects arguments of the same type.

However, since the types of the string literals are different (const char[3] and const char[6]), the call is not legal. The template argument deduction fails because the types of the arguments cannot be deduced to match the same type T. Therefore, this call is not valid.

(b) compare("bye", "dad"):
Similar to the previous call, this call also compares two string literals. The types of the string literals are const char[4] and const char[4] respectively.

In this case, the types of the arguments match (const char[4] and const char[4]), so the template argument deduction is successful. The type T can be deduced as const char[4], and the function call is legal. The type of T in this case is const char[4].

To summarize:
(a) The call compare("hi", "world") is not legal.
(b) The call compare("bye", "dad") is legal, and the type T is deduced as const char[4].
    */
}

void exercise_16_35() {
    /*
(a) calc(c, 'c'):
In this call, the function calc is invoked with arguments c and 'c'. The type of c is char, and the type of 'c' is char as well.

The template function calc takes two parameters, one of type T and the other of type int. In this call, the argument types match the parameter types. The type of T can be deduced as char, and the function call is legal. The type of T in this case is char.

(b) calc(d, f):
In this call, the function calc is invoked with arguments d and f. The type of d is double, and the type of f is float.

The template function calc takes two parameters, one of type T and the other of type int. In this call, the argument types do not match the parameter types. The type T cannot be deduced because there is no way to convert double and float to int.

Therefore, this call is not legal due to a deduction failure.

(c) fcn(c, 'c'):
In this call, the function fcn is invoked with arguments c and 'c'. The type of c is char, and the type of 'c' is char as well.

The template function fcn takes two parameters, both of type T. In this call, the argument types match the parameter types. The type of T can be deduced as char, and the function call is legal. The type of T in this case is char.

(d) fcn(d, f):
In this call, the function fcn is invoked with arguments d and f. The type of d is double, and the type of f is float.

The template function fcn takes two parameters, both of type T. In this call, the argument types do not match the parameter types. The type T cannot be deduced because there is no way to convert double and float to the same type.

Therefore, this call is not legal due to a deduction failure.

To summarize:
(a) The call calc(c, 'c') is legal, and the type T is deduced as char.
(b) The call calc(d, f) is not legal due to deduction failure.
(c) The call fcn(c, 'c') is legal, and the type T is deduced as char.
(d) The call fcn(d, f) is not legal due to deduction failure.
    */
}

void exercise_16_37() {
    /*
No, you cannot directly call the library max function passing an int and a double as arguments.

The max function from the C++ standard library is not a function template with a single template type parameter, but rather an overloaded function template with multiple template parameters. It is designed to handle different types, but the types of the arguments must match exactly.

In the case of max, it has several overloaded versions that accept different combinations of types, such as max(int, int), max(double, double), and so on. You can call the appropriate overload for the specific types you want to compare, but you cannot directly call max with an int and a double argument.

To compare an int and a double using the max function, you would need to explicitly cast the arguments to the same type, either by casting the int to a double or the double to an int. Then, you can call the corresponding overload of max with the matching argument types. 
    */
}

void exercise_16_38() {
    /*
In C++, the make_shared function template is used to create a shared pointer to a dynamically allocated object. When calling make_shared, an explicit template argument is required to specify the type of the object to be allocated.

The reason an explicit template argument is needed is because make_shared is a function template that can work with any type. The type of the object needs to be known at compile time in order for the function template to instantiate the appropriate version of the function.
    */
}

void exercise_16_39() {
    /*
template <typename T>
int compare(const T& v1, const T& v2)
{
    if (v1 < v2) return -1;
    if (v2 < v1) return 1;
    return 0;
}

int main()
{
    const char* str1 = "hello";
    const char* str2 = "world";
    
    int result = compare<const char*>(str1, str2);
    std::cout << "Comparison result: " << result << std::endl;
    
    return 0;
}
    */
}

void exercise_16_40() {
    /*
The provided function is legal, assuming that the operations used in the decltype expression are well-defined for the argument type(s).

The function fcn3 is a function template that takes two iterators (beg and end) representing a range and returns a copy of the element pointed to by the beg iterator.

The return type of the function is deduced using the decltype specifier in the trailing return type. 
It uses the expression *beg + 0 to determine the return type.

The decltype(*beg + 0) expression evaluates the addition of the value pointed to by beg with 0. 
The resulting type of this addition is used as the return type of the function. The decltype specifier decltype(*beg + 0) deduces the type of the expression without actually performing the addition at compile-time.

However, there are some restrictions on the argument type(s) that can be passed to fcn3. Since the function dereferences the iterator using the *beg expression, the iterator type must support the dereference operator (operator*). 
Additionally, the addition operation (+) must be defined for the type of the element pointed to by the iterator and the type int (for the 0 literal).
    */
}

void exercise_16_41()
{
/*
template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> typename std::common_type<T1, T2>::type {
    return a + b;
}

int main() {
    int a = 1000000000;
    long long b = 2000000000;
    
    auto result = sum(a, b);
    
    std::cout << "Result: " << result << std::endl;

    return 0;
}
*/
}

void exercise_16_42()
{
    /*
(a) g(i):
In this call, the argument is an lvalue i of type int. The template parameter T is deduced as int& due to the forwarding reference (T&&). The type of val will also be int&.

(b) g(ci):
In this call, the argument is an lvalue ci of type const int. The template parameter T is deduced as const int& due to the forwarding reference (T&&). The type of val will also be const int&.

(c) g(i * ci):
In this call, the argument is an rvalue resulting from the expression i * ci, which is an int. The template parameter T is deduced as int (non-reference) due to the forwarding reference (T&&). The type of val will be int&&.

To summarize:
(a) T is deduced as int&, val is of type int&.
(b) T is deduced as const int&, val is of type const int&.
(c) T is deduced as int, val is of type int&&.
    */
}

void exercise_16_43()
{
    /*
The template parameter T of g would be deduced as int& because the expression i = ci is an assignment operation that assigns the value of ci to i. 
The result of the assignment is an lvalue referring to i, and since the function parameter is a forwarding reference (T&&), T will be deduced as an lvalue reference to int (int&).

So, the template parameter T in this case would be int&.
    */
}

void exercise_16_46() 
{
    /*
Let's break down the loop step by step:

Initialization: size_t i = 0
This initializes a variable i of type size_t (an unsigned integer type) to 0. This variable will be used as an index to iterate over the elements of the StrVec container.
Condition: i != size()
The loop will continue executing as long as the value of i is not equal to the size of the StrVec container. The size() function is likely a member function of the StrVec class that returns the current number of elements in the container.
Iteration: ++i
After each iteration of the loop, the value of i is incremented by 1. This ensures that the loop progresses through each element of the container.
Body: alloc.construct(dest++, std::move(*elem++))
This line of code performs two important operations:
a. *elem++: Dereferences the pointer elem and retrieves the value it points to. The ++ operator increments the pointer to point to the next element in memory.
b. std::move(...): This casts the value retrieved from *elem++ into an rvalue reference, enabling potential move semantics. Move semantics allow for the efficient transfer of resources from one object to another, minimizing unnecessary copying.
c. alloc.construct(dest++, ...) invokes the construct member function of the allocator object (alloc). This function is likely responsible for constructing an object at the memory location specified by the dest pointer. The dest++ operation increments the pointer to indicate the next memory location where the next object should be constructed.
In summary, this loop iterates over the elements of the StrVec container and constructs new objects at the specified destination (dest) using the values stored in the elem pointer. The std::move operation is used to enable efficient resource transfer, and the alloc.construct function handles the actual construction of objects.
    */
}

void exercise_16_47() {
    /*
template <typename T>
void flip(T& a, T& b) {
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

int main() {
  std::string str1 = "Hello";
  std::string str2 = "World";

  flip(str1, str2);

  std::cout << "After flip: str1 = " << str1 << ", str2 = " << str2 << std::endl;

  return 0;
}
    */
}

void exercise_16_49() {
    /*
g(42);
The first g function template is called with the argument 42, which is an integer literal. 
Since there is no exact match for g(T), the compiler deduces T as int and instantiates void g(int). 
Therefore, void g(int) is called.

g(p);
The second g function template is called with the argument p, which is a pointer to an integer. 
In this case, there is an exact match for g(T*), so the compiler instantiates void g(int*). 
Therefore, void g(int*) is called.

g(ci);
The third g function template is called with the argument ci, which is a constant integer. 
Again, there is no exact match for g(T), but since the argument is const-qualified, the compiler deduces T as const int and instantiates void g(const int). 
Therefore, void g(const int) is called.

g(p2);
The fourth g function template is called with the argument p2, which is a pointer to a constant integer. 
Once more, there is an exact match for g(T*), so the compiler instantiates void g(const int*). 
Therefore, void g(const int*) is called.

f(42);
The first f function template is called with the argument 42. 
There is no exact match for f(T), but since the argument is not const-qualified, the compiler deduces T as int and instantiates void f(int). 
Therefore, void f(int) is called.

f(p);
The second f function template is called with the argument p, which is a pointer to an integer. 
There is an exact match for f(const T*), so the compiler instantiates void f(int*). 
Therefore, void f(int*) is called.

f(ci);
The third f function template is called with the argument ci, which is a constant integer. 
There is no exact match for f(T), but since the argument is const-qualified, the compiler deduces T as const int and instantiates void f(const int). 
Therefore, void f(const int) is called.

f(p2);
The fourth f function template is called with the argument p2, which is a pointer to a constant integer. 
There is an exact match for f(const T*), so the compiler instantiates void f(const int*). 
Therefore, void f(const int*) is called.

In summary, the function templates g and f are overloaded with different parameter types, including pointers and const-qualified arguments. 
The compiler deduces the appropriate template instantiation based on the argument types, favoring exact matches when available and making const adjustments when necessary.
*/
}

void exercise_16_50() {
    /*
template <typename T>
void f(T) {
    std::cout << "Calling f(T)" << std::endl;
}

template <typename T>
void f(const T*) {
    std::cout << "Calling f(const T*)" << std::endl;
}

template <typename T>
void g(T) {
    std::cout << "Calling g(T)" << std::endl;
}

template <typename T>
void g(T*) {
    std::cout << "Calling g(T*)" << std::endl;
}

int main() {
    int i = 42, *p = &i;
    const int ci = 0, *p2 = &ci;

    g(42);   // Calling g(T)
    g(p);    // Calling g(T*)
    g(ci);   // Calling g(T)
    g(p2);   // Calling g(T*)

    f(42);   // Calling f(T)
    f(p);    // Calling f(T*)
    f(ci);   // Calling f(T)
    f(p2);   // Calling f(const T*)

    return 0;
}

*/
}

void exercise_16_53() {
    /*
template<typename T>
void print(T& arg)
{
    std::cout << arg << std::endl;
}

template<typename T, typename... Args>
void print(T& arg, Args&... args)
{
    std::cout << arg << ", ";
    print(args...);
}

int main()
{
    int i = 42;
    double d = 3.14;
    char c = 'A';
    std::string s = "Hello, world!";
    bool b = true;

    print(i);
    print(d, c);
    print(s, b, i, d, c);

    return 0;
}
*/
}

void exercise_16_54() {
    /*
template<typename... Args>
void errorMsg(const std::string& message, Args&&... args)
{
    std::ostringstream oss;
    oss << "Error: " << message << " ";
    ((oss << args << " "),...);
    std::cout << oss.str() << std::endl;
}

int main()
{
    int errorCode = 404;
    double pi = 3.14159;
    std::string filePath = "example.txt";

    errorMsg("File not found.");
    errorMsg("Invalid argument:", 42);
    errorMsg("Error in file:", filePath, "at line:", 10);
    errorMsg("Value of pi:", pi, "is not accurate.");

    return 0;
}
*/
}

void exercise_16_58() {
    /*
class StrVec {
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    void emplace_back(const std::string& s);
    // ... other member functions ...

private:
    std::string* elements;
    std::string* first_free;
    std::string* cap;
    std::allocator<std::string> alloc;

    void reallocate();
};

void StrVec::emplace_back(const std::string& s) {
    if (first_free == cap)
        reallocate();
    alloc.construct(first_free++, s);
}

void StrVec::reallocate() {
    auto new_capacity = size() ? 2 * size() : 1;
    auto new_elements = alloc.allocate(new_capacity);
    auto dest = new_elements;
    auto elem = elements;

    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));

    free();

    elements = new_elements;
    first_free = dest;
    cap = elements + new_capacity;
}

template<typename T>
class Vec {
public:
    Vec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    void emplace_back(const T& elem);
    // ... other member functions ...

private:
    T* elements;
    T* first_free;
    T* cap;
    std::allocator<T> alloc;

    void reallocate();
};

template<typename T>
void Vec<T>::emplace_back(const T& elem) {
    if (first_free == cap)
        reallocate();
    alloc.construct(first_free++, elem);
}

template<typename T>
void Vec<T>::reallocate() {
    auto new_capacity = size() ? 2 * size() : 1;
    auto new_elements = alloc.allocate(new_capacity);
    auto dest = new_elements;
    auto elem = elements;

    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, std::move(*elem++));

    free();

    elements = new_elements;
    first_free = dest;
    cap = elements + new_capacity;
}
*/
}

void exercise_16_61() {
    /*
template<typename T, typename... Args>
std::shared_ptr<T> make_shared(Args&&... args) {
    // Allocate memory for the control block and the object
    auto* mem = new char[sizeof(std::shared_ptr<T>) + sizeof(T)];

    // Create a control block at the beginning of the allocated memory
    auto* control_block = new (mem) std::shared_ptr<T>();

    // Create the object at the offset after the control block
    auto* object = new (mem + sizeof(std::shared_ptr<T>)) T(std::forward<Args>(args)...);

    // Initialize the control block with the object and the deleter
    control_block->reset(object, [](T* ptr) {
        ptr->~T();  // Destruct the object
        delete[] reinterpret_cast<char*>(ptr);  // Deallocate memory
    });

    // Return the shared_ptr initialized with the control block
    return std::shared_ptr<T>(control_block);
}

struct MyClass {
    int value;
    MyClass(int val) : value(val) {}
};

int main() {
    std::shared_ptr<MyClass> ptr = make_shared<MyClass>(42);

    std::cout << ptr->value << std::endl;  // Output: 42

    return 0;
}
*/
}

void exercise_16_62()
{
    /*
class Sales_data {
public:
    std::string bookNo;
    unsigned unitsSold;
    double revenue;

    Sales_data(const std::string& bookNo, unsigned unitsSold, double revenue)
        : bookNo(bookNo), unitsSold(unitsSold), revenue(revenue) {}

    bool operator==(const Sales_data& other) const {
        return bookNo == other.bookNo &&
               unitsSold == other.unitsSold &&
               revenue == other.revenue;
    }
};

struct Sales_dataHash {
    std::size_t operator()(const Sales_data& sd) const {
        std::size_t h1 = std::hash<std::string>{}(sd.bookNo);
        std::size_t h2 = std::hash<unsigned>{}(sd.unitsSold);
        std::size_t h3 = std::hash<double>{}(sd.revenue);

        return h1 ^ h2 ^ h3;
    }
};

int main() {
    std::unordered_multiset<Sales_data, Sales_dataHash> salesSet;


    salesSet.insert(Sales_data("ISBN123", 3, 29.99));
    salesSet.insert(Sales_data("ISBN456", 2, 14.99));
    salesSet.insert(Sales_data("ISBN789", 5, 9.99));


    for (const auto& sale : salesSet) {
        std::cout << "Book: " << sale.bookNo
                  << ", Units Sold: " << sale.unitsSold
                  << ", Revenue: " << sale.revenue << std::endl;
    }

    return 0;
}
*/
}

void exercise_16_63() {
    /*
template<typename T>
int countOccurrences(const std::vector<T>& vec, const T& value) {
    return std::count(vec.begin(), vec.end(), value);
}

int main() {
    std::vector<double> doubleVec = { 1.1, 2.2, 3.3, 2.2, 4.4, 2.2 };
    std::vector<int> intVec = { 1, 2, 3, 2, 4, 2 };
    std::vector<std::string> stringVec = { "apple", "banana", "apple", "orange", "apple" };

    double doubleValue = 2.2;
    int intValue = 2;
    std::string stringValue = "apple";

    // Count occurrences of values in the vectors
    int doubleCount = countOccurrences(doubleVec, doubleValue);
    int intCount = countOccurrences(intVec, intValue);
    int stringCount = countOccurrences(stringVec, stringValue);

    // Print the results
    std::cout << "Occurrences of " << doubleValue << " in doubleVec: " << doubleCount << std::endl;
    std::cout << "Occurrences of " << intValue << " in intVec: " << intCount << std::endl;
    std::cout << "Occurrences of \"" << stringValue << "\" in stringVec: " << stringCount << std::endl;

    return 0;
}
*/
}

void exercise_16_64() {
    /*
template<typename T>
int countOccurrences(const std::vector<T>& vec, const T& value) {
    return std::count(vec.begin(), vec.end(), value);
}
template<>
int countOccurrences(const std::vector<const char*>& vec, const char* const& value) {
    int count = 0;
    for (const char* str : vec) {
        if (std::strcmp(str, value) == 0)
            count++;
    }
    return count;
}

int main() {
    std::vector<const char*> charPtrVec = { "apple", "banana", "apple", "orange", "apple" };

    const char* const charPtrValue = "apple";

    // Count occurrences of const char* in the vector
    int charPtrCount = countOccurrences(charPtrVec, charPtrValue);

    // Print the result
    std::cout << "Occurrences of \"" << charPtrValue << "\" in charPtrVec: " << charPtrCount << std::endl;

    return 0;
}
*/
}

void exercise_16_65() {
    /*
template <typename T>
std::string debug_rep(const T& t) {
    std::cout << "Generic version" << std::endl;
    return std::string(t);
}

template <>
std::string debug_rep(const char* const& s) {
    return debug_rep(std::string(s));
}

// Specialization of debug_rep for char*
template <>
std::string debug_rep(char* const& s) {
    return debug_rep(std::string(s));
}



int main() {
    const char* const cstr = "Hello";
    char* str = const_cast<char*>(cstr);

    std::cout << debug_rep(cstr) << std::endl;
    std::cout << debug_rep(str) << std::endl;

    return 0;
}
*/
}

int main() { return 0; }
