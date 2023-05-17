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

using namespace std;

void exercise_14_1() {
    /*
    Overloaded operators and built-in operators share some similarities, but they differ in several ways.

Similarities:

Both overloaded and built-in operators can perform operations on operands.
Both operators have a specific syntax that must be followed to use them.
Differences:

Overloaded operators can be defined to work with user-defined types, whereas built-in operators only work with built-in types.
Overloaded operators can have user-defined semantics, meaning the behavior of an overloaded operator can be completely different from its built-in counterpart. Built-in operators have a fixed behavior that cannot be changed.
Overloaded operators can have any combination of parameters and return types, whereas built-in operators have a fixed set of parameters and return types.
Overloaded operators must be defined explicitly, whereas built-in operators are predefined by the language.
In summary, overloaded operators provide greater flexibility and control over their behavior than built-in operators, but they also require more work to define and use.

    */
}

void exercise_14_3() {

    /*
(a) The built-in == operator for string literals is applied.
(b) The overloaded == operator for strings is applied.
(c) The overloaded == operator for vectors is applied.
(d) The built-in == operator for string literals is applied to compare "svec1[0]" and "stone", and then the overloaded == operator for strings is applied to compare the result of that expression with svec2[0].

    */
}

void exercise_14_4() {
    /*
(a) and (b): Typically, operators that modify the left-hand operand, such as % and %=, should be implemented as member functions of the class of the left-hand operand. In this case, we would expect the operators to be members of the class that defines the % and %= operations.

(c) and (d): Typically, operators that change the state of the object should be implemented as member functions of the class. In this case, we would expect the ++ and -> operators to be members of the class that defines the corresponding operations.

(e): The << operator should be implemented as a non-member function that takes the left-hand operand as its first parameter and the right-hand operand as its second parameter. This is because the left-hand operand is not an instance of the class that defines the << operator.

(f) and (g): Operators that do not change the state of the object and do not require access to the private members of the class, such as && and ==, should be implemented as non-member functions.

(h): The () operator should be implemented as a member function of the class, since it is used to call the function associated with the object.
    */

}

void exercise_14_7() {
    /*
class String {
public:
    String() : String("") { }
    String(const char*);
    String(const String&);
    String& operator=(const String&);
    ~String();

    void print() const;

    friend std::ostream& operator<<(std::ostream&, const String&);

private:
    std::pair<char*, char*> alloc_n_copy(const char*, const char*);
    void free();

    char *elements;
    char *end;
    std::allocator<char> alloc;
};

String::String(const char* s)
{
    auto slen = std::strlen(s);
    auto data = alloc_n_copy(s, s + slen);
    elements = data.first;
    end = data.second;
}

String::String(const String& rhs)
{
    auto data = alloc_n_copy(rhs.elements, rhs.end);
    elements = data.first;
    end = data.second;
}

String& String::operator=(const String& rhs)
{
    auto data = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = data.first;
    end = data.second;
    return *this;
}

String::~String()
{
    free();
}

void String::print() const
{
    for (auto p = elements; p != end; ++p)
        std::cout << *p;
    std::cout << std::endl;
}

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e)
{
    auto data = alloc.allocate(e - b);
    return {data, std::uninitialized_copy(b, e, data)};
}

void String::free()
{
    if (elements) {
        for (auto p = end; p != elements;) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, end - elements);
    }
}

std::ostream& operator<<(std::ostream& os, const String& s)
{
    for (auto p = s.elements; p != s.end; ++p)
        os << *p;
    return os;
}

int main()
{
    String s1("hello");
    std::cout << s1 << std::endl;

    String s2 = s1;
    std::cout << s2 << std::endl;

    String s3;
    s3 = s2;
    std::cout << s3 << std::endl;

    return 0;
}

*/
}

void exercise_14_10() {
    /*
    The Sales_data input operator expects input in the format of bookNo, units_sold, and price separated by spaces.

(a) In the first input, "0-201-99999-9 10 24.95", the bookNo is "0-201-99999-9", the units_sold is 10, and the price is 24.95. The input operator will read these values and assign them to the corresponding members of the Sales_data object.

(b) In the second input, "10 24.95 0-210-99999-9", the input is in the wrong order. The input operator expects bookNo as the first input, units_sold as the second input, and price as the third input. Since the input is not in the correct order, the input operator will fail to read any values and set the input stream state to fail, indicating an input error.

    */
}

void exercise_14_11() {
    /*
The input operator should check whether the input is valid before modifying the state of the object. In the given input operator, there is no check for whether the input is valid or not. If the input is invalid (e.g. if price is not entered), the value of price would be undefined, which would result in an incorrect revenue calculation.

If the operator is given the data in the previous exercise, it would read the values of bookNo and units_sold correctly, but the value of price would be set to 10, resulting in an incorrect revenue calculation.
    */
}

