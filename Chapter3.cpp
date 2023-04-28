#include <iostream>
#include <string>
#include "cctype"
#include <vector>

using namespace std;

int exercise_3_4() {
    string s1, s2;
    cout << "Enter two strings :" << endl;
    cin >> s1 >> s2;
    if  (s1 == s2) { 
        cout << "The strings are equal" << endl;
    } else { 
        string larger_string = (s1 > s2) ? s1 : s2;
        cout << "The larger string is : " << larger_string << endl;

    }
    if  (s1.size() == s2.size()) { 
        cout << "The string are of equal size " << endl;
    } else { 
        string larger_size = (s1.size() > s2.size()) ? s1 : s2;
        cout << "The string with the larger size is :" << larger_size << endl;
    }
    return 0;
}

int exercise_3_5() {
    string s1, s2, s3;
    cout << "Enter strings :" << endl;
    while(cin >> s1) {
        s2 += s1;
        s3 += s1 + " ";
    }
    cout << "Without space : " << s2 << endl;
    s3.pop_back();
    cout << "With space : " << s3 << endl; 
    return 0;
}

int exercise_3_6() {
    string s("Hello World!");
    for (auto& c : s) {
        c = 'X';
    }
    cout << s << endl;
    return 0;
}

int exercise_3_7() {
    // In the previous exercise, we used a range for loop to change all the characters in a string to "X". 
    // We declared the loop control variable using the auto keyword, which causes the type to be inferred as a reference to a char in this case.
    // If we declare the loop control variable explicitly as type char instead of using auto, the loop would make a copy of each character in the string, rather than modifying the original characters in the string. 
    // This is because a char type is not a reference type, so changes made to it inside the loop would not affect the original characters in the string.

    string s("Hello World!");
    for (char c : s) {
        c = 'X';
    }
    cout << s << endl;
    return 0;

}

int exercise_3_8() {
    string s("Hello World!");
    decltype(s.size()) index = 0;
    while(index < s.size()) s[index] = 'x', ++index; 
    cout << s << endl;
    return 0;
}

int exercise_3_10() {
    string input, output;
    getline(cin, input);
    for (auto c : input) if(!ispunct(c)) output += c;
    cout << output << endl;
    return 0;
}

int exercise_3_13() {
    /* 
    How many elements are there in each of the following vectors? What are the values of the elements?
    (a) vector<int> v1; This vector is empty, i.e., it has no elements.

    (b) vector<int> v2(10);  This vector has 10 elements, and each element has an initial value of 0.

    (c) vector<int> v3(10, 42); This vector has 10 elements, and each element has the value of 42.

    (d) vector<int> v4{10}; This vector has 1 element, which is the integer 10.
    
    (e) vector<int> v5{10, 42}; This vector has 2 elements, and their values are 10 and 42, respectively.

    (f) vector<string> v6{10}; This vector has 10 elements, and each element is initialized to the empty string.

    (g) vector<string> v7{10, "hi"}; This vector has 10 elements, and each element is initialized to the string "hi".
    */
    return 0;
}

int exercise_3_16() {

    vector<int> v1; // This vector is empty, i.e., it has no elements.
    vector<int> v2(10);  // This vector has 10 elements, and each element has an initial value of 0.
    vector<int> v3(10, 42); // This vector has 10 elements, and each element has the value of 42.
    vector<int> v4{10}; // This vector has 1 element, which is the integer 10.
    vector<int> v5{10, 42}; // This vector has 2 elements, and their values are 10 and 42, respectively.
    vector<string> v6{10}; // This vector has 10 elements, and each element is initialized to the empty string.
    vector<string> v7{10, "hi"}; // This vector has 10 elements, and each element is initialized to the string "hi".
    
    cout << "The vector has " << v1.size() << " elements: ";
    for (auto &i : v1) cout << i << " ";
    cout << endl;

    cout << "The vector has " << v2.size() << " elements: ";
    for (auto &i : v2) cout << i << " ";
    cout << endl;

    cout << "The vector has " << v3.size() << " elements: ";
    for (auto &i : v3) cout << i << " ";
    cout << endl;

    cout << "The vector has " << v4.size() << " elements: ";
    for (auto &i : v4) cout << i << " ";
    cout << endl;

    cout << "The vector has " << v5.size() << " elements: ";
    for (auto &i : v5) cout << i << " ";
    cout << endl;

    cout << "The vector has " << v6.size() << " elements: ";
    for (auto &i : v6) cout << i << " ";
    cout << endl;

    cout << "The vector has " << v7.size() << " elements: ";
    for (auto &i : v7) cout << i << " ";
    cout << endl;

    return 0;
    
}

