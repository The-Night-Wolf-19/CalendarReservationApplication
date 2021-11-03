#ifndef _USER_EVENTS_H_
#define _USER_EVENTS_H_
#include<bits/stdc++.h>
#include "User.h"
using namespace std;
class User_events {
    private:
        string event_id;
        int start_time;
        int end_time;
        int duration;
        int number_of_users;
        vector<string> user_list;
    public:
        User_events(string id,int start, int dur, int num_of_users, vector<string> users)
        {
            event_id=id;
            start_time=start;
            end_time=start+dur;
            duration=dur;
            number_of_users=num_of_users;
            user_list=users;
        }
        // User_events(string id,int start, int dur)
        // {
        //     event_id=id;
        //     start_time=start;
        //     end_time=start+dur;
        //     duration=dur;
        //     number_of_users=0;
        //     // number_of_users=num_of_users;
        //     // user_list=users;

        // }
        string getEventID()
        {
            return event_id;
        }
        int getEventStart()
        {
            return start_time;
        }
        void setEventStart(int start)
        {
            start_time=start;   
        }
        int getEventEnd()
        {
            return end_time;
        }
        void setEventEnd(int end)
        {
            end_time=end;
        }
        int getEventDuration()
        {
            return duration;
        }
        void setEventDuration(int dur)
        {
            duration=dur;
        }
        int getEventNumberOfUsers()
        {
            return number_of_users;
        }
        
        vector<string>& getEventUserList()
        {
            return user_list;
        }
        void addEventUser(string user)
        {
            user_list.push_back(user);
            number_of_users=user_list.size();
        }
};


#endif