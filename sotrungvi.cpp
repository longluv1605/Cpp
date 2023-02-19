#include <iostream>
#include <algorithm>

int main() {
    int n; std::cin >> n;
    int arr[n];

    for(auto& x : arr) std::cin >> x;

    std::sort(arr, arr + n);

    if(n % 2 != 0) std::cout << arr[n / 2];
    else std::cout << (arr[n / 2] + arr[n / 2 - 1]) / 2;

    return 0;
}