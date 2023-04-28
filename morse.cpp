#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class MorseText
{
private:
    map<char, string> morseCodeMap = {
        {'A', ".-"},
        {'B', "-..."},
        {'C', "-.-."},
        {'D', "-.."},
        {'E', "."},
        {'F', "..-."},
        {'G', "--."},
        {'H', "...."},
        {'I', ".."},
        {'J', ".---"},
        {'K', "-.-"},
        {'L', ".-.."},
        {'M', "--"},
        {'N', "-."},
        {'O', "---"},
        {'P', ".--."},
        {'Q', "--.-"},
        {'R', ".-."},
        {'S', "..."},
        {'T', "-"},
        {'U', "..-"},
        {'V', "...-"},
        {'W', ".--"},
        {'X', "-..-"},
        {'Y', "-.--"},
        {'Z', "--.."},
        {'0', "-----"},
        {'1', ".----"},
        {'2', "..---"},
        {'3', "...--"},
        {'4', "....-"},
        {'5', "....."},
        {'6', "-...."},
        {'7', "--..."},
        {'8', "---.."},
        {'9', "----."},
        {'.', ".-.-.-"},
        {',', "--..--"},
        {'?', "..--.."},
        {'\'', ".----."},
        {'!', "-.-.--"},
        {'/', "-..-."},
        {'(', "-.--."},
        {')', "-.--.-"},
        {'&', ".-..."},
        {':', "---..."},
        {';', "-.-.-."},
        {'=', "-...-"},
        {'+', ".-.-."},
        {'-', "-....-"},
        {'_', "..--.-"},
        {'\"', ".-..-."},
        {'$', "...-..-"},
        {'@', ".--.-."},
        {' ', " "}};
    map<string, char> inverseMorseCodeMap;

    void initializeInverseMorseCodeMap()
    {
        for (auto &pair : morseCodeMap)
        {
            inverseMorseCodeMap[pair.second] = pair.first;
        }
    }

    string morseToText(string morseCode)
    {
        string text = "";
        string currentCode = "";
        for (char c : morseCode)
        {
            if (c == ' ')
            {
                if (!currentCode.empty())
                {
                    text += inverseMorseCodeMap[currentCode];
                    currentCode = "";
                }
            }
            else
            {
                currentCode += c;
            }
        }
        if (!currentCode.empty())
        {
            text += inverseMorseCodeMap[currentCode];
        }
        return text;
    }

    string textToMorse(string text)
    {
        string morseCode = "";
        for (char c : text)
        {
            if (morseCodeMap.count(c) > 0)
            {
                morseCode += morseCodeMap[c];
                morseCode += " ";
            }
        }
        return morseCode;
    }

    string readFromFile(string fileName)
    {
        ifstream inputFile(fileName);
        if (!inputFile.is_open())
        {
            cout << "Error: could not open input file " << fileName << endl;
            return "";
        }
        string content = "";
        char c;
        while (inputFile.get(c))
        {
            content += c;
        }
        inputFile.close();
        return content;
    }

    void writeToFile(string content, string fileName)
    {
        ofstream outputFile(fileName);
        if (!outputFile.is_open())
        {
            cout << "Error: could not open output file " << fileName << endl;
            return;
        }
        outputFile << content;
        outputFile.close();
        cout << "Successfully wrote output to file " << fileName << endl;
    }

public:
    void run()
    {
        initializeInverseMorseCodeMap();
        string inputFileName, outputFileName, content;
        int choice;
        while (true)
        {
            cout << "Choose an option:\n";
            cout << "1. Convert text to Morse code\n";
            cout << "2. Convert Morse code to text\n";
            cout << "3. Quit\n";
            cin >> choice;
            if (choice == 1)
            {
                cout << "Enter the name of the input file: ";
                cin >> inputFileName;
                content = readFromFile(inputFileName);
                string morseCode = textToMorse(content);
                cout << "The Morse code is: " << morseCode << endl;
                cout << "Enter the name of the output file: ";
                cin >> outputFileName;
                writeToFile(morseCode, outputFileName);
            }
            else if (choice == 2)
            {
                cout << "Enter the name of the input file: ";
                cin >> inputFileName;
                content = readFromFile(inputFileName);
                string text = morseToText(content);
                cout << "The text is: " << text << endl;
                cout << "Enter the name of the output file: ";
                cin >> outputFileName;
                writeToFile(text, outputFileName);
            }
            else if (choice == 3)
            {
                break;
            }
            else
            {
                cout << "Invalid choice. Please enter a valid choice.\n";
            }
        }
    }
};

int main()
{

    MorseText mrt;
    mrt.run();
}