int exercise_3_17() {
    vector<string> words;
    string word; 
    while (cin >> word) words.push_back(word);
    const int wordsPerLine = 8;
    int count = 0;
    for (auto &w : words) {
        for (auto &c : w) c = toupper(c);
        cout << w << "  ";
        if (++count % wordsPerLine == 0) cout << endl;
    } 
    return 0;
}

int exercise_3_18() {
    /*
    Is the following program legal? If not, how might you fix it? vector<int> ivec;
    ivec[0] = 42;

    The following program is not legal because it tries to access an element of the vector that does not exist. 
    In other words, the vector is empty, and there is no element at position 0 to assign the value 42.
    To fix it, you could add an element to the vector using the push_back() method, which adds a new element to the end of the vector:

    vector<int> ivec;
    ivec.push_back(42); 

    This will add the value 42 to the vector at position 0. 
    
    Alternatively, you could also use the resize() method to set the size of the vector and then assign a value to the element at position 0:

    vector<int> ivec;
    ivec.resize(1);
    ivec[0] = 42;

    This will resize the vector to have a size of 1, and then assign the value 42 to the element at position 0.

    */
    return 0;
}

int exercise_3_19()  {
    /*
    List three ways to define a vector and give it ten elements, each with the value 42.
    
    Using the vector constructor: 
        vector<int> ivec(10, 42);

    Using the assign() method:
        vector<int> ivec;
        ivec.assign(10, 42);

    Using a for loop and the push_back() method:
        vector<int> ivec;
            for (int i = 0; i < 10; i++) {
                ivec.push_back(42);
            }
    */
   return 0;

}

int exercise_3_20() {
    vector<int> vec;
    int input;
    while (cin >> input) vec.push_back(input);
    for (decltype(vec.size()) index = 0; index < vec.size() - 1; ++index) cout << vec[index] + vec[index + 1] << " ";
    cout << endl;
    for (decltype(vec.size()) index = 0; index < vec.size() / 2; ++index) cout << vec[index] + vec[vec.size() - index - 1] << " ";
    cout << endl; 
    return  0;
}

int exercise_3_21() {

    vector<int> v1; // This vector is empty, i.e., it has no elements.
    vector<int> v2(10);  // This vector has 10 elements, and each element has an initial value of 0.
    vector<int> v3(10, 42); // This vector has 10 elements, and each element has the value of 42.
    vector<int> v4{10}; // This vector has 1 element, which is the integer 10.
    vector<int> v5{10, 42}; // This vector has 2 elements, and their values are 10 and 42, respectively.
    vector<string> v6{10}; // This vector has 10 elements, and each element is initialized to the empty string.
    vector<string> v7{10, "hi"}; // This vector has 10 elements, and each element is initialized to the string "hi".
    
    int count = 0;

    for (auto it = v1.cbegin(); it != v1.cend(); ++it) ++count;
    cout << "The vector has " << count << " elements." << endl;
    count = 0;

    for (auto it = v2.cbegin(); it != v2.cend(); ++it) ++count;
    cout << "The vector has " << count << " elements." << endl;
    count = 0;

    for (auto it = v3.cbegin(); it != v3.cend(); ++it) ++count;
    cout << "The vector has " << count << " elements." << endl;
    count = 0;
    
    for (auto it = v4.cbegin(); it != v4.cend(); ++it) ++count;
    cout << "The vector has " << count << " elements." << endl;
    count = 0;

    for (auto it = v5.cbegin(); it != v5.cend(); ++it) ++count;
    cout << "The vector has " << count << " elements." << endl;
    count = 0;
    
    for (auto it = v6.cbegin(); it != v6.cend(); ++it) ++count;
    cout << "The vector has " << count << " elements." << endl;
    count = 0;

    for (auto it = v7.cbegin(); it != v7.cend(); ++it) ++count;
    cout << "The vector has " << count << " elements." << endl;
    count = 0;

    return 0;
    
}

