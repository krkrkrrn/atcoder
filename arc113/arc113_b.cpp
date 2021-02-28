#include <bits/stdc++.h>
using namespace std;
#define FOR_COUNT(n, max) for(int n = 0; n < (max); (n)++)
#define DEBUG_VAL(txt, n) cout << "debug : " << txt << " : " << n << endl

int multi(int a, int b) {
    int ans = 1;
    FOR_COUNT(i, b) {
        ans *= a;
    }
    return ans;
}

int main() {
    int a, b, c, ans;
    cin >> a >> b >> c;

    b %= 4;
    if(b == 0) {
        b = 4;
    } else if(b == 2) {
        if(c > 1) {
            b = 4;
        }
    } else if(b == 3) {
        if(c % 2 == 0) {
            b = 1;
        }
    }
    ans = multi(a % 10, b) % 10;
    cout << ans << endl;

    // int base = a % 10;
    // unsigned long long int ans_for_check_correct = multi(base, multi(b, c));
    // DEBUG_VAL("check correct", ans_for_check_correct);
}