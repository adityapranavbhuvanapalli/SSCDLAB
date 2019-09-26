//Author : Aditya Pranav Bhuvanapalli
#include <iostream>
using namespace std;
typedef struct
{
    int a,b,p;
    int rem,wait,ta;
}process;
process p[100];
int n,time=0;
void input()
{
    int i;
    cout<<"Enter n : ";cin>>n;
    cout<<"Process\tArrival\tBurst\tPriority"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"P"<<i<<"\t";
        cin>>p[i].a>>p[i].b>>p[i].p;
        p[i].rem=p[i].b;
        p[i].wait=p[i].ta=0;
    }
}
void gantt()
{
    int i,j,min,time=0,ind;
    while(1)
    {
        min=999;
        for(i=0;i<n;i++)
        {
            if(p[i].p<min && p[i].rem>0 && p[i].a<=time)
            {
                ind=i;
                min=p[i].p;
            }
        }
        if(min==999)
            break;
        p[ind].rem--;
        time++;
        if(p[ind].rem==0)
        {
            p[ind].ta=time-p[ind].a;
            p[ind].wait=p[ind].ta-p[ind].b;
        }
    }
}
void calcwait()
{
    int i;
    float avgwait=0;
    cout<<"\nWaiting Times :"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"P"<<i<<" : "<<p[i].wait<<endl;
        avgwait+=p[i].wait;
    }
    avgwait/=n;
    cout<<"\nAvg waiting time = "<<avgwait<<endl;
}
void calcta()
{
    int i;
    float avgta=0;
    cout<<"\nTurn Around Times : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<"P"<<i<<" : "<<p[i].ta<<endl;
        avgta+=p[i].ta;
    }
    avgta/=n;
    cout<<"\nAvg waiting time = "<<avgta<<endl;
}
int main()
{
    input();
    gantt();
    calcwait();
    calcta();
    return 0;
}
