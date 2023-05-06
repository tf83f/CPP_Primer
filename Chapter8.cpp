#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

istream& exercise_8_1(istream& is) {
    // Write a function that takes and returns an istream&. 
    // The function should read the stream until it hits end-of-file. 
    // The function should print what it reads to the standard output. 
    // Reset the stream so that it is valid before returning the stream.
    string line;
    while (getline(is, line)) cout << line << '\n';
    is.clear();
    return is;
}

vector<string> exercise_8_4(const string& filename)
{
    vector<string> lines;
    ifstream file(filename);
    if (file) {
        string line;
        while(getline(file, line)) lines.push_back(line);
        
    }
    return lines;
}

vector<string> exercise_8_5(const string& filename)
{
    vector<string> lines;
    ifstream file(filename);
    if (file) {
        string line;
        while(file >> line) lines.push_back(line);
        
    }
    return lines;
}

vector<string> exercise_8_9(istream& is) {
    vector<string> lines;
    string line;
    while (getline(is, line)) lines.push_back(line);
    return lines;
}

int exercise_8_10(const string& filename) {
    vector<string> lines;
    ifstream file(filename);
    if (file) {
        string line;
        while (getline(file, line)) lines.push_back(line);
    }
    file.close();
    
    for (auto const& l : lines)
    {
        istringstream iss(l);
        string word;
        while (iss >> word) cout << word << endl;
    }
    return 0;
}

int exercise_8_11() {
    struct PersonInfo {
    string name;
    vector<string> phones;
    };

    string line, word;
    vector<PersonInfo> people;
    istringstream record;

    while (getline(cin, line)) {
        PersonInfo info;
        record.str(line);
        record >> info.name;
        while (record >> word) {
            info.phones.push_back(word);
        }
        people.push_back(info);
        record.clear();
    }

    for (const auto& person : people) {
        cout << person.name << ": ";
        for (const auto& phone : person.phones) {
            cout << phone << " ";
        }
        cout << endl;
    }

    return 0;
}

int exercise_8_12() {
    /*
     Why didn’t we use in-class initializers in PersonInfo?

     In-class initializers are used to initialize the member variables of a class at the time of declaration. 
     However, in the case of PersonInfo, the phones member is a vector that needs to be constructed at runtime, and the initial contents are unknown at compile-time. 
     Therefore, in-class initializers cannot be used for phones and it needs to be initialized at runtime using the constructor or some other member function.
    */
   return 0;
}

int main() {
    return 0;
}
