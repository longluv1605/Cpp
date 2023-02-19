//In ra so phan tu khac nhau trong mang so nguyen.

#include<iostream>
#include<set>
#include<algorithm>

int main(){
    int n;
    std::cin >> n;
    
    std::set<int> arr;

    for(int i = 0; i < n; i++){
        int x;
        std::cin >> x;
        arr.insert(x);
    }

    for(auto x: arr){
        std::cout << x << " ";
    }
    std::cout << "\n" << arr.size() << "\n";

    system("pause");

    return 0;
} 