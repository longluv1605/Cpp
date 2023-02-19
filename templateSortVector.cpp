//Mau ham sort vector.

#include<bits/stdc++.h>

template <class T>
void sortVT(std::vector<T>& v, std::string how){
    //sort(v.begin(), v.end());
    if(how == "up"){
        for(int i = 0; i < (int) v.size() - i - 1; i++){
            int max = v[i], min = v[i];
            int jmax = i, jmin = i;

            for(int j = i + 1; j < (int) v.size() - i; j++){
                if(max < v[j]){
                    max = v[j];
                    jmax = j;
                }
                
                if(min > v[j]){
                    min = v[j];
                    jmin = j;
                }
            }
            std::swap(v[i], v[jmin]);
            std::swap(v[v.size() - i - 1], v[jmax]);
        }
    }
    if(how == "down"){
        for(int i = 0; i < (int) v.size() - i - 1; i++){
            int max = v[i], min = v[i];
            int jmax = i, jmin = i;

            for(int j = i + 1; j < (int) v.size() - i; j++){
                if(max < v[j]){
                    max = v[j];
                    jmax = j;
                }
                
                if(min > v[j]){
                    min = v[j];
                    jmin = j;
                }
            }
            std::swap(v[i], v[jmax]);
            std::swap(v[v.size() - i - 1], v[jmin]);

            for(auto x: v){
                std::cout << x << " ";
            }
            std::cout << "\n";
        }
    }
}

template <class D>
void sortVT(std::vector<D>& v){
    for(int i = 0; i < (int) v.size() - 1; i++){
        for(int j = i + 1; j < (int) v.size(); j++){
            if(v[i] > v[j]){
                std::swap(v[i], v[j]);

                for(auto x: v){
                    std::cout << x << " ";
                }
                std::cout << "\n";
            } 
        }
    }
}

int main(){
    std::vector<int> v = {8,6,9,4,7,5,1,3,2};
    std::string how = "up";

    //sortVT(v, how);
    sortVT(v);

    std::cout << "\n";
    for(auto x: v){
        std::cout << x << " ";
    }
    std::cout << "\n";

    system("pause");

    return 0;
}