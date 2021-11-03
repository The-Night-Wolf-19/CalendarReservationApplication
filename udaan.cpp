#include <bits/stdc++.h>
#include "User.h"
#include "User_Calendar.h"
#include "Calendar.h"
#include "User_day.h"
#include "User_events.h"
using namespace std;
int main()
{
    Calendar cal=Calendar();
    unordered_map<string,int> function_code;
    function_code["add-user"]=1;
    function_code["create-event"]=2;
    function_code["show-events"]=3;
    function_code["suggest-slot"]=4;
    function_code["exit"]=5;;
    bool flag=true;
    while(flag)
    {
        // cout<<"\nEnter command:\n";
        string command;
        cin>>command;
        switch(function_code[command])
        {
            case 1:{
                string username;
                cin>>username;
                cout<<cal.register_user(username)<<endl;
                break;
            }
            case 2:{
                string day;
                int start, duration, num_of_users;
                cin>>day>>start>>duration>>num_of_users;
                vector<string> userlist(num_of_users);
                for(int i=0;i<num_of_users;i++)
                {
                    cin>>userlist[i];
                }
                cout<<cal.create_event(day,start,duration,num_of_users,userlist)<<endl;
                break;
            }
            case 3:{
                string day,username;
                cin>>day>>username;
                cal.show_events(day,username);
                break;
            }
            case 4:{
                // cout<<"Suggestion\n";
                string day;
                cin>>day;
                int start,end,duration,num_of_users;
                cin>>start>>end>>duration>>num_of_users;
                vector<string> userlist(num_of_users);
                if(end-start<duration){cout<<"none"<<endl;break;}
                for(int i=0;i<num_of_users;i++)
                cin>>userlist[i];
                int begin=cal.suggestion(day,start,end,duration,num_of_users,userlist);
                if(begin==-1)cout<<"none"<<endl;
                else cout<<begin<<endl;
                break;
            }
            case 5:
            {
                flag=false;
                break;
            }
            default: cout<<"Please Enter a correct command";
        }
    }
    // cout<<cal.register_user("sh1")<<"\n";
    // cout<<cal.register_user("sh2")<<"\n";
    // cout<<cal.register_user("sh3")<<"\n";
    // vector<string> v;
    // v.push_back("sh1");
    
    // v.push_back("sh2");
    
    // v.push_back("sh3"); 
    // cout<<cal.create_event("12345",0,20,3,v)<<"\n";
    // cout<<cal.create_event("12345",5,19,3,v)<<"\n";
    // cal.show_events("12345","sh1");
    // // cout<<cal.register_user("shu");
    // cal.display_userList();


    return 0;
}