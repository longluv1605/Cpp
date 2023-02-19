//In ra ngay lien trc.

#include <bits/stdc++.h>
using namespace std;

struct Date{
    int day, month, year;
    
    //nhap
    void in(){
        cin >> day >> month >> year;
    }
    
    //check.
    bool checkvalid(){
        if(month < 1 || month > 12){
            return false;
        }
        switch(month){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            if(day < 1 || day > 31){
                return false;
            }
            break;

            //
            case 4: case 6: case 9: case 11: 
            if(day < 1 || day > 30){
                return false;
            }
            break;

            //
            case 2: 
            if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
                if(day < 1 || day > 29){
                    return false;
                }
            }
            else{
                if(day < 1 || day > 28){
                    return false;
                }
            }
            break;
        }
        return true;
    }
    
    //chuyen
    Date getPreDay(){
        // them code cua ban o day
        if(day == 1){
            switch(month){
                //
                case 2: case 4: case 6: case 8: case 9: case 11:
                day = 31;
                month -= 1;
                break;
                
                //
                case 5: case 7: case 10: case 12:
                day == 30;
                month -= 1;
                break;

                //
                case 3:
                if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
                    day = 29;
                }
                else{
                    day = 28;
                }
                month -= 1;
                break;

                //
                case 1:
                day = 31; month = 12; year -= 1;
                break;
            }
        }
        Date pre;
        pre.day = day;
        pre.month = month;
        pre.year = year;
        return pre;
    }   
    
    //xuat
    void print(){
        day < 10 ? cout << "0" << day << "/" : cout << day << "/";
        month <10 ? cout << "0" << month << "/" << year : cout << month << "/" << year;
    }
     
};

void nhapNgay(string& date, Date& now){
    cin >> date;
    char c;
    stringstream ss(date);
    ss >> now.day >> c >> now.month >> c >> now.year;
}

int main() {
    // them code cua ban o day
    Date now;
    string date;
    nhapNgay(date, now);
    
    //Check
    if(now.checkvalid() == false){
        cout << "INVALID";
        return 1;
    };

    //Tinh ngay trc
    Date pre = now.getPreDay();
    pre.print();

    system("pause");
    return 0;
}