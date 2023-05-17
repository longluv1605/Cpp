#include <bits/stdc++.h>

int length(int arr[], int n, int k) {
    int len = n, sum = 0, i = 0, j = 0;

    for (; j < n; j++) {
        sum += arr[j];
        while (sum >= k) {
            len = std::min(len, j - i + 1);
            sum -= arr[i++];
        }
    }
    return len;
}

/*
10 20
1 2 3 4 5 6 2 7 3 8
*/

int main() {
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\input.txt", "r", stdin);
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\output.txt", "w", stdout);

    int n, k; std::cin >> n >> k;

    int arr[n];
    for (auto &x : arr) std::cin >> x;
    
    std::cout << length(arr, n, k);

    return 0;
}