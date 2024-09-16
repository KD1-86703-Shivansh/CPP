#include <iostream>
using namespace std;

class time
{
    int hour;
    int minutes;
    int seconds;

    public:
    
    time() : hour(0),minutes(0),seconds(0)
    {
    }

    time(int h, int m, int s)
    {
        hour = h;
        minutes = m;
        seconds = s;
    }
    
    int getHour()
    {
        return hour;
    }

    int getMinutes()
    {
        return minutes;
    }

    int getSeconds()
    {
        return seconds;
    }

    void printTime()
    {
        cout<<"Time : "<<hour<<":"<<minutes<<":"<<seconds<<endl;
    }

    void setHour(int h)
    {
        hour = h;
    }

    void setMinutes(int m)
    {
        minutes = m;
    }

    void setSeconds(int s)
    {
        seconds = s;
    }

    void acceptTime()
    {
        cout<<"Enter hours : "<<endl;
        cin>>hour;
        cout<<"Enter minutes : "<<endl;
        cin>>minutes;
        cout<<"Enter seconds : "<<endl;
        cin>>seconds;
    }
};


int main()
{
    time **ptr = new time *[5];

    // accept time
    for(int i=0;i<5;i++)
    {
        ptr[i] = new time;
        ptr[i]->acceptTime();
    }

    //display time
    for(int i =0;i<5;i++)
    {
        ptr[i]->printTime();
    }

    for(int i=0;i<5;i++)
    {
        delete ptr[i];
        ptr[i]= NULL;
    }
}