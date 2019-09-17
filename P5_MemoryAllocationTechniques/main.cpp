#include<stdio.h>
#include<stdlib.h>
int frag[100],b[100],f[100],i,j,nb,nf,temp,lowest=10000,highest=0;
int bf[100],ff[100];
void firstfit()
{
    for(i=1;i<=nf;i++)
    {
        for(j=1;j<=nb;j++)
        {
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];
                if(temp>=0)
                {
                    ff[i]=j;
                    break;
                }
            }
        }
        frag[i]=temp;
        bf[ff[i]]=1;
    }

}
void bestfit()
{
    for(i=1;i<=nf;i++)
    {
        for(j=1;j<=nb;j++)
        {
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];

                if(temp>=0&&lowest>temp)
                {
                    ff[i]=j;
                    lowest=temp;
                }
            }
        }
        frag[i]=lowest;
        bf[ff[i]]=1;
        lowest=10000;
    }
}
void worstfit()
{
    for(i=1;i<=nf;i++)
    {
        for(j=1;j<=nb;j++)
        {
            if(bf[j]!=1)
            {
                temp=b[j]-f[i];

                if(temp>=0&&highest<temp)
                {
                    ff[i]=j;
                    highest=temp;
                }
            }
        }
        frag[i]=highest;
        bf[ff[i]]=1;
        highest=0;
    }
}
int main()
{
    int ch;
    printf("\nEnter the number of blocks:");
    scanf("%d",&nb);
    printf("Enter the number of files:");
    scanf("%d",&nf);
    printf("\nEnter the size of the blocks:-\n");
    for(i=1;i<=nb;i++)
        scanf("%d",&b[i]);
    printf("Enter the size of the files :-\n");
    for(i=1;i<=nf;i++)
        scanf("%d",&f[i]);
    printf("\nEnter the choice:\n1:FIRST-FIT\t2:BEST-FIT\t3:WORST-FIT\t4:Exit\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:firstfit();break;
        case 2:bestfit();break;
        case 3:worstfit();break;
        case 4:exit(0);
    }
    printf("\nFile_no:\tFile_size :\tBlock_no:\tBlock_size:\tFragement");
    for(i=1;i<=nf;i++)
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\n",i,f[i],ff[i],b[ff[i]],frag[i]);
    return 0;
}
