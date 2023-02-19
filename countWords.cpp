#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() {
    std::string s;
    std::getline(std::cin, s);
    
    /*Solution using stringstream & vector<string>.
    
    std::stringstream ss(s);
    
    std::vector<std::string> vt;
    std::string temp;
    
    while (ss >> temp) {
        vt.push_back(temp);
        
    }
    std::cout << vt.size();
    */
    
    //Solution 2.
    std::string str[500]; 
    
    int k = 0, cnt = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        if (s[i] == ' ' && s[i + 1] == ' ') {
            continue;
        } 
        else if (s[i] == ' ' && s[i + 1] != ' ') {
            k++;
            continue;
        }
        else {
            str[k] += s[i];
        }
    }
    for (int i = 0; i < 500; i++) {
        if (str[i] == "\0") break;
        cnt++;
    }
    
    std::cout << cnt;
    
    return 0;
}