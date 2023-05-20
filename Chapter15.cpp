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

void exercise_15_1() {
    /*
    In the context of programming, a virtual member refers to a method or function declared in a base class and overridden in a derived class. It is a concept commonly used in object-oriented programming languages like C++, C#, and Java.

When a method is declared as "virtual" in the base class, it allows derived classes to provide their own implementation of that method. This enables polymorphism, which means that objects of different derived classes can be treated as objects of the base class, and the appropriate version of the method is called based on the actual type of the object at runtime.

The use of virtual members allows for dynamic dispatch, where the decision of which implementation of the method to execute is made at runtime based on the actual type of the object, rather than at compile time based on the declared type of the variable. This is in contrast to non-virtual members, where the decision is made based on the declared type of the variable.
*/
}

void exercise_15_2() {
    /*
    In object-oriented programming languages, such as C++, Java, and C#, the protected and private access specifiers are used to control the visibility and accessibility of class members (variables and functions) from within and outside the class.

Here's how they differ:

Private Access Specifier:
Members declared as private are only accessible within the class that defines them.
They cannot be accessed or modified by any other class, including derived classes.
Private members are typically used to encapsulate internal implementation details of a class and hide them from other classes.
Only the class that defines the private members has direct access to them.

Protected Access Specifier:
Members declared as protected are accessible within the class that defines them and its derived classes.
Protected members are not accessible from outside the class hierarchy.
They provide a level of visibility that allows derived classes to access and modify them.
Protected members are often used to expose certain data or functionality to derived classes while still maintaining encapsulation and restricting access from unrelated classes.
*/
}

void exercise_15_4() {
    /*
(a) class Derived : public Derived { ... };

This declaration is incorrect because it attempts to derive a class from itself (Derived is derived from Derived). Inheritance is used to create a relationship between a derived class and its base class, but it cannot be used to derive a class from itself. It would result in a compilation error.

(b) class Derived : private Base { ... };

This declaration is correct. It declares a class Derived that is privately derived from the Base class. Private inheritance means that the derived class inherits all the members of the base class, but they become private members in the derived class. This declaration is allowed and creates a valid relationship between the Derived and Base classes.

(c) class Derived : public Base;

This declaration is incorrect. It is missing the body of the class, which defines the members and functions of the Derived class. The correct syntax for class declaration includes the body enclosed in curly braces { ... }. Without the body, it would result in a compilation error.
*/
}

void exercise_15_5() {
    /*
class Quote {
public:
    Quote(const std::string& book, double price) : book(book), price(price) {}

    virtual double calculateCost(std::size_t quantity) const {
        return quantity * price;
    }

    virtual void display() const {
        std::cout << "Book: " << book << ", Price: " << price;
    }

protected:
    std::string book;
    double price;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote(const std::string& book, double price, std::size_t minQty, double discount)
        : Quote(book, price), minQuantity(minQty), discount(discount) {}

    double calculateCost(std::size_t quantity) const override {
        if (quantity >= minQuantity)
            return quantity * (1 - discount) * price;
        else
            return quantity * price;
    }

    void display() const override {
        std::cout << "Book: " << book << ", Price: " << price
                  << ", Minimum Quantity: " << minQuantity
                  << ", Discount: " << discount;
    }

private:
    std::size_t minQuantity;
    double discount;
};

int main() {
    Quote quote("Sample Book", 10.0);
    Bulk_quote bulkQuote("Bulk Book", 20.0, 5, 0.2);

    quote.display();
    std::cout << ", Total Cost: " << quote.calculateCost(3) << std::endl;

    bulkQuote.display();
    std::cout << ", Total Cost: " << bulkQuote.calculateCost(7) << std::endl;

    return 0;
}
*/
}

void exercise_15_6() {
    /*
class Quote {
public:
    Quote(const std::string& book, double price) : book(book), price(price) {}

    virtual double calculateCost(std::size_t quantity) const {
        return quantity * price;
    }

    virtual void display() const {
        std::cout << "Book: " << book << ", Price: " << price;
    }

protected:
    std::string book;
    double price;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote(const std::string& book, double price, std::size_t minQty, double discount)
        : Quote(book, price), minQuantity(minQty), discount(discount) {}

    double calculateCost(std::size_t quantity) const override {
        if (quantity >= minQuantity)
            return quantity * (1 - discount) * price;
        else
            return quantity * price;
    }

    void display() const override {
        std::cout << "Book: " << book << ", Price: " << price
                  << ", Minimum Quantity: " << minQuantity
                  << ", Discount: " << discount;
    }

private:
    std::size_t minQuantity;
    double discount;
};

void print_total(const Quote& quote, std::size_t quantity) {
    std::cout << "Book: " << quote.book << ", Quantity: " << quantity
              << ", Total Cost: " << quote.calculateCost(quantity) << std::endl;
}

int main() {
    Quote quote("Sample Book", 10.0);
    Bulk_quote bulkQuote("Bulk Book", 20.0, 5, 0.2);

    print_total(quote, 3);
    print_total(bulkQuote, 7);

    return 0;
}
*/
}

