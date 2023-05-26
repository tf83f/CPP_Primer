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
#include <cstring>
#include <sstream>
#include<tuple>
#include<bitset>
#include<array>
#include<regex>
#include<random>
#include<ctime>
#include <iomanip>

using namespace std;

void exercise_17_2() {
    /*

tuple<string, vector<string>, pair<string, int>> my_tuple("Hello", {"World", "OpenAI"}, make_pair("ChatGPT", 3));

int main() {
    tuple<string, vector<string>, pair<string, int>> my_tuple("Hello", {"to", "you"}, make_pair("year", 2023));

    std::cout << "String: " << std::get<0>(my_tuple) << std::endl;

    std::cout << "Vector of strings: ";
    for (const auto& str : std::get<1>(my_tuple)) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    std::cout << "Pair: " << std::get<2>(my_tuple).first << ", " << std::get<2>(my_tuple).second << std::endl;

    return 0;
}
*/
}

void exercise_17_4() {
    /*
struct Book {
    std::string title;
    std::string author;
    int year;
};

std::tuple<bool, Book> findBook(const std::vector<Book>& library, const std::string& title) {
    auto it = std::find_if(library.begin(), library.end(), [&](const Book& book) {
        return book.title == title;
    });

    if (it != library.end()) {
        return std::make_tuple(true, *it);
    } else {
        return std::make_tuple(false, Book());
    }
}

int main() {
    
    std::vector<Book> library = {
        {"The Great Gatsby", "F. Scott Fitzgerald", 1925},
        {"To Kill a Mockingbird", "Harper Lee", 1960},
        {"1984", "George Orwell", 1949},
        {"Pride and Prejudice", "Jane Austen", 1813}
    };

    std::string bookTitle;
    std::cout << "Enter the title of the book to search: ";
    std::getline(std::cin, bookTitle);

    std::tuple<bool, Book> result = findBook(library, bookTitle);
    bool found = std::get<0>(result);
    Book book = std::get<1>(result);

    if (found) {
        std::cout << "Book found:" << std::endl;
        std::cout << "Title: " << book.title << std::endl;
        std::cout << "Author: " << book.author << std::endl;
        std::cout << "Year: " << book.year << std::endl;
    } else {
        std::cout << "Book not found." << std::endl;
    }

    return 0;
}

*/
}

void exercise_17_9() {
    /*
(a) The bitset object bitvec with a size of 64 is initialized with the value 32. The bit pattern would be:
0000000000000000000000000000000000000000000000000000000000100000

(b) The bitset object bv with a size of 32 is initialized with the value 1010101. The bit pattern would be:
00000000000011110110100110110101

(c) The string bstr is obtained from user input and then used to initialize a bitset bv with a size of 8. The bit pattern would be determined by the binary representation of the input string. For example, if the input string is "10101010", the bit pattern would be:
10101010
    */
}

int exercise_17_10() {
    std::bitset<22> bits;
    bits.set(1);
    bits.set(2);
    bits.set(3);
    bits.set(5);
    bits.set(8);
    bits.set(13);
    bits.set(21);

    std::bitset<22> defaultBits;

    for (int i = 1; i <= 21; ++i) {
        defaultBits.set(i);
    }
    std::cout << "Bits: " << bits << std::endl;
    std::cout << "Default Bits: " << defaultBits << std::endl;

    return 0;
}

void exercise_17_12() {
    /*
struct Quiz {
    std::array<bool, 10> responses;
};

void updateQuiz(Quiz& quiz, int questionNumber, bool answer) {
    if (questionNumber >= 1 && questionNumber <= 10) {
        quiz.responses[questionNumber - 1] = answer;
    } else {
        std::cout << "Invalid question number." << std::endl;
    }
}

int main() {
    Quiz quiz;

    quiz.responses.fill(false);

    updateQuiz(quiz, 2, true);
    updateQuiz(quiz, 5, false);

    for (int i = 0; i < 10; ++i) {
        std::cout << "Question " << i + 1 << ": " << std::boolalpha << quiz.responses[i] << std::endl;
    }

    return 0;
}
*/
}

