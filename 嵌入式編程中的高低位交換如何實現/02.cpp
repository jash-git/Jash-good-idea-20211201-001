#include <stdio.h>

void expandPrintBin(int val2);
unsigned short HighAndLowSwitchHEX(unsigned short data);

int main () {

    HighAndLowSwitchHEX(38491);
    return 0;
}


//由于二进制直观，故写了一个扩展的打印二进制的函数
void expandPrintBin(int val2)
{
    int i,k;
    unsigned char *p = (unsigned char*)&val2 + 3; //从低位到高位,低端字节计算机
    for( k = 0; k <= 3; k++)
    {
        int val2 = *(p-k);
        for (i = 7; i >= 0; i--)
        {
            if(val2 & (1 << i))
                printf("1");
            else
                printf("0");
        }
        printf(" ");
    }
}
unsigned short HighAndLowSwitchHEX(unsigned short data)
{
    unsigned char i = 0;
    unsigned short temp = 0x0000;

    for(i = 0; i < 16; i++)
    {
        temp = ((data >> i) & 0x0001) | temp;
        if(i < 15)
        {
            temp = temp << 1;
        }
    }
    printf("temp:%x\n\n",temp);
    expandPrintBin(temp);
    return temp;
}