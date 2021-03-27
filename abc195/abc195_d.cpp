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

long pow(int a, int b) {
    long res = 1;
    for(int n = 0; n < b; n++) {
        res *= a;
    }
    return res;
}

int main() {
    long N;
    cin >> N;
    int comma = 5;
    long sum = 0;
    long diff = 0;
    for(int n = 15; n > 0; n -= 3) {
        long c = N - pow(10, n) + 1;
        if(c > 0) {
            // DEBUG_VAL("c", c);
            sum += (c - diff) * comma;
            diff = c;
        }
        comma--;
    }
    cout << sum << endl;
}