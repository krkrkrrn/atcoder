#include <bits/stdc++.h>
using namespace std;
#define DEBUG_VAL(txt, n) cout << "debug : " << txt << " : " << n << endl
#define DEBUG_DONE(txt) cout << "debug : " << txt << endl

// https://atcoder.jp/contests/arc113

struct counter {
    map<char, long long> m_each_done;
    map<char, long long> m_each_duplicate;
    stack<char> m_box;

    void set_char(char c) {
        if(!m_box.empty() && m_box.top() == c) {
            // DEBUG_DONE("if success.");
            replace_char(c);
        }
        // count variety char
        if(!m_each_duplicate.count(c)) {
            m_each_duplicate[c] = 0;
        }
        m_each_duplicate.at(c) ++;
        // DEBUG_VAL("char", c);
        // DEBUG_VAL("count", m_each_duplicate.at(c));
        m_box.push(c);
    }

    void replace_char(char c) {
        // set change character number.
        if(!m_each_done.count(c)) {
            m_each_done[c] = 0;
        }
        m_each_done.at(c) += m_box.size() - m_each_duplicate.at(c);
        // reset tempolary data.
        m_each_duplicate.erase(m_each_duplicate.begin(), m_each_duplicate.end());
        m_each_duplicate[c] = m_box.size();
    }

    long long get_count() {
        long long sum = 0;
        for(const auto& [key, value] : m_each_done) {
            // DEBUG_VAL("get_count() : char", key);
            // DEBUG_VAL("get_count() : value", value);
            sum += value;
        }
        return sum;
    }
};

int main() {
    string S;
    cin >> S;
    // DEBUG_VAL("S", S);
    // print_each_str(S);
    counter ct;
    for(int i = S.size() - 1; i >= 0; i--) {
        // DEBUG_VAL("c", S.at(i));
        ct.set_char(S.at(i));
    }
    cout << ct.get_count() << endl;
}