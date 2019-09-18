#include <iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
string terminal[100],first[100],follow[100];
int N;
char nonterminal[100];
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
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<first[i].length();j++)
        {
            if(first[i][j]!='#')
                cout<<"M["<<nonterminal[i]<<","<<first[i][j]<<"] = "<<nonterminal[i]<<"->"<<terminal[i]<<endl;
        }
        if(find(first[i],'#'))
        {
            for(j=0;j<follow[i].length();j++)
            {
                cout<<"M["<<nonterminal[i]<<","<<follow[i][j]<<"] = "<<nonterminal[i]<<"->"<<terminal[i]<<endl;
            }
        }
    }
}
int main()
{
    int i,j;
    inputgrammar();
    cout<<"FIRST :"<<endl;
    for(i=0;i<N;i++)
    {
        cout<<"FIRST("<<terminal[i]<<") = ";cin>>first[i];
    }
    cout<<"FOLLOW :"<<endl;
    for(i=0;i<N;i++)
    {
        cout<<"FOLLOW("<<nonterminal[i]<<") = ";cin>>follow[i];
    }
    cout<<endl<<"Predictive Parsing Table Entries"<<endl;
    predictiveparsingtable();
    return 0;
}
