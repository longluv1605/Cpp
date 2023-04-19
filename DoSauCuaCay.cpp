#include <bits/stdc++.h>

class Graph {
private: 
    std::vector<std::vector<int>> adj;
    int N, M;
    std::vector<bool> marked;
    std::vector<int> edgeTo;
    std::vector<int> distTo;
public:
    Graph(int _N) : N(_N) , M(0), marked(N, false), edgeTo(N), distTo(N, -1) {
        adj.resize(N);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
        M++;
    }

    void BFS(int s) {
        edgeTo[s] = s;
        distTo[s] = 0;

        std::queue<int> queue;
        queue.push(s);
        marked[s] = true;

        while (!queue.empty()) {
            int w = queue.front();
            queue.pop();
            for (const auto &x : adj[w]) {
                if (!marked[x]) {
                    edgeTo[x] = w;
                    distTo[x] = distTo[w] + 1;
                    marked[x] = true;
                    queue.push(x);
                }
            }
        }
    }
    
    std::vector<int> getDist() {
        return distTo;
    }
};

int getMaxDist(Graph graph) {
    std::vector<int> dist = graph.getDist();
    int maxDist = 0;
    for (const auto &x : dist) {
        if (x > maxDist) maxDist = x;
    }
    return maxDist;
}

int main() {
    int n; std::cin >> n;
    Graph *graph = new Graph(n);
    
    for (int i = 0; i < n - 1; i++) {
        int v, e;
        std::cin >> v >> e;
        graph->addEdge(v, e);
    }

    graph->BFS(0);
    std::cout << getMaxDist(*graph) << std::endl;
    return 0;
}