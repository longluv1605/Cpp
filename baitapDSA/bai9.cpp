#include <bits/stdc++.h>

int counter(int arr[], int n, int k) {
    int i = 0, j = 0, cnt = 0;
    int mul = 1;
    
    for (; j < n; j++) {
        mul *= arr[j];
        while (mul > k) {
            mul /= arr[i++];
        }
        cnt += j - i + 1;
    }
    return cnt;
}

/*
10 30
1 2 3 4 5 6 3 7 1 8
*/

int main() {
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\input.txt", "r", stdin);
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\output.txt", "w", stdout);

    int n, k; std::cin >> n >> k;
    int arr[n];
    for (auto &x : arr) std::cin >> x;

    std::cout << counter(arr, n, k);

    return 0;
}