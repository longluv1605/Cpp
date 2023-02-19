#include <iostream>
#include <iomanip>

int main() {
    int n;
    std::cin >> n;
    
    int a[n][n];
    
    int x = 1, i = 0, j = 0;
    
    int top = 0, back = n, left = 0, right = n;

    int cnt = 0;

    // std::cout << x << " " << i << " " << j << " " << top
    //      << " " << back << " " << left << " " << right
    //      << std::endl;
    
    while(cnt != n * n) {
        while(j < right) {
            a[i][j] = x;
            x++;
            j++;
            cnt++;
        }
        
        i++; j--;
        while(i < back) {
            a[i][j] = x;
            x++;
            i++;
            cnt++;
        }
        
        j--; i--;
        while(j >= left) {
            a[i][j] = x;
            x++;
            j--;
            cnt++;
        }
        
        i--; j++;
        while(i > top) {
            a[i][j] = x;
            x++;
            i--;
            cnt++;
        }
        j++; i++;
        
        top++; left++; right--; back--;
    }

    // std::cout << x << " " << i << " " << j << " " << top
    //      << " " << back << " " << left << " " << right
    //      << std::endl;
    
    
    for(int p = 0; p < n; p++) {
        for(int q = 0; q < n; q++) {
            std::cout << std::setw(4) << a[p][q];
        }
        
        std::cout << std::endl;
    }
    return 0;
}