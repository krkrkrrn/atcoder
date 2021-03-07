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

unsigned long part_reverse(unsigned long n, int begin, int end) {
    // bitset<32> print_bit(n);
    // DEBUG_VAL("n", print_bit);

    // create bit mask
    unsigned long bit_mask = ((1 << (end + 1)) - 1) ^ ((1 << begin) - 1);
    unsigned long x = n & bit_mask;

    // print_bit = x;
    // DEBUG_VAL("x", print_bit);

    x >>= begin;

    // print_bit = x;
    // DEBUG_VAL("x >>= ", print_bit);

    unsigned long res = bit_reverse(x, (end - begin + 1));

    // print_bit = res;
    // DEBUG_VAL("bit_reverse", print_bit);

    res <<= begin;

    // print_bit = res;
    // DEBUG_VAL("res <<= ", print_bit);

    // print_bit = (n & ~bit_mask);
    // DEBUG_VAL("n & ~", print_bit);

    res = res | (n & ~bit_mask);
    
    // print_bit = res;
    // DEBUG_VAL("out", print_bit);
    return res;
} 

bool rvom_and_rsrev(unsigned long& bit, int bit_length) {
    unsigned long min = bit;
    int begin, end;
    for(int i = 0; i < bit_length; i++) {
        for(int j = i + 2; j < bit_length; j++) {
            if(((bit >> i) & 1) == ((bit >> j) & 1)) {
                unsigned long n = part_reverse(bit, i, j);
                if(min > n) {
                    bitset<16> print_bit(n);
                    DEBUG_VAL("min > n", print_bit);
                    min = n;
                    begin = i;
                    end = j;
                }
            } 
        }
    }
    if(bit > min) {
        bit = min;
        return true;
    } else {
        return false;
    }
}

void read_string(string s) {
    unsigned long ab = 0;
    int ab_length = s.size();
    for(int i = 0; i < s.size(); i++) {
        if(s.at(s.size() - 1 - i) == 'b') {
            ab |= (1 << i);
        }
    }
    
    int count = 1000;
    while(rvom_and_rsrev(ab, ab_length)) {
        if(count < 0) {
            DEBUG_DONE("over 1000 loop.");
            break;
        }
        count--;
    }
    
    bitset<32> print_bit(ab);
    DEBUG_VAL("0b", print_bit);
    // long debug_re = bit_reverse(ab, ab_length);
    // bitset<32> print_bit2(debug_re);
    // DEBUG_VAL("re : 0b", print_bit2);
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
        read_string(s);
    }

    // DEBUG_DONE("print S");
    // print_vec(S);
}