// Misbehaviour for few cases

#include <iostream>
#include<cstring>
using namespace std;
char nonterminal[100],temp;
string terminal[100];
int N;
string stack;
int top=-1;

void push(char ch)
{
    top++;
    stack.append(1,ch);
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

void grammar()
{
    int i;
    N=8;
    nonterminal[0]='E';
    nonterminal[1]='X';
    nonterminal[2]='X';
    nonterminal[3]='T';
    nonterminal[4]='Y';
    nonterminal[5]='Y';
    nonterminal[6]='F';
    nonterminal[7]='F';
    terminal[0]="TX";
    terminal[1]="+TX";
    terminal[2]="#";
    terminal[3]="FY";
    terminal[4]="*FY";
    terminal[5]="#";
    terminal[6]="i";
    terminal[7]="(E)";
    for(i=0;i<N;i++)
    {
        cout<<nonterminal[i]<<" -> "<<terminal[i]<<endl;
    }
    cout<<endl;
}

void grammar2()
{
    int i;
    N=6;
    nonterminal[0]='S';
    nonterminal[1]='S';
    nonterminal[2]='S';
    nonterminal[3]='T';
    nonterminal[4]='X';
    nonterminal[5]='X';
    terminal[0]="a";
    terminal[1]="^";
    terminal[2]="(T)";
    terminal[3]="SX";
    terminal[4]=",SX";
    terminal[5]="#";
    for(i=0;i<N;i++)
    {
        cout<<nonterminal[i]<<" -> "<<terminal[i]<<endl;
    }
    cout<<endl;
}

string first(char X)
{
    int i=0,j=0,k;
    char ch;
    string F;
    string F1;
    for(i=0;i<N;i++)
    {
        if(nonterminal[i]==X)
        {
            if(isupper(terminal[i][0]))
            {
                F1=first(terminal[i][0]);
                for(k=0;k<F1.length();k++)
                {
                    if(!find(F,F1[k]))
                    {
                        F.append(1,F1[k]);
                    }
                }
            }
            else if(terminal[i]=="#")
            {
                F.append("#");
            }
            else
            {
                F.append(1,terminal[i][0]);
            }
        }
    }
    return F;
}
int main()
{
    int i=0;
    string fir;
    grammar();
    for(i=0;i<N;i++)
    {
        if(!find(stack,nonterminal[i]))
        {
            push(nonterminal[i]);
            fir=first(nonterminal[i]);
            cout<<"FIRST("<<nonterminal[i]<<") = {"<<fir<<"}"<<endl;
        }
    }
    return 0;
}
