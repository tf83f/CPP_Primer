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

void exercise_12_1() {
    /*
    At the end of this code, both b1 and b2 will have 4 elements because they are sharing the same sequence of strings in memory.

    Here's what happens step by step:

    b1 is initialized as an empty StrBlob object.
    b2 is initialized with an initializer list containing three strings: "a", "an", and "the". b2 now has three elements.
    b1 is assigned the value of b2, which means they now refer to the same underlying sequence of strings.
    The push_back() function is called on b2 to add the string "about" to the end of its sequence. The push_back() function modifies the sequence in place, so both b1 and b2 now have four elements: "a", "an", "the", and "about".
*/
}

void exercise_12_3() {
    /*
    The push_back() and pop_back() member functions of the StrBlob class do modify the underlying data of the StrBlob, so const versions of these functions are not needed.

    The push_back() function adds a new element to the end of the StrBlob, while the pop_back() function removes the last element from the StrBlob. Both of these operations change the state of the StrBlob object, so they cannot be const member functions.

    Therefore, we do not need const versions of push_back() and pop_back() for the StrBlob class.
    */
}

void exercise_12_4() {
    /*
    In the check function, we only need to check whether i is less than the size of the vector because the vector index starts from 0. If i is greater than or equal to the size of the vector, then it is out of bounds and we throw an std::out_of_range exception.

    We don't need to check whether i is greater than zero because the index of the first element in the vector is 0, and i is already guaranteed to be less than the size of the vector by the check for out-of-bounds access. If i is less than zero, then the behavior is undefined and the program may crash or behave unpredictably.

    Therefore, it is not necessary to check whether i is greater than zero in the check function.
    */
}

void exercise_12_5() {
    /*
    The decision of whether to make the constructor that takes an initializer list explicit depends on the design and usage of the class.

    Making the constructor explicit would prevent implicit conversions from an initializer list to a StrBlob object. This can help to prevent unintended conversions that may lead to errors and make the code more explicit and less error-prone. Explicit conversion also makes the code more self-documenting and improves readability.

    On the other hand, if the class is designed to be used with initializer lists frequently, then making the constructor explicit can make the code less concise and harder to read. In this case, the implicit conversion can make the code more convenient and easier to use.

    In summary, making the constructor that takes an initializer list explicit can help prevent unintended conversions and make the code more explicit and readable. However, it can also make the code less concise and harder to use in some cases. The decision of whether to make the constructor explicit depends on the design and usage of the class.
    */
}

void exercise_12_6() {
    /*
    vector<int>* create_vector() {
        return new vector<int>();
    }
    void read_input(vector<int>* vec) {
        int val;
        while (cin >> val) vec->push_back(val);
    }
    void print_vector(const vector<int>* vec) {
        for (auto it = vec->cbegin(); it != vec->cend(); ++it) { cout << *it << " ";}
    }
    int main() {
        vector<int> *vec = create_vector();
        read_input(vec);
        print_vector(vec);
        delete vec;
        return 0;
    }
    */
}

void exercise_12_7() {
    /*
    shared_ptr<vector<int>> create_vector() {
        return make_shared<vector<int>>();
    }
    void read_input(shared_ptr<vector<int>> vec) {
        int val;
        while (cin >> val) vec->push_back(val);
    }
    void print_vector(const shared_ptr<vector<int>>& vec) {
        for (auto it = vec->cbegin(); it != vec->cend(); ++it) { cout << *it << " ";}
    }
    int main() {
        auto vec = create_vector();
        read_input(vec);
        print_vector(vec);
    
        return 0;
    }
    */
}

void exercise_12_9() {
    /*

    In the first line, we allocate a new int on the heap and initialize it to the value 42, and store the pointer to that memory in the variable q. In the second line, we allocate another int on the heap and initialize it to the value 100, and store the pointer to that memory in the variable r. At this point, q and r point to two separate blocks of memory on the heap.

    In the third line, we assign the value of q to r. This means that the address of the memory block allocated for 42 is now stored in both q and r. Since we did not save the address of the memory block allocated for 100, we have lost the ability to deallocate that block, which can lead to a memory leak.

    In the fourth line, we allocate a new int on the heap and initialize it to the value 42, and create a std::shared_ptr that points to that memory. In the fifth line, we allocate another int on the heap and initialize it to the value 100, and create another std::shared_ptr that points to that memory. At this point, q2 and r2 point to two separate blocks of memory on the heap.

    In the sixth line, we assign the value of q2 to r2. This means that both q2 and r2 now point to the same block of memory on the heap, which contains the value 42. The std::shared_ptr that previously pointed to the memory block containing the value 100 is no longer referenced, so it will be deallocated automatically by the std::shared_ptr class, if there are no other references to it.
    */
}

