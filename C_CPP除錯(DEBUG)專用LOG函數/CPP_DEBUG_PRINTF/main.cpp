#include <iostream>
#include <cstdio>

using namespace std;

#define DBG_PRINTF(fmt, args...)  \
do\
{\
    printf("<<File:%s  Line:%d  Function:%s>> ", __FILE__, __LINE__, __FUNCTION__);\
    printf(fmt, ##args);\
}while(0)

void Pause()
{
    printf("Press Enter key to continue...");
    fgetc(stdin);
}
int main()
{
    cout << "Hello world!" << endl<< endl;

    int a=1,b=2,c=a+b;
    printf("a=%d,b=%d,c=a+b\n\n",a,b);
    if(c)
    {
        DBG_PRINTF("C>%d\n\n",0);
    }
    else
    {
       DBG_PRINTF("C<%d\n\n",0);
    }

    Pause();
    return 0;
}
