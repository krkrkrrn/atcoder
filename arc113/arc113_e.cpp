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

template <class T> void print_vv(vector<vector<T>> vv) {
    for(const auto v : vv) {
        for(const auto x : v) {
            cout << " " << x;
        }
        cout << endl;
    }
}

// https://atcoder.jp/contests/arc113/tasks/arc113_e

unsigned long bit_reverse(unsigned long n, int l) {
    unsigned long res = 0;
    while(l--) {
        res <<= 1;
        res |= (n & 1);
        n >>= 1;
    }
    return res;
}

unsigned long part_reverse() {
    
} 

void rvom_and_rsrev(string s) {
    unsigned long ab = 0;
    int ab_length = s.size();
    for(int i = 0; i < s.size(); i++) {
        if(s.at(s.size() - 1 - i) == 'b') {
            ab |= (1 << i);
        }
    }
    

    bitset<32> print_bit(ab);
    DEBUG_VAL("0b", print_bit);
    long debug_re = bit_reverse(ab, ab_length);
    bitset<32> print_bit2(debug_re);
    DEBUG_VAL("re : 0b", print_bit2);
}



int main() {
    int T;
    cin >> T;
    vector<string> S;
    for(int i = 0; i < T; i++) {
        string s;
        cin >> s;
        S.push_back(s);
    }

    for(const auto s : S) {
        rvom_and_rsrev(s);
    }

    // DEBUG_DONE("print S");
    // print_vec(S);
}