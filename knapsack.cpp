#include <bits/stdc++.h>

int n, M;
long long arr[15][2];
// int res = 0;

long long stolen(int i, int m) {
    if (m < 0) return LONG_MIN;
    if (i == n) return 0;
    
    long long skip = stolen(i + 1, m);
    long long take = stolen(i + 1, m - arr[i][0]) + arr[i][1];
    
    return std::max(skip, take);
}

// 3 5

// 4 9
// 2 6
// 3 7

/*
stolen(0, 5):
    skip = stolen(1, 5):
                skip = stolen(2, 5): --> 7
                            skip = stolen(3, 5): --> 0
                            take = stolen(3, 2) + 7: --> 7
                take = stolen(2, 3) + 6: 
                            skip = stolen(3, 3): --> 0
                            take = stolen(3, 0) + 7: --> 7
    take = stolen(1, 1) + 9:

*/

int main() {
    std::cin >> n >> M;
    
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i][0];
        std::cin >> arr[i][1];
    }
    
    std::cout << stolen(0, M);
    
    return 0;
}