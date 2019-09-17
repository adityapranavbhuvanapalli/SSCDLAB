#include <iostream>
using namespace std;
int mutex=1,empty=5,full=0,buffer[5],top=-1;
int wait(int s)
{
    return --s;
}
int signal(int s)
{
    return ++s;
}
void producer()
{
    mutex=wait(mutex);
    empty=wait(empty);
    cout<<"Produce  : ";cin>>buffer[++top];
    cout<<"Produced : "<<buffer[top]<<endl;
    cout<<"Empty : "<<empty<<endl;
    full=signal(full);
    mutex=signal(mutex);
}
void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    cout<<"Consumed : "<<buffer[top--]<<endl;
    cout<<"Full : "<<full<<endl;
    empty=signal(empty);
    mutex=signal(mutex);
}
int main()
{
    int ch;
    while(1)
    {
        cout<<"1. Produce 2. Consume 3. Exit"<<endl<<"Your Choice :";
        cin>>ch;
        switch(ch)
        {
            case 1: if(mutex==1 && empty>0)
                        producer();
                    else
                        cout<<"Buffer is Full"<<endl;
                    break;
            case 2: if(mutex==1 && full>0)
                        consumer();
                    else
                        cout<<"Buffer is Empty"<<endl;
                    break;
            case 3: return 0;
        }
    }
    return 0;
}
