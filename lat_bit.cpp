//Dao lai toan bo bit nhi phan cua so dang thap phan cho trc (0 --> 1 && 1 --> 0) roi chuyen lai sang dang thap phan.

#include<iostream>
#include<cmath>
#include<iomanip>
#include<vector>

int main()
{
    std::cout << "Nhap n: ";
	int n;
	std::cin >> n;
    std::vector<int> bit;

    //Chuyen n sang co so 2 (nguoc).
	while(n > 0){
        bit.push_back(n % 2);
        n /= 2;    
    }

    //Them 0 toi khi du 32 bit.
    for(int i = bit.size(); i < 32; i++){
        bit.push_back(0);
    }

    //Dao xuoi lai dung dinh dang bit.
    for(int i = 0; i < 16; i++){
       std::swap(bit[i], bit[31 - i]);
    }

    std::cout << "Dinh dang co so 2 cua n la: ";
    for(int i = 0; i < 32; i++){
        std::cout << bit[i];
    }
    std::cout << "\n";

    //Lat bit.
	for (int i = 0; i < 32; i++)
	{
		if (bit[i] == 1)
		{
			bit[i] = 0;
		}
		else
		{
			bit[i] = 1;
		}
	}

    std::cout << "Dinh dang co so 2 cua n sau khi lat bit la: ";
    for(int i = 0; i < 32; i++){
        std::cout << bit[i];
    }
    std::cout << "\n";

    //Chuyen sang co so 10.
	unsigned long dec = 0;
	for (int i = 31; i >= 0; i--)
	{
		dec += bit[i] * pow(2, 31 - i);
	}

    //Xuat.
    std::cout << "Dinh dang co so 10 cua n sau khi lat bit la: ";
	std::cout << std::setw(9) << std::fixed << dec << std::endl;

    system("pause");

	return 0;
}