void exercise_15_7() {
    /*
Static Type:
Static type refers to the type of a variable or expression that is known and checked at compile-time. It is a property of statically typed programming languages. When a variable is declared or an expression is evaluated, the static type represents the type that the variable or expression is expected to have based on its declaration or usage in the code.
The static type is determined by the declared type of a variable or the expression's syntax and context. The compiler performs static type checking to ensure that operations and assignments are performed on compatible types and that the code adheres to the type system rules.

Dynamic Type:
Dynamic type refers to the actual type of an object or expression at runtime. It is a property of dynamically typed programming languages or situations where type information is resolved during program execution. Unlike static typing, where types are checked at compile-time, dynamic typing allows the type of a variable or expression to change during program execution.
The dynamic type is determined when an object is instantiated or an expression is evaluated at runtime. It represents the specific class or type that the object or expression embodies or refers to, which may be different from its static type. Dynamic typing enables flexibility and late binding, where method dispatch and type compatibility are resolved dynamically based on the actual type of objects or expressions at runtime.

In summary, the static type is the type known and checked at compile-time, based on declarations and static analysis, while the dynamic type is the actual type of an object or expression at runtime, which may differ from its static type and is determined dynamically during program execution.
    */
}

void exercise_15_8() {
    /*
Polymorphic Base Class and Derived Class:

In C++, when dealing with polymorphism using inheritance and virtual functions, the static type of a pointer or reference can be a base class type, while the dynamic type can be a derived class type.

class Animal {
public:
    virtual void makeSound() {
        cout << "Animal sound" << endl;
    }
};

class Cat : public Animal {
public:
    void makeSound() override {
        cout << "Meow!" << endl;
    }
};

int main() {
    Animal* animal = new Cat();  // Static type: Animal*, Dynamic type: Cat*
    animal->makeSound();  // Calls the overridden method in the Cat class
    delete animal;
    return 0;
}  

Type Casting:
In C++, type casting allows changing the static type of an expression while preserving its dynamic type. 
This situation occurs when an explicit conversion is performed using the static_cast, dynamic_cast, or reinterpret_cast operators.
   
int main() {
    double num = 3.14;
    int intValue = static_cast<int>(num);  // Static type: int, Dynamic type: double

    Animal* animal = new Cat();
    Cat* cat = dynamic_cast<Cat*>(animal);  // Static type: Cat*, Dynamic type: Cat*
    
    return 0;
}

Function Overriding:
When a member function is overridden in a derived class, the static type of the expression can be the base class type, while the dynamic type can be the derived class type. 
This situation occurs when a member function is called on an object, and the actual implementation is determined at runtime based on the dynamic type of the object.

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape." << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle." << endl;
    }
};

int main() {
    Shape* shape = new Circle();  // Static type: Shape*, Dynamic type: Circle*
    shape->draw();  // Calls the overridden method in the Circle class
    delete shape;
    return 0;
}


    */
}

void exercise_15_11() {
    /*
class Quote {
public:
    Quote(const std::string& isbn, double price) : isbn(isbn), price(price) {}
    
    // Virtual function for debugging
    virtual void debug() const {
        std::cout << "ISBN: " << isbn << ", Price: " << price << std::endl;
    }

    // Other member functions and data members of Quote class
    // ...
    
protected:
    std::string isbn;
    double price;
};

class BulkQuote : public Quote {
public:
    BulkQuote(const std::string& isbn, double price, int minQuantity, double discount)
        : Quote(isbn, price), minQuantity(minQuantity), discount(discount) {}
    
    // Override debug() function for BulkQuote
    void debug() const override {
        std::cout << "ISBN: " << isbn << ", Price: " << price << ", Min Quantity: " << minQuantity
                  << ", Discount: " << discount << std::endl;
    }

    // Other member functions and data members of BulkQuote class
    // ...
    
private:
    int minQuantity;
    double discount;
};

class LimitedQuote : public Quote {
public:
    LimitedQuote(const std::string& isbn, double price, int maxQuantity, double discount)
        : Quote(isbn, price), maxQuantity(maxQuantity), discount(discount) {}
    
    // Override debug() function for LimitedQuote
    void debug() const override {
        std::cout << "ISBN: " << isbn << ", Price: " << price << ", Max Quantity: " << maxQuantity
                  << ", Discount: " << discount << std::endl;
    }

    // Other member functions and data members of LimitedQuote class
    // ...
    
private:
    int maxQuantity;
    double discount;
};

int main() {
    Quote quote("123456789", 10.99);
    BulkQuote bulkQuote("987654321", 19.99, 5, 0.2);
    LimitedQuote limitedQuote("567891234", 29.99, 2, 0.15);

    quote.debug();  // Calls debug() from Quote class
    bulkQuote.debug();  // Calls debug() from BulkQuote class
    limitedQuote.debug();  // Calls debug() from LimitedQuote class

    return 0;
}
    */
}

