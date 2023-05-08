#include <iostream>
#include <algorithm>

int start, end;

int findLeft(int arr[], int x, int l, int r) {
    if (l > r) return -1;
    int m = (l + r) / 2;

    if (arr[m] == x) {
        int ans = findLeft(arr, x, l, m - 1);
        return ans == -1 ? m : ans;
    }
    return findLeft(arr, x, m + 1, r);
}

int findRight(int arr[], int x, int l, int r) {
    if (l > r) return -1;
    int m = (l + r) / 2;

    if (arr[m] == x) {
        int ans = findRight(arr, x, m + 1, r);
        return ans == -1 ? m : ans;
    }
    return findRight(arr, x, l, m - 1);
}

int find(int arr[], int x, int l, int r) {
    if (l > r) return -1;
    int m = l + (r - l) / 2;
    
    if (arr[m] == x) return m;

    if (arr[m] > x) return find(arr, x, l, m - 1);
    return find(arr, x, m + 1, r);
}

void getAns(int arr[], int x) {
    int pivot = find(arr, x, 0, 18);
    // std::cout << pivot << std::endl;
    if (pivot == -1) {
        start = pivot;
        end = pivot;
        return;
    }

    int left = findLeft(arr, x, 0, pivot - 1);
    int right = findRight(arr, x, pivot + 1, 18);
    // std::cout << left << " " << right << std::endl;
    start = (left == -1 ? pivot : left);
    end = (right == -1 ? pivot : right);
}

int main() {
    int arr[] = {-12, -8, -6, -3, -1, -1, 0, 1, 2, 2, 3, 3, 3, 3, 3, 3, 7, 7,8};
    int x = 8;

    getAns(arr, x);
    
    // std::cout << findLeft(arr, 3, 0, 9);

    std::cout << "[" << start << ", " << end << "]\n";
    return 0;
}