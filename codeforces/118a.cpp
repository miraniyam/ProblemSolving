#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char vowel[12] = {'A', 'a', 'O', 'o', 'Y', 'y', 'E', 'e', 'U', 'u', 'I', 'i'};
bool isVowel(char t);

int main() {
    string test;
    cin >> test;

    string result = "";

    for(int i = 0; i < test.length(); i++) {
        char token = test.at(i);
        bool vResult = isVowel(token);
        if(!vResult) {
            result = result+".";
            result = result+token;
        }
    }
    transform(result.begin(), result.end(), result.begin(), ::towlower);
    cout << result << endl;
    return 0;
}

bool isVowel(char t) {
    for(int i = 0; i < 12; i++) {
        if(t == vowel[i]) {
            return true;
        }
    }
    return false;
}