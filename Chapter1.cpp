#include <iostream>
#include <sstream>
#include "Sales_item.h"

// Exercise 1.23: Write a program that reads several transactions and counts how many transactions occur for each ISBN.
int exercise_1_23() {
    Sales_item item, total;
    if (std::cin >> total) {
        int count = 1;
        while (std::cin >> item) {
            if (item.isbn() == total.isbn()) {
                ++count;
            }
            else {
                std::cout << "Count for ISBN " << total.isbn() << " is " << count << std::endl;
                total = item;
                count = 1;
            }
        }
        std::cout << "Count for ISBN " << total.isbn() << " is " << count << std::endl;
    }
    else {
        std::cerr << "No data entered." << std::endl;
        return -1;
    }
    return 0;
}

// Exercise 1.24: Test the previous program by giving multiple transactions representing multiple ISBNs. The records for each ISBN should be grouped together.
int exercise_1_24() {
    std::istringstream iss(
        "0-201-70353-X 4 24.99\n"
        "0-201-70353-X 3 19.99\n"
        "0-201-70353-X 1 49.99\n"
        "0-201-78345-X 2 35.00\n"
        "0-201-78345-X 1 30.00\n"
        "0-201-78345-X 3 42.50\n"
        "0-201-78345-X 4 19.99\n"
    );
    std::cin.rdbuf(iss.rdbuf()); 
    exercise_1_23();
    return 0;
}

// Exercise 1.25: Using the Sales_item.h header from the Web site, compile and exe- cute the bookstore program presented in this section.
int exercise_1_25() {
        Sales_item total;
        if (std::cin >> total) {
            Sales_item trans;
            while (std::cin >> trans) {
                if (total.isbn() == trans.isbn())
                    total += trans;
                else {
                std::cout << total << std::endl;
                total = trans;
                }
            }
            std::cout << total << std::endl;
        }
        else {
            std::cerr << "No data ?" << std::endl;
            return -1;
        }
        return 0;
}

int main() {
    //exercise_1_23();
    //exercise_1_24();
    exercise_1_25();
    return 0;
}
