#include <bits/stdc++.h>

bool check(std::string s, std::string p) {
    if (s.size() < p.size()) return false;
    // qsort(p, 0, p.size() - 1);
    std::sort(p.begin(), p.end());

    for (int i = 0; i <= s.size() - p.size(); ++i) {
        std::string tmp = s.substr(i, p.size());
        //qsort(tmp, 0, p.size() - 1);
        std::sort(tmp.begin(), tmp.end());
        if (tmp == p) return true;
    }
    return false;
}

int partition(std::string &s, int l, int r) {
    char p = s[r];
    int i = l - 1, j = r + 1;

    while (true) {
        do {
            ++i;
        } while (s[i] < p);

        do {
            --j;
        } while (s[j] > p);
        if (j < i) break;
        std::swap(s[i], s[j]);
    }
    return j;
}

void qsort(std::string &s, int l, int r) {
    if (l >= r) return;
    int p = partition(s, l, r);
    qsort(s, l, p);
    qsort(s, p + 1, r);
}

//abcde
//ace

int main() {
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\input.txt", "r", stdin);
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\output.txt", "w", stdout);

    std::string s, p;
    std::cin >> s >> p;

    if (check(s, p)) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;

    return 0;
}