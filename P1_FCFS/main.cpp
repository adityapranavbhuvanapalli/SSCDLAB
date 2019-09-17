#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
float avgwait=0,avgta=0;
typedef struct
{
    int name;
    float a,b;
    float start,stop;
    float wait,ta;
}process;
void gantt(process p[100],int n)
{
    int i,j,dummy=0;
    process v;
    for(i=1;i<n;i++)
    {
        j=i-1;
        v=p[i];
        while(j>=0 && p[j].a>v.a)
        {
            p[j+1]=p[j];
            j=j-1;
        }
        p[j+1]=v;
    }

    for(i=0;i<n;i++)
    {
        //p[i].start=dummy;
        if(p[i].a>dummy)
        {
            p[i].start=p[i].a;
        }
        else
        {
            p[i].start=dummy;
        }
        p[i].stop=p[i].start+p[i].b;
        dummy=p[i].stop;
    }

    for(i=0;i<n;i++)
    {
        p[i].wait=p[i].start-p[i].a;
        p[i].ta=p[i].stop-p[i].a;
    }

    for(i=0;i<n;i++)
    {
        avgwait=avgwait+p[i].wait;
        avgta=avgta+p[i].ta;
    }

    avgwait=avgwait/n;
    avgta=avgta/n;

}
int main()
{
    int i,n;
    printf("Enter no. of process :");
    scanf ("%d",&n);
    process p[n];
    for(i=0;i<n;i++)
    {
        p[i].name=i+1;
        printf("P%d : ",p[i].name);
        printf("\nArrival = ");
        scanf("%f",&p[i].a);
        printf("\nBurst = ");
        scanf("%f",&p[i].b);
    }
    printf("\nProcess\tArrival\tBurst\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%f\t%f\n",p[i].name,p[i].a,p[i].b);
    }
    gantt(p,n);
    printf("\nProcess\tArrival\tBurst\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t%f\t%f\n",p[i].name,p[i].a,p[i].b);
    }
    printf("Avg. wait = %f",avgwait);
    printf("Avg. TA   = %f",avgta);
    return 0;
}
