#include <iostream>
#include <string>
#include <vector>

using namespace std;

int exercice_7_10() {
    /*
    What does the condition in the following if statement do? 
    
    The condition in the if statement:

    if (read(read(cin, data1), data2))

    calls the read function twice: once with cin and data1, and then again with the result of the first read call and data2. The read function is assumed to return a std::istream& (or something that can be implicitly converted to a bool), so the condition checks whether the second read call succeeded or failed.

    This condition is equivalent to:
    
    std::istream& input1 = read(cin, data1);
    std::istream& input2 = read(input1, data2);

    if (input2)

    The purpose of this condition is to check whether both data1 and data2 were read in successfully from the input stream. 
    If both reads were successful, the if statement is true and its body is executed. 
    Otherwise, the if statement is false and its body is skipped.
    */

   return 0;

}

int exercise_7_16() {
    /*
    What, if any, are the constraints on where and how often an access spec- ifier may appear inside a class definition? 
    What kinds of members should be defined after a public specifier? What kinds should be private?

    An access specifier (public, private, or protected) can appear any number of times inside a class definition, and in any order. However, it is common practice to group related members (e.g., data members and member functions) together and separate them with access specifiers.

    Members that are part of the interface to the class should be defined after a public specifier. 
    These are the members that are intended to be used by code outside of the class. Typically, these include member functions that provide a public interface to the class, and any data members that need to be accessible from outside the class.

    Members that are implementation details and should not be accessible from outside the class should be defined after a private specifier. These are the members that are intended to be used only by the class itself or by its friends. 
    Typically, these include data members that store implementation details and any helper functions or other implementation details that should not be part of the public interface.

    It is generally good practice to make as much of a class's implementation private as possible, so that the class's users are not burdened with unnecessary details and the implementation can be changed more easily without affecting the class's users.
    */
   return 0;
}

int exercise_7_18() {
    /*
    What is encapsulation? Why is it useful?

    Encapsulation is a fundamental concept in object-oriented programming that refers to the practice of combining data and operations on that data into a single unit, called a class. 
    The data members of a class are hidden from the outside world, and can only be accessed through the class's public interface, which consists of the member functions of the class.

    The purpose of encapsulation is to protect the data of a class from being accidentally or intentionally modified by code outside of the class. By keeping the data members private, a class can enforce invariants that ensure the data is always in a valid state. 
    The public interface of the class provides a controlled way to manipulate the data, which can help prevent bugs and improve code readability and maintainability.

    Encapsulation also helps with code reuse, since classes with well-defined public interfaces can be used as building blocks for larger programs without exposing their internal details. 
    This allows for more modular and flexible code, since changes to the internal implementation of a class can be made without affecting the rest of the program as long as the public interface remains the same.
    */
   return 0;
}

int exercise_7_20() {
    /*
    When are friends useful? Discuss the pros and cons of using friends.

    Friends are useful in situations where a class needs to grant access to its private members to a specific function or class that is not part of the class hierarchy. Friends can be defined using the friend keyword, which allows the specified function or class to access the private members of the class as if they were its own.

    The pros of using friends are:

    Increased encapsulation: Friends allow a class to maintain encapsulation by keeping its private members hidden from the outside world while still granting access to specific functions or classes. This allows the class to maintain its internal invariants while still allowing external code to access its private members.
    Improved performance: Friends can be used to avoid unnecessary copying of objects or data by allowing a function to access a class's private data directly. This can improve performance in cases where copying or passing objects is expensive.
    Flexibility: Friends allow for more flexible design by allowing a class to grant access to its private members to specific functions or classes as needed, without having to expose those members to the entire class hierarchy.
    
    The cons of using friends are:

    Reduced encapsulation: Friends can reduce encapsulation by allowing external code to access a class's private members directly. This can make it harder to maintain the internal invariants of the class and can lead to bugs and unexpected behavior.
    Tight coupling: Friends can create tight coupling between a class and the functions or classes that are granted access to its private members. This can make it harder to modify or extend the class in the future.
    Potential security risks: Friends can be used to circumvent security measures that are intended to protect the class's private members. This can be a security risk if the friend function or class is not trusted or if it can be compromised.
    */
   return 0;
}

