#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

struct Record {
    string input;
    string response;
};

vector<Record> database = {
    {"What is your name?", "I'm ChatKing, an AI model"},
    {"Hi", "Hello"},
    {"How are you?", "I'm good, and how are you?"},
    {"I'm good", "Great"},
    {"Who developed you?", "Mansi developed me!"},
    {"What languages do you know?", "Currently, I know only English"},
    {"In which city are you developed?", "Pune"},
    {"Do you believe that AI will replace software engineers?", "Absolutely No!!"}
};

string findMatch(const string& input) {
    for (const auto& record : database) {
        if (record.input == input) {
            return record.response;
        }
    }
    return "I'm not sure if I understand what you are talking about.";
}

int main() {
    string input;

    while (true) {
        try {
            cout << "Enter your question: ";
            getline(cin, input);

            if (input == "Bye") {
                cout << "BYE, SEE YOU NEXT TIME!" << endl;
                break;
            } else {
                string response = findMatch(input);
                cout << response << endl;
            }
        } catch (const exception& e) {
            cerr << "Exception: " << e.what() << endl;
        } catch (...) {
            cerr << "Unknown exception occurred." << endl;
        }
    }

    return 0;
}
