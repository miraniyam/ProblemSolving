#include <iostream>
#include <string>
using namespace std;

int main() {
    int t = 0;
    cin >> t;

    string* str = new string[t];
    for (int i = 0; i < t; i++) {
        cin >> str[i];
    }

    for (int i = 0; i < t; i++) {
        int length = str[i].length();
        if(length <= 10) {
            cout << str[i] << endl;
            continue;
        }else {
            char first = str[i].at(0);
            char last = str[i].at(length-1);
			cout << first << length - 2 << last << endl;
        }
    }

    return 0;    
}