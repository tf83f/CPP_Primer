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

using namespace std;

void exercise_13_1() {
    /*

A copy constructor is a special member function of a class that creates an object by initializing it with another object of the same class. It is used to create a new object that is a copy of an existing object.

The copy constructor is called when a new object is created as a copy of an existing object, typically by using the assignment operator or when passing an object by value to a function. It is also called when a class object is constructed using another class object as an argument to the constructor.

The copy constructor is important because it allows for deep copying of objects, which means that a new object is created with a new memory allocation and an identical copy of all the data members of the original object.
    */
}

void exercise_13_2() {
    /*
    The following declaration is illegal because it leads to an infinite recursion of copy constructor calls. 
    In this declaration, the Sales_data copy constructor is taking its argument rhs by value, which means that a copy of the argument is made and passed to the constructor. But in order to make this copy, the copy constructor must be called again to create the copy of rhs. This process will continue indefinitely and eventually cause a stack overflow, resulting in a runtime error.

    To fix this issue, the copy constructor should take its argument by reference-to-const instead of by value, like this:
    Sales_data::Sales_data(const Sales_data& rhs);
    */
}

void exercise_13_3() {
    /*
    When we copy a StrBlob, a new shared_ptr to the same underlying dynamic array is created. 
    This means that both objects share the same dynamic array and the number of elements in the array. 
    Each StrBlob has its own reference count and each shared_ptr keeps track of how many StrBlob objects share the same array. 
    Any modification to the shared dynamic array will be reflected in both StrBlob objects.

    On the other hand, when we copy a StrBlobPtr, a new pointer to the same dynamic array and the same index is created. 
    This means that both objects point to the same dynamic array and the same index within the array. 
    However, each StrBlobPtr has its own object that manages the reference to the underlying StrBlob object. 
    Any modification to the shared dynamic array will also be reflected in both StrBlobPtr objects.
    */
}

void exercise_13_4() {
    /*
    There are three uses of the copy constructor in this program fragment:

    Point local = arg; 
    - The copy constructor is called to initialize local with the contents of arg.
    
    Point *heap = new Point(global); *heap = local; 
    - The copy constructor is called to initialize the new object pointed to by heap with the contents of global. 
    Then, the copy assignment operator is called to assign the contents of local to the object pointed to by heap.
    
    Point pa[4] = {local, *heap}; 
    - The copy constructor is called twice to initialize the objects in the array pa with the contents of local and the object pointed to by heap.
    */
}

void exercise_13_5() {
    /*
    class HasPtr {
    public:
        HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) { }
        HasPtr(const HasPtr& rhs) : ps(new std::string(*rhs.ps)), i(rhs.i) { }
    private:
        std::string* ps;
        int i;
};

    */
}

void exercise_13_6() {
    /*
    A copy-assignment operator is a member function of a class that is used to copy the values of one object to another object of the same class. It is used when we need to assign a new value to an existing object of the same class.

    The synthesized copy-assignment operator is a default implementation of the copy-assignment operator that the compiler provides automatically if the class does not provide its own copy-assignment operator. It performs a shallow copy of the data members, which means that it copies the values of the data members from the right-hand object to the left-hand object. For pointer data members, it copies the pointer value, but not the object that the pointer points to.

    The synthesized copy-assignment operator is synthesized when the class does not provide its own copy-assignment operator. It is used in situations where the copy-assignment operator is needed, such as when an object is assigned to another object of the same class.
    */
}

void exercise_13_7() {
    /*
    When we assign one StrBlob to another, the pointer to the shared dynamic memory holding the elements is copied. 
    Both objects then point to the same memory, and the use count is incremented by one.

    When we assign one StrBlobPtr to another, the pointer and the weak_ptr to the dynamic memory holding the elements are copied. 
    Both objects then point to the same memory and weak_ptr object, and the use count of the shared_ptr is incremented by one.
    */
}

