#include <iostream> 
#include <vector>
#include <string>
#include <sstream>

int main() {
    std::string input;
    std::getline(std::cin, input);

    //std::cout << input << std::endl;
    
    std::vector<int> vt;

    std::stringstream ss(input);
    int num;
    while(ss >> num) {
        //std::cout << num << "-->"; 
        vt.push_back(num);    
    }
    //std::cout << std::endl;

    //for(auto x: vt) std::cout << x << " ";

    int size = vt.size(), sum = 0;
    for(int i = 1; i < size - 1; i++) {
        if(vt[i] > vt[i - 1] && vt[i] > vt[i + 1]) sum += vt[i];
    }

    std::cout << sum;
    
    return 0;
}