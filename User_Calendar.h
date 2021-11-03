#ifndef _USER_CALENDAR_H_
#define _USER_CALENDAR_H_
#include<bits/stdc++.h>
#include "User_day.h"
using namespace std;

class User_Calendar{
    private:
    string calendar_id;
    vector<User_day> Days;
    public:
    User_Calendar()
    {
        calendar_id="none";
    }
    User_Calendar(string id)
    {
        calendar_id = id;
    }
    string getCalendarID()
    {
        return calendar_id;
    }
    void addUserDay(User_day u_day)
    {
        this->Days.push_back(u_day);
        
    }
    void setUserDay(vector<User_day> temp)
    {
        Days=temp;
    }
    void print_days()
    {
        cout<<Days.size()<<"user_cal_day\n";
    }
    vector<User_day>& getDays()
    {
       return Days;
    }
};

#endif