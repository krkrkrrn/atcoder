#include <bits/stdc++.h>
using namespace std;

int main() {
    int K;
    int count = 0;
    cin >> K;
    for(int a = 1; a <= K; a++) {
        for(int b = 1; b <= K / a; b++) {
            for(int c = 1; c <= K / a / b; c++) {
                count++;
            }
        }
    }
    cout << count << endl;
}