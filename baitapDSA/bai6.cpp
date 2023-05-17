#include <bits/stdc++.h>

int n, m;

int partition(std::vector<std::pair<int, int>> vector, int l, int r) {
    if (r < l) return -1;
    int p = vector[r].first;
    int i = l - 1, j = r + 1;
    while (1) {
        do {
            i++;
        } while (vector[i].first < p);
        do {
            j--;
        } while (vector[j].first > p);

        if (j < i) break;
        std::swap(vector[j], vector[i]);
    }
    return j;
}

void qsort(std::vector<std::pair<int, int>> vector, int l, int r) {
    if (r <= l) return;
    int p = partition(vector, l, r);
    qsort(vector, l, p);
    qsort(vector, p + 1, r);
}

std::vector<std::pair<int, int>> intersect(std::vector<std::pair<int, int>> firstList, std::vector<std::pair<int, int>> secondList) {
    std::vector<std::pair<int, int>> res;
    int i = 0, j = 0;
    while (i < n && j < m) {
        std::pair<int, int> x = firstList[i];
        std::pair<int, int> y = secondList[j];

        if (x.second >= y.first || x.first <= y.second) {
            std::pair<int, int> p;
            p.first = std::max(x.first, y.first);
            p.second = std::min(x.second, y.second);
            if (x.second < y.second) ++i;
            else ++j;
            res.push_back(p);
        }
    }

    return res;
}

int main() {
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\input.txt", "r", stdin);
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\output.txt", "w", stdout);
    std::cin >> n >> m;

    std::vector<std::pair<int, int>> firstList(n), secondList(m);

    for (int i = 0; i < n; i++) {
        int start, end;
        std::cin >> start >> end;
        firstList[i] = {start, end};
    }
    qsort(firstList, 0, n - 1);
    

    for (int i = 0; i < m; i++) {
        int start, end;
        std::cin >> start >> end;
        secondList[i] = {start, end};
    }
    qsort(secondList, 0, m - 1);

    std::vector<std::pair<int, int>> res = intersect(firstList, secondList);
    
    for (auto x : res) {
        std::cout << "[" << x.first << ", " << x.second << "]" << std::endl;
    }

    return 0;
}