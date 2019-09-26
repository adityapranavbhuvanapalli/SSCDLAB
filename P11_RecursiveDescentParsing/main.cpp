//Author : Aditya Pranav Bhuvanapalli
#include <iostream>
#include<stdio.h>
using namespace std;
int N,ip=0;
char nonterminal[100];
string terminal[100];
string s;
void grammar()
{
    int i;
    char ch;
    cout<<"Enter N : ";cin>>N;
    cout<<"Enter the productions "<<endl;
    for(i=0;i<N;i++)
    {
        cin>>nonterminal[i]>>ch>>ch>>terminal[i];
    }
}
void nonterminalfn(char X)
{
    int i,j;
    int temp;
    for(i=0;i<N;i++)
    {
        temp=ip;
        if(nonterminal[i]==X)
        {
            for(j=0;j<terminal[i].length();j++)
            {
                if(s[ip]==terminal[i][j])
                {
                    ip++;
                }
                else if(isupper(terminal[i][j]))
                {
                    nonterminalfn(terminal[i][j]);
                }
                else if(terminal[i]=="#")
                {
                    break;
                }
                else
                {
                    ip=temp;
                    break;
                }
            }
        }
    }
}
int main()
{
    grammar();
    while(1)
    {
        ip=0;
        cout<<"Enter string :"<<endl;cin>>s;
        nonterminalfn('S');
        if(ip==s.length())
        {
            cout<<"Success"<<endl;
        }
        else
        {
            cout<<"Failure"<<endl;
        }
    }
    return 0;
}