void exercise_14_12() {
    /*
istream& operator>>(istream& is, Person& p) {
    string name, address;
    cout << "Enter name: ";
    if (getline(is, name)) {
        cout << "Enter address: ";
        if (getline(is, address)) {
            p = Person(name, address);
        }
        else {
            is.setstate(ios::failbit);
        }
    }
    else {
        is.setstate(ios::failbit);
    }
    return is;
}

    */
}

void exercise_14_13() {
    /*
Addition (+): The addition operator could be used to combine two Sales_data objects, accumulating their sales quantities and updating other relevant members such as revenue and average price.
Subtraction (-): The subtraction operator could be utilized to calculate the difference between two Sales_data objects, representing a change in sales or quantities.
Multiplication (*): The multiplication operator could be employed to scale the Sales_data object by a scalar value, effectively increasing or decreasing the sales quantities and revenue accordingly.
Division (/): The division operator could be useful for dividing the sales quantities and revenue of a Sales_data object by a scalar value, possibly to determine an average or normalize the data.
Compound Assignment Operators (+=, -=, *=, /=): These operators could be implemented to combine arithmetic operations with assignment, allowing for concise and efficient updates to the Sales_data object.

    */
}

void exercise_14_14() {
    /*
By defining operator+ in terms of operator+=, we can leverage the existing implementation of operator+= for addition. This approach promotes code reuse since we don't need to duplicate the addition logic in both operators. Instead, we can use operator+= to perform the addition and then return a new object, thereby achieving the desired result of operator+.

Additionally, defining operator+ to call operator+= can be more efficient from a performance standpoint. When we use operator+=, we can modify the state of the left-hand operand directly without creating a temporary object. This can lead to improved performance and reduced memory overhead since we don't need to allocate memory for a new object.

On the other hand, if we were to define operator+= in terms of operator+, we would need to create a temporary object to perform the addition. This involves memory allocation and additional copying or moving of data, which can be less efficient, especially when dealing with large objects.

Therefore, by defining operator+ to call operator+=, we achieve code reuse, optimize memory usage, and potentially improve performance by avoiding unnecessary object creation and copying.
    */
}

void exercise_14_31() {
    /*
The StrBlobPtr class in the exercise does not define the copy constructor, assignment operator, or destructor explicitly because the default versions provided by the compiler are sufficient and appropriate for this class.

The default copy constructor and assignment operator generated by the compiler will perform member-wise copy and assignment respectively. In the case of StrBlobPtr, the only data members are a weak_ptr and a size_t variable, which can be safely copied and assigned using the default implementations.

The default destructor will also work correctly for StrBlobPtr. The weak_ptr member does not require explicit cleanup or deallocation because it is a shared pointer, and its destruction will be managed automatically by the reference counting mechanism. The size_t member does not require any special destruction.

Therefore, in this case, it is unnecessary to provide explicit definitions for the copy constructor, assignment operator, or destructor. The default implementations are sufficient and will correctly handle the copying, assignment, and destruction of StrBlobPtr objects.
    */
}

void exercise_14_33() {
    /*
The overloaded function-call operator in C++ can take any number of operands, including zero operands. 
However, it is important to note that the overloaded function-call operator is invoked using the syntax of a function call, so the number and types of operands must match the defined function-call operator signature.
*/
}

void exercise_14_35() {
    /*
template<typename T>
class IfThenElse {
public:
    T operator()(bool condition, const T& ifValue, const T& elseValue) const {
        return condition ? ifValue : elseValue;
    }
};

int main() {
    IfThenElse<std::string> ifThenElse;

    std::string result = ifThenElse(true, "Condition is true", "Condition is false");
    std::cout << result << std::endl;  // Output: "Condition is true"

    result = ifThenElse(false, "Condition is true", "Condition is false");
    std::cout << result << std::endl;  // Output: "Condition is false"

    return 0;
}
*/
}

void exercise_14_36() {
    /*
template<typename T>
class IfThenElse {
public:
    T operator()(bool condition, const T& ifValue, const T& elseValue) const {
        return condition ? ifValue : elseValue;
    }
};

int main() {
    IfThenElse<std::string> ifThenElse;
    std::vector<std::string> lines;

    std::string line;
    while (std::getline(std::cin, line)) {
        lines.push_back(ifThenElse(true, line, ""));
    }

    // Print the lines stored in the vector
    for (const auto& line : lines) {
        std::cout << line << std::endl;
    }

    return 0;
}
    */
}

void exercise_14_37() {
    /*
template<typename T>
class ValueComparator {
public:
    ValueComparator(const T& value) : value_(value) {}

    bool operator()(const T& other) const {
        return other == value_;
    }

private:
    T value_;
};

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5, 3, 6, 7, 3, 8};

    int oldValue = 3;
    int newValue = 9;

    ValueComparator<int> comparator(oldValue);
    std::replace_if(numbers.begin(), numbers.end(), comparator, newValue);

    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    return 0;
}
*/
}