void exercise_17_13() { /*
struct Quiz {
    std::array<bool, 10> responses;
};

struct CorrectAnswers {
    std::array<bool, 10> answers;
};

int calculateGrade(const Quiz& quiz, const CorrectAnswers& correctAnswers) {
    int score = 0;
    for (int i = 0; i < 10; ++i) {
        if (quiz.responses[i] == correctAnswers.answers[i]) {
            score++;
        }
    }
    return score;
}

int main() {
    Quiz quiz;

    quiz.responses.fill(false);
    quiz.responses[1] = true;
    quiz.responses[4] = false;


    CorrectAnswers correctAnswers;

    correctAnswers.answers.fill(false);
    correctAnswers.answers[1] = true;
    correctAnswers.answers[4] = true;


    int grade = calculateGrade(quiz, correctAnswers);
    std::cout << "Grade: " << grade << " out of 10" << std::endl;

    return 0;
    */
}

void exercise_17_17() {
    /*
def find_violating_words(sequence):
    words = re.findall(r'\b\w+ei\w*\b', sequence)
    violating_words = [word for word in words if 'ei' not in word.lower()]
    return violating_words

input_sequence = input("Enter a sequence of words: ")
violating_words = find_violating_words(input_sequence)

if violating_words:
    print("The following words violate the 'ei' grammar rule:")
    for word in violating_words:
        print(word)
else:
    print("No words violate the 'ei' grammar rule.")
    */
}

void exercise_17_21() {
    /*
bool validatePhoneNumber(const std::string& number) {
   
    std::regex pattern(R"(^\d{3}-\d{3}-\d{4}$)");
    
    return std::regex_match(number, pattern);
}

int main() {
    std::string phoneNumber;
    std::cout << "Enter a phone number (in the format xxx-xxx-xxxx): ";
    std::cin >> phoneNumber;

    if (validatePhoneNumber(phoneNumber)) {
        std::cout << "Valid phone number!" << std::endl;
    } else {
        std::cout << "Invalid phone number!" << std::endl;
    }

    return 0;
}
*/
}

void exercise_17_22() {
    /*
bool validatePhoneNumber(const std::string& number) {
   
    std::regex pattern(R"(^\s*\d{3}\s*-\s*\d{3}\s*-\s*\d{4}\s*$)");
    
    return std::regex_match(number, pattern);
}

int main() {
    std::string phoneNumber;
    std::cout << "Enter a phone number (in the format xxx-xxx-xxxx): ";
    std::cin >> phoneNumber;

    if (validatePhoneNumber(phoneNumber)) {
        std::cout << "Valid phone number!" << std::endl;
    } else {
        std::cout << "Invalid phone number!" << std::endl;
    }

    return 0;
}
*/
}

void exercise_17_23() {
    /*
std::vector<std::string> findZipCodes(const std::string& text) {
    std::regex pattern(R"(^\d{5}(?:-\d{4})?$)");
    std::vector<std::string> zipCodes;

    std::sregex_iterator iterator(text.begin(), text.end(), pattern);
    std::sregex_iterator endIterator;

    while (iterator != endIterator) {
        zipCodes.push_back(iterator->str());
        ++iterator;
    }

    return zipCodes;
}

int main() {
    std::string text = "Zip codes: 12345, 98765-4321, 456789, 1234-5678";
    std::vector<std::string> zipCodes = findZipCodes(text);

    for (const auto& zipCode : zipCodes) {
        std::cout << zipCode << std::endl;
    }

    return 0;
}
*/
}

void exercise_17_24() {
    /*
std::string reformatPhoneNumber(const std::string& number, const std::string& format) {

    std::string digitsOnly = std::regex_replace(number, std::regex(R"(\D)"), "");

    std::string formattedNumber;
    int index = 0;
    for (char c : format) {
        if (c == 'X') {
            if (index < digitsOnly.length()) {
                formattedNumber += digitsOnly[index++];
            }
        } else {
            formattedNumber += c;
        }
    }

    return formattedNumber;
}

int main() {
    std::string phoneNumber;
    std::cout << "Enter a phone number: ";
    std::cin >> phoneNumber;

    std::string format;
    std::cout << "Enter the desired format (e.g., XXX-XXX-XXXX): ";
    std::cin >> format;

    std::string reformattedNumber = reformatPhoneNumber(phoneNumber, format);
    std::cout << "Reformatted number: " << reformattedNumber << std::endl;

    return 0;
}
*/
}

