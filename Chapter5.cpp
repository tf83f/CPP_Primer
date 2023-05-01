#include <iostream>
#include <string>
#include <vector>

using namespace std;

int exercise_5_5() {
    // Using an if–else statement, write your own version of the program to generate the letter grade from a numeric grade.
    int grade;
    cout << "Enter your numeric grade: ";
    cin >> grade;

    char letter_grade;

    if (grade >= 90) {
        letter_grade = 'A';
    } else if (grade >= 80) {
        letter_grade = 'B';
    } else if (grade >= 70) {
        letter_grade = 'C';
    } else if (grade >= 60) {
        letter_grade = 'D';
    } else {
        letter_grade = 'F';
    }

    cout << "Your letter grade is " << letter_grade << endl;

    return 0;
}

int exercise_5_6() {
    int grade;
    cout << "Enter your numeric grade: ";
    cin >> grade;

    char letter_grade = (grade >= 90) ? 'A' :
                        (grade >= 80) ? 'B' :
                        (grade >= 70) ? 'C' :
                        (grade >= 60) ? 'D' :
                                        'F';

    cout << "Your letter grade is " << letter_grade << endl;

    return 0;
}

int exercise_5_12() {
    int a_count = 0, e_count = 0, i_count = 0, o_count = 0, u_count = 0;
    int space_count = 0, tab_count = 0, newline_count = 0;
    int ff_count = 0, fl_count = 0, fi_count = 0;

    char ch, prev_ch = '\0';
    while (cin >> ch) {
        switch (ch) {
            case 'a': case 'A':
                ++a_count; break;
            case 'e': case 'E':
                ++e_count; break;
            case 'i': case 'I':
                if (prev_ch == 'f') { ++fi_count; }
                else { ++i_count; }
                break;
            case 'o': case 'O':
                ++o_count; break;
            case 'u': case 'U':
                ++u_count; break;
            case ' ':
                ++space_count; break;
            case '\t':
                ++tab_count; break;
            case '\n':
                ++newline_count; break;
            case 'f':
                if (prev_ch == 'f')
                    ++ff_count;
                break;
            case 'l':
                if (prev_ch == 'f')
                    ++fl_count;
                break;
            default:
                break;
        }
        prev_ch = ch;
    }

    cout << "Number of vowels:\n"
              << "a: " << a_count << '\n'
              << "e: " << e_count << '\n'
              << "i: " << i_count << '\n'
              << "o: " << o_count << '\n'
              << "u: " << u_count << '\n'
              << "Number of spaces: " << space_count << '\n'
              << "Number of tabs: " << tab_count << '\n'
              << "Number of newlines: " << newline_count << '\n'
              << "Number of ff sequences: " << ff_count << '\n'
              << "Number of fl sequences: " << fl_count << '\n'
              << "Number of fi sequences: " << fi_count << '\n';

    return 0;
}

int exercise_5_13 () {
    /*
    Each of the programs in the highlighted text on page 184 contains a common programming error. 
    Identify and correct each error.

    (a) unsigned aCnt = 0, eCnt = 0, iouCnt = 0; char ch = next_text();
    switch (ch) {
            case ’a’: aCnt++;
            case ’e’: eCnt++;
            default: iouCnt++;
    }

    It's worth noting that the switch statement lacks break statements after each case. 
    This means that if the input character is 'a', then aCnt, eCnt, and iouCnt will all be incremented. Similarly, if the input character is 'e', then eCnt and iouCnt will both be incremented. 
    This behavior may or may not be intended, depending on the requirements of the program.

    Additionally, the code does not handle any errors that may occur when reading the character from the input source, and it does not specify what the input source is. 

    (b) unsigned index = some_value(); 
    switch (index) {
          case 1:
              int ix = get_value();
              ivec[ ix ] = index;
              break;
          default:
              ix = ivec.size()-1;
              ivec[ ix ] = index;
    }

    It's worth noting that the behavior of the code in the default case may not be what is intended, as ix is assigned a value without being declared first. 
    Additionally, the code does not handle any errors that may occur when calling the get_value() function, and it does not specify what ivec is or how it is initialized. 

    (c) unsigned evenCnt = 0, oddCnt = 0; int digit = get_num() % 10; switch (digit) {
          case 1, 3, 5, 7, 9:
              oddcnt++;
              break;
          case 2, 4, 6, 8, 10:
              evencnt++;
              break; 
    }

    It's worth noting that the case for 10 will never be executed since the result of digit % 10 can only be between 0 and 9. 
    Additionally, the code does not handle any errors that may occur when calling the get_num() function, and it does not specify what the input source is.

    (d) unsigned ival=512, jval=1024, kval=4096; unsigned bufsize;
    unsigned swt = get_bufCnt();
    switch(swt) {
            case ival:
                bufsize = ival * sizeof(int);
                break;
            case jval:
                bufsize = jval * sizeof(int);
                break;
            case kval:
                bufsize = kval * sizeof(int);
                break;
    }

    It's worth noting that if the value returned by get_bufCnt() does not match any of the cases in the switch statement, then bufsize will not be initialized, which may lead to undefined behavior if it is later used. 
    Additionally, the code does not specify what the get_bufCnt() function does or what the input source is.

    */

   return 0;

}

