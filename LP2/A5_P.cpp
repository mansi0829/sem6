#include <iostream>
#include <regex>
#include <string>
#include <vector>
using namespace std;

vector<pair<regex, string>> rules = {
    {regex("hi|hello", regex_constants::icase), "Hello! How can I assist you?"},
    {regex(".*name.*", regex_constants::icase), "My name is Chatbot."},
    {regex(".*sports.*", regex_constants::icase), "I love Sports!! I like playing Cricket."},
    {regex(".*actor.*", regex_constants::icase), "Vicky Kaushal is my favorite actor!"},
    {regex(".*created.*|.*creator.*", regex_constants::icase), "Mansi Gundre is my creator."},
    {regex("how.*are.*you", regex_constants::icase), "I'm doing well, thank you!"},
    {regex("exit", regex_constants::icase), "Goodbye!"},
};

string generateResponse(const string& userInput)
{
    for (const auto& rule : rules) {
        if (regex_search(userInput, rule.first)) {
            return rule.second;
        }
    }
    return "I'm sorry, I don't understand.";
}

int main()
{
    cout << "Chatbot: Hello! How can I assist you?" << endl;
    while (true) {
        try {
            string userInput;
            cout << "User: ";
            getline(cin, userInput);

            if (regex_search(userInput, regex("exit", regex_constants::icase))) {
                cout << "Chatbot: Goodbye!" << endl;
                break;
            }

            string response = generateResponse(userInput);
            cout << "Chatbot: " << response << endl;
        } catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