int exercise_7_24() {
    /*
    class Screen {
    public:
        using pos = std::string::size_type;

        // constructors
        Screen() = default;
        Screen(pos height, pos width) : height_(height), width_(width), contents_(height * width, ' ') {}
        Screen(pos height, pos width, char c) : height_(height), width_(width), contents_(height * width, c) {}

        // member functions
        char get() const { return contents_[cursor_]; }
        char get(pos row, pos col) const { return contents_[row * width_ + col]; }
        Screen& move(pos row, pos col) { cursor_ = row * width_ + col; return *this; }
        Screen& set(char c) { contents_[cursor_] = c; return *this; }
        Screen& set(pos row, pos col, char c) { contents_[row * width_ + col] = c; return *this; }
        Screen& display(std::ostream &os) { do_display(os); return *this; }
        const Screen& display(std::ostream &os) const { do_display(os); return *this; }

    private:
        // member function to do the work of displaying a Screen
        void do_display(std::ostream &os) const { os << contents_; }

        pos cursor_ = 0;
        pos height_ = 0, width_ = 0;
        std::vector<char> contents_;
    };
    */
   return 0;
}

int exercise_7_28() {
    /*
    What would happen in the previous exercise if the return type of move, set, and display was Screen rather than Screen&?

    If the return type of move, set, and display was Screen rather than Screen&, the program would still compile but it would create a copy of the object each time these functions were called. 
    This would result in unnecessary overhead and could potentially slow down the program if the object is large or if these functions are called frequently. 
    By returning a reference to the object, we avoid creating copies and can modify the original object directly.
    */
   return 0;
}

int exercise_7_33() {
    /*
    What would happen if we gave Screen a size member defined as follows? Fix any problems you identify.
    pos Screen::size() const
    {
        return height * width;
    }

    We will run into a couple of problems:

    The return type of size() is pos, which implies that it should return a position on the screen. 
    However, the function is calculating the area of the screen (height * width) and returning it as a position. This is a semantic error.
    The calculation of height * width assumes that height and width are of the same type, but there is no indication in the code that this is the case. 
    If height and width are of different types, this code will not compile.
    To fix these problems, we can change the return type of size() to a more appropriate type, such as size_t, and change the calculation to return the area of the screen:

    size_t Screen::size() const
    {
        return height * width;
    }

    This will calculate and return the area of the screen in terms of the number of characters it can display.

    */
   return 0;
}

int exercise_7_35() {
    /*
    Explain the following code, indicating which definition of Type or initVal is used for each use of those names. Say how you would fix any errors.
   
   typedef string Type;
   Type initVal();
   class Exercise {
   public:
       typedef double Type;
       Type setVal(Type);
       Type initVal();
   private:
       int val;
    };
    Type Exercise::setVal(Type parm) {
        val = parm + initVal();
    return val; }

    The code defines a type alias Type for the string type, and a function initVal that takes no arguments and returns a value of type Type (i.e., string).

    The code defines a type alias Type for the string type, and a function initVal that takes no arguments and returns a value of type Type (i.e., string).

    Then, it defines a class Exercise with a public type alias Type for the double type, a public member function setVal that takes an argument of type Type (i.e., double) and returns a value of the same type, and a private integer member variable val. The class also has a private member function initVal with the same name as the previously defined function.

    In the implementation of Exercise::setVal, Type refers to the public type alias of the class, which is double. However, the initVal() function call in this implementation refers to the previously defined initVal function outside of the class, which returns a string and not a double. This will result in a type mismatch error.

    To fix this, we need to specify which initVal function to call in the implementation of Exercise::setVal. We can do this by qualifying the call with the scope resolution operator ::, like this:

    Type Exercise::setVal(Type parm) {
       val = parm + Exercise::initVal();
       return val;
    }
    */
   return 0;
}

