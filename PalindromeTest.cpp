#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

// Palindrom function work with only number. 
void isPalindrome(int num)
{
 	int tmp, final = 0;
 	int test =  num;
 	while(num > 0)
 	{
 		tmp =  num % 10;
 		final =  final*10 + tmp;
 		num =  num/10;
 	}
 	
 	if(final ==  test)
 	{
 		cout<< "Nuber" << test << " is Palindrom Number" << endl;
	}
	else
	{
		cout<< "Nuber " << test << " is NOT Palindrom Number" << endl;
	}
}
int main()
{
	isPalindrome(123321);
	isPalindrome(125);
	isPalindrome(1212);
	isPalindrome(121);		
	return 0;
}
