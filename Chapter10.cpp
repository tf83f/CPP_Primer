#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>
#include <forward_list>
#include <algorithm>
#include <numeric>
#include <fstream>

using namespace std;

int exercise_10_3() {
    vector<int> vec = {1, 2, 3, 4};
    int sum = accumulate(vec.cbegin(), vec.cend(), 0);
    cout << sum;
    return 0;
}

int exercise_10_5() {
    /*
    f both rosters held C-style strings, rather than library strings, the call to equal would compare the pointers to the first elements of the two arrays, rather than the contents of the strings.

    In other words, the comparison would be a pointer comparison, not a string comparison. This means that even if the two C-style strings have the same characters, but are located in different memory locations, the equal function would return false.
    */
return 0;
}

int exercise_10_6(){
    vector<int> vec;
    fill_n(back_inserter(vec), 10, 0);
    for (auto i : vec) cout << i;
    return 0;
}

int exercise_10_7() {

    // There is an error in the program. The vec vector is created but its size is not set, so it has size 0. 
    // When copy is called to copy elements from lst to vec, it will try to write to elements that do not exist, leading to undefined behavior.
    vector<int> vec;
    list<int> lst;
    int i;
    while (cin >> i)
        lst.push_back(i);
    copy(lst.cbegin(), lst.cend(),back_inserter(vec));
    for (auto i : vec) cout << i;
    return 0;

    // There is no error in the program. 
    // The reserve function is used to pre-allocate memory for vec, which allows us to avoid unnecessary reallocations as we add elements to the vector. Then, fill_n is used to fill the first 10 elements of vec with zeros. 
    //This program will run correctly without any issues.

}

int exercise_10_8() {
    /*
    The claim that algorithms do not change the size of the containers over which they operate still holds when using back_inserter.

    back_inserter is a special iterator that provides a way to add elements to the end of a container, effectively changing the size of the container. 
    However, when an algorithm uses back_inserter, it is explicitly indicating that it intends to modify the size of the container, and the algorithm is designed to work correctly with this type of iterator.

    In other words, the algorithm itself does not change the size of the container, but instead delegates the responsibility of adding new elements to the back_inserter. 
    The use of back_inserter is a way of allowing algorithms to modify the size of the container while still maintaining the guarantee that the algorithm itself will not change the size of the container.

    */
   return 0;
}

void exercise_10_9(vector<string> &words)
{
    for (auto i : words) cout<< i << " ";
    cout << endl;

    sort(words.begin(), words.end());

    for (auto i : words) cout<< i << " ";
    cout << endl;

    auto end_unique = unique(words.begin(), words.end());

    for (auto i : words) cout<< i << " ";
    cout << endl;
    cout << words.size();
    cout << endl;

    words.erase(end_unique, words.end());
    
    for (auto i : words) cout<< i << " ";
    cout << endl;
    cout << words.size();
    cout << endl;
}

int exercise_10_13() {
    int sz = 5;
    std::vector<std::string> words = {"apple", "banana", "pear", "orange", "grape", "kiwi", "mango"};


    auto partitionIter = std::partition(words.begin(), words.end(), [sz] (const string &s) {return s.size()>= sz;});


    std::cout << "Words with five or more characters:\n";
    for (auto iter = words.begin(); iter != partitionIter; ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;

    std::cout << "Words with five or more characters:\n";
    for (auto iter = partitionIter; iter != words.end(); ++iter) {
        std::cout << *iter << " ";
    }
    std::cout << std::endl;
    
    return 0;
}

auto exercise_10_14 = [](int a, int b) { return a + b;};

void exercise_10_25() {
    /*
    using namespace std::placeholders;

    bool check_size(const string& s, string::size_type size) {
        return s.size() >= size;
    }

    void biggies(vector<string>&words, string::size_type size) {
        auto it = partition(words.begin(), words.end(), bind(check_size, _1, size));

        for (auto i = words.begin(); i != it; ++i) {
            cout << *i << " ";
        }
        cout << endl;

        for (auto i = it; i != words.end(); ++i) {
            cout << *i << " ";
        }
        cout << endl;
    }


    int main() {
        std::vector<std::string> words = {"apple", "banana", "pear", "orange", "grape", "kiwi", "mango"};

        sort(words.begin(), words.end());
        auto it = unique(words.begin(), words.end());
        words.erase(it, words.end());
        biggies(words, 5);

        return 0;
    }

    */
}

int exercise_10_27() {
    vector<int> vec = {1, 2, 2, 3, 4, 2, 8, 3};
    list<int> lst;
    unique_copy(vec.cbegin(), vec.cend(), back_inserter(lst));
    for (auto i : lst) cout << i << " ";
    cout << endl;
    return 0;
}

int exercise_10_29() {
std::ifstream infile("test.txt");
    std::vector<std::string> vec{std::istream_iterator<std::string>{infile},
                                 std::istream_iterator<std::string>{}};
    for (const auto& s : vec) {
        std::cout << s << std::endl;
    }
    return 0;
}

int exercise_10_31() {
    istream_iterator<int> in_iter(cin), eof;
    vector<int> vec(in_iter, eof);
    
    sort(vec.begin(), vec.end());

    ostream_iterator<int> out_iter(cout, " ");

    unique_copy(vec.begin(), vec.end(), out_iter);

    return 0;
}

int exercise_10_33(int argc, char *argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " input_file odd_output_file even_output_file\n";
        return 1;
    }

    std::ifstream infile(argv[1]);
    if (!infile) {
        std::cerr << "Error: could not open input file " << argv[1] << '\n';
        return 1;
    }

    std::ofstream oddfile(argv[2]);
    if (!oddfile) {
        std::cerr << "Error: could not open odd output file " << argv[2] << '\n';
        return 1;
    }

    std::ofstream evenfile(argv[3]);
    if (!evenfile) {
        std::cerr << "Error: could not open even output file " << argv[3] << '\n';
        return 1;
    }

    std::istream_iterator<int> in_iter(infile), eof;
    std::vector<int> vec(in_iter, eof);

    std::ostream_iterator<int> odd_iter(oddfile, " ");
    std::copy_if(vec.begin(), vec.end(), odd_iter, [](int i) { return i % 2 != 0; });

    std::ostream_iterator<int> even_iter(evenfile, "\n");
    std::copy_if(vec.begin(), vec.end(), even_iter, [](int i) { return i % 2 == 0; });

    return 0;
}

int exercise_10_35() {
    vector<int> vec = {1,2,3,4,5};
    for (auto r_iter = vec.crbegin(); r_iter != vec.crend(); ++r_iter) cout << *r_iter << " ";
    cout << endl;
    for (auto iter = prev(vec.cend()) ; iter != prev(vec.cbegin()); --iter) cout << *iter << " ";
    cout << endl;
    return 0;
}

int exercise_10_36() {
    std::list<int> lst = {1, 2, 10, 3, 4, 0, 5};
    auto it = std::find(lst.rbegin(), lst.rend(), 0);
    if (it != lst.rend()) {
        std::cout << "Last element with value 0 is: " << *it << std::endl;
    } else {
        std::cout << "No element with value 0 found." << std::endl;
    }

    return 0;
}

int exercise_10_37() {
    std::vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> l;

    auto v_it = v.begin() + 3;
    auto v_end = v.begin() + 8; 
    auto l_it = std::front_inserter(l);
    std::copy(v_it, v_end, l_it);

    for (auto i : l) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    return 0;
}

int main()
