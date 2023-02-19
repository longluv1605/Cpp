//In ra ngay tiep theo.

#include <bits/stdc++.h>
using namespace std;

struct date{
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
            case 1: case 3: case 5: case 7: case 8: case 10: 
            case 12: if(day < 1 || day > 31){
                return false;
            }
            break;
            case 4: case 6: case 9: 
            case 11: if(day < 1 || day > 30){
                return false;
            }
            break;
            case 2: if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
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
    date getNextDay(){
        // them code cua ban o day
        switch(month){
            case 1: case 3: case 5: case 7: case 8: 
            case 10: if(day == 31){
                day = 1;
                month += 1;
                //break;
            }
            else{
                day += 1;
                //break;
            }
            break;
            case 12: if(day == 31){
                day = 1;
                month = 1;
                year += 1;
                //break;
            }
            else{
                day += 1;
                //break;
            }
            break;
            case 4: case 6: case 9: 
            case 11: if(day == 30){
                day = 1;
                month += 1;
                //break;
            }
            else{
                day += 1;
                //break;
            }
            break;
            case 2: if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0){
                if(day == 29){
                    day = 1;
                    month += 1;
                    //break;
                }
                else{
                    day += 1;
                    //break;
                }
            }
            else{
                if(day == 28){
                    day = 1;
                    month += 1;
                    //break;
                }
                else{
                    day += 1;
                    //break;
                }
            }
            break;
        }
        date next;
        next.day = day;
        next.month = month;
        next.year = year;
        return next;
    }   
    
    //xuat
    void print(){
        day < 10 ? cout << "0" << day << "/" : cout << day << "/";
        month <10 ? cout << "0" << month << "/" << year : cout << month << "/" << year;
    }
     
};

int main() {
    // them code cua ban o day
    date now;
    string str;
    cin >> str;
    char c;
    stringstream ss(str);
    ss >> now.day >> c >> now.month >> c >> now.year;
    
    if(now.checkvalid() == false){
        cout << "INVALID";
        return 1;
    };
    date next = now.getNextDay();
    next.print();

    system("pause");
    return 0;
}