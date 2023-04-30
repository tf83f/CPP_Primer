#include <iostream>
#include <string>
#include "cctype"
#include <vector>

using namespace std;

int exercise_4_2() {
    /*
    Using Table 4.12 (p. 166), parenthesize the following expressions to indicate the order in which the operands are grouped:
    
    (a) * vec.begin() 

    *(vec.begin())
    The dereference operator * has higher precedence than the member access operator .
    , so vec.begin() is dereferenced first.
    
    (b) * vec.begin() + 1

    (*(vec.begin())) + 1
    Again, the dereference operator has higher precedence than the addition operator +, 
    so vec.begin() is dereferenced first and then 1 is added to the result.

    */
   return 0;

}

int exercise_4_4() {
    /*
    Parenthesize the following expression to show how it is evaluated. 
    Test your answer by compiling the expression (without parentheses) and printing its result.
    12 / 3 * 4 + 5 * 15 + 24 % 4 / 2
    */
   double a = 12 / 3 * 4 + 5 * 15 + 24 % 4 / 2;
   double b = (12 / 3) * 4 + (5 * 15) + ((24 % 4) / 2);
   cout << a << " = " << b << endl;
   return 0;

}

int exercise_4_5() {
    /*
    Determine the result of the following expressions.
    (a) -30*3+21/5 (b) -30+3*21/5
    (c) 30/3*21%5 (d) -30/3*21%4
    */
    double a = -30*3+21/5;
    double b = -30+3*21/5; 
    double c = 30/3*21%5; 
    double d = -30/3*21%4;
    cout << a << " = - 86 // " << b << " = - 18 // " << c << " = 0 // " << d <<" = - 2 ";
    return 0;
}

int exercise_4_7() {
    /*
    What does overflow mean? Show three expressions that will overflow.

    In C++, overflow occurs when a value is assigned to a variable that exceeds the maximum or minimum value that the variable can represent. The behavior of overflow is undefined, which means that the result of an operation that causes overflow is not guaranteed to be predictable or consistent across different systems or compilers.

    Here are three expressions that will overflow:

    int max = INT_MAX + 1;
    This expression tries to assign a value to max that is one greater than the maximum value that an int can represent. 
    This will result in overflow, and the value of max will be implementation-defined.

    short s = SHRT_MAX; s += 1;
    This expression tries to add 1 to the maximum value that a short can represent. 
    This will result in overflow, and the value of s will be implementation-defined.

    unsigned int x = 0; x -= 1;
    This expression tries to subtract 1 from an unsigned int with a value of 0. 
    This will result in underflow, which is a type of overflow that occurs when a value is assigned to a variable that is less than the minimum value that the variable can represent. 
    The behavior of underflow is also undefined in C++.
    */
   return 0;
}

int exercise_4_9() {
    /*
    Explain the behavior of the condition in the following if: 
    const char *cp = "Hello World";
    if (cp && *cp)

    The condition cp && *cp checks if both cp and the value pointed to by cp are not null. Here's how it works:

        cp is a pointer to a string literal "Hello World".
        cp is not null, so the first part of the condition (cp) is true.
        *cp dereferences the pointer cp and gives us the value of the first character of the string, which is 'H'.
        Since 'H' is not null, the second part of the condition (*cp) is also true.
        
    Therefore, the overall result of the condition is true, and the code inside the if statement will be executed.

    The purpose of this condition is to check if the pointer cp is pointing to a non-empty string. 
    If cp were null or if the string were empty (i.e., the first character were null), the condition would evaluate to false, and the code inside the if statement would not be executed.

    */
   return 0;
}

int exercise_4_10() {
    int ints;
    while (cin >> ints && ints != 42)
        cout << "Valid input" << endl;
    cout << "ENDED : Invalid input!" << endl;
    return 0;
}

int exercise_4_11() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a <  b && b < c && c < d)
        cout << "We  have A < B < C < D" << endl;
    else 
        cout << "We don't have : A < B < C < D" << endl;
    return 0;
}

