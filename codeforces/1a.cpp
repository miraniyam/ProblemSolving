#include <iostream>
using namespace std;

int main() {
    unsigned long long n = 0;
    unsigned long long m = 0;
    unsigned long long a = 0;

    cin >> n;
    cin >> m;
    cin >> a;

    unsigned long long wresult = n/a;
    unsigned long long hresult = m/a;
    if(n%a > 0) {
        wresult++;
    }
    if(m%a > 0) {
        hresult++;
    }

    cout << wresult*hresult;

    return 0;
}