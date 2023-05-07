#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
using namespace std;

int exercise_9_1() {
    /*
    Which is the most appropriate—a vector, a deque, or a list—for the following program tasks? Explain the rationale for your choice. If there is no reason to prefer one or another container, explain why not.
    (a) Read a fixed number of words, inserting them in the container alphabetically as they are entered. 

    A list would be the most appropriate container for this task because it allows constant time insertions and doesn't require elements to be moved around when new elements are inserted. 
    Also, since the words are being inserted alphabetically, a list would make it easier to maintain the order.
    
    (b) Read an unknown number of words. Always insert new words at the back. Remove the next value from the front.
    
    A deque would be the most appropriate container for this task. 
    Deques allow efficient insertion and deletion at both the front and back of the container, and also provide direct access to elements. 
    Since we always insert new words at the back and remove the next value from the front, a deque would be a good choice.
    
    (c) Read an unknown number of integers from a file. Sort the numbers and then print them to standard output.

    A vector would be the most appropriate container for this task. Vectors provide direct access to elements and support random access iterators, which are needed for sorting. 
    Since we are reading an unknown number of integers from a file, we cannot predict how much space we need in advance. 
    Vectors are also efficient for sorting, since they provide contiguous memory storage.
    */
   return 0;
}

int exercise_9_2() {
    
    std::list<std::deque<int>> list_of_deques;
    std::deque<int> deque1 = {1, 2, 3};
    std::deque<int> deque2 = {4, 5, 6};
    std::deque<int> deque3 = {7, 8, 9};
    list_of_deques.push_back(deque1);
    list_of_deques.push_back(deque2);
    list_of_deques.push_back(deque3);
    for (const auto& deque : list_of_deques) {
        for (const auto& element : deque) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
    return 0;


}

bool exercise_9_4(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value) {
    /*
    Write a function that takes a pair of iterators to a vector<int> and an int value. 
    Look for that value in the range and return a bool indicating whether it was found.
    */
   for (auto iter = begin; iter != end; ++iter)
   {
        if (*iter == value) return true;
   }
   return false;
}

vector<int>::const_iterator exercise_9_5(vector<int>::const_iterator begin, vector<int>::const_iterator end, int value) {
    auto it = begin;
    while (it != end && *it != value) {
        ++it;
    }
    return it;
}

bool exercise_9_15(vector<int> v1, vector<int> v2) 
{
    if (v1.size() != v2.size()) return false;

    for (int i = 0; i < v1.size(); i++) 
        if (v1[i] != v2[i]) return false;
    
    return true;
}

bool exercise_9_16(list<int> lst, vector<int> v) 
{
    if (lst.size() != v.size()) return false;
    auto lit = lst.begin();
    for (auto vit = v.begin(); vit != v.end(); vit++, lit++) {
        if (*lit != *vit) return false;
    }
    return true;
}

int exercise_9_21() {
    /*
    Explain how the loop from page 345 that used the return from insert to add elements to a list would work if we inserted into a vector instead.

    If we were to use a vector<string> instead of a list<string>, the insert function would still work in the same way, but the performance characteristics would be different.

    Since vector is a contiguous container, inserting elements in the middle requires shifting all elements that come after the insertion point, which can be expensive if the vector is large. 
    In contrast, list is a linked list container, and inserting elements into the middle of the list only requires updating the links between the elements, which is a much cheaper operation.

    Therefore, while the loop would still work correctly with a vector<string>, it would be less efficient than using a list<string> for this particular operation. 
    Additionally, the order in which elements are inserted may affect the performance of subsequent operations, since inserting elements in the middle of a vector can cause reallocations, which can be expensive.
    */
   return 0;
}

int exercise_9_26() {
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
    vector<int> v(begin(ia), end(ia));
    list<int> l(begin(ia), end(ia));

    auto vit = v.begin();
    while (vit != v.end()) {
        if (*vit % 2 == 0) vit = v.erase(vit);
        else ++vit;
    }
    auto lit = l.begin();
    while (lit != l.end()) {
        if (*lit % 2 != 0) lit = l.erase(lit);
        else ++lit;
    }

    cout << "vector: ";
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    cout << "list:   ";
    for (auto i : l) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}

int exercise_9_27(forward_list<int> &flst) {
    auto prev = flst.before_begin();
    auto curr = flst.begin();
    while (curr != flst.end()) {
        if (*curr % 2) curr = flst.erase_after(prev);
        else prev = curr, ++curr;
    }
    for (auto i : flst) cout << i <<" ";
    return 0;
}

void exercise_9_28(forward_list<string>& flist, const string& s1, const string& s2) {
    auto prev = flist.before_begin();
    auto curr = flist.begin();

    while (curr != flist.end()) {
        if (*curr == s1) {
            flist.insert_after(curr, s2);
            return;
        } else {
            prev = curr;
            ++curr;
        }
    }

    flist.insert_after(prev, s2);
}

int exercise_9_41()
{
    std::vector<char> chars = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'w', 'o', 'r', 'l', 'd', '!'};
    std::string str(chars.begin(), chars.end());
    std::cout << str << std::endl;
    return 0;

}

int exercise_9_47() {
    string s = "ab2c3d7R4E6";
    string numbers = "0123456789";
    string::size_type pos = 0;
    while ((pos = s.find_first_of(numbers, pos)) != string::npos) {
        cout << "Numeric character found at position: " << pos << " - " << s[pos] << endl;
        ++pos;
    }
    
    string letters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    pos = 0;
    while ((pos = s.find_first_of(letters, pos)) != string::npos) {
        cout << "Alphabetic character found at position: " << pos << " - " << s[pos] << endl;
        ++pos;
    }

    pos = 0;
    while ((pos = s.find_first_not_of(numbers, pos)) != string::npos) {
        cout << "Alphabetic character found at position: " << pos << " - " << s[pos] << endl;
        ++pos;
    }
    
    pos = 0;
    while ((pos = s.find_first_not_of(letters, pos)) != string::npos) {
        cout << "Numeric character found at position: " << pos << " - " << s[pos] << endl;
        ++pos;
    }
    
    return 0;
}

int main() {
    return 0;
}
