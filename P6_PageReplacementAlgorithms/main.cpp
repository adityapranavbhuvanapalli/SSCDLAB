//Author : Aditya Pranav Bhuvanapalli

// Change : I did Optimal instead of LFU
// Refer others for LFU
#include <iostream>
#include <stdio.h>
using namespace std;
char frames[10];
string s;
int N;
int haspagefault(char ch)
{
    int i;
    for(i=0;i<N;i++)
    {
        if(frames[i]==ch)
        {
            return 0;
        }
    }
    return 1;
}
int fifo()
{
    int i,j;
    int point=-1;
    int count=0;
    for(i=0;i<N;i++)
    {
        frames[i]='X';
    }
    cout<<"PAGE\t\tFRAMES"<<endl;
    for(i=0;i<s.length();i++)
    {
        cout<<s[i]<<"\t\t";
        if(haspagefault(s[i]))
        {
            point=(point+1)%N;
            frames[point]=s[i];
            count++;
            for(j=0;j<N;j++)
            {
                cout<<frames[j]<<" ";
            }
        }
        cout<<endl;
    }
    return count;
}

int lru()
{
    int i,j,k,highest,dist[10],ind;
    int point=-1;
    int count=0;
    for(i=0;i<N;i++)
    {
        frames[i]='X';
    }
    cout<<"PAGE\t\tFRAMES"<<endl;
    for(i=0;i<s.length();i++)
    {
        cout<<s[i]<<"\t\t";
        if(haspagefault(s[i]))
        {
            if(i<N)
            {
                point=(point+1)%N;
            }
            else
            {
                highest=0;
                for(j=0;j<N;j++)
                {
                    for(k=i-1;k>=0;k--)
                    {
                        if(s[k]==frames[j])
                        {
                            dist[j]=i-k;
                            break;
                        }
                    }
                    if(dist[j]>highest)
                    {
                        highest=dist[j];
                        ind=j;
                    }
                }
                point=ind;
            }
            //point=(point+1)%N;
            frames[point]=s[i];
            count++;
            for(j=0;j<N;j++)
            {
                cout<<frames[j]<<" ";
            }
        }
        cout<<endl;
    }
    return count;
}

int lfu()
{
    int i,j,k,lowest,freq[10],ind;
    int point=-1;
    int count=0;
    for(i=0;i<N;i++)
    {
        frames[i]='X';
    }
    cout<<"PAGE\t\tFRAMES"<<endl;
    for(i=0;i<s.length();i++)
    {
        cout<<s[i]<<"\t\t";
        if(haspagefault(s[i]))
        {
            if(i<N)
            {
                point=(point+1)%N;
            }
            else
            {
                lowest=999;
                for(j=0;j<N;j++)
                {
                    freq[j]=0;
                    for(k=i-1;k>=0;k--)
                    {
                        if(s[k]==frames[j])
                        {
                            freq[j]++;
                        }
                    }
                    if(freq[j]<lowest)
                    {
                        lowest=freq[j];
                        ind=j;
                    }
                }
                point=ind;
            }
            //point=(point+1)%N;
            frames[point]=s[i];
            count++;
            for(j=0;j<N;j++)
            {
                cout<<frames[j]<<"("<<freq[j]<<")"<<" ";
            }
        }
        cout<<endl;
    }
    return count;
}

int main()
{

    cout<<"Enter N : ";cin>>N;
    cout<<"Enter string :"<<endl;cin>>s;
	cout<<"No. of page faults using FIFO 	:"<<fifo()<<endl;
	cout<<"No. of page faults using LRU  	:"<<lru()<<endl;
	cout<<"No. of page faults using LFU     :"<<lfu()<<endl;
	return 0;
}
