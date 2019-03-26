#include <iostream>
using namespace std;

int main() {
    int w = 0; // scale

    cin >> w;
    bool result = false;

    for(int i = 2; i < w; i = i + 2) {
        int temp = w%i;
        if(temp == 0) {
            // 2로 나눠지면 even number로 나눠지는거니까 break
            result = true;
            break;
        }
    }

    if(result) {
        cout << "YES"<<endl;
    }else {
        cout << "NO"<<endl;
    }
    return 0;    
}