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

// https://atcoder.jp/contests/arc113/tasks/arc113_d
#define INT_PRIME 998244353

void set_unit_numbers(vector<vector<int>>& samples, vector<int> unit) {
    if(samples.size() < 1) {
        do {
            samples.push_back(unit);
        } while(next_permutation(unit.begin(), unit.end()));
    } else {
        vector<vector<int>> result;
        for(const auto sample : samples) {
            do {
                vector<int> v = sample;
                
//                v.insert(sample.end(), unit.begin(), unit.end());
                copy(unit.begin(), unit.end(), back_inserter(v));
                result.push_back(v);
            } while(next_permutation(unit.begin(), unit.end()));
        }
        samples = result;
        DEBUG_DONE("samples print");
        print_vv(samples);
    }
}

void test_sky_reflectot(int& N, int&M, int& K) {
    DEBUG_DONE("all samples.");
    int debug_count_limit = 3;
    vector<vector<int>> all_sample;
    vector<int> unit_order_K;
    int unit_count = 0;
    for(int i = 1; i <= K; i++) {
        unit_order_K.push_back(i);
    }
    set_unit_numbers(all_sample, unit_order_K);
    DEBUG_VAL("all_sample.at(0).size()", all_sample.at(0).size());
    for(int i = 0; i < debug_count_limit; i++) {
        if(all_sample.at(0).size() >= N*M) {
            break;
        }
        set_unit_numbers(all_sample, unit_order_K);
    }

    for(const auto v : all_sample) {
        for(const auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}

void sky_reflector(int& N, int& M, int& K) {
    
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    test_sky_reflectot(N, M, K);
}