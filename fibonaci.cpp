#include <bits/stdc++.h>

const int size = 10000000;

long mem[size];
//Solution 1

long fibo1(int n) {
    if (mem[n] != -1) return mem[n];
    if (n <= 1) return n;

    return mem[n] = fibo1(n - 1) + fibo1(n - 2);
}

//Solution 2
long fibo2(int n) {
    for (int i = 0; i <= n; i++) {
        if (i <= 1) mem[i] = 1;
        else mem[i] = mem[i - 1] + mem[i - 2];
    }

    return mem[n];
}

//Solution 3
long fibo3(int n) {
    if (n < 2) return n;
    long long fibo_1 = 1, fibo_2 = 0;
    for (int i = 2; i <= n; i++) {
            long long cur = fibo_1 + fibo_2;
            fibo_2 = fibo_1;
            fibo_1 = cur;
    }
    return fibo_1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    std::cin >> n;
    std::memset(mem, -1, sizeof(mem));
    std::cout << fibo3(n) << std::endl;
    system("pause");
    return 0;
}