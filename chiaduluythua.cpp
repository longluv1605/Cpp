#include <bits/stdc++.h>

long long getAns(long long a, long long b, long long k) {
    if (b == 0) return 1;
    if (b == 1) return a % k;
    long long m = b / 2;
    long long n = b - m;
    long long x = getAns(a, m, k); // first half.
    long long y; // sec half.
    if (m == n) y = x;
    else y = (x * a % k) % k;
    return (x * y) % k;
}

int main() {
    long long a, b, k; std::cin >> a >> b >> k;
    // std::cout << b / 2 + b % 2;
    // std::cout << LONG_LONG_MAX << std::endl;
    // for (int i = 0; i < get.size(); i++) std::cout << get[i] << " ";
    
    std::cout << getAns(a, b, k);
    return 0;
}