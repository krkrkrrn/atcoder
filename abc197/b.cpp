#include <bits/stdc++.h>
using namespace std;
#define FOR_ITR(i, itr) for(int i = 0; i < (itr).size(); i++)
#define DEBUG_DONE(txt) cout << "debug : " << txt << endl
#define DEBUG_VAL(txt, n) cout << "debug : " << txt << " : " << n << endl
#define PRINT_ERROR(txt) cout << "##ERROR : " << txt << " ##" << endl
#define PRINT_ERROR_VAL(txt, val) \
cout << "##ERROR : " << txt << " : VALUE : " << val << " ##" << endl

// print vector with template
template <class T> void print_vec(vector<T> vec) {
    for(const auto x : vec) {
        cout << x << endl;
    }
}

int main() {
    int H, W, X, Y;
    vector<string> hw;
    int v = 1;
    cin >> H >> W >> X >> Y;
    for(int n = 0; n < H; n++) {
        string s;
        cin >> s;
        hw.push_back(s);
    }
    // 横+
    for(int n = Y; n < W; n++) {
        if(hw.at(X-1).at(n) == '#') {
            break;
        }
        v++;
    }
    // 横-
    for(int n = Y - 2; n >= 0; n--) {
        if(hw.at(X-1).at(n) == '#') {
            break;
        }
        v++;
    }
    // 縦+
    for(int n = X; n < H; n++) {
        if(hw.at(n).at(Y-1) == '#') {
            break;
        }
        v++;
    }
    // 縦-
    for(int n = X - 2; n >= 0; n--) {
        if(hw.at(n).at(Y-1) == '#') {
            break;
        }
        v++;
    }
    cout << v << endl;
}