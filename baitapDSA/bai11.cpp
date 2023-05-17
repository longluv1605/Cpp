#include <bits/stdc++.h>

int n;
int move[][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
std::vector<std::vector<int>> grid;

void dfs(int x, int y) {
    grid[x][y] = 0;
    for (int k = 0; k < 4; k++) {
        int i = x + move[k][0];
        int j = y + move[k][1];
        if (i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 1) {
            dfs(i, j);
        }
    }
}

int count() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    return cnt;
} 

int main() {
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\input.txt", "r", stdin);
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\output.txt", "w", stdout);
    std::cin >> n;

    std::vector<std::vector<int>> _grid(n, std::vector<int>(n));
    grid = _grid;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::cout << count();

    // std::cout << move[0][10];

    return 0;
}