#include <stdio.h>

unsigned char highAndLowShiftHEX(unsigned char );
void printBin(int );

int main () {

    highAndLowShiftHEX(209);
    return 0;
}

unsigned char highAndLowShiftHEX(unsigned char data)  
{  
   data=(data<<4)|(data>>4);  
   data=((data<<2)&0xcc)|((data>>2)&0x33);  
   data=((data<<1)&0xaa)|((data>>1)&0x55);  
   printf("  after shift data=%x \n",data);  
   printBin(data);
   return data;  
}

//由于二进制直观，故写了一个打印二进制的函数
void printBin(int n)
{
    int len = sizeof(n)*8;//总位数。
    int i;
    if(i == 0)
    {
         printf("0");
         return;
    }
    for(i = len-1; i >= 0; i --)//略去高位0.
    {
        if(n&(1<<i)) break;
    }

    for(;i>=0; i --)
        printf("%d", (n&(1<<i)) != 0);
}