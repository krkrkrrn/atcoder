#include <bits/stdc++.h>
using namespace std;
#define FOR_COUNT(n, max) for(int n = 0; n < (max); (n)++)
#define DEBUG_VAL(txt, n) cout << "debug : " << txt << " : " << n << endl

int main() {
    int a, b, c, result;
    int pattern = 4;
    cin >> a >> b >> c;
    a = a % 10;
    if(a == 0 || a == 1 || a == 5 || a == 6) {
        pattern = 1;
        cout << a << endl;
        return 0;
    } else if(a == 4 || a == 9) {
        pattern = 2;
    }
    b = (b - 1) % pattern;
    if(pattern == 4) {
        if(b == 2) {
            if(c > 1) {
                b = 0;
            }
        } else if(b == 3) {
            if(c % 2 == 0) {
                b = 1;
            }
        }
    }
    result = a;
    FOR_COUNT(n, b) {
        result *= a;
        DEBUG_VAL("loop", result);
    }
    result = result % 10;
    cout << result << endl;
}