void exercise_17_25() {
    /*
std::map<std::string, std::string> extractPhoneNumbers(const std::string& text) {
    std::regex pattern(R"((\b[A-Za-z]+\b).*(\d{3}-\d{3}-\d{4}))");
    std::map<std::string, std::string> phoneNumbers;

    std::sregex_iterator iterator(text.begin(), text.end(), pattern);
    std::sregex_iterator endIterator;

    while (iterator != endIterator) {
        std::smatch match = *iterator;
        std::string name = match[1].str();
        std::string number = match[2].str();

        if (phoneNumbers.find(name) == phoneNumbers.end()) {
            phoneNumbers[name] = number;
        }

        ++iterator;
    }

    return phoneNumbers;
}

int main() {
    std::string text = "John: 123-456-7890\n"
                       "Alice: 987-654-3210\n"
                       "Bob: 111-222-3333\n"
                       "John: 555-555-5555";

    std::map<std::string, std::string> phoneNumbers = extractPhoneNumbers(text);

    for (const auto& entry : phoneNumbers) {
        std::cout << entry.first << ": " << entry.second << std::endl;
    }

    return 0;
}
*/
}

void exercise_17_26() {
    /*
std::map<std::string, std::vector<std::string>> extractPhoneNumbers(const std::string& text) {
    std::regex pattern(R"((\b[A-Za-z]+\b).*(\d{3}-\d{3}-\d{4}))");
    std::map<std::string, std::vector<std::string>> phoneNumbers;

    std::sregex_iterator iterator(text.begin(), text.end(), pattern);
    std::sregex_iterator endIterator;

    while (iterator != endIterator) {
        std::smatch match = *iterator;
        std::string name = match[1].str();
        std::string number = match[2].str();

        phoneNumbers[name].push_back(number);

        ++iterator;
    }

    return phoneNumbers;
}

int main() {
    std::string text = "John: 123-456-7890\n"
                       "Alice: 987-654-3210\n"
                       "Bob: 111-222-3333\n"
                       "John: 555-555-5555\n"
                       "Alice: 999-999-9999";

    std::map<std::string, std::vector<std::string>> phoneNumbers = extractPhoneNumbers(text);

    for (const auto& entry : phoneNumbers) {
        const std::string& name = entry.first;
        const std::vector<std::string>& numbers = entry.second;

        if (numbers.size() > 1) {
            std::cout << name << ": ";
            for (size_t i = 1; i < numbers.size(); ++i) {
                std::cout << numbers[i] << " ";
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
*/
}

void exercise_17_28() {
    /*
unsigned int generateRandomUnsignedInt() {
    static random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<unsigned int> dis;
    return dis(gen);
}


int main() {
    for (int i = 0; i < 5; ++i) {
        std::cout << generateRandomUnsignedInt() << std::endl;
    }

    return 0;
}
*/
}

void exercise_17_29() {
    /*
unsigned int generateRandomUnsignedInt(unsigned int seed = random_device()())
{
    static mt19937 gen(seed);
    static uniform_int_distribution<unsigned int> dis;
    return dis(gen);
}

int main() {
    unsigned int seed;
    std::cout << "Enter seed value (or press Enter for a random seed): ";
    std::string seedInput;
    std::getline(std::cin, seedInput);

    if (!seedInput.empty()) {
        try {
            seed = std::stoul(seedInput);
        } catch (...) {
            std::cerr << "Invalid seed value. Using a random seed." << std::endl;
            seed = std::random_device()();
        }
    } else {
        seed = std::random_device()();
    }

    std::cout << "Using seed: " << seed << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cout << generateRandomUnsignedInt(seed) << std::endl;
    }

    return 0;
}
*/
}

void exercise_17_30() {
    /*
unsigned int generateRandomUnsignedInt(unsigned int minVal, unsigned int maxVal, unsigned int seed = std::random_device()()) {
    static std::mt19937 gen(seed);
    std::uniform_int_distribution<unsigned int> dis(minVal, maxVal);

    return dis(gen);
}

int main() {
    unsigned int minVal, maxVal;
    std::cout << "Enter minimum value: ";
    std::cin >> minVal;
    std::cout << "Enter maximum value: ";
    std::cin >> maxVal;

    unsigned int seed;
    std::cout << "Enter seed value (or press Enter for a random seed): ";
    std::string seedInput;
    std::getline(std::cin, seedInput);

    if (!seedInput.empty()) {
        try {
            seed = std::stoul(seedInput);
        } catch (...) {
            std::cerr << "Invalid seed value. Using a random seed." << std::endl;
            seed = std::random_device()();
        }
    } else {
        seed = std::random_device()();
    }

    std::cout << "Using seed: " << seed << std::endl;

    for (int i = 0; i < 5; ++i) {
        std::cout << generateRandomUnsignedInt(minVal, maxVal, seed) << std::endl;
    }

    return 0;
}
*/
}

