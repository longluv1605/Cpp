#include <bits/stdc++.h>

class Graph {
private:
    std::vector<std::vector<int>> adj;
    int N, M;
    std::vector<int> edgeTo;
    std::vector<int> distTo;
    std::vector<std::map<int, int>> length;
    std::vector<std::map<int, bool>> canGo;

public:
    Graph(int _N, int _M)
        : N(_N), M(_M), edgeTo(N, 0), distTo(M, -1), length(N), canGo(N)
    {
        adj.resize(N);
    }

    void addEdge(int u, int v, int w) {
        adj[u].push_back(v);
        canGo[u][v] = true;
        length[u][v] = w;
        adj[v].push_back(u);
        canGo[v][u] = true;
        length[v][u] = w;
    }

    void BFS(int s, int t) {
        edgeTo[s] = s;
        distTo[s] = 0;
        
        std::queue<int> queue;
        queue.push(s);

        while (!queue.empty()) {
            int w = queue.front();
            queue.pop();
            for (const auto &x : adj[w]) {
                if (canGo[w][x]) {
                    edgeTo[x] = w;
                    canGo[x][w] = false;
                    if (x == t && distTo[x] != -1) distTo[x] = std::min(distTo[x], distTo[w] + length[x][w]);
                    else distTo[x] = distTo[w] + length[x][w];
                    queue.push(x);
                }
            }
        }
    }

    int getMinDist(int s, int t) {
        BFS(s, t);
        return distTo[t];
    }
};

int main() {
    int N, M, s, t;
    std::cin >> N >> M >> s >> t;

    Graph *graph = new Graph(N, M);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph->addEdge(u, v, w);
    }

    std::cout << graph->getMinDist(s, t) << std::endl;
    return 0;
}