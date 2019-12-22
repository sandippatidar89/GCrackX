/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void BinaryToDecimal( int binaryNum )
{
    int decimalNum = 0;
    int last_digit;
    int base = 1;
    
    while(binaryNum > 0)
    {
        last_digit = binaryNum % 10; 
        binaryNum =  binaryNum / 10;
        decimalNum = decimalNum + last_digit*base;
        
        base = base*2;
    }
    
    cout << "Decimal Number is: " << decimalNum << endl;
}

int main()
{
    cout<<"Binary To Decimal Program!!!" << endl;
    BinaryToDecimal(111);
    BinaryToDecimal(100);
    BinaryToDecimal(1111);
    
    return 0;
}
