#include <bits/stdc++.h>
using namespace std;

int main() {
    bool is_even = false;

    for(int i = 0; i < 2; i++) {
        int16_t n;
        cin >> n;
        if(n % 2 == 0) {
            is_even = true;
            break;
        }
    }

    if(is_even) {
        cout << "Even" << endl;
    } else {
        cout << "Odd" << endl;
    }
}