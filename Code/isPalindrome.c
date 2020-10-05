

#include <stdio.h>



int isPalindrome(char* str);

int main(void)

{
   int P = isPalindrome( "kayak");
	
	printf( "%d", P);
	
    
    return 0;
}
int isPalindrome(char* str) 
{
	int  succes;
	int len;
	for(len = 0; str[len] != '\0';  len ++);
	
	for( int i = 0; i< len/2; i++)
	
	{
		if(str[i] != str[len-i-1])
		
		{ succes = 0;
			return succes;
		 }
		 }
	 succes = 1;
	 
	 return succes;
		
	
	}
