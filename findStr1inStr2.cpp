#include <iostream>
#include <string>

int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;
    
    /*size_t found = str2.find(str1, 0);
    
    (found == std::string::npos) ? std::cout << "NO" : std::cout << "YES";*/
    int check;
//     string
// substringexample

    for (int i = 0; i < (int) str2.size() - 1; i++) {
        check = 0;
        
        for (int j = 0; j < (int) str1.size() - 1; j++) {
            if (str1[j] == str2[i]) {
                i++;
                check++;
            }
            else break;
        }
        
        if (check == (int) str1.size() - 1) break;
    }
    
    (check == (int) str1.size() - 1) ? std::cout << "YES" : std::cout << "NO";
    
    return 0;
}