int exercise_7_36() {
    /*
   The following initializer is in error. Identify and fix the problem.
    struct X {
        X (int i, int j): base(i), rem(base % j) { } 
        int rem, base;
    };

    The problem with the initializer is that rem is initialized before base, but it uses the uninitialized value of base in its calculation.

    To fix this, we need to change the order of initialization so that base is initialized before rem. 
    We can do this by rearranging the order of the member variables in the struct definition:

    struct X {
        int base, rem;
        X(int i, int j) : base(i), rem(base % j) { }
    };
    */
   return 0;
}

int exercise_7_37() {
    /*
    Using the version of Sales_data from this section, determine which constructor is used to initialize each of the following variables and list the values of the data members in each object:
    Sales_data first_item(cin);
    int main() {
        Sales_data next;
        Sales_data last("9-999-99999-9");
    }

    Sales_data();
    Sales_data(const std::string &s);
    Sales_data(std::istream &is);
    */
   return 0;
}

int exercise_7_41() {
    /*
    Rewrite your own version of the Sales_data class to use delegating constructors. 
    Add a statement to the body of each of the constructors that prints a message whenever it is executed. 
    Write declarations to construct a Sales_data object in every way possible. 
    Study the output until you are certain you understand the order of execution among delegating constructors.
    
    class Sales_data {
    public:
        Sales_data() : Sales_data("", 0, 0.0) { std::cout << "Default constructor executed\n"; }
        Sales_data(const std::string& isbn) : Sales_data(isbn, 0, 0.0) { std::cout << "Constructor with isbn executed\n";}
        Sales_data(const std::string& isbn, unsigned units_sold, double revenue) : isbn(isbn), units_sold(units_sold), revenue(revenue) {std::cout << "Constructor with isbn, units sold, and revenue executed\n";}
        
    private:
        std::string isbn;
        unsigned units_sold = 0;
        double revenue = 0.0;
    };

    int main() {
        Sales_data item1;
        Sales_data item2("978-0134494166");
        Sales_data item3("978-0134494166", 10, 59.99);
        return 0;
    }
    */
   return 0;

}

int exercise_7_43() {
    /*
    Assume we have a class named NoDefault that has a constructor that takes an int, but has no default constructor. 
    Define a class C that has a member of type NoDefault. 
    Define the default constructor for C.

    class NoDefault {
    public:
        NoDefault(int i) { }
    };

    class C {
    public:
        C() : nd(0) { }
    private:
        NoDefault nd;
    };
    */
   return 0;
}

int exercise_7_44() {
    /*
    Is the following declaration legal? If not, why not? vector<NoDefault> vec(10);

    The following declaration is illegal, assuming NoDefault has no default constructor.

    This is because vector<NoDefault> requires NoDefault to be default-constructible so that it can allocate and construct the 10 elements in the vector. 
    If NoDefault has no default constructor, the elements cannot be constructed.
    */
   return 0;
}

int exercise_7_46() {
    /*
    Which, if any, of the following statements are untrue? Why?
    (a) A class must provide at least one constructor.

    The statement is untrue. A class need not provide a constructor if the class can be fully initialized with its member variables being default-initialized.
    
    (b) A default constructor is a constructor with an empty parameter list.
    
    The statement is true. A default constructor is a constructor that takes no arguments.

    (c) If there are no meaningful default values for a class, the class should not provide a default constructor
    
    The statement is true. If there are no meaningful default values for a class, the class should not provide a default constructor. 
    In such cases, the class should require its users to explicitly initialize its objects with arguments passed to a non-default constructor.
    
    (d) If a class does not define a default constructor,the compiler generates one that initializes each data member to the default value of its associated type.

    The statement is untrue. If a class does not define a default constructor, the compiler will not generate one. A default constructor is only generated by the compiler if the class does not define any constructors at all. 
    If the class defines any constructor (including copy constructor or move constructor), then the compiler will not generate the default constructor.
    */
   return 0;
}

