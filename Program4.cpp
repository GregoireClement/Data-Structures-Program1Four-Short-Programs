#include <iostream>
#include <string>
using namespace std;

int GetNumOfNonWSCharacters(string const userString) {
    unsigned int count = 0;
    for (int i = 0; i< userString.length(); ++i) {
        if (userString.at(i) != ' ') {
            ++count;
        }
    }
    return count;
}

int GetNumOfWords(string userString) {
    unsigned int count = 0;
    for (int i = 0; i < userString.length(); ++i) {
        if (userString.at(i) == ' ' || userString.at(i) == '\n' || userString.at(i) == '\t') {
            while (userString.at(i) == ' ') { //This handles multiple spaces
                i++;
            }
            count++;
        }
    }
    count = count + 1; //For the last word
    return count;
}

unsigned int FindText(string seek, string userString) {
    unsigned int instances = 0; //# of times a word occurs
    int pos; 
    pos = userString.find(seek);

    while (pos != string::npos) {
        pos = userString.find(seek, pos + 1);
        instances++;
    }
    return instances;
}

void ReplaceExclamation(string userString) {
    for (int i = 0;i< userString.length();i++) {
        if (userString.at(i) == '!') {
            userString.at(i) = '.';
        }
    }
    return userString;
}

string ShortenSpace(string userString) {
    string editedString;
    editedString.resize(userString.length());
    int iterator = 0;
    for (int i = 0; i < userString.length(); iterator++) {
        editedString.at(iterator) += userString.at(i);

        if (userString.at(i) == ' ') {
            while (userString.at(i) == ' ') {
                i++;
            }
        }
        else {
            i++;
        }
    }
    editedString.erase(editedString.find('\0')); 
    return editedString;
}

char printMenu() {
    char ch;

    cout << "\nMENU" << endl;
    cout << "c - Number of non-whitespace characters" << endl;
    cout << "w - Number of words" << endl;
    cout << "f - Find text" << endl;
    cout << "r - Replace all !'s" << endl;
    cout << "s - Shorten spaces" << endl;
    cout << "q - Quit" << endl << endl;
    cout << "Choose an option:" << endl;
    cin >> ch;

    return ch; // return the user's choice as a character
}


int main() {
    string userString;
    unsigned int numberNWS;//number of nonwhite space characters
    unsigned int numberW; //number of words
    unsigned int instances;//number of times a word occurs
    string editedString;
    string seek;//String that is found in the userString

    cout << "Enter a sample text:\n" << endl;
    getline(cin, userString);//Get the user input
    cout << "You entered: " << userString << endl;

    userChoice = PrintMenu();
    while (userChoice != 'q') {
        //cout << endl;
        if (userChoice == 'c') {
            numberNWS = GetNumOfNonWSCharacters(userString);
            cout << "Number of non-whitespace characters: " << numberNWS << endl;
            cout << endl;
        }
        else if (userChoice == 'w') {
            numberW = GetNumOfWords(userString);
            cout << "Number of words: " << numberW << endl;
            cout << endl;
        }
        else if (userChoice == 'f') {
            cout << "Enter a word or phrase to be found:" << endl;
            cin.ignore();
            getline(cin, seek);
            instances = FindText(seek, userString);
            cout << "\"" << seek << "\"" << " instances: " << instances << endl;
            cout << endl;
        }
        else if (userChoice == 'r') {//replace all ! with periods call
            editedString = ReplaceExclamation(userString);
            cout << "Edited text: " << editedString << endl;
            cout << endl;

        }
        else if (userChoice == 's') {
            //editedString = "";
            editedString = ShortenSpace(userString);
            cout << "Edited text: " << editedString << endl;
            cout << endl;
        }
        userChoice = PrintMenu();
    }

    return 0;
}