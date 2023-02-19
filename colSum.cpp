#include <iostream> 

int main() {
    int m, n;
    std::cin >> m >> n;
    
    int matrix[m][n], ans[n];

    for(auto& x : ans) x = 0;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            std::cin >> matrix[i][j];
            ans[j] += matrix[i][j];
        }
    }
    
    for(int j = 0; j < n; j++) {
        std::cout << ans[j] << " ";
    }
    
    return 0;
}