#ifndef _CALENDAR_H_
#define _CALENDAR_H_
#include<bits/stdc++.h>
#include "User.h"
#include "User_Calendar.h"
#include "User_day.h"
#include "User_events.h"

using namespace std;

class Calendar{
    private:
    vector<User> userList;
    public:
    string register_user(string user_name);
    void display_userList();
    string create_event(string day, int start, int duration, int num_of_users, vector<string> user_list);
    void show_events(string day,string user_name );   
    int suggestion(string day, int start_range, int end_range, int duration, int num_of_users, vector<string> user_list);
    // Calendar();
};

string s="success",u="failure";

string Calendar::register_user(string name)
{
    int sz = userList.size();

    for(int i=0;i<sz;i++)
    {
        if(userList[i].getUserName() == name)
        {
            return u;
        }
    }

    User user = User(name);
   userList.push_back(user);

    return s;
}
void Calendar::display_userList()
{
    for(int i=0;i<userList.size();i++)
    {
        cout<<userList[i].getUserName()<<"\n";
    }
}


string Calendar::create_event(string day, int start, int duration, int num_of_users, vector<string> user_list)
{
    if(start+duration>1440)return u;
    string id=day+to_string(start);
    int end=start+duration;
    // vector<User> users_list;
    for(int i=0;i<num_of_users;i++)
    {
        bool if_user=false;
        for(int j=0;j<userList.size();j++)
        {
            if(userList[j].getUserName()==user_list[i])
            {
                if_user=true;
                vector<User_day> days=userList[j].getCalendar().getDays();
                for(int k=0;k<days.size();k++)
                {
                    if(days[k].getDayName()==day)
                    {
                        vector<User_events> events=days[k].getEvents();
                        for(int l=0;l<events.size();l++)
                        {
                            if(start>=events[k].getEventStart() && start<events[k].getEventEnd())
                            return u;
                        
                            if(end>events[k].getEventStart() && end<=events[k].getEventEnd())
                            return u;

                            if(start<=events[k].getEventStart() && end>=events[k].getEventEnd())
                            return u;
                        }
                    }
                }
                // users_list.push_back(userList[j]);
            }
        }
        if(!if_user)
        return u;
    }
    User_events event=User_events(id,start,duration,num_of_users,user_list);
    for(int i=0;i<num_of_users;i++)
    {
        for(int j=0;j<userList.size();j++)
        {
            if(userList[j].getUserName()==user_list[i])
            {
                bool if_day_exist=false;
                for(int k=0;k<userList[j].getCalendar().getDays().size();j++)
                {
                    if(userList[j].getCalendar().getDays()[k].getDayName()==day)
                    {
                        if_day_exist=true;
                        userList[j].getCalendar().getDays()[k].getEvents().push_back(event);
                        break;
                    }
                }
                if(!if_day_exist)
                {
                    User_day u_day=User_day(day);
                    u_day.getEvents().push_back(event);
                    userList[j].getCalendar().getDays().push_back(u_day);
                }
            }
        }
    }
    return s;    
}

void Calendar::show_events(string day,string user_name)
{
    
    bool found = false;
    int sz = userList.size();
    // cout<<sz<<"size"<<endl;
    for(int i=0;i<sz;i++)
    {
        if(userList[i].getUserName() == user_name)
        {
            found=true;
             vector<User_day> days=userList[i].getCalendar().getDays();
            // cout<<days.size()<<"day_size"<<endl;
             for(int j=0;j<days.size();j++)
             {
                 if(days[j].getDayName() == day)
                 {
                    vector<User_events> events = days[j].getEvents();

                    for(int k=0;k<events.size();k++)
                    {
                        int startTime = events[k].getEventStart();
                        int endTime = events[k].getEventEnd();
                        vector<string> users = events[k].getEventUserList();

                        cout<<startTime<<"-"<<endTime<<" ";

                        for(int l=0;l<users.size();l++)
                        {
                            cout<<users[l]<<" ";
                        }
                        cout<<endl;

                        // return;
                    }
                    return;
                 }
             }
        }
    }

    if(!found)cout<<u<<endl;
    // return;
}

int Calendar::suggestion(string day, int start_range, int end_range, int duration, int num_of_users, vector<string> user_list)
{
    //  vector<User> users;
    vector<pair<int,int>> suggest;
    suggest.push_back({start_range,end_range});
     for(int i=0;i<user_list.size();i++)
     {
         for(int j=0;j<userList.size();j++)
         {
             if(userList[j].getUserName() == user_list[i])
             {
                 vector<pair<int,int>> temp;
                 vector<User_day> days = userList[j].getCalendar().getDays();
                 for(int k=0;k<days.size();k++)
                 {
                     if(days[k].getDayName() == day)
                     {
                         vector<User_events> events = days[k].getEvents();
                         for(int l=0;l<events.size();l++)
                         {
                             if(events[l].getEventEnd() < start_range || events[l].getEventStart() > end_range)
                                continue;

                            for(int m=0;m<suggest.size();m++)
                            {
                                if(suggest[m].first<=events[l].getEventStart() && suggest[m].second>=events[l].getEventEnd())
                                {
                                    int x1,x2,y1,y2;
                                    x1=suggest[m].first;
                                    y1=events[l].getEventStart();
                                    x2=events[l].getEventEnd();
                                    y2=suggest[m].second;
                                    if(y1-x1>=duration)
                                    temp.push_back({x1,y1});
                                    if(y2-x2>=duration)
                                    temp.push_back({x2,y2});

                                }
                                else if(suggest[m].first<=events[l].getEventStart())
                                {
                                    int x1,y1;
                                    x1=suggest[m].first;
                                    y1=events[l].getEventStart();
                                    if(y1-x1>=duration)temp.push_back({x1,y1});
                                }
                                else if(suggest[m].second>=events[l].getEventEnd())
                                {
                                    int x1,y1;
                                    y1=suggest[m].second;
                                    x1=events[l].getEventEnd();
                                    if(y1-x1>=duration)temp.push_back({x1,y1});
                                }
                            }
                            suggest=temp;
                            temp={};
                         }
                     }
                 }
             }
         }
     }
     if(suggest.size()==0)return -1;
     return suggest[0].first;
}

#endif