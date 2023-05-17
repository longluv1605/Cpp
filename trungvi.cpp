#include <bits/stdc++.h>

std::pair<int, int> partition(int arr[], int l, int r) {
    int i = l, gl = l, gr = r;
    int p = arr[r];
    while (i <= gr) {
        if (arr[i] == p) i++;
        else if (arr[i] < p) std::swap(arr[gl++], arr[i++]);
        else std::swap(arr[gr--], arr[i]);
    }
    return {gl, gr};
}

int getMedian(int arr[], int l, int r, int k) {
    if (r == l) return l;
    std::pair<int, int> p = partition(arr, l, r);
    if (k >= p.first && k <= p.second) return arr[k];
    if (k < p.first) return getMedian(arr, l, p.first - 1, k);
    return getMedian(arr, p.second + 1, r, k);
}

int main() {
    int n; std::cin >> n;
    int arr[n];
    for (auto &x : arr) std::cin >> x;
    // if (n % 2 != 0) std::cout << std::setprecision(1) << std::fixed << getMedian(arr, 0, n - 1, n / 2) * 1.0;
    // else std::cout << std::setprecision(1) << std::fixed << (getMedian(arr, 0, n - 1, n / 2 - 1) + getMedian(arr, n / 2 - 1, n - 1, n / 2)) / 2.0;
    
    std::pair<int, int> k = partition(arr, 0, n - 1);
    std::cout << k.first << " " << k.second << std::endl;
    for (auto x : arr) std::cout << x << " ";
    
    return 0;
}