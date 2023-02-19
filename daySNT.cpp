//In ra day gom cac so lien tiep khong la so nguyen to.


#include<iostream>
#include<utility>
#include<vector>

bool checkSNT(int x){
    for(int i = 2; i < x; i++){
        if(x % i == 0) return false;
    }
    
    return true;
}

void khoiTao(int arr[], int L[], int n){
    for(int i = 0; i < n - 1; i++){
        arr[i] = i + 2;
        L[i] = 0;

        for(int j = i; j >= 0; j--){
            if(checkSNT(arr[j]) == false){
                L[i]++;
            }
            else break;
        }
    }
}

void print(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        if(arr[i] < 10) std::cout << " " << arr[i] << " ";
        else std::cout << arr[i] << " ";
    }
    std::cout << "\n\n";
}

//Cach1
std::pair<std::vector<int>, int> timVtriMaxL(int L[], int n){
    int max = 0;
    std::vector<int> K;

    for(int i = 0; i < n - 1; i++){
        if(L[i] > max){
            max = L[i];
        }
    }

    for(int i = 0; i < n - 1; i++){
        if(L[i] == max) K.push_back(i);
    }

    return std::make_pair(K, max);
}
//Cach 1
void print(int arr[], int L[], int n){
    std::pair<std::vector<int>, int> answer = timVtriMaxL(L, n);

    for(auto x: answer.first){
        for(int i = x - answer.second + 1; i <= x; i++){
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
    }

    std::cout << std::endl;
}


//Cach 2
int timMaxL(int L[], int n){
    int max = 0;
    for(int i = 0; i < n - 1; i++){
        if(L[i] > max) max = L[i];
    }

    return max;
}
//Cach2
void print(int arr[], int L[], int n, int max){
    for(int i = 0; i < n - 1; i++){
        if(L[i] == max){
            for(int j = i - max + 1; j <= i; j++){
                std::cout << arr[j] << " ";
            }
            std::cout << "\n";
        }
    }
}



int main(){
    int n;
    std::cin >> n;

    int arr[n - 1], L[n - 1];
    khoiTao(arr, L, n);

    print(arr, n);
    print(L, n);

    //Cach 1
    print(arr, L, n);

    //Cach 2
    int max  = timMaxL(L, n);
    print(arr, L, n, max);

    system("pause");
    return 0;
}