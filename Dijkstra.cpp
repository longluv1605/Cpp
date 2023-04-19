#include <bits/stdc++.h>

const int INF = 1e9;

class Dijkstra {
private:
    int N, M;
    
    // Danh sach ke kem co trong so (dinh ke, khoang cach).
    std::vector<std::vector<std::pair<int, int>>> adj; 
    
    // Hang doi uu tien voi cap (khoang cach, dinh) voi top la phan tu co khoang cach nho nhat.
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> Q;

    //Danh sach luu cac dinh da kiem tra xong.
    std::vector<bool> visited;

    //Danh sach luu duong di tinh tu s.
    std::vector<int> dist;

public:
    Dijkstra(int _N, int _M)
        : N(_N), M(_M), adj(N + 1), visited(N + 1, false), dist(N + 1, INF)
    {}

    void addEdge(int u, int v, int w) {
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void dijkstra(int s) {
        dist[s] = 0;

        Q.push({0, s});
        while (!Q.empty()) {
            std::pair<int, int> top = Q.top();
            Q.pop();
            int u = top.second;
            //int kc = top.first;
            visited[u] = true;
            
            for (const auto &x : adj[u]) {
                int v = x.first;
                int w = x.second;
                if (visited[v]) continue;
                if (dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    Q.push({dist[v], v});
                }
            }
        }
    }

    int getDist(int t) {
        return dist[t];
    }
};

int getDistTo(Dijkstra *d, int s, int t) {
    d->dijkstra(s);
    return d->getDist(t);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, M, s, t;
    std::cin >> N >> M >> s >> t;

    Dijkstra *d = new Dijkstra(N, M);

    for (int i = 0; i < M; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;

        d->addEdge(u, v, w);
    }

    std::cout << getDistTo(d, s, t) << std::endl;

    return 0;
}