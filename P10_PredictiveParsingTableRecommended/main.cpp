#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
string terminal[100],first[100],follow[100],t,nt;
int N,Nt,Nnt;
char nonterminal[100];
int M[100][100];
void inputgrammar()
{
     int i;
     char ch;
     cout<<"Enter no. of productions : ";cin>>N;
     cout<<"Enter the grammar :"<<endl;
     for(i=0;i<N;i++)
     {
         cin>>nonterminal[i]>>ch>>ch>>terminal[i];
     }
}
int contains(string str,char ch)
{
    int i;
    for(i=0;i<str.length();i++)
    {
        if(ch==str[i])
        {
            return i;
        }
    }
    return -1;
}
int find(string str,char ch)
{
    int i;
    for(i=0;i<str.length();i++)
    {
        if(ch==str[i])
        {
            return 1;
        }
    }
    return 0;
}
void predictiveparsingtable()
{
    int i,j,x,y;
    for(i=0;i<nt.length();i++)
    {
        for(j=0;j<t.length();j++)
        {
            M[i][j]=-1;
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<first[i].length();j++)
        {
            if(first[i][j]!='#')
            {
                cout<<"M["<<nonterminal[i]<<","<<first[i][j]<<"] = "<<nonterminal[i]<<"->"<<terminal[i]<<endl;
                x=contains(nt,nonterminal[i]);
                y=contains(t,first[i][j]);
                M[x][y]=i;
                //cout<<"Debug: M["<<x<<","<<y<<"] = "<<nonterminal[M[x][y]]<<"->"<<terminal[M[x][y]]<<endl;
            }

        }
        if(find(first[i],'#'))
        {
            for(j=0;j<follow[i].length();j++)
            {
                cout<<"M["<<nonterminal[i]<<","<<follow[i][j]<<"] = "<<nonterminal[i]<<"->"<<terminal[i]<<endl;
                x=contains(nt,nonterminal[i]);
                y=contains(t,follow[i][j]);
                M[x][y]=i;
                //cout<<"Debug: M["<<x<<","<<y<<"] = "<<nonterminal[M[x][y]]<<"->"<<terminal[M[x][y]]<<endl;
            }
        }
    }
    for(i=0;i<t.length();i++)
    {
        cout<<"\t"<<t[i];
    }
    cout<<endl;
    for(i=0;i<nt.length();i++)
    {
        cout<<nt[i]<<"\t";
        for(j=0;j<t.length();j++)
        {
            if(M[i][j]!=-1)
                cout<<nonterminal[M[i][j]]<<"->"<<terminal[M[i][j]]<<"\t";
            else
                cout<<"\t";
        }
        cout<<endl;
    }
}
int main()
{
    int i,j;
    inputgrammar();
    t="";
    nt="";
    for(i=0;i<N;i++)
    {
        if(!find(nt,nonterminal[i]))
        {
            nt.append(1,nonterminal[i]);
        }
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<terminal[i].length();j++)
        {
            if(!find(t,terminal[i][j]) && !isupper(terminal[i][j]) && terminal[i][j]!='#')
            {
                t.append(1,terminal[i][j]);
            }
        }
    }
    t.append(1,'$');
    cout<<"Nonterminals = "<<nt<<endl;
    cout<<"Terminals = "<<t<<endl;
    cout<<"FIRST :"<<endl;
    for(i=0;i<N;i++)
    {
        cout<<"FIRST("<<terminal[i]<<") = ";
        cin>>first[i];
    }
    cout<<"FOLLOW :"<<endl;
    for(i=0;i<N;i++)
    {
        cout<<"FOLLOW("<<nonterminal[i]<<") = ";
        cin>>follow[i];
    }
    cout<<endl<<"Predictive Parsing Table Entries"<<endl;
    predictiveparsingtable();
    return 0;
}
