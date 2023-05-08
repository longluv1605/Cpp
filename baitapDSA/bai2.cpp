#include <iostream>
#include <algorithm>

int search(int arr[], int x, int l, int r) {
    while (l <= r) {
        int m = (l + r) / 2;
        if (arr[m] == x) return m;
        if (x >= arr[0]) {
            if (arr[m] > x) return search(arr, x, l, m - 1);
            else {
                if (arr[m] >= arr[0]) return search(arr, x, m + 1, r);
                else return search(arr, x, l, m - 1);
            }
        }
        else {
            if (arr[m] < x) return search(arr, x, m + 1, r);
            else {
                if (arr[m] < arr[0]) return search(arr, x, l, m - 1);
                else return search(arr, x, m + 1, r);
            }
        }
    }
    return -1;
}

int main() {
    int arr[] = {-1, -1, 0, 1, 2, 2, 3, 3, 3, 3, 3, 3, 7, 7,8 ,-12, -8, -6, -1};
    int x = 8;
    std::cout << search(arr, x, 0, 18);
    return 0;
}