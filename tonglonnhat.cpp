#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n; std::cin >> n;
    int arr[n];
    
    for(auto& x: arr) std::cin >> x;
    int sum;
    
    std::vector<int> s;
    
    for(int i = 0; i <= n - 4; i++) {
        sum = arr[i] + arr[i + 1] + arr[i + 2] + arr[i + 3];
        s.push_back(sum);
    }

    //for(auto x : s) std::cout << x << " ";

    std::sort(s.begin(), s.end());

    std::cout << *(s.end() - 1);

    return 0;
}