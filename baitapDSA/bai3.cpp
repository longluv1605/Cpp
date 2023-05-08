#include <iostream>
#include <algorithm>

int res = INT_MAX;

int search(int arr[], int l, int r) {
    if (l > r) return l;
    int m = (l + r) / 2;
    if (arr[m] >= arr[0]) return search(arr, m + 1, r);
    return search(arr, l, m - 1);
}

int main() {
    int arr[] = {-1, -1, 0, 1, 2, 2, 3, 3, 3, 3, 3, 3, 7, -17, -14 ,-12, -8, -6, -1};
    int x = 8;
    std::cout << search(arr, 0, 18) << "-->" << arr[search(arr, 0, 18)];
    return 0;
}