void exercise_12_10() {
    /*
    The call to process is not correct. The reason is that shared_ptr<int>(p) creates a temporary shared_ptr object that points to the same memory block as p, but it is not stored anywhere. When the temporary shared_ptr goes out of scope at the end of the statement, it will be destroyed and will delete the memory block it points to. Then, when process tries to access that memory block through the shared_ptr passed to it, the behavior will be undefined.

    To correct the call, we can simply pass p itself to process, without creating a temporary shared_ptr object. Here's the corrected call:

    process(p);

    This call passes the shared_ptr object p by value to process, which will increment the reference count of the shared ownership group that manages the memory block pointed to by p. When p goes out of scope, the reference count will be decremented, and the memory block will be deleted only when the reference count reaches zero.
    */
}

void exercise_12_11() {
    /*
    If we called process as follows then a new temporary shared_ptr object would be created using the get member function of the shared_ptr p. The get member function returns a raw pointer to the object managed by p.

    However, this is not safe. The reason is that the shared_ptr constructor takes ownership of the pointer that is passed to it. In this case, the temporary shared_ptr object does not take ownership of the memory block pointed to by p.get(). Instead, when the temporary shared_ptr object is destroyed, it will try to delete the memory block pointed to by p.get(), but this is incorrect because the memory block is already being managed by p.

    This double deletion of the same memory block can cause undefined behavior, which can manifest in various ways, including crashes or memory corruption. Therefore, we should not pass a raw pointer to a shared_ptr constructor or to any function that expects a shared_ptr. Instead, we should pass the shared_ptr object itself or a reference to it, as shown in the previous exercise.
    */
}

void exercise_12_12() {
    /*
    (a) The call process(sp) is legal. It passes a shared_ptr object sp to the function process by value. This will increment the reference count of the shared ownership group that manages the memory block pointed to by sp. When process returns, the reference count of the ownership group will be decremented, and if it reaches zero, the memory block will be deleted.

    (b) The call process(new int()) is illegal because it creates a raw pointer to a dynamically allocated int, which is not managed by a shared_ptr. When the process function returns, there will be no way to free the memory allocated by the new expression, leading to a memory leak.

    (c) The call process(p) is illegal because p is a raw pointer, not a shared_ptr. The function process takes a shared_ptr by value, so it will create a new shared_ptr object that takes ownership of the memory block pointed to by p. However, this will result in two shared_ptr objects owning the same memory block, which can cause undefined behavior when they are destroyed.

    (d) The call process(shared_ptr<int>(p)) is legal but it is not safe. It creates a temporary shared_ptr object that takes ownership of the memory block pointed to by p. However, since p is already pointing to a dynamically allocated int, it is likely that p will be deleted before the temporary shared_ptr object is destroyed. This can lead to a dangling pointer, which can cause undefined behavior when the temporary shared_ptr object is destroyed.
    */
}

void exercise_12_13() {
    /*
    Executing the following code is undefined behavior because the shared_ptr sp and the raw pointer p both point to the same dynamically allocated object of type int. The shared_ptr object sp manages the memory of the object while the raw pointer p points to the same memory location. Deleting p will deallocate the memory, which is already managed by sp. When sp goes out of scope and tries to delete the memory block, it will result in a double free, leading to undefined behavior.

    Therefore, it is important to use shared_ptr objects properly and not mix them with raw pointers. When using shared_ptr, we should always let the shared_ptr objects manage the memory and not use raw pointers to delete them.
    */
}

void exercise_12_14() {
    /*
    struct Connection {

    void connect() { std::cout << "Connected to remote host.\n"; }
    void close() { std::cout << "Connection closed.\n"; }
    };

    void process_connection(std::shared_ptr<Connection> conn) {
        conn->connect();
        // ...
        conn->close();
    }

    int main() {

        auto conn_ptr = std::make_shared<Connection>();

        process_connection(conn_ptr);

        return 0;
    }
    */
}

