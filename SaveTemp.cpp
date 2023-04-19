#include <bits/stdc++.h>

class Graph
{
private:
    std::vector<std::vector<int>> adj;
    int N, M;
    std::vector<std::map<int, int>> length;
    std::vector<bool> marked;
    std::vector<int> edgeTo;
    std::vector<int> distTo;

public:
    Graph(int _N) : N(_N), M(0), length(N), marked(N, false), edgeTo(N, 0), distTo(N, -1)
    {
        adj.resize(N);
    }

    void addEdge(int u, int v, int w)
    {
        adj[u].push_back(v);
        length[u][v] = w;
        adj[v].push_back(u);
        length[v][u] = w;
        M++;
    }

    void BFS(int s, int t)
    {
        edgeTo[s] = s;
        distTo[s] = 0;

        std::queue<int> queue;
        queue.push(s);
        marked[s] = true;

        while (!queue.empty())
        {
            int w = queue.front();
            queue.pop();
            for (const auto &x : adj[w])
            {
                if (!marked[x]) {
                    edgeTo[x] = w;
                    if (x != t) marked[x] = true;
                    if (x == t && distTo[x] != -1) distTo[x] = std::min(distTo[x], distTo[w] + length[x][w]);
                    else distTo[x] = distTo[w] + length[x][w];
                    queue.push(x);
                }
            }
        }
    }

    int getDist(int s, int t)
    {
        BFS(s, t);
        return distTo[t];
    }
};

int main()
{
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    Graph *graph = new Graph(n);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph->addEdge(u, v, w);
    }

    std::cout << graph->getDist(s, t) << std::endl;
    return 0;
}