void exercise_13_9() {
    /*
    A destructor is a special member function in C++ that is responsible for freeing up the resources used by an object when it goes out of scope or is deleted explicitly. The purpose of the destructor is to ensure that any dynamically allocated memory, such as memory allocated using new, is properly deallocated and any other resources are released, such as file handles, network sockets, and database connections.

    The synthesized destructor is a default destructor that is automatically generated by the compiler if you do not define one yourself. This default destructor does nothing if the class has no resources to deallocate, but it calls the destructors of any member objects and base classes in the reverse order of their construction if they have destructors defined.

    A destructor is synthesized when you do not provide an explicit destructor definition in your class declaration. In that case, the compiler will generate a default destructor for you. However, if your class has resources that need to be freed or cleaned up, you will need to provide an explicit destructor definition that performs those tasks.

    */
}

void exercise_13_10() {
    /*
    When a StrBlob object is destroyed, its destructor is called, which deallocates the dynamically allocated memory used to store the elements of the vector data. 
    This means that the vector itself is destroyed, and all the elements it contains are destroyed along with it. If there are any StrBlobPtr objects that reference the StrBlob object being destroyed, their behavior is undefined, as they will be pointing to memory that has been deallocated.

    When a StrBlobPtr object is destroyed, its destructor is called, but it does not deallocate any memory because StrBlobPtr does not own the memory it points to. 
    If there are no other StrBlobPtr objects that reference the same StrBlob object, the StrBlob object itself may still exist, and its elements will not be deallocated until the StrBlob object is destroyed. 
    However, if there are other StrBlobPtr objects that reference the same StrBlob object, the StrBlob object will not be destroyed until all StrBlobPtr objects that reference it are destroyed, because the StrBlobPtr objects do not own the memory they point to.
    */
}

void exercise_13_12() {
    /*
    There are a total of four destructor calls that occur:

    When the item1 object is created using the copy constructor to initialize it with the *trans object.
    
    When the item2 object is created using the default copy constructor to initialize it with the accum object.
    
    When the item2 object goes out of scope at the end of the function, its destructor is called.
    
    When the accum object goes out of scope at the end of the function, its destructor is called.
    
    Note that the item1 object does not have its destructor called explicitly because it goes out of scope at the end of the function and is destroyed automatically.
    */
}

void exercise_13_13() {
    /*
    struct X {
        X() {std::cout << "X()" << std::endl;}
        X(const X&) {std::cout << "X(const X&)" << std::endl;}
        X& operator=(const X&) {std::cout << "operator=(const X&)" << std::endl; return *this;}
        ~X() {std::cout << "~X()" << std::endl;}
    };

    void f1(X x) { }
    void f2(X& x) { }
    void f3(const X& x) { }

    int main() {
        X a; // calls X()
        X b(a); // calls X(const X&)

        X c = a; // calls X(const X&)
        a = b; // calls operator=(const X&)

        f1(a); // calls X(const X&)
        f2(a); // does not call any copy-control members
        f3(a); // does not call any copy-control members

        X* p = new X; // calls X()
        delete p; // calls ~X()

        std::vector<X> v;

        v.push_back(a); // calls X(const X&) to copy a into the vector
        v.push_back(X()); // calls X() to create a temporary object, then X(const X&) to copy it into the vector

        return 0; // calls ~X() for a, b, c, and all objects in v
    }
    */
}

void exercise_13_15() {
    /*
    We create an object a of type numbered. Its serial number is 1.
    
    We create an object b of type numbered by copying a. b's serial number is 2.
    
    We create an object c of type numbered by copying b. c's serial number is 3.
    
    We call function f with object a. This creates a copy of a inside the function, which gets a new serial number of 4. The function prints the serial number of this new object, which is 4.
    
    We call function f with object b. This creates a copy of b inside the function, which gets a new serial number of 5. The function prints the serial number of this new object, which is 5.
    
    We call function f with object c. This creates a copy of c inside the function, which gets a new serial number of 6. The function prints the serial number of this new object, which is 6.
    
    Note that when we copy objects a and b to create b and c, the serial numbers of the new objects are incremented. This is because the synthesized copy constructor copies the value of mysn from the original object, but does not generate a new unique serial number.

    */
}

