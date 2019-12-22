#include <iostream>

using namespace std;

void DecimalToBinary( int num )
{
    int binaryNumber[32];
    int counter = 0;
    
    while(num > 0)
    {
        binaryNumber[counter] = num % 2;
        num = num/2;
        counter++;
    }
    
    cout << "Binary Number is: ";
    for (int j = counter -1; j >= 0; j--)
    {
        cout << binaryNumber[j];
    }
    cout << endl;
}

void DecimalToOctal( int num )
{
    int OctalNumber[32];
    int counter = 0;
    
    while(num > 0)
    {
        OctalNumber[counter] = num % 8;
        num = num/8;
        counter++;
    }
    
    cout << "Octal Number is: ";
    for (int j = counter -1; j >= 0; j--)
    {
        cout << OctalNumber[j];
    }
    cout << endl;
}

void DecimalToHexadecimal( int num )
{
    char HexaDecimal[100];
    int counter = 0;
    int tmp;
    
    while(num > 0)
    {
        tmp = num % 16;
        
        if (tmp <10)
        {
            HexaDecimal[counter] = 48 + tmp;
        } else if (tmp > 9)
        {
            HexaDecimal[counter] =  55 + tmp;
        }
        
        num = num/16;
        counter++;
    }
    
    cout << "HexaDecimal Number is: ";
    for (int j = counter -1; j >= 0; j--)
    {
        cout << HexaDecimal[j];
    }
    cout << endl;
}

void DecimalToBOH(int inum)
{
    cout << "Decimal Number is:" << inum << endl;
    DecimalToBinary(inum);
    DecimalToOctal(inum);
    DecimalToHexadecimal(inum);
    
    cout << endl;
}

int main()
{
    int x;
    cout<<"======This is Decimal to Binary | Octal | HexaDecimal Tool========" << endl;
    DecimalToBOH(2);
    DecimalToBOH(3);
    DecimalToBOH(4);
    DecimalToBOH(7);
    DecimalToBOH(11);
    DecimalToBOH(235);
    DecimalToBOH(100);
    DecimalToBOH(111);
    DecimalToBOH(200);
    return 0;
}
