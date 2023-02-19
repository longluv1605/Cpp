#include<iostream>

int parents[51];

void make_set(int n){
    for(int i = 1; i <= n; i++){
        std::cin >> parents[i];
    }
}

/*
    1 2 3 4 5 6 7 8 9 
    1 6 2 1 2 7 9 8 4
*/

//Solution 1.
int find(int v){
    if(v == parents[v]) return v;
    return parents[v] = find(parents[v]);
}

//Solution 2.
// int find2(int v){
//     int k = v;
//     while(k != parents[k]){
//         k = parents[k];
//     }

//     while(v != parents[v]){
//         int i = v;
//         v = parents[v];
//         parents[i] = k;
//     }

//     return v;
// }


void UnionF(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b){
        parents[b] = a;
    }
}

int main(){
    int n; std::cin >> n;

    std::cout << "1 2 3 4 5 6 7 8 9" << std::endl;

    make_set(n);

    int v;
    std::cin >> v;

    std::cout << find(v) << std::endl;


    return 0;
}