void exercise_13_19() {
    /*
    class Employee {
    public:
        Employee() : name(""), id(++next_id) {}
        Employee(const std::string& name) : name(name), id(++next_id) {}
        Employee(const Employee& other) : name(other.name), id(++next_id) {}
        Employee& operator=(const Employee& other) {
            if (this != &other) {
                name = other.name;
                id = ++next_id;
            }
            return *this;
        }
        ~Employee() {}
        const std::string& get_name() const { return name; }
        int get_id() const { return id; }
    private:
        std::string name;
        int id;
        static int next_id;
    };
    */
}

void exercise_13_21() {
    /*
    The TextQuery and QueryResult classes manage dynamically allocated memory, so they need to define their own versions of the copy-control members to ensure that the dynamically allocated memory is properly managed.

    For the TextQuery class, we need to define a destructor to deallocate the memory pointed to by the shared_ptr member. We also need to define the copy constructor and copy-assignment operator to ensure that the shared_ptr is correctly copied and reference counts are updated.

    For the QueryResult class, we only need to define the copy constructor and copy-assignment operator. The dynamically allocated memory is managed by the shared_ptr member of the TextQuery class, so the QueryResult class does not need to do anything special to manage its memory.
    
    class TextQuery {
    public:
        // constructors and other member functions omitted for brevity
        
        // copy constructor
        TextQuery(const TextQuery& tq) :
            file(tq.file), wordMap(tq.wordMap), 
            lineNumbers(tq.lineNumbers) { }
        
        // copy-assignment operator
        TextQuery& operator=(const TextQuery& rhs) {
            if (this != &rhs) {
                file = rhs.file;
                wordMap = rhs.wordMap;
                lineNumbers = rhs.lineNumbers;
            }
            return *this;
        }
        
        // destructor
        ~TextQuery() { }

    private:
        std::shared_ptr<std::vector<std::string>> file;
        std::map<std::string, std::shared_ptr<std::set<line_no>>> wordMap;
        std::shared_ptr<std::set<line_no>> lineNumbers;

    class QueryResult {
        friend std::ostream& operator<<(std::ostream&, const QueryResult&);
    public:
        // constructors and other member functions omitted for brevity
        
        // copy constructor
        QueryResult(const QueryResult& qr) :
            sought(qr.sought), lines(qr.lines), file(qr.file) { }
        
        // copy-assignment operator
        QueryResult& operator=(const QueryResult& rhs) {
            if (this != &rhs) {
                sought = rhs.sought;
                lines = rhs.lines;
                file = rhs.file;
            }
            return *this;
        }

    private:
        std::string sought;
        std::shared_ptr<std::set<line_no>> lines;
        std::shared_ptr<std::vector<std::string>> file;
    };
};
*/
}

void exercise_13_22() {
    /*
    class HasPtr {
    public:
        HasPtr(const std::string& s = std::string()) :
            ps(new std::string(s)), i(0) { }
        HasPtr(const HasPtr& hp) :
            ps(new std::string(*hp.ps)), i(hp.i) { }
        HasPtr& operator=(const HasPtr& hp) {
            auto newp = new std::string(*hp.ps);
            delete ps;
            ps = newp;
            i = hp.i;
            return *this;
        }
        ~HasPtr() { delete ps; }
    private:
        std::string *ps;
        int i;
    };
    */
}

void exercise_13_24() {
    /*

    If the version of HasPtr in this section did not define a destructor, then the dynamically allocated memory for the string object would not be freed, leading to a memory leak. 
    This means that when the HasPtr object goes out of scope or is destroyed, the memory allocated for the string object would not be freed.

    If HasPtr did not define the copy constructor, then the compiler would synthesize one for us. 
    However, since HasPtr contains a pointer member, the synthesized copy constructor would perform a shallow copy of the pointer, which means that two HasPtr objects would end up pointing to the same dynamically allocated string object. 
    If one of the HasPtr objects goes out of scope or is destroyed, it would delete the string object, leaving the other HasPtr object with a dangling pointer. 
    This would result in undefined behavior when the dangling pointer is dereferenced.

    */
}