int exercise_7_47() {
    /*
    Explain whether the Sales_data constructor that takes a string should be explicit. 
    What are the benefits of making the constructor explicit? What are the drawbacks?

    The Sales_data constructor that takes a string should be made explicit to prevent implicit conversions from a string to a Sales_data object.

    Benefits of making the constructor explicit:

    Prevents implicit conversions from a string to a Sales_data object, which can help avoid unintended conversions and make code more explicit.
    Helps prevent unexpected behavior and errors in code that relies on implicit conversions.
    Drawbacks of making the constructor explicit:

    Can make code slightly less concise if explicit conversions are needed.
    Can make the code more verbose and harder to read in certain cases.
    Overall, the benefits of making the constructor explicit tend to outweigh the drawbacks in most cases, especially in larger code bases where it is important to prevent unintended conversions and improve code clarity.
    */
   return 0;
}

int exercise_7_49() {
    /*
    Exercise 7.49: For each of the three following declarations of combine, explain what happens if we call i.combine(s), where i is a Sales_data and s is a string:
    
    (a) Sales_data &combine(Sales_data);
    This function takes a Sales_data object by value, meaning that a copy of i is made and passed to the function. 
    When the function is called with i.combine(s), a new temporary Sales_data object is created using the string s, and passed to the function. 
    The function modifies this temporary object, but does not modify the original i.
    
    (b) Sales_data &combine(Sales_data&);
    This function takes a Sales_data object by non-const reference, meaning that i can be modified by the function. 
    When the function is called with i.combine(s), the reference to i is passed to the function, so the function can modify i. 
    However, the function cannot be called with a string argument, because string cannot be converted to a Sales_data reference.
    
    (c) Sales_data &combine(const Sales_data&) const;
    This function takes a const reference to a Sales_data object, meaning that i cannot be modified by the function. 
    The const qualifier at the end of the function declaration indicates that this function does not modify the object on which it is called. 
    When the function is called with i.combine(s), the string s cannot be converted to a Sales_data reference, so the call will not compile.
    */
   return 0;
}

int exercise_7_56() {
    /*
    What is a static class member? 
    What are the advantages of static members? 
    How do they differ from ordinary members?

    A static class member is a member of a class that is shared by all instances of the class. 
    It is declared with the static keyword and is stored separately from the instances of the class. 
    Only one copy of the static member is shared by all instances of the class.

    The advantages of static members are that they can be used to maintain a single value across all instances of the class, they can be used to implement class-wide functionality, and they can be used to provide global access to certain class-related data. 
    Static members can also be used to control access to class data and to manage the lifecycle of objects.

    Static members differ from ordinary members in several ways. 
    Static members are not associated with any instance of the class and can be accessed directly using the scope resolution operator (::) without the need for an instance of the class. 
    Ordinary members are associated with an instance of the class and can only be accessed through an instance of the class. Static members also have a single copy that is shared by all instances of the class, while ordinary members have a separate copy for each instance of the class. 
    Finally, static members can be initialized at the time of their declaration, while ordinary members must be initialized in a constructor.
    */
   return 0;
}

int exercise_7_58() {
    /*
    Which, if any, of the following static data member declarations and definitions are errors? Explain why.
    // example.h 
    class Example { 
    public:
        static double rate = 6.5;
        static const int vecSize = 20; 
        static vector<double> vec(vecSize);
    };
    // example.C
    #include "example.h"
    double Example::rate; vector<double> Example::vec;

    The definition of a static data member inside the class must not include an initializer.
    Therefore, the definition of rate inside the class is an error. It should be removed from the class definition

    In the definition of vec, we need to specify the size of the vector when initializing it. 
    We cannot use vecSize in the initialization list of a static data member. 
    Instead, we need to define and initialize the vector outside the class

    // example.h
    class Example {
    public:
        static double rate;
        static const int vecSize = 20;
        static vector<double> vec;
    };

    // example.C
    #include "example.h"
    double Example::rate = 6.5;
    vector<double> Example::vec(Example::vecSize);
    */
   return 0;
}

int main()
{
    return 0;  
}

