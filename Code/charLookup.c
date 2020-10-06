#include <stdio.h>

int charLookup(char c, char *str);
void test();

int main(void)
{
	test();
	return 0;
}

int charLookup(char c, char *str)
{
	for (int index = 0; str[index] != '\0'; index++)
	{
		if (str[index] == c)
		{
			return index;
		}
	}
	return -1;
}

void test()
{
	printf("\n\n-- Tests de la fonction 'charLookup(char c, char* str)' --\n");
	printf("Entrees\t\t\tValeur attendue\tValeur obtenue\tTest reussi\n");

	int testCount = 5;
	char charInputs[] = {'H', '!', 'a', 'e', 'a'};
	char *strInputs[] = {"Hello world!", "Hello world!", "Hello world!", "HELLO WORLD!", "Banana playa"};
	int results[] = {0, 11, -1, -1, 1};

	for (int i = 0; i < testCount; i++)
	{
		int actualResult = charLookup(charInputs[i], strInputs[i]);
		char *successState = results[i] == actualResult ? "OUI" : "NON";
		printf("'%c', \"%s\"\t%d\t\t%d\t\t%s\n", charInputs[i], strInputs[i], results[i], actualResult, successState);
	}
}