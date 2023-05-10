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
using namespace std;

void exercise_11_1() {
    /*
    A vector is an ordered collection of elements that are stored in contiguous memory locations. 
    Each element in a vector can be accessed by its index, which is a non-negative integer that identifies the position of the element in the vector. 
    Vectors are commonly used to store a sequence of elements, such as a list of numbers or strings.

    On the other hand, a map (also known as a dictionary or associative array) is an unordered collection of key-value pairs. 
    Each key in a map is unique and associated with a value. Maps are commonly used to store a set of key-value pairs that can be accessed by their key. 
    Unlike a vector, the elements in a map are not stored in contiguous memory locations, and they cannot be accessed by an index.
    */
}

void exercise_11_2() {
    /*
    List: A list is a useful data structure when you need to store an ordered collection of elements, and you may need to add or remove elements from either end of the list. 
    For example, a to-do list where new tasks can be added to the end and completed tasks can be removed from the beginning.
    
    Vector: A vector is useful when you need to store an ordered collection of elements and you need to access them randomly. 
    Vectors provide fast random access and are useful for operations that require efficient traversal of the elements. 
    For example, storing a large set of numerical data where you need to perform mathematical operations on individual elements.

    Deque: A deque (double-ended queue) is useful when you need to store a collection of elements that can be added or removed from either end. 
    Deques are similar to lists but are more efficient when elements need to be added or removed frequently from both ends. 
    For example, a buffer of incoming data where elements are added at the front and removed from the back as they are processed.

    Map: A map (also known as a dictionary or associative array) is useful when you need to store a collection of key-value pairs, and you need to access them by their key. 
    Maps provide fast key-based lookup and are useful for storing data that can be accessed efficiently by their associated key. For example, storing a database of user profiles where each user is identified by their unique username.

    Set: A set is useful when you need to store a collection of elements where each element is unique. Sets provide fast membership testing and are useful for removing duplicates or finding the intersection, union, or difference of two sets. 
    For example, keeping track of unique visitors to a website or identifying the common interests of a group of people.
    */
}

void exercise_11_6() {
    /*
    A set and a list are both data structures used to store collections of elements, but they differ in their structure and the way elements are stored.

    A list is an ordered collection of elements that can contain duplicates. Elements in a list are accessed by their index, which is a non-negative integer that identifies the position of the element in the list. Lists are useful when you need to maintain the order of elements and allow duplicates. For example, a list of names in alphabetical order, or a list of products with multiple instances of the same product.

    A set, on the other hand, is an unordered collection of unique elements. Elements in a set are not accessed by their index, but rather are looked up based on their value. Sets are useful when you need to ensure that each element is unique and when you need to perform set-based operations such as union, intersection, or difference. For example, a set of unique email addresses, or a set of tags associated with a blog post.

    In summary, lists are used to store an ordered collection of elements that may contain duplicates, while sets are used to store an unordered collection of unique elements.

    When deciding between a list and a set, consider the structure of your data and the operations you need to perform on it. If the order of elements matters and you allow duplicates, use a list. If uniqueness is important and you need to perform set-based operations, use a set.
*/
}

int exercise_11_8() {
    /*
    The advantage of using a set instead of a vector to store excluded words is that set operations, such as searching for a word or checking if a word is excluded, are typically faster with sets. 
    This is because sets are implemented as a binary search tree or a hash table, which allows for faster lookup times compared to a linear search through a vector. 
    Additionally, sets automatically ensure that there are no duplicate elements, whereas vectors can contain duplicates unless explicitly checked and removed. However, if the list of excluded words is small, the performance difference between a vector and a set may not be noticeable, and a vector may be more convenient to work with.
    */
   vector <string> excluded = {"the", "and", "or", "but", "not"};
   string word;

   while (cin >> word) {
        bool isEcluded = false;
        for (const auto& ex : excluded) {
            if (word == ex) {
                isEcluded = true;
                break; }
        }

        if (!isEcluded) cout << word << " ";
   }
    return 0;
}

