//Author : Aditya Pranav Bhuvanapalli

// Misbehaviour for few cases

#include <iostream>
#include<cstring>
using namespace std;
char production_head[100],temp;
string production_body[100];
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
    production_head[0]='E';
    production_head[1]='X';
    production_head[2]='X';
    production_head[3]='T';
    production_head[4]='Y';
    production_head[5]='Y';
    production_head[6]='F';
    production_head[7]='F';
    production_body[0]="TX";
    production_body[1]="+TX";
    production_body[2]="#";
    production_body[3]="FY";
    production_body[4]="*FY";
    production_body[5]="#";
    production_body[6]="i";
    production_body[7]="(E)";
    for(i=0;i<N;i++)
    {
        cout<<production_head[i]<<" -> "<<production_body[i]<<endl;
    }
    cout<<endl;
}

void grammar2()
{
    int i;
    N=6;
    production_head[0]='S';
    production_head[1]='S';
    production_head[2]='S';
    production_head[3]='T';
    production_head[4]='X';
    production_head[5]='X';
    production_body[0]="a";
    production_body[1]="^";
    production_body[2]="(T)";
    production_body[3]="SX";
    production_body[4]=",SX";
    production_body[5]="#";
    for(i=0;i<N;i++)
    {
        cout<<production_head[i]<<" -> "<<production_body[i]<<endl;
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
        if(production_head[i]==X)
        {
            if(isupper(production_body[i][0]))
            {
                F1=first(production_body[i][0]);
                for(k=0;k<F1.length();k++)
                {
                    if(!find(F,F1[k]))
                    {
                        F.append(1,F1[k]);
                    }
                }
            }
            else if(production_body[i]=="#")
            {
                F.append("#");
            }
            else
            {
                F.append(1,production_body[i][0]);
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
        if(!find(stack,production_head[i]))
        {
            push(production_head[i]);
            fir=first(production_head[i]);
            cout<<"FIRST("<<production_head[i]<<") = {"<<fir<<"}"<<endl;
        }
    }
    return 0;
}
