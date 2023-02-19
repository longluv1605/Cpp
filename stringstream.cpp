#include <iostream>
#include <string>
#include <sstream>
#include <vector>

void leak(std::string input, std::vector<int>& num, std::vector<char>& key) {
    std::stringstream ss(input);
    int n;
    char c;
    if (input[0] >= '0' && input[0] <= '9') {
        while (ss >> n >> c) {
            num.push_back(n);
            key.push_back(c);
        }
    }
    else {
        while (ss >> c >> n) {
            num.push_back(n);
            key.push_back(c);
        }
    }
}

int main()
{
    std::string input = "5+323*9-2(2-1)";
    // std::getline(std::cin, input);
    std::vector<int> num;
    std::vector<char> key;
    
    leak(input, num, key);

    for (auto x : num) std::cout << x << " ";
    std::cout << "\n";
    for (auto x : key) std::cout << x << " ";
    std::cout << "\n";

    return 0;
}