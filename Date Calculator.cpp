#include<iostream>

using namespace std;

bool is_double(int year){
    if((year%4==0&&year%100!=0)||year%400==0) return true;
    else return false;
}

void date(){
    cout<<"请输入依次输入如今年月日以及需要横跨的天数"<<endl;
    int nor[]={31,28,31,30,31,30,31,31,30,31,30,31};
    int unnor[]={31,29,31,30,31,30,31,31,30,31,30,31};
    int cur_year,cur_month,cur_day,day;
    cin>>cur_year>>cur_month>>cur_day>>day;
    if(cur_month>12||cur_month<1){
        cout<<"输入异常"<<endl;
        date();
    }
    else {
        int *a;
        if(is_double(cur_year)) a=unnor;
        else a=nor;
        if(cur_day>a[cur_month-1]) {
            cout<<"输入异常"<<endl;
            date();
            }
        else {
            cur_day+=day;               
            while(cur_day>a[cur_month-1]){
                int *a;
                if(is_double(cur_year)) a=unnor;
                else a=nor;
                if(cur_day>a[cur_month-1]){
                    cur_day-=a[cur_month-1];
                    cur_month++;
                }
                if(cur_month>12){
                    cur_year++;
                    cur_month=1;
                }
            }
        }       
    }
    cout<<cur_year<<"年"<<cur_month<<"月"<<cur_day<<"日"<<endl;
}


int main(){
    date();
}