int exercise_4_12() {
    /*
    The expression i != j < k is a chained comparison expression that uses the less than operator < and the not equal to operator !=. However, the order of evaluation is not immediately clear due to the operator precedence rules.

    According to the precedence rules, the less than operator < has higher precedence than the not equal to operator !=. Therefore, the expression is equivalent to i != (j < k).

    Here's how the expression is evaluated step by step:

    j < k: This sub-expression compares the values of j and k using the less than operator <. 
    If j is less than k, this sub-expression evaluates to true (which has a value of 1). 
    Otherwise, it evaluates to false (which has a value of 0).
    
    i != (j < k): This sub-expression compares the value of i with the value of the sub-expression j < k. 
    If i is not equal to the value of j < k, this sub-expression evaluates to true (which has a value of 1). 
    Otherwise, it evaluates to false (which has a value of 0).
    
    In summary, the expression i != j < k checks if j is less than k, and if i is not equal to the result of that comparison. 
    Therefore, the value of the expression depends on the values of i, j, and k.
*/
return 0;

}

int exercise_4_19() {
    /*
    Given that ptr points to an int, that vec is a vector<int>, and that ival is an int, explain the behavior of each of these expressions. 
    Which, if any, are likely to be incorrect? 
    Why? How might each be corrected?

    (a) ptr != 0 && *ptr++: 
    This expression first checks if ptr is not null, and then evaluates the value pointed to by ptr and increments ptr. 
    The behavior of this expression depends on the initial value of ptr. 
    If ptr is null, the expression will short-circuit and not evaluate the second operand. 
    Otherwise, the expression will evaluate to the value pointed to by the original value of ptr and then increment ptr. 
    This expression may be correct, depending on the intended behavior, but it can be confusing and hard to read. 
    To make it clearer, we could separate it into two statements:

    if (ptr != 0) {
        int val = *ptr;
        ++ptr;
        // use val as needed
    }

    (b) ival++ && ival: 
    This expression increments ival and checks if the original value of ival is non-zero. 
    If the original value of ival is zero, the expression will short-circuit and not evaluate the second operand. 
    Otherwise, the expression will evaluate to the new value of ival. 
    This expression is likely incorrect, because it increments ival twice: once in the first operand and once in the second operand. 
    To fix this, we could use two separate statements:

    ++ival; // increment ival
    if (ival) {
        // use ival as needed
    }

    (c) vec[ival++] <= vec[ival]: 
    This expression accesses two elements of the vector vec: one at index ival and another at index ival+1, and then increments ival. 
    The behavior of this expression depends on the values of the elements accessed. 
    If vec[ival] <= vec[ival+1], the expression will evaluate to true. 
    Otherwise, the expression will evaluate to false. 
    This expression is likely incorrect, because it modifies ival twice: once in the index expression for the left-hand side of the comparison and once in the index expression for the right-hand side of the comparison. 
    To fix this, we could use two separate statements:

    int lhs = vec[ival++];
    int rhs = vec[ival];
    if (lhs <= rhs) {
        // use lhs and rhs as needed
    }

    */
   return 0;

}

int exercise_4_20 () {
    /*
    Assuming that iter is a vector<string>::iterator, indicate which, if any, of the following expressions are legal. 
    Explain the behavior of the legal expressions and why those that aren’t legal are in error.

    a) *iter++; This is legal. It dereferences the current value of iter, and then increments the iterator to point to the next element in the vector.

    (b) (*iter)++; This is illegal. The ++ operator can't be applied to a string.

    (c) *iter.empty() This is illegal. iter doesn't have an empty() member function. It should be iter->empty() instead.

    (d) iter->empty(); This is legal. It calls the empty() member function on the string pointed to by iter.

    (e) ++*iter; This is illegal. The ++ operator can't be applied to a string.

    (f) iter++->empty(); This is legal. It calls the empty() member function on the string pointed to by iter, and then increments iter to point to the next element in the vector.
    */
    return 0;
}

