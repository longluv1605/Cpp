#include <bits/stdc++.h>

int n, k;
int partition(int arr[], int l, int r) {
    int i = l - 1;
    int j = r + 1;
    int p = arr[r];
    while (1) {
        do { 
            ++i;
        } while (arr[i] < p);
        do {
            --j;
        } while (arr[j] > p);
        if (j < i) break;
        std::swap(arr[i], arr[j]);
    }
    return j;
}

void qsort(int arr[], int l, int r) {
    if (l >= r) return;
    int p = partition(arr, l, r);
    qsort(arr, l, p);
    if (p == k - 1) std::cout << arr[p];
    qsort(arr, p + 1, r);
}

/* 
11 2
4 1 3 5 8 6 3 7 9 1 2
*/
int main() {
    std::cin >> n >> k;
    int arr[n];
    for (auto &x : arr) std::cin >> x;
    qsort(arr, 0, n - 1);
    return 0;
}