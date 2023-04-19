#include <bits/stdc++.h>

int n;
std::vector<std::vector<int>> children;
std::vector<bool> visited;
std::vector<int> height;

void bfs(int s) {
    height[s] = 0;
    visited[s] = true;
    std::queue<int> queue;
    queue.push(s);
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        for (auto& child : children[u]) {
            if (!visited[child]) {
                visited[child] = true;
                height[child] = height[u] + 1;
                queue.push(child);
            }
        }
    }
}

bool check (int s) {
    bfs(s);
    int h = 0;
    for (int i = 0; i < n; i++) {
        if (children[i].size() == 0) {
            if (h != 0) {
                if (h != height[i]) return false;
                else h = height[i];
            }
        }
        else if (children[i].size() != 2) {
            return false;
        } 
    }
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::cin >> n;
    std::vector<std::vector<int>> _children(n); children = _children;
    std::vector<bool> _visited(n, false); visited = _visited;
    std::vector<int> _height(n); height = _height;

    for (int i = 0; i < n - 1; i++) {
        int u, v; std::cin >> u >> v;
        children[u].push_back(v);
    }

    if (check(0)) std::cout << "yes";
    else std::cout << "no";
}