void exercise_17_31() {
    /*
If the variables b and e were defined inside the do loop of the game-playing program, their scope would be limited to the body of the loop. This means that they would be created and destroyed with each iteration of the loop.

The program would still compile and execute without any errors, but there would be some behavioral differences compared to when b and e are defined outside the loop.

Here are a few implications of defining b and e inside the do loop:

Initialization: The variables b and e would be initialized with their respective values at the beginning of each iteration of the loop. This could result in unnecessary reinitialization if the values remain the same across iterations.
Lifetime: The variables b and e would be destroyed at the end of each iteration of the loop. This means that any values stored in these variables would be lost once the iteration completes. If you need to retain the values across iterations, defining them inside the loop would not be appropriate.
Accessibility: The variables b and e would only be accessible within the body of the loop. If you need to access these variables outside the loop, such as for post-loop processing or displaying the final results, defining them inside the loop would prevent that.
In the context of the game-playing program, defining b and e inside the do loop could potentially lead to unintended consequences or incorrect behavior, depending on the specific requirements and logic of the program. Therefore, it is generally recommended to define variables in a scope that appropriately matches their intended usage and lifespan.
    */
}

void exercise_17_33() {
    /*
template <typename T> T getRandomElement(const std::vector<T>& vec) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<std::size_t> dis(0, vec.size() - 1);

    return vec[dis(gen)];
}


void wordTransformations(const std::string& inputWord, const std::map<std::string, std::vector<std::string>>& wordMap) {
    std::string currentWord = inputWord;


    while (wordMap.count(currentWord) > 0) {
        const std::vector<std::string>& transformations = wordMap.at(currentWord);

        std::string transformedWord = getRandomElement(transformations);

        std::cout << currentWord << " -> " << transformedWord << std::endl;

        currentWord = transformedWord;
    }
}

int main() {
    std::map<std::string, std::vector<std::string>> wordMap{
        {"dog", {"cat", "elephant", "lion"}},
        {"cat", {"dog", "tiger", "rabbit"}},
        {"lion", {"tiger", "elephant", "giraffe"}},
        {"elephant", {"dog", "cat", "giraffe"}},
        {"tiger", {"lion", "giraffe", "rhino"}},
        {"giraffe", {"elephant", "lion", "tiger"}}
    };

    std::string input;
    std::cout << "Enter a word: ";
    std::cin >> input;

    wordTransformations(input, wordMap);

    return 0;
}
*/
}

void exercise_17_34() {
    /*
int main() {
    double pi = 3.14159265359;
    double num = 123.456789;
    int intValue = 42;
    std::string str = "Hello, World!";
    bool flag = true;

    std::cout << std::setw(10) << std::setfill('*') << "Hello" << std::endl;
    std::cout << std::setprecision(5) << num << std::endl;
    std::cout << std::setprecision(3) << std::scientific << num << std::endl;
    std::cout << std::fixed << num << std::endl;
    std::cout << std::hex << intValue << std::endl;
    std::cout << std::oct << intValue << std::endl;
    std::cout << std::dec << intValue << std::endl;

    std::cout << std::boolalpha << flag << std::endl;
    std::cout << std::noboolalpha << flag << std::endl;
    std::cout << std::showbase << std::hex << intValue << std::endl;
    std::cout << std::noshowbase << intValue << std::endl;
    std::cout << std::showpoint << num << std::endl;
    std::cout << std::noshowpoint << num << std::endl;
    std::cout << std::showpos << num << std::endl;
    std::cout << std::noshowpos << num << std::endl;
    std::cout << std::uppercase << std::hex << intValue << std::endl;
    std::cout << std::nouppercase << intValue << std::endl;

    return 0;
}
*/
}

void exercise_17_37() {
    /*
int main() {
    std::ifstream inputFile("test.txt");
    if (!inputFile) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    const int bufferSize = 256;
    char buffer[bufferSize];

    while (inputFile.getline(buffer, bufferSize)) {
        std::string line(buffer);
        std::cout << "Read line: " << line << std::endl;
    }

    inputFile.close();

    return 0;
}
*/
}

void exercise_17_38() {
    /*
int main() {
    std::ifstream inputFile("test.txt");
    if (!inputFile) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    const int bufferSize = 256;
    char buffer[bufferSize];

    while (inputFile.getline(buffer, bufferSize)) {
        std::string line(buffer);
        std::istringstream iss(line);
        std::string word;

        while (iss >> word) {
            std::cout << word << std::endl;
        }
    }

    inputFile.close();

    return 0;
}
*/
}

int main()
{
    return 0;
}