int exercise_3_22() {
    vector<string> text;
    string line; 
    while (getline(cin, line)) text.push_back(line);
    auto it = text.begin();
    while(it != text.end() && !it->empty()) {
        for (auto &c : *it) c = toupper(c);
        ++it;
    }
    for (auto line : text) { cout << line << endl;}
    return 0;

}

int exercise_3_23() {
    vector<int> vec ={0,1,2,3,4,5,6,7,8,9};
    for (auto it = vec.begin(); it != vec.end(); ++it) *it *= 2;
    for (auto el : vec) cout << el << " ";
    return 0;
}

int exercise_3_24() {
    vector<int> vec ={0,1,2,3,4,5,6,7,8,9};
    for (auto it = vec.begin(); it != vec.end() - 1; ++it) { cout << *it + *(it + 1) << " "; }
    cout << endl;
     for (auto it1 = vec.begin(), it2 = vec.end() - 1; it1 < it2; ++it1, --it2) { cout << *it1 + *it2 << " ";}
    cout << endl;
    return 0;
}

int exercise_3_25() {
    vector<unsigned> scores(11,0);
    unsigned grade;
    while(cin >> grade) {
        if (grade <= 100) {
            auto it = scores.begin() + grade/10;
            ++(*it);
        }
    }
    for (auto it = scores.cbegin(); it != scores.cend(); ++it) {
        cout << *it << " ";
    }
    return 0;
}

int exercise_3_26() {
    /*
    We wrote mid = beg + (end - beg) / 2; instead of mid = (beg + end) / 2; in the binary search program on page 112 to prevent integer overflow.

    When we compute (beg + end) / 2 to find the middle index of the current range, there is a risk of integer overflow if beg and end are large enough. 
    If the sum of beg and end exceeds the maximum value that can be represented by an integer, the result will wrap around and become negative, which can lead to undefined behavior.

    To avoid this problem, we use the expression beg + (end - beg) / 2 instead. 
    The subexpression (end - beg) computes the length of the current range, which is guaranteed to be non-negative. 
    Dividing this length by 2 and adding the result to beg gives us the correct index of the middle element, without the risk of integer overflow.

    */
   return 0;
}

int exercise_3_29() {
        /*
    Fixed size: Arrays have a fixed size that is determined at the time of creation, and it cannot be changed afterward. 
    In contrast, vectors can grow or shrink dynamically to accommodate the number of elements they hold.
    
    No bounds checking: Arrays do not perform bounds checking on array accesses, meaning that it is possible to read or write outside the bounds of an array. 
    This can result in undefined behavior or program crashes. In contrast, vectors perform bounds checking and will throw an exception if an attempt is made to access an out-of-bounds index.
    
    No copy or assignment: Arrays cannot be copied or assigned directly. 
    If you want to copy an array or assign it to another variable, you need to do it element by element using a loop or a function such as memcpy(). 
    In contrast, vectors can be copied or assigned easily using their copy constructor or assignment operator.
    
    No support for algorithms: Arrays do not have built-in support for many of the algorithms provided by the standard library, such as sorting or searching. 
    You need to write your own functions or use external libraries to perform these operations on arrays. In contrast, vectors have built-in support for many of these algorithms.
    
    No dynamic memory management: Arrays do not provide any built-in mechanisms for dynamic memory management, such as resizing or deallocating memory. 
    You need to manage memory yourself using new and delete operators or other memory management functions. 
    In contrast, vectors manage their own memory dynamically and automatically resize as needed.
    */
    return 0; 
}

int exercise_3_32() {
    int arr[10];
    for (int i = 0; i < 10; i++) { arr[i] = i; }
    int arr2[10];
    for (int i = 0; i < 10; i++) { arr2[i] = arr[i];}
    for (int i = 0; i < 10; i++) { cout << "arr2[" << i << "] = " << arr2[i] << endl; }

    vector<int> vec;
    for (int i = 0; i < 10; i++) { vec.push_back(i);}
    vector<int> vec2 = vec; 
    for (int i = 0; i < 10; i++) { cout << "vec2[" << i << "] = " << vec2[i] << endl; }

    return 0;
}

