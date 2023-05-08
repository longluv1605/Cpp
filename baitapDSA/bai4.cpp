#include <bits/stdc++.h>

int n, M;
int res = 0;
bool changeI, changeJ; 

void getAns(int arr[][2], int i, int j, int P, int V) {
    if (j < i) return;
    if (changeI) {
        P -= arr[i - 1][0];
        V -= arr[i - 1][1];
        // changeI = false;
    }
    if (changeJ) {
        P -= arr[j + 1][0];
        V -= arr[j + 1][1];
        // changeJ = false;
    }
    
    if (P <= M && res < V) res = V; 
    
    changeI = true; changeJ = false;
    getAns(arr, i + 1, j, P, V);
    
    changeJ = true; changeI = false;
    getAns(arr, i, j - 1, P, V);
}

int main() {
    std::cin >> n >> M;
    int P = 0, V = 0;
    
    int arr[n][2];
    for (int i = 0; i < n; i++) {
        int p, v;
        std::cin >> p >> v;
        arr[i][0] = p;
        arr[i][1] = v;
        P += p;
        V += v;
    }
    
    changeJ = false; changeI = false;
    getAns(arr, 0, n - 1, P, V);
    
    std::cout << res;
    return 0;
}