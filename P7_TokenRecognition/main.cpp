#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char str[100],ch;
	int i=0,state=0;
	printf("Enter string : \n");
	gets(str);
	while(str[i]!='\0')
	{
		ch=str[i++];
		switch(state)
		{
			case 0:
					if(ch=='a')state=1;
					else if(ch=='b')state=4;
					else state=6;
					break;
			case 1:
					if(ch=='b')state=2;
					else if(ch=='a')state=5;
					else state=6;
					break;
			case 2:
					if(ch=='b')state=3;
					else state=6;
					break;
			case 3:
					if(ch=='b')state=4;
					else state=6;
					break;
			case 4:
					if(ch=='b')state=4;
					else state=6;
					break;
			case 5:
					if(ch=='a')state=5;
					else if(ch=='b')state=4;
					else state=6;
					break;
			case 6:
					state=6;
					break;
		}
	}
	if(state==0 || state==1 || state==5)
		printf("\nString accepted by a*\n");
	else if(state==2 || state==4)
		printf("\nString accepted by a*b+\n");
	else if(state==3)
		printf("\nString accepted by abb\n");
	else
		printf("\nString not accepted by any of the following regex \n 1. a*\n 2. a*b+\n 3. abb\n");
	return 0;
}
