#include <bits/stdc++.h>

int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

int n; 
int map[1001][1001];
bool visited[1001][1001] = {{false}};

void dfs(int x, int y) {
    if (visited[x][y]) return;
    visited[x][y] = true;
    
    if (x != y) dfs(y, x);
    
    for (int i = 0; i < 4; i++) {
        int u = x + move[i][0], v = y + move[i][1];
        if (u >= 0 && u < n && v >= 0 && v < n && !visited[u][v] && map[u][v] == 1) {
            dfs(u, v);
        }
    }
    
    // int i1 = x, i2 = x, j1 = y, j2 = y;
    // while (i1 >= 0) {
    //     if (!visited[i1][y] && map[i1][y] == 1) {
    //         dfs(i1, y);
    //     }
    //     i1--;
    // }
    // while (i2 < n) {
    //     if (!visited[i2][y] && map[i2][y] == 1) {
    //         dfs(i2, y);
    //     }
    //     i2++;
    // }
    // while (j1 >= 0) {
    //     if (!visited[x][j1] && map[x][j1] == 1) {
    //         dfs(x, j1);
    //     }
    //     j1--;
    // }
    // while (j2 < n) {
    //     if (!visited[x][j2] && map[x][j2] == 1) {
    //         dfs(x, j2);
    //     }
    //     j2++;
    // }
}

int count() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                cnt++;
                dfs(i, j);
            }
        }
    }
    return cnt;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> map[i][j];
        }
    }

    std::cout << count();
    
    return 0;
}