#ifndef _USER_H_
#define _USER_H_
#include<bits/stdc++.h>
#include "User_Calendar.h"
using namespace std;

class User{
    private:
        string user_name;
        User_Calendar calendar;
    public:
    // User()
    // {

    // }
    User(string name)
    {
        user_name = name;
        string temp = name;
        reverse(temp.begin(),temp.end());
        string id = name + temp;
        calendar=User_Calendar(id);
    }
    string getUserName()
    {
        return user_name;
    }
    
    User_Calendar& getCalendar()
    {
        return calendar;
    }
};


#endif