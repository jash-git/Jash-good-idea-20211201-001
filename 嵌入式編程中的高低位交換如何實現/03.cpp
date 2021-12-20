#include <stdio.h>

unsigned short highAndLowShiftHEX(unsigned short data);
void expandPrintBin(int val2);

int main () {

    highAndLowShiftHEX(38491);
    return 0;
}

unsigned short highAndLowShiftHEX(unsigned short data)
{
  data = (data << 8) | (data >> 8);   //0101101110010110
  data = ((data << 4) & 0xF0FF) | ((data >> 4) & 0xFF0F); //1011010101101001
  data = ((data << 2) & 0xCCCC) | ((data >> 2) & 0x3333); //1110010110010110
  data = ((data << 1) & 0xAAAA) | ((data >>1 ) & 0x5555); //1101101001101001
  printf("  after shift data=%x \n",data);  
  expandPrintBin(data);
  return data;  
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