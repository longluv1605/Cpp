#include <bits/stdc++.h>

void setSum(int sum[], int n) {
    for (int i = 0; i < n; i++) {
        int x; std::cin >> x;
        sum[i] = x;
    }
    for (int i = n - 2; i >= 0; i--) {
        sum[i] += sum[i + 1];
    }
}

void setQueue(std::queue<int> &qu, int sum[], int n) {
    for (int i = 0; i < n; i++) {
        qu.push(sum[i]);
    }
}

int getAns(std::queue<int> quMinSize, std::queue<int> quA, std::queue<int> quB) {
    while (!(quMinSize.front() == quA.front() && quA.front() == quB.front())) {
        while (quMinSize.front() > quA.front() || quMinSize.front() > quB.front()) {
            quMinSize.pop();
        }
        while (quA.front() > quMinSize.front()) {
            quA.pop();
        }
        while (quB.front() > quMinSize.front()) {
            quB.pop();
        }
    }
    return quMinSize.front();
}

int main() {
    int n1, n2, n3;
    std::cin >> n1 >> n2 >> n3;
    int sum1[n1], sum2[n2], sum3[n3];
    std::queue<int> qu1, qu2, qu3;

    setSum(sum1, n1); setQueue(qu1, sum1, n1);
    setSum(sum2, n2); setQueue(qu2, sum2, n2);
    setSum(sum3, n3); setQueue(qu3, sum3, n3);

    if (n1 <= n2 && n1 <= n3) {
        std::cout << getAns(qu1, qu2, qu3);
    }
    else if (n2 <= n3 && n2 <= n1) {
        std::cout << getAns(qu2, qu1, qu3);
    }
    else {
        std::cout << getAns(qu3, qu2, qu1);
    }
    // 8 5 3 2 1
    // 9 5 2
    // 7 6 5 1
    return 0;
}