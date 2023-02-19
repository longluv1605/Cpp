#include <iostream>
#include <string>

//abcda

int main() {
    std::string str = "abcd";
    //std::cin >> str;
    int id = 3; char c = 'a';
    
    //std::cin >> id >> c;
    
    //str.insert(id, 1, c);
    str += c; std::cout << str << " " << str.size() << std::endl;
    for(int i = (int) str.size() - 1; i > id; i--) {
        std::swap(str[i], str[i - 1]);
    }
    
    std::cout << str;
    
    return 0;
}