int exerise_3_33() {
    /*
    What would happen if we did not initialize the scores array in the program on page 116?
    
    unsigned scores[11] = {}; // 11 buckets, all value initialized to 0

    If we did not initialize the scores array in the program on page 116, its elements would have undefined values. 
    When we use uninitialized variables, the behavior of the program is undefined, which means that it can produce unpredictable results. 
    In this case, the program might display garbage values, or it might crash due to accessing invalid memory locations. 
    It is always a good practice to initialize variables before using them, to avoid undefined behavior and ensure that the program behaves predictably.
    */
   return 0;
}

int exercise_3_35() {
  const int SIZE = 10;
  int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  cout << "Array before setting elements to zero: ";
  for (int i = 0; i < SIZE; ++i) { cout << arr[i] << " "; }
  cout << endl;

  int* ptr = arr; 
  for (int i = 0; i < SIZE; ++i) {
    *ptr = 0;
    ++ptr;
  }


  cout << "Array after setting elements to zero: ";
  for (int i = 0; i < SIZE; ++i) {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

int exercise_3_41() {
  int arr[] = {1, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  // we initialize a vector vec from the array by passing two iterators to the vector constructor: the address of the first element of the array (arr) and the address of the element one past the end of the array (arr + size). 
  // This constructs a vector with the same elements as the array.
  vector<int> vec(arr, arr + size); 
  for (int i = 0; i < vec.size(); ++i) cout << vec[i] << " ";
  return 0;
}

int exercise_3_42() {
    vector<int> vec = {1, 2, 3, 4, 5};
    int arr[vec.size()];
    for (int i = 0; i < vec.size(); ++i) { arr[i] = vec[i]; }
    for (int i = 0; i < vec.size(); ++i) { cout << arr[i] << " "; }
    return 0;
}

int exercise_3_43() {
    /*
    Write three different versions of a program to print the elements of ia. 
    One version should use a range for to manage the iteration, the other two should use an ordinary for loop in one case using subscripts and in the other using pointers. 
    In all three programs write all the types directly. 
    That is, do not use a type alias, auto, or decltype to simplify the code.
    */

    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    // using range for loop
    for (int (&row)[4] : ia) {
        for (int col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

    // using regular for loop with subscripts
    for (size_t i = 0; i != 3; ++i) {
        for (size_t j = 0; j != 4; ++j) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }

    // using regular for loop with pointers
    for (int (*p)[4] = ia; p != ia + 3; ++p) {
        for (int *q = *p; q != *p + 4; ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }

    return 0;
}

int exercise_3_44() {
    /*
    Rewrite the programs from the previous exercises using a type alias for the type of the loop control variables.
    */

    using int_array = int[4]; 

    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    // using range for loop
    for (int_array &row : ia) { // using the type alias
        for (int col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

    // using regular for loop with subscripts
    for (size_t i = 0; i != 3; ++i) {
        for (size_t j = 0; j != 4; ++j) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }

    // using regular for loop with pointers
    for (int_array *p = ia; p != ia + 3; ++p) { // using the type alias
        for (int *q = *p; q != *p + 4; ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }

    return 0;
}

int exercise_3_45() {
    /*
    Rewrite the programs again, this time using auto.
    */
   
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };

    // using range for loop with auto
    for (auto &row : ia) {
        for (auto col : row) {
            cout << col << " ";
        }
        cout << endl;
    }

    // using regular for loop with subscripts and auto
    for (auto i = 0; i != 3; ++i) {
        for (auto j = 0; j != 4; ++j) {
            cout << ia[i][j] << " ";
        }
        cout << endl;
    }

    // using regular for loop with pointers and auto
    for (auto p = ia; p != ia + 3; ++p) {
        for (auto q = *p; q != *p + 4; ++q) {
            cout << *q << " ";
        }
        cout << endl;
    }

    return 0;
}

int main() {
    return 0;
}
