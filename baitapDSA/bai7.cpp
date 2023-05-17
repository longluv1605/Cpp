#include <bits/stdc++.h>

int mostWater(int arr[], int n) {
    int res = 0;
    int i = 1, j = n;
    while (i < j) {
        res = std::max(res, std::min(arr[i], arr[j]) * (j - i));

        if (arr[i] <= arr[j]) {
            ++i;
        }
        else --j;
    }
    return res;
}

int main() {
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\input.txt", "r", stdin);
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\output.txt", "w", stdout);

    int n;
    std::cin >> n;
    int arr[n + 1];
    for (int i = 1; i <= n; i++) std::cin >> arr[i];

    std::cout << mostWater(arr, n) << std::endl;

    return 0;
}