void exercise_13_29() {
    /*
    The swap function here is using the std::swap algorithm to swap the values of lhs.ps and rhs.ps, and lhs.i and rhs.i. 
    The std::swap algorithm is defined in the <utility> header and is implemented in terms of move operations, which means it does not perform any recursion.

    Therefore, the calls to swap inside swap(HasPtr&, HasPtr&) do not cause a recursion loop, as they simply call the std::swap algorithm and not the swap function itself. 
    This avoids the issue of infinite recursion, which would occur if swap called itself directly or indirectly through other functions.

    */
}

void exercise_13_30() {
    /*
        class HasPtr {
    public:
        HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
        HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
        HasPtr& operator=(const HasPtr& hp) {
            auto newp = new std::string(*hp.ps);
            delete ps;
            ps = newp;
            i = hp.i;
            return *this;
        }
        ~HasPtr() { delete ps; }

        // Add swap function
        friend void swap(HasPtr& lhs, HasPtr& rhs) {
            std::cout << "Executing swap" << std::endl;
            using std::swap;
            swap(lhs.ps, rhs.ps);
            swap(lhs.i, rhs.i);
        }

        std::string* ps;
        int i;
    };

    int main() {
        HasPtr hp1("Hello");
        HasPtr hp2("World");

        std::cout << "Before swap: hp1.ps = " << *hp1.ps << ", hp2.ps = " << *hp2.ps << std::endl;
        swap(hp1, hp2);
        std::cout << "After swap: hp1.ps = " << *hp1.ps << ", hp2.ps = " << *hp2.ps << std::endl;

        return 0;
    }
    */
}

void exercise_13_31() {
    /*
    class HasPtr {
    public:
        HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
        HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
        HasPtr& operator=(const HasPtr& hp) {
            auto newp = new std::string(*hp.ps);
            delete ps;
            ps = newp;
            i = hp.i;
            return *this;
        }
        ~HasPtr() { delete ps; }

        // Add < operator overload
        bool operator<(const HasPtr& rhs) const {
            return *ps < *rhs.ps;
        }

        std::string* ps;
        int i;
    };

    int main() {
        std::vector<HasPtr> v;
        v.emplace_back("world");
        v.emplace_back("hello");
        v.emplace_back("c++");
        v.emplace_back("programming");

        std::cout << "Before sort: ";
        for (const auto& hp : v)
            std::cout << *hp.ps << " ";
        std::cout << std::endl;

        std::sort(v.begin(), v.end());

        std::cout << "After sort: ";
        for (const auto& hp : v)
            std::cout << *hp.ps << " ";
        std::cout << std::endl;

        return 0;
    }
    */
}

void exercise_13_32() {
/*
he pointerlike version of HasPtr would benefit from defining a swap function. In fact, defining a swap function is necessary for the pointerlike version of HasPtr because the default implementation of std::swap for pointers simply swaps the pointers themselves, rather than the objects they point to. This means that swapping two instances of HasPtr using std::swap would only swap the pointers, leaving the pointed-to objects in their original locations. This could lead to memory leaks or undefined behavior if the objects pointed to by the swapped pointers are not correctly managed.

By defining a custom swap function, we can properly swap the pointed-to objects and avoid these issues. For example:
class HasPtr {
public:
    HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
    HasPtr(const HasPtr& hp) : ps(new std::string(*hp.ps)), i(hp.i) {}
    HasPtr& operator=(const HasPtr& hp) {
        auto newp = new std::string(*hp.ps);
        delete ps;
        ps = newp;
        i = hp.i;
        return *this;
    }
    ~HasPtr() { delete ps; }

    // Define swap function for pointerlike version
    friend void swap(HasPtr& lhs, HasPtr& rhs) {
        std::swap(lhs.ps, rhs.ps);
        std::swap(lhs.i, rhs.i);
    }


    std::string* ps;
    int i;
};

int main() {
    HasPtr* hp1 = new HasPtr("Hello");
    HasPtr* hp2 = new HasPtr("World");

    std::cout << "Before swap: *hp1->ps = " << *hp1->ps << ", *hp2->ps = " << *hp2->ps << std::endl;
    std::swap(*hp1, *hp2);
    std::cout << "After swap: *hp1->ps = " << *hp1->ps << ", *hp2->ps = " << *hp2->ps << std::endl;

    // Alternatively, we can call the swap function explicitly
    swap(*hp1, *hp2);
    std::cout << "After second swap: *hp1->ps = " << *hp1->ps << ", *hp2->ps = " << *hp2->ps << std::endl;

    delete hp1;
    delete hp2;

    return 0;
}
*/
}

