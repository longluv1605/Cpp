#include <bits/stdc++.h>

bool canDelete(std::vector<int> rank) {
    for (auto x : rank) if (x > 1) return true;
    return false;
}

void print(std::vector<std::vector<int>>& adj, std::vector<int>& rank, int n) {
    while (canDelete(rank)) {
        std::vector<bool> marked(n, false);
        for (int i = 0; i < n; i++) {
            if (rank[i] == 1 && !marked[i]) {
                rank[i] = -1;
                for (auto j : adj[i]) {
                    // if (!marked[j]) {
                        --rank[j];
                        marked[j] = true;
                    // }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) if (rank[i] >= 0) std::cout << i << " ";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n; std::cin >> n;
    std::vector<std::vector<int>> adj(n);
    std::vector<int> rank(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        rank[u]++;
        rank[v]++;
    }
    
    print(adj, rank, n);
    
    return 0;
}