void exercise_15_15() {
    /*
class Quote {
public:
    Quote(const std::string& isbn, double price) : isbn(isbn), price(price) {}

    virtual double netPrice(std::size_t quantity) const {
        return price * quantity;
    }

    virtual ~Quote() = default; // Virtual destructor for proper polymorphic behavior

protected:
    std::string isbn;
    double price;
};

class Disc_quote : public Quote {
public:
    Disc_quote(const std::string& isbn, double price, std::size_t quantity, double discount)
        : Quote(isbn, price), quantity(quantity), discount(discount) {}

    double netPrice(std::size_t quantity) const override {
        return price * quantity * (1 - discount);
    }

protected:
    std::size_t quantity;
    double discount;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote(const std::string& isbn, double price, std::size_t quantity, double discount, std::size_t minQuantity)
        : Disc_quote(isbn, price, quantity, discount), minQuantity(minQuantity) {}

    double netPrice(std::size_t quantity) const override {
        if (quantity >= minQuantity) {
            return price * quantity * (1 - discount);
        } else {
            return price * quantity;
        }
    }

private:
    std::size_t minQuantity;
};
*/
}

void exercise_15_16() {
    /*
class Quote {
public:
    Quote(const std::string& isbn, double price) : isbn(isbn), price(price) {}

    virtual double netPrice(std::size_t quantity) const {
        return price * quantity;
    }

    virtual ~Quote() = default; // Virtual destructor for proper polymorphic behavior

protected:
    std::string isbn;
    double price;
};

class Disc_quote : public Quote {
public:
    Disc_quote(const std::string& isbn, double price, std::size_t quantity, double discount)
        : Quote(isbn, price), quantity(quantity), discount(discount) {}

    double netPrice(std::size_t quantity) const override {
        return price * quantity * (1 - discount);
    }

protected:
    std::size_t quantity;
    double discount;
};

class Limited_quote : public Disc_quote {
public:
    Limited_quote(const std::string& isbn, double price, std::size_t quantity, double discount, std::size_t maxQuantity)
        : Disc_quote(isbn, price, quantity, discount), maxQuantity(maxQuantity) {}

    double netPrice(std::size_t quantity) const override {
        if (quantity <= maxQuantity) {
            return Disc_quote::netPrice(quantity); // Call the base class's netPrice() function
        } else {
            return price * quantity; // No discount applied for quantities exceeding the limit
        }
    }

private:
    std::size_t maxQuantity;
};
*/
}

void exercise_15_22() {
    /*
class GeometricPrimitive {
public:
    virtual ~GeometricPrimitive() = default;
    virtual void draw() const = 0;
    virtual double calculateArea() const = 0;
protected:
    // Common protected members for geometric primitives
    double positionX;
    double positionY;
};

class Box : public GeometricPrimitive {
public:
    void draw() const override {
        // Code to draw a box
    }

    double calculateArea() const override {
        // Calculation for box area
    }
private:
    // Box-specific private members
    double width;
    double height;
};

class Circle : public GeometricPrimitive {
public:
    void draw() const override {
        // Code to draw a circle
    }

    double calculateArea() const override {
        // Calculation for circle area
    }
private:
    // Circle-specific private members
    double radius;
};
    */
}

void exercise_15_24() {
    /*
A virtual destructor is typically needed for classes that are designed to be used as base classes in inheritance hierarchies. When a class is used as a base class and objects of derived classes are deleted through a pointer to the base class, having a virtual destructor ensures that the destructor of the derived class is called, in addition to the destructor of the base class.

The primary reason for using a virtual destructor is to enable proper destruction of objects in polymorphic scenarios. If a derived class has resources allocated in its constructor or during its lifetime, those resources need to be properly deallocated when the object is destroyed. Without a virtual destructor, only the base class destructor would be called when deleting a derived class object through a pointer to the base class, resulting in a potential resource leak.

The operations performed by a virtual destructor are typically the same as those performed by a regular destructor. They are responsible for cleaning up any resources that were acquired during the object's lifetime, such as releasing memory, closing files, or freeing other system resources.

To summarize, classes that are intended to be used as base classes in inheritance hierarchies and have any resources to deallocate should have a virtual destructor. The virtual destructor ensures that the destructors of both the base class and derived class are called when deleting objects through a pointer to the base class, allowing proper cleanup of resources.
    */
}