void exercise_13_33() {
    /*

    The parameter to the save and remove members of the Message class is a non-const reference to Folder (Folder&) because these functions modify the set of folders that a message is stored in.

    If the parameter were simply Folder, then a copy of the Folder object would be made, and any changes made to that copy would not affect the original Folder object. Since the goal of these functions is to modify the set of folders that a message is stored in, they need to be able to modify the original Folder object.

    If the parameter were const Folder&, then the functions would not be able to modify the Folder object at all. This would prevent them from adding or removing the message from the set of messages stored in a particular Folder.

    Therefore, a non-const reference to Folder (Folder&) is the appropriate parameter type for these functions.

    */
}

void exercise_13_39() {
    /*
    class StrVec {
    public:
        StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
        StrVec(const StrVec&);
        StrVec& operator=(const StrVec&);
        ~StrVec();
        void push_back(const std::string&);
        size_t size() const { return first_free - elements; }
        size_t capacity() const { return cap - elements; }
        void reserve(size_t n);
        void resize(size_t n);
        std::string* begin() const { return elements; }
        std::string* end() const { return first_free; }
    private:
        static std::allocator<std::string> alloc;
        void chk_n_alloc() { if (size() == capacity()) reallocate(); }
        std::pair<std::string*, std::string*> alloc_n_copy(const std::string*, const std::string*);
        void free();
        void reallocate();
        std::string* elements;
        std::string* first_free;
        std::string* cap;
    };

    std::allocator<std::string> StrVec::alloc;

    void StrVec::push_back(const std::string& s)
    {
        chk_n_alloc();
        alloc.construct(first_free++, s);
    }

    std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string* b, const std::string* e)
    {
        auto data = alloc.allocate(e - b);
        return { data, std::uninitialized_copy(b, e, data) };
    }

    void StrVec::free()
    {
        if (elements) {
            for (auto p = first_free; p != elements; )
                alloc.destroy(--p);
            alloc.deallocate(elements, cap - elements);
        }
    }

    StrVec::StrVec(const StrVec& s)
    {
        auto newdata = alloc_n_copy(s.begin(), s.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
    }

    StrVec::~StrVec() { free(); }

    StrVec& StrVec::operator=(const StrVec& rhs)
    {
        auto data = alloc_n_copy(rhs.begin(), rhs.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
    }

    void StrVec::reallocate()
    {
        auto newcapacity = size() ? 2 * size() : 1;
        auto newdata = alloc.allocate(newcapacity);
        auto dest = newdata;
        auto elem = elements;
        for (size_t i = 0; i != size(); ++i)
            alloc.construct(dest++, std::move(*elem++));
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
    }

    void StrVec::reserve(size_t n)
    {
        if (n > capacity()) {
            auto newdata = alloc.allocate(n);
            auto dest = newdata;
            auto elem = elements;
            for (size_t i = 0; i != size(); ++i)
                alloc.construct(dest++, std::move(*elem++));
            free();
            elements = newdata;
            first_free = dest;
            cap = elements + n;
        }
    }

    void StrVec::resize(size_t n)
    {
        if (n > size()) {
            reserve(n);
            for (size_t i = size(); i != n; ++i)
                alloc.construct(first_free++, "");
        } else if (n < size()) {
            while (first_free != elements + n)
                alloc.destroy(--first_free);
        }
    }
    int main()
    {
        StrVec sv;
        std::cout << "Initial capacity: " << sv.capacity() << std::endl;

        sv.push_back("Hello");
        sv.push_back("world");
        sv.push_back("!");

        std::cout << "Capacity after 3 push_backs: " << sv.capacity() << std::endl;
        std::cout << "Contents of StrVec: ";
        for (auto it = sv.begin(); it != sv.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        sv.reserve(10);
        std::cout << "Capacity after reserve(10): " << sv.capacity() << std::endl;

        sv.resize(5);
        std::cout << "Capacity after resize(5): " << sv.capacity() << std::endl;
        std::cout << "Size after resize(5): " << sv.size() << std::endl;
        std::cout << "Contents of StrVec: ";
        for (auto it = sv.begin(); it != sv.end(); ++it)
            std::cout << *it << " ";
        std::cout << std::endl;

        return 0;
    }
*/
}

