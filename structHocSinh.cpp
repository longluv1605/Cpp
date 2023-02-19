//Nhap thong tin va diem 3 mon sau do in ra trung binh hoc ki.

#include<iostream>

struct HocSinh{
    std::string ho, ten;
    float t, l , h, tb;

    void Nhap(){
        std::cout << "Nhap ho: ";
        std::getline(std::cin, ho);
        
        std::cout << "Nhap ten: ";
        std::getline(std::cin, ten);

        std::cout << "Nhap diem toan li hoa: ";
        std::cin >> t >> l >> h;

        //Tinh diem tb.
        tb = (t + l + h) / 3.0;
    }

    void Xuat(){
        //Xuat ho va ten.
        std::cout << ho << " " << ten << "\n";

        //Xuat diem.
        std::cout << t << " " << l << " " << h << " " << tb << "\n";
    }
};


int main(){

    HocSinh A;

    A.Nhap();

    A.Xuat();

    system("pause");

    return 0;
}