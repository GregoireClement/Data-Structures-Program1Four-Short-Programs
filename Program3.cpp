#include <iostream>
#include <string>
using namespace std;


int main() {

    string s1;
    int bff = 0, idk = 0, jk = 0, tmi = 0, ttyl = 0;


    cout << "Enter text:" << endl;
    getline(cin, s1);

    cout << "You entered: " << s1 << endl;

    bff = s1.find("BFF");
    if (bff >= 0) {
        s1.replace(bff, 3, "best friend forever");
    }

    idk = s1.find("IDK");
    if (idk >= 0) {
        s1.replace(idk, 3, "I don't know");
    }

    jk = s1.find("JK");
    if (jk >= 0) {
        s1.replace(jk, 2, "just kidding");
    }

    tmi = s1.find("TMI");
    if (tmi >= 0) {
        s1.replace(tmi, 3, "too much information");
    }

    ttyl = s1.find("TTYL");
    if (ttyl >= 0) {
        s1.replace(ttyl, 4, "talk to you later");
    }

    cout << "Expanded: " << s1 << endl;
    return 0;
}