void exercise_13_45() {
    /*
    In C++, references are a way to alias an existing object. An lvalue reference is a reference that can only bind to an lvalue expression, meaning an expression that identifies an object that has a name and is located in memory. An lvalue reference is declared with the & symbol, and is commonly used to pass objects by reference to functions, as well as to create aliases to existing objects.

    On the other hand, an rvalue reference is a reference that can bind to an rvalue expression, which is an expression that creates a temporary object that does not have a name and cannot be referenced again after the expression is evaluated. An rvalue reference is declared with the && symbol, and is commonly used to bind to temporaries that are created by move operations.

    In summary, lvalue references are used to create aliases to existing objects, while rvalue references are used to bind to temporary objects.
    */
}

void exercise_13_46() {
    /*
    int? r1 = f();: This can bind to an rvalue reference, because f() is a function call that returns a temporary object (assuming f() returns by value).
    int? r2 = vi[0];: This can bind to an lvalue reference, because vi[0] is an lvalue expression that identifies an object that has a name and is located in memory.
    int? r3 = r1;: This can bind to an lvalue reference, because r1 is an lvalue expression that identifies an object that has a name and is located in memory.
    int? r4 = vi[0] * f();: This can bind to an rvalue reference, because the expression vi[0] * f() creates a temporary object that does not have a name and cannot be referenced again after the expression is evaluated.
    */
}

void exercise_13_47() {
    /*
    class String {
    public:
        String() : String("") { }
        String(const char*);
        String(const String&);
        String& operator=(const String&);
        ~String();

        void print() const;

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
        std::cout << "Copy constructor called" << std::endl;
        auto data = alloc_n_copy(rhs.elements, rhs.end);
        elements = data.first;
        end = data.second;
    }

    String& String::operator=(const String& rhs)
    {
        std::cout << "Copy-assignment operator called" << std::endl;
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

    int main()
    {
        String s1("hello");
        String s2(s1); // calls the copy constructor
        String s3 = s1; // calls the copy constructor
        s3 = s2; // calls the copy-assignment operator
        return 0;
    }
    */
}

void exercise_13_50() {
/* 
class String {
public:
    String() : String("") { }
    String(const char*);
    String(const String&);
    String& operator=(const String&);
    String(String&&) noexcept;
    String& operator=(String&&) noexcept;
    ~String();

    void print() const;

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
    std::cout << "Copy constructor called" << std::endl;
    auto data = alloc_n_copy(rhs.elements, rhs.end);
    elements = data.first;
    end = data.second;
}

String& String::operator=(const String& rhs)
{
    std::cout << "Copy-assignment operator called" << std::endl;
    auto data = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = data.first;
    end = data.second;
    return *this;
}

String::String(String&& s) noexcept
    : elements(s.elements), end(s.end)
{
    std::cout << "Move constructor called" << std::endl;
    s.elements = s.end = nullptr;
}

String& String::operator=(String&& rhs) noexcept
{
    std::cout << "Move-assignment operator called" << std::endl;
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
    }
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

int main()
{
    String s1("hello");

    cout << "-------1-------" << endl;
    String s2(s1); // calls the copy constructor

    cout << "-------2-------" << endl;
    String s3 = s1; // calls the copy constructor

    cout << "-------3-------" << endl;
    s3 = s2; // calls the copy-assignment operator

    cout << "-------4-------" << endl;
    String s4(std::move(s1)); // calls the move constructor

    cout << "-------5-------" << endl;
    s1 = std::move(s2); // calls the move-assignment operator

    cout << "-------6-------" << endl;
    return 0;
}
*/

}

int main() {
    return 0;
}
