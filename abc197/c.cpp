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
    int N;
    vector<int> a_or;
    int min_xor = pow(2, 30);
    cin >> N;
    for(int n = 0; n < N; n++) {
        int a;
        cin >> a;
        bool flg = true;
        FOR_ITR(i, a_or) {
            DEBUG_VAL("a_or()", a_or.at(i));
            int temp_or = a_or.at(i) | a;
            if(temp_or == a || temp_or == a_or.at(i)) {
                a_or.at(i) = temp_or;
                int temp_xor = a_or.at(i) ^ a;
                if(temp_xor < min_xor && temp_xor != 0) {
                    min_xor = temp_xor;
                }
                flg = false;
            }
        }
        if(flg) {
            a_or.push_back(a);
        }
    }
    print_vec(a_or);
    DEBUG_VAL("min_xor", min_xor);
}