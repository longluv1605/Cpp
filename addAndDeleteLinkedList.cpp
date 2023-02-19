#include <iostream>

struct Node {
    int value;
    Node* nextNode;
};

Node* makeNode(int value) {
    Node* newNode = new Node();
    newNode->value = value;
    newNode->nextNode = NULL;
    
    return newNode;
}

int size(Node* head) {
    int cnt = 0;
    while (head != NULL) {
        head = head->nextNode;
        cnt++;
    }
    
    return cnt;
}

//0 1 2 3 4 5
//n = 6

Node* addNode(Node* head, int index, int value){
    Node* newNode = makeNode(value);
    Node* temp = head;
    int n = size(temp);
    
    if (index > n) return head;

    if (index == 0) {
        newNode->nextNode = temp;
        return head = newNode;
    } 
    
    for (int i = 1; i < index; i++) {
        temp = temp->nextNode;
    }
    newNode->nextNode = temp->nextNode;
    temp->nextNode = newNode;
    return head;
}


Node* deleteNode(Node* head, int index){
    Node* temp = head;
    int n = size(head); 

    if(index > n) return head;

    if(index == 0) return head = head->nextNode;

    for(int i = 1; i < index; i++) {
        temp = temp->nextNode;
    }    
    temp->nextNode = (temp->nextNode)->nextNode;
    return head;
}

void print(Node* head) {
    std::cout << size(head) << "\n--------------------------------\n";
    while (head != NULL) {
        std::cout << head->value << " " << head << std::endl;
        head = head->nextNode;
    }
    std::cout << "-------------------------------\n\n"; 
}

int main() {
    Node* head = NULL;

    for (int i = 0; i < 10; i++) {
        head = addNode(head, i, i + 10);
    }
    head = addNode(head, 0, 22);

    print(head);

    head = addNode(head, 1, 11);

    print(head);

    head = deleteNode(head, 0);

    print(head);

    return 0;
}