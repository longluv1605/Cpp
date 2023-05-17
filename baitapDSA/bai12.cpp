#include <bits/stdc++.h>

struct Node {
    int val;
    Node *next;
    Node *left;
    Node *right;
    Node *parent;
};

Node* findParent(Node *head, int par) {
    if (head == NULL) return NULL;
    if (head->val == par) return head;
    if (findParent(head->left, par) != NULL) return findParent(head->left, par);
    return findParent(head->right, par);
}


void add(Node *head, int par, int val) {
    Node *newNode = new Node();
        newNode->val = val;
        newNode->next = NULL;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
    Node *parent = findParent(head, par);
    if (parent == NULL) parent = newNode;
    else if (parent->left == NULL) parent->left = newNode;
    else parent->right = newNode;
    newNode->parent = parent;
}

void matchNext(Node *head) {
    std::queue<Node *> queue;
    queue.push(head);

    while (!queue.empty()) {
        Node *cur = queue.front();
        queue.pop();
        if (cur->parent != NULL) {
            if (cur == cur->parent->left && cur->parent->right != NULL) {
                cur->next = cur->parent->right;
            } 
            else {
                if (cur->parent->next != NULL) {
                    cur->next = cur->parent->next->left != NULL ? cur->parent->next->left : cur->parent->next->right;
                }
            }
        }
        if (cur->left != NULL) queue.push(cur->left);
        if (cur->right != NULL) queue.push(cur->right);
    }
}

int main() {
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\input.txt", "r", stdin);
    freopen("D:\\VsCode\\NormalProject\\Project1\\baitapDSA\\output.txt", "w", stdout);
    int n;
    std::cin >> n;
    Node *head;
    head->val = 1;
    head->next = NULL;
    head->left = NULL;
    head->right = NULL;
    head->parent = NULL;

    while (--n) {
        int par, val;
        std::cin >> par >> val;
        add(head, par, val);
    }

    matchNext(head);

    for (int i = 1; i < 7; i++) {
        Node *cur = findParent(head, i);
        std::cout << i << " ";
        if (cur->next == NULL) std::cout << "NULL\n";
        else std::cout << cur->next->val << std::endl; 
    }

    return 0;
}