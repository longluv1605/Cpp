#include <iostream>
#include <string>

int main() {
    std::string str = "abcde";
    for(int i = 0; i < (int) str.size() / 2; i++){
        std::swap(str[i], str[str.size() - i - 1]);
    }
    
    std::cout << str;
    return 0;
}