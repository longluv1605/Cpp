#include <iostream>
#include <iomanip>

void printPyramid(int n) {
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= n - i; j++) {
            std::cout << "     ";
        }

        int x = i;
        for(int j = 1; j <= i; j++) {
            std::cout << std::setw(5) << x++;
        }

        x -= 2;
        for(int j = 1; j < i; j++){
            std::cout << std::setw(5) << x--;
        }

        std::cout << std::endl;

    }
}

int main(int argc, char* argv[]) {
    int n;
    std::cin >> n;

    printPyramid(n);

    return 0;
}