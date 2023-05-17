#include <bits/stdc++.h>

std::stack<char> getStack(std::string str) {
    std::stack<char> st;
    for (auto c : str) {
        if (c == '#' && !st.empty()) {
            st.pop();
        }
        else st.push(c);
    }

    return st;
}

std::string reString(std::string str) {
    std::stack<char> st = getStack(str);
    std::string s = "";
    while (!st.empty()) {
        s = st.top() + s;
        st.pop();
    }
    return s;
}

bool check(std::string a, std::string b) {
    a = reString(a);
    b = reString(b);
    return a == b;
}


int main() {
    std::string a, b;
    std::cin >> a >> b;

    std::cout << check(a, b);

    return 0;
}