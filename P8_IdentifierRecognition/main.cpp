#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
int check(char s[100])
{
	int i,n;
	n=strlen(s);
	if(isalpha(s[0]) || s[0]=='_')
	{
		for(i=1;i<n;i++)
			if(!(isalnum(s[i]) || s[i]=='_'))
				return 0;
		return 1;
	}
	return 0;
}
int main()
{
	char reg[100];
	string res="is not a C identifier";
	printf("Enter the string : ");
	gets(reg);
	if(check(reg))
		res="is a C identifier";
	cout<<reg<<" : "<<res<<endl;
}