int exercise_5_14 () {
    string word, prev_word, max_word;
    int max_count = 0, count = 1;
    while (cin >> word) {
        if (word == prev_word) count++;
        else {
            if (count > max_count) max_count = count, max_word = prev_word;
            count = 1;
            prev_word = word;
        }
    }
    if (count > max_count) max_count = count, max_word = prev_word;

    if (max_count > 1) { cout << "The word '" << max_word << "' occurred " << max_count << " times." << endl; } 
    else { cout << "No word was repeated." << endl; }
    return 0;
}

int exercise_5_15() {
    /*
    Explain each of the following loops. Correct any problems you detect.
    
    (a) 
    for(int ix=0; ix!=sz; ++ix) {...} 
    if (ix != sz) // . . . 

    This code has a problem because ix is not in scope outside of the for-loop, so the check after the loop will result in a compilation error. 
    To fix this, the declaration of ix should be moved outside the loop, and a semicolon should be added to the end of the for-loop header
    
    int ix;
    for(ix=0; ix!=sz; ++ix) {...} 
    if (ix != sz) // . . . 

    (b) 
    int ix;
    for(ix != sz; ++ix){...}

    This loop declares an integer variable ix without initializing it, and then iterates while ix is not equal to the value of sz.

    int ix = 0;
    for(;ix != sz; ++ix){...}
    
    (c) 
    for(int ix = 0; ix != sz; ++ix ,++sz) {...}

    This code has a problem because it modifies sz inside the loop, which can result in unexpected behavior.
    */
   return  0;

}

int exercise_5_16() {
    vector<int> v1{0, 1, 1, 2};
    vector<int> v2{0, 1, 1, 2, 3, 5, 8};
    decltype(v1.size()) end;
    if (v1.size() < v2.size()) { end = v1.size(); } 
    else { end = v2.size(); }
    for (decltype(v1.size()) i = 0; i != end; ++i) 
        if (v1[i] != v2[i]) {
            cout << "FALSE";
            return 0;}
    cout << "TRUE";
    return 0;
}

int exercise_5_24() {
    int num1, num2;
    
    cout << "Enter the first number: ";
    cin >> num1;
    
    cout << "Enter the second number: ";
    cin >> num2;
    
    if(num2 == 0) {
        cout << "Error: division by zero" << endl;
    } else {
        double result = static_cast<double>(num1) / num2;
        cout << "Result: " << result << endl;
    }
    
    return 0;
}

int exercise_5_25() {
    int num1, num2;
    
    cout << "Enter the first number: ";
    cin >> num1;
    
    while (true) {
        try {
            cout << "Enter the second number: ";
            cin >> num2;
            
            if(num2 == 0) {
                throw runtime_error("division by zero");
            } else {
                double result = static_cast<double>(num1) / num2;
                cout << "Result: " << result << endl;
                break; // exit the loop if division succeeds
            }
        } catch(runtime_error& e) {
            cerr << "Error: " << e.what() << endl;
            cerr << "Please enter a non-zero second number." << endl;
        }
    }
    
    return 0;
}

int main() {
    return 0;
}
