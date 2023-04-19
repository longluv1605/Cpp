#include <bits/stdc++.h>

int n, m;

bool dfs(std::vector<std::vector<int>>& adj, std::vector<char>& color, int s) {
    int u = s;
    color[u] = 'g';
    for (auto v : adj[u]) {
        if (color[v] == 'w') {
            if(!dfs(adj, color, v)) return false;
        }
        else if (color[v] == 'g') {
            return false;
        }
    }
    color[u] = 'b';
    return true;
}

bool checkDFS(std::vector<std::vector<int>>& adj, std::vector<char>& color) {
    for (int i = 0; i < n; i++) {
        if (color[i] == 'w') if (!dfs(adj, color, i)) return false;
    }
    return true;
}

bool kahn(std::vector<std::vector<int>>& adj, std::vector<char>& color, std::vector<int>& in) {
    std::queue<int> queue;
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) queue.push(i);
    }

    int check = 0;
    while (!queue.empty()) {
        int u = queue.front();
        queue.pop();
        check++;
        for (auto v : adj[u]) {
            in[v]--;
            if (in[v] == 0) queue.push(v); 
        }
    }
    return check == n;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    std::cin >> n >> m;
    std::vector<std::vector<int>> adj(n);
    std::vector<char> color(n, 'w');
    std::vector<int> in(n, 0);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        in[v]++;
    }
    

    if (kahn(adj, color, in)) std::cout << "yes";
    else std::cout << "no";
    return 0;
}