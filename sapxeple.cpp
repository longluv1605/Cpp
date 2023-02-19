#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n; std::cin >> n;
    int arr[n];
    std::vector<int> id, value;

    for(int i = 0; i < n; i++) {
        std::cin >> arr[i];
        if(arr[i] % 2 != 0) {
            id.push_back(i);
            value.push_back(arr[i]);
        }
    }
    std::sort(value.begin(), value.end());

    for(int i = 0; i < (int) id.size(); i++) {
        arr[id[i]] = value[i];
    }

    for(auto x: arr) std::cout << x << " ";

    return 0;
}