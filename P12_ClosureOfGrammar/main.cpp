//Author : Aditya Pranav Bhuvanapalli
#include <iostream>
#include<stdio.h>
using namespace std;
int N;
char nonterminal[100];
string terminal[100];
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

    nonterminal[N]='X';
    terminal[N]="S";
    N++;
}
void closure(string s)
{
    int i,k;
    string temp;
    cout<<"\t"<<s<<endl;
    for(k=0;k<s.length();k++)
    {
        if(s[k]=='.')
        {
            k++;
            break;
        }
    }
    for(i=0;i<N;i++)
    {
        if(nonterminal[i]==s[k])
        {
            temp=nonterminal[i];
            temp.append("->.");
            temp.append(terminal[i]);
            closure(temp);
        }
    }

}
int main()
{
    string s;
    grammar();
    while(1)
    {
        cout<<"Enter string :"<<endl;cin>>s;
        cout<<"Closure("<<s<<") = "<<endl;
        cout<<"{"<<endl;
        closure(s);
        cout<<"}"<<endl;
    }
    return 0;
}