int exercise_11_9() {
map<string, vector<int>> wordMap;
    string word;
    int lineNum = 0;


    while (getline(cin, word)) {
        ++lineNum;
        size_t pos = 0;
        while ((pos = word.find_first_not_of(" ", pos)) != string::npos) {

            size_t endPos = word.find_first_of(" ", pos);
            if (endPos == string::npos) {
                endPos = word.length();
            }

            string w = word.substr(pos, endPos - pos);
            wordMap[w].push_back(lineNum);

            pos = word.find_first_not_of(" ", endPos);
        }
    }


    for (const auto& p : wordMap) {
        cout << p.first << ": ";
        for (const auto& line : p.second) {
            cout << line << " ";
        }
        cout << endl;
    }

    return 0;
}

void exercise_11_10() {
    /*
    We cannot define a map from vector<int>::iterator to int or from list<int>::iterator to int. 
    The reason is that iterators are not guaranteed to be stable or unique over time, even for the same container.

    When a container is modified, such as by inserting or erasing elements, iterators to elements in the container can become invalid or refer to different elements. 
    Therefore, attempting to use an invalid or incorrect iterator as a key in a map can result in undefined behavior.

    To safely use a map with a container's elements, it is recommended to use the element values themselves as the map keys instead of the iterators. 
    For example, in the case of vector<int> or list<int>, we could define a map from int to vector<int>::iterator or list<int>::iterator, respectively. 
    This way, we can use the element value to look up the iterator, which will always be unique for a given value, rather than trying to use the iterator itself as a key.
    */
}

int exercise_11_13() {
    vector<pair<string, int>> pairs;
    string str;
    int num;
    while (cin >> str >> num) { 
       pairs.emplace_back( make_pair(str, num) );
        // pairs.emplace_back( pair<string, int>{str, num} ); 
        // pairs.emplace_back( str, num );   

        }
    for (const auto& p : pairs) { cout << "(" << p.first << ", " << p.second << ")" << endl;}
    return 0;

}

void exercise_11_15() {
    /*

    For a map from int to vector<int>, the mapped_type is vector<int>, the key_type is int, and the value_type is std::pair<const int, vector<int>>.

    The mapped_type is the type of the value associated with each key in the map. 
    In this case, each key is an int and each value is a vector<int>.

    The key_type is the type of the keys in the map. In this case, the keys are int.

    The value_type is the type of each element in the map. 
    It is a std::pair of the key_type and the mapped_type, where the first element of the pair is a const version of the key type (because keys in a map are immutable), and the second element of the pair is the mapped type.
    */
}

void exercise_11_17() {
    /*
    copy(v.begin(), v.end(), inserter(c, c.end())): This call is legal. 
    It uses the inserter iterator adaptor to insert each element in the range [v.begin(), v.end()) into the multiset c. 
    The inserter adaptor takes a container c and an iterator i, and returns an iterator that inserts elements into c at the position indicated by i. 
    In this case, we use c.end() as the iterator i, which inserts elements at the end of the multiset.

    copy(v.begin(), v.end(), back_inserter(c)): This call is legal. 
    It uses the back_inserter iterator adaptor to insert each element in the range [v.begin(), v.end()) into the multiset c. 
    The back_inserter adaptor takes a container c and returns an iterator that appends elements to c by calling c.push_back().

    copy(c.begin(), c.end(), inserter(v, v.end())): This call is legal. 
    It uses the inserter iterator adaptor to insert each element in the multiset c into the vector v. 
    The inserter adaptor takes a container v and an iterator i, and returns an iterator that inserts elements into v at the position indicated by i. 
    In this case, we use v.end() as the iterator i, which inserts elements at the end of the vector.

    copy(c.begin(), c.end(), back_inserter(v)): This call is legal. 
    It uses the back_inserter iterator adaptor to append each element in the multiset c to the vector v. 
    The back_inserter adaptor takes a container v and returns an iterator that appends elements to v by calling v.push_back(). 
    Note that this call appends the elements from c to the end of v, so it does not preserve the order of the elements in c.
*/
}

int exercise_11_23() {
    std::multimap<std::string, std::pair<std::string, std::string>> families;

    families.insert({"Smith", {"John", "2001-01-01"}});
    families.insert({"Smith", {"Jane", "2003-05-12"}});
    families.insert({"Jones", {"Bob", "1999-03-15"}});
    families.insert({"Jones", {"Tom", "2002-12-22"}});
    families.insert({"Johnson", {"Linda", "1998-11-02"}});

    for (auto it = families.begin(); it != families.end(); ++it) {
        std::cout << it->first << ": " << it->second.first << " (" << it->second.second << ")" << std::endl;
    }

    return 0;
}

int main() {
    return 0;
}