void exercise_12_15() {
    /*
    using Connection = struct {
    void close() { std::cout << "Connection closed.\n"; }
    };

    using ConnectionPtr = std::shared_ptr<Connection>;

    void process(ConnectionPtr p) {
        std::cout << "Processing connection...\n";
        // Use a lambda to define the end_connection behavior
        auto end_connection = [p]() { p->close(); };
        // ...
        std::cout << "Connection processing complete.\n";
        end_connection();
    }

    int main() {
        auto p = std::make_shared<Connection>();
        process(p);
        return 0;
    }
    */
}

void exercise_12_17() {
    /*
    (a) IntP p0(ix); is illegal because ix is an int object, and unique_ptr cannot take ownership of a regular pointer or an object that was not allocated using new. This will result in a compile-time error.

    (b) IntP p1(pi); is illegal because pi is a regular pointer, not a pointer to an object allocated using new. Therefore, unique_ptr cannot take ownership of it. This will result in a compile-time error.

    (c) IntP p2(pi2); is legal because pi2 is a pointer to an object allocated using new. However, we should be careful when using unique_ptr to take ownership of an object that was allocated by someone else (in this case, using new directly). We should ensure that the unique_ptr object is the only owner of the dynamically allocated object.

    (d) IntP p3(&ix); is illegal because &ix is the address of a regular object, not a pointer to an object allocated using new. This will result in a compile-time error.

    (e) IntP p4(new int(2048)); is legal and correct because new int(2048) allocates a new object of type int on the heap and returns a pointer to it, which is then passed to the constructor of the unique_ptr object.

    (f) IntP p5(p2.get()); is legal, but it is potentially dangerous. This constructor takes a raw pointer as an argument and constructs a new unique_ptr object that takes ownership of the pointed-to object. However, p2 still owns the object and will eventually delete it when it goes out of scope. This will result in a double delete, which is a serious runtime error.
    */
}

int exercise_12_23() {
    const char* str1 = "Hello, ";
    const char* str2 = "world!";
    size_t size = strlen(str1) + strlen(str2) + 1;
    char* dynArr = new char[size];
    strcpy(dynArr, str1);
    strcat(dynArr, str2);
    cout<< dynArr << endl;
    delete[] dynArr;

    string s1 = "Hello, ";
    string s2 = "world!";
    string s3 = s1 + s2;
    cout << s3 << endl;
    return 0;
}

int exercise_12_24() {
    cout << "Enter a string: ";
    string input;
    getline(cin, input);
    char *str = new char[input.size() + 1];
    strcpy(str, input.c_str());
    cout << "The input string is: " << str << endl;
    delete[] str;
    return 0;
}

int exercise_12_26() {
    std::allocator<std::string> alloc;
    auto const p = alloc.allocate(3);
    auto q = p;
    alloc.construct(q++, "hello");
    alloc.construct(q++, "world");
    alloc.construct(q++, "!");
    std::for_each(p, q, [](const std::string &s) { std::cout << s << std::endl; });
    while (q != p)
        alloc.destroy(--q);
    alloc.deallocate(p, 3);
    return 0;
}

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <memory>

using namespace std;

class QueryResult;

class TextQuery {
public:
    using line_no = vector<string>::size_type;

    TextQuery(ifstream&);
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<line_no>>> wm;
};

TextQuery::TextQuery(ifstream &is) : file(new vector<string>) {
    string text;
    while (getline(is, text)) {
        file->push_back(text);
        int n = file->size() - 1;
        istringstream line(text);
        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<line_no>);
            lines->insert(n);
        }
    }
}

class QueryResult {
friend ostream& print(ostream&, const QueryResult&);

public:
    using line_no = TextQuery::line_no;
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f)
        : sought(s), lines(p), file(f) { }

private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};

QueryResult TextQuery::query(const string &sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

ostream &print(ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " times" << endl;
    for (auto num : *qr.lines)
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    return os;
}

void runQueries(ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        cout << "Enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}
int main() {
    ifstream infile("test.txt");
    runQueries(infile);
    return 0;
}