void exercise_14_38() {
    /*
class IsShorter {
public:
    bool operator()(const std::string& str1, const std::string& str2) const {
        return str1.size() < str2.size();
    }
};

class Print {
public:
    void operator()(const std::string& str) const {
        std::cout << str << " ";
    }
};

void biggies(std::vector<std::string>& words, std::vector<std::string>::size_type sz) {
    // Sort the words in ascending order of size
    std::sort(words.begin(), words.end(), IsShorter());

    // Find the first word with a size >= sz
    auto iter = std::find_if(words.begin(), words.end(), [sz](const std::string& str) {
        return str.size() >= sz;
    });

    // Print the remaining words
    std::for_each(iter, words.end(), Print());

    std::cout << std::endl;
}

int main() {
    std::vector<std::string> words = {"apple", "banana", "cat", "dog", "elephant"};

    std::cout << "Words with size >= 4: ";
    biggies(words, 4);

    return 0;
}

*/
}

void exercise_14_44() {
    /*
int add(int i, int j) { return i + j; }

auto mod = [](int i, int j) { return i % j; };

struct divide {
int operator()(int denominator, int divisor) { return denominator / divisor; } 
};

function<int(int, int)> f1 = add;
function<int(int, int)> f2 = divide();
function<int(int, int)> f3 = [](int i, int j) { return i * j; };

map<string, function<int(int, int)>> binops = {
{"+", add},
{"-", std::minus<int>()},
{"/", divide()},
{"*", [](int i, int j) { return i * j; }},
{"%", mod} }; 

int main() {
cout << f1(4,2) << endl; 
cout << f2(4,2) << endl; 
cout << f3(4,2) << endl; 
cout << binops["+"](10,5) << endl;
cout << binops["-"](10, 5) << endl;
cout << binops["/"](10, 5) << endl;
cout << binops["*"](10, 5) << endl; 
cout << binops["%"](10, 5) << endl;

return 0;
}

*/
}

void exercise_14_45() {
    /*
class Sales_data {
public:
    // Constructors and other member functions

    // Conversion operator to string
    operator std::string() const {
        return bookNo;
    }

    // Conversion operator to double
    operator double() const {
        return revenue;
    }

private:
    std::string bookNo;
    double revenue;
};
    */
}

void exercise_14_46() {
    /*
Defining conversion operators for Sales_data to convert to string and double can be a good idea in certain cases, depending on the context and requirements of your program. Let's consider the following aspects:

Clarity and Intention: Conversion operators can improve code readability and express the intention of converting a Sales_data object to a string or double explicitly. This can make the code more self-explanatory and easier to understand.
Convenience and Usability: Having conversion operators allows for more convenient usage of Sales_data objects in scenarios where implicit conversions are desired. It can simplify code by allowing direct assignment or initialization of string or double variables with Sales_data objects, without the need for explicit conversion functions or constructors.
On the other hand, whether these conversion operators should be explicit or implicit depends on the specific requirements and potential risks involved:

Implicit Conversion: If you choose to define the conversion operators as implicit, they will allow automatic conversions to string or double whenever the context requires it. This can be convenient but also carries some risks, as implicit conversions may lead to unintended and potentially confusing behavior. For example, if you have a function that takes a double argument, and you pass a Sales_data object by mistake, the compiler will silently perform the conversion, which may not be what you intended.
Explicit Conversion: If you make the conversion operators explicit, they will only be invoked explicitly through explicit type casting. This ensures that the conversion is intentional and reduces the risk of accidental conversions. Users will have to explicitly cast Sales_data objects to string or double using static_cast or explicit type conversion syntax.
Choosing between explicit and implicit conversion operators depends on the trade-offs you want to make in terms of convenience versus safety and potential risks. If you expect that implicit conversions may lead to confusion or unintended behavior in your program, it's generally safer to make the conversion operators explicit. This way, you can ensure that conversions are explicitly requested by the programmer and minimize the chances of unexpected conversions.

In summary, defining conversion operators for Sales_data to string and double can be a good idea to improve code clarity and convenience, but whether they should be explicit or implicit depends on the specific requirements and potential risks of your program.
*/
}

void exercise_14_47() {
    /*
The two conversion operators in the Integral struct have different constness qualifiers and, therefore, have different behaviors. Let's discuss the difference between the two operators:

operator const int()
This conversion operator returns a non-const int. It allows an instance of the Integral struct to be converted to a non-const int. The constness of the Integral object itself does not affect the constness of the resulting int. It means that if you have a const Integral object, you can still call this conversion operator and obtain a non-const int value.
operator int() const
This conversion operator returns a const int. It allows an instance of the Integral struct to be converted to a const int. The constness of the Integral object affects the constness of the resulting int. If you have a const Integral object, you can call this conversion operator and obtain a const int value.
*/
}

int main() {
    return 0;
}
