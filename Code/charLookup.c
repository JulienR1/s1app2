#include <stdio.h>

int charLookup (char c, char* str);


int main(void){
	
	int position = charLookup( 'm', "canard");
	
	printf( "%d", position);
	
    return 0;
}

int charLookup (char c, char* str)
{
	for (int index = 0; str[index] != '\0'; index ++)
	{
		if (str[index] == c )
		{	
			return index;
		}
	}
	return -1;
}
