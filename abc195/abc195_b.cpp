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
    int A, B, W;
    cin >> A >> B >> W;
    int min_N = -1;
    int max_N;
    // グラム単位に統一
    W = W * 1000;
    for(int n = 1; n < 1002; n++) {
        if(A * n <= W && W <= B * n) {
            max_N = n;
            if(min_N < 0) {
                min_N = n;
            }
        }
    }
    
}