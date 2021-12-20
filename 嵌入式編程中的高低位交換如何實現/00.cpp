#include <stdio.h>

unsigned char highAndLowShiftHEX(unsigned char data);
void printBin(int n);

int main () {

    highAndLowShiftHEX(209);
    return 0;
}

unsigned char highAndLowShiftHEX(unsigned char data)  
{  
   unsigned char i;  
   unsigned char tmp=0x00;  
   for(i=0;i<8;i++)  
   {  
       tmp=((data>>i)&0x01)|tmp;  
       //printBin(tmp);
       if(i<7)  
           tmp=tmp<<1;  
   }  
   printf("\nafter shift data:");  
   printBin(tmp);
   return tmp;    
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