void exercise_15_26() {
    /*
class Quote {
public:
    Quote() { std::cout << "Quote default constructor" << std::endl; }

    Quote(const Quote& other) { std::cout << "Quote copy constructor" << std::endl }

    Quote& operator=(const Quote& other) {
        std::cout << "Quote copy assignment operator" << std::endl;
        return *this;
    }

    ~Quote() { std::cout << "Quote destructor" << std::endl; }
};

class Bulk_quote : public Quote {
public:
    Bulk_quote() { std::cout << "Bulk_quote default constructor" << std::endl; }

    Bulk_quote(const Bulk_quote& other) : Quote(other) {
        std::cout << "Bulk_quote copy constructor" << std::endl;
    }

    Bulk_quote& operator=(const Bulk_quote& other) {
        Quote::operator=(other);
        std::cout << "Bulk_quote copy assignment operator" << std::endl;
        return *this;
    }

    ~Bulk_quote() { std::cout << "Bulk_quote destructor" << std::endl; }
};

int main() {
    cout << " --1-- " << endl;
    Quote q1;
    cout << " --2-- " << endl;
    Quote q2 = q1;
    cout << " --3-- " << endl;
    Quote q3;
    cout << " --4-- " << endl;
    q3 = q2;
    cout << " --5-- " << endl;
    Bulk_quote bq1;
    cout << " --6-- " << endl;
    Bulk_quote bq2 = bq1;
    cout << " --7-- " << endl;
    Bulk_quote bq3;
    cout << " --8-- " << endl;
    bq3 = bq2;
    cout << " --9-- " << endl;

    return 0;
}
*/
}

void exercise_15_27() {
    /*
class Quote {
public:
    Quote() {
        std::cout << "Quote default constructor" << std::endl;
    }

    Quote(const Quote& other) {
        std::cout << "Quote copy constructor" << std::endl;
    }

    Quote& operator=(const Quote& other) {
        std::cout << "Quote copy assignment operator" << std::endl;
        return *this;
    }

    ~Quote() {
        std::cout << "Quote destructor" << std::endl;
    }
};

class Bulk_quote : public Quote {
public:
    using Quote::Quote;  // Inheriting base class constructors

    ~Bulk_quote() {
        std::cout << "Bulk_quote destructor" << std::endl;
    }
};

int main() {
    cout << "--1--" << endl;
    Bulk_quote bq1;            // Calls Quote default constructor
    cout << "--2--" << endl;
    Bulk_quote bq2(bq1);       // Calls Quote copy constructor
    cout << "--3--" << endl;
    Bulk_quote bq3 = bq2;      // Calls Quote copy constructor
    cout << "--4--" << endl;
    bq3 = bq1;                 // Calls Quote copy assignment operator
    cout << "--5--" << endl;
    return 0;
}
*/
}

void exercise_15_28() {
    /*
class Quote {
public:
    virtual double net_price(std::size_t quantity) const = 0;
    virtual ~Quote() = default;
};

class Bulk_quote : public Quote {
public:
    double net_price(std::size_t quantity) const override {
        // Compute net price for Bulk_quote
        // Implementation omitted for brevity
    }
};

int main() {
    std::vector<std::shared_ptr<Quote>> quotes;
    
    // Adding Bulk_quote objects to the vector
    quotes.push_back(std::make_shared<Bulk_quote>());
    quotes.push_back(std::make_shared<Bulk_quote>());
    quotes.push_back(std::make_shared<Bulk_quote>());

    // Compute total net_price of all elements in the vector
    double totalNetPrice = 0.0;
    for (const auto& quote : quotes) {
        totalNetPrice += quote->net_price(1); // Assuming quantity = 1
    }

    std::cout << "Total net price: " << totalNetPrice << std::endl;

    return 0;
}
    */
}

void exercise_15_30() {
    /*
class Quote {
public:
    virtual Quote* clone() const & {return new Quote(*this);} 
    virtual Quote* clone() && {return new Quote(std::move(*this));}
}

class Bulk_quote : public Quote {
    Bulk_quote* clone() const & {return new Bulk_quote(*this);} 
    Bulk_quote* clone() && {return new Bulk_quote(std::move(*this));} 
};
class Basket {
public:
    void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }
    double total_receipt(std::ostream&) const;
    void add_item(const Quote& sale) { items.insert(std::shared_ptr<Quote>(sale.clone())); }
    void add_item(Quote&& sale); { items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));}

private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) { return lhs->isbn() < rhs->isbn(); }
    std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{compare};
};

double Basket::total_receipt(ostream &os) const {
    double sum = 0.0;
    for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
        sum += print_total(os, **iter, items.count(*iter));
}
os << "Total Sale: " << sum << endl; 
return sum;
}
*/
}

int main()
{
    return 0;
}
