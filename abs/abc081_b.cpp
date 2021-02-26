#include <bits/stdc++.h>
#define DEBUG_DONE(txt) std::cout << "debug : " << txt << std::endl
#define DEBUG_VAL(txt, n) \
std::cout << "debug : " << txt << " : " << n << std::endl

void count_factorial_of_two(int &count) {
    int32_t a;
    std::cin >> a;
    for(int n = 0; n < count; n++) {
        // return nth bit 
        if((a >> n) & 1) {
            count = n;
            return;
        }
    }
}

int main() {
    int N;
    int c = 32;
    std::cin >> N;
    for(int n = 0; n < N; n++) {
        count_factorial_of_two(c);
    }
    std::cout << c << std::endl;
}