int exercise_4_21() {
    /*
    Write a program to use a conditional operator to find the elements in a vector<int> that have odd value and double the value of each such element.
    */

    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (auto& num : vec) {
        num % 2 != 0 ? num *= 2 : num;
    }

    for (const auto& num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

int exercise_4_22() {
    /*
    Extend the program that assigned high pass, pass, and fail grades to also assign low pass for grades between 60 and 75 inclusive. 
    Write two versions: One version that uses only conditional operators; the other should use one or more if statements. 
    Which version do you think is easier to understand and why?
    */
   
    vector<int> scores = {82, 91, 73, 67, 55, 89, 90, 72, 68, 52};

    // Version 1: using only conditional operators
    vector<string> grades_v1;
    for (auto score : scores) {
        string grade = (score > 90) ? "high pass" 
                          : (score > 75) ? "pass" 
                          : (score >= 60) ? "low pass"
                          : "fail";
        grades_v1.push_back(grade);
    }

    // Version 2: using if statements
    vector<string> grades_v2;
    for (auto score : scores) {
        string grade;
        if (score > 90) {
            grade = "high pass";
        } else if (score > 75) {
            grade = "pass";
        } else if (score >= 60) {
            grade = "low pass";
        } else {
            grade = "fail";
        }
        grades_v2.push_back(grade);
    }

    // Print the grades from both versions
    for (int i = 0; i < scores.size(); i++) {
        cout << "Score: " << scores[i] 
                  << ", Grade (using cond. operators): " << grades_v1[i]
                  << ", Grade (using if statements): " << grades_v2[i] << endl;
    }

    return 0;
}

int exercise_4_23() {
    /*
    The following expression fails to compile due to operator precedence. 
    Using Table 4.12 (p. 166), explain why it fails. How would you fix it?
    string s = "word";
    string pl = s + s[s.size() - 1] == ’s’ ? "" : "s" ;

    The expression fails to compile because of the precedence of the + operator, which has higher precedence than the ternary conditional operator ?:. 
    As a result, the expression is evaluated as:
    (string pl = s + s[s.size() - 1]) == ’s’ ? "" : "s"

    which is not what the programmer intended.

    To fix this, we need to add parentheses to ensure that the ternary conditional operator is evaluated before the + operator. 
    One possible fix is:

    string pl = s + (s[s.size() - 1] == 's' ? "" : "s");

    This evaluates the condition s[s.size() - 1] == 's', and appends an empty string "" if the condition is true, or the string "s" otherwise, to the end of the original string s.
    */
   return 0;
}

int exercise_4_25() {
    /*
    What is the value of ~’q’ << 6 on a machine with 32-bit ints and 8 bit chars, that uses Latin-1 character set in which ’q’ has the bit pattern 01110001?
    
    In Latin-1 character set, the bit pattern for 'q' is 01110001. Applying the bitwise complement operator ~ on this value gives its complement, which is 10001110.

    In a machine with 32-bit ints and 8-bit chars, the expression ~'q' first promotes the character 'q' to an integer by sign-extending the value to 32 bits. Since 'q' has a bit pattern of 01110001, its sign bit is 0 and sign-extending it gives 00000000 00000000 00000000 01110001. Applying the bitwise complement operator on this value results in 11111111 11111111 11111111 10001110.

    Finally, left shifting the resulting value by 6 bits gives 11111111 11111111 11100011 10000000, which in decimal is -7296.

    Therefore, the value of the expression is -7296.

    */
   return 0;
}

int exercise_4_26() {
    /*
    In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?

    If we used unsigned int as the type for quiz1, then the expression (quiz1&0x1 ? cnt : 0) 
    in the final calculation of the student's grade would always evaluate to 0 because quiz1&0x1 would never be true 
    (i.e., the least significant bit of an unsigned int can never be 1 for a positive number). 
    Therefore, the student's grade would not include any points for quiz1.
    */
   return 0;
}

int exercise_4_27() {
    /*
    What is the result of each of these expressions?
    unsigned long ul1 = 3, ul2 = 7;
    (a) ul1 & ul2 
    This performs a bitwise AND operation between ul1 and ul2, which results in 3 (0011 in binary).
    
    (b) ul1 | ul2 
    This performs a bitwise OR operation between ul1 and ul2, which results in 7 (0111 in binary).

    (c) ul1 && ul2 
    This performs a logical AND operation between ul1 and ul2. Both ul1 and ul2 are nonzero, so the result is true (which is represented as 1 in C++).
    
    (d) ul1 || ul2
    This performs a logical OR operation between ul1 and ul2. Both ul1 and ul2 are nonzero, so the result is true (which is represented as 1 in C++).
    */
   return 0;
}

int exercise_4_29() {
    /*
    Predict the output of the following code and explain your reasoning.
    Now run the program. Is the output what you expected? If not, figure out why.
    
    int x[10];   int *p = x;
    cout << sizeof(x)/sizeof(*x) << endl; 
    cout << sizeof(p)/sizeof(*p) << endl;

    The first cout statement prints the size of the x array divided by the size of its first element. 
    Since x is an array of 10 integers, its total size is 10 times the size of an integer. Therefore, sizeof(x)/sizeof(*x) evaluates to 10/1, which is equal to 10.

    The second cout statement prints the size of the pointer p divided by the size of the integer that it points to. Since p is a pointer to an integer, its size is equal to the size of a memory address on the system, which is typically 4 bytes on a 32-bit system or 8 bytes on a 64-bit system. 
    Therefore, sizeof(p)/sizeof(*p) evaluates to 4/4 on a 32-bit system or 8/4 on a 64-bit system, which is equal to 1 or 2, respectively.

    The output matches the expected results.

    */
    return 0;
}

int exercise_4_30() {
    /*
    Using Table 4.12 (p. 166), parenthesize the following expressions to match the default evaluation:
    
    (a) sizeof x + y 

    sizeof(x) + y
    The sizeof operator has higher precedence than the addition operator +. 
    Therefore, sizeof x is evaluated first and then added to y.
    
    (b) sizeof p->mem[i] 
    
    sizeof(p->mem[i])
    The arrow operator -> has higher precedence than the subscript operator []. 
    Therefore, p->mem[i] is evaluated first, and then the sizeof operator is applied to the result.
        
    (c) sizeof a < b 
    
    (sizeof a) < b
    The comparison operator < has higher precedence than the sizeof operator. 
    Therefore, sizeof a is evaluated first, and then compared to b.

    (d) sizeof f()

    sizeof(f())
    The sizeof operator has higher precedence than the function call operator (). 
    Therefore, the sizeof operator is applied to the result of the function call f(). 
    However, the result of sizeof applied to a function call is implementation-defined and may not be meaningful. 
    In most cases, it returns the size of the return type of the function.

    */

    return 0;

}

int exercise_34() {
    /*
    Given the variable definitions in this section, explain what conversions take place in the following expressions:
    
    (a) In the expression if (fval), the conversion that takes place is the conversion of fval from floating-point type to bool type. This is done by implicitly converting fval to the integer value 0 if it is zero, or to the integer value 1 if it is non-zero. The resulting bool value is then used as the condition for the if statement.

    (b) In the expression dval = fval + ival;, the conversions that take place are:

    ival is converted from int type to float type by the usual arithmetic conversions, because the other operand fval is a float.
    The resulting float values of fval and ival are added together, and the result is a float value.
    The resulting float value is then converted to double type, which is the type of the variable dval. This conversion is done implicitly.
    
    (c) In the expression dval + ival * cval;, the conversions that take place are:

    ival and cval are promoted from int type to double type by the usual arithmetic conversions, because the other operand dval is a double.
    The resulting double values of ival and cval are multiplied together, and the result is a double value.
    The resulting double value is then added to the double value of dval, and the result is a double value.
    */
   return 0;
}

int exercse_36() {
    /*
    Assuming i is an int and d is a double write the expression i *= d so that it does integral, rather than floating-point, multiplication.

    i *= static_cast<int>(d);
    
    */
   return 0;
}

int main() {

    return 0;
}
