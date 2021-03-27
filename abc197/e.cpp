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
    cin >> N;
    map<int, set<int>> balls;
    for(int i = 0; i < N; i++) {
        int x, c;
        cin >> x >> c;
        if(balls.count(c)) {
            balls.at(c).insert(x);
        } else {
            set<int> s;
            s.insert(x);
            balls[c] = s;
        }
    }
    // for(int i = 0; i < 1000; i++) {
    //     if(balls.count(i)) {
    //         for(auto n : balls.at(i)) {
    //             cout << n << " ";
    //         }
    //         cout << endl;
    //     }
    // }
    int diff = 0;
    int sum = 0;
    for(int i = 1; i < 200000; i++) {
        if(balls.count(i)) {
            for(auto n : balls.at(i)) {
                sum += abs(n - diff) - 1;
                diff = n;
            }
        }
    }
    sum += diff - 1;
    cout << sum << endl;
}