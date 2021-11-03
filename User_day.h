#ifndef _USER_DAY_H_
#define _USER_DAY_H_
#include<bits/stdc++.h>
#include "User_events.h"
using namespace std;
class User_day{
    private:
    string day_id;
    vector<User_events> Events;
    public:
    User_day(string id){
        day_id=id;
    }

    string getDayName()
    {
        return day_id;
    }
    vector<User_events>& getEvents()
    {
        return Events;
    }
    void addUserEvent(User_events event)
    {
        this->Events.push_back(event);
    }
    void setUserEvent(vector<User_events> event)
    {
        